#include "appdatabase.h"

appdatabase::appdatabase()
{
    initializeDatabase(databaseName);
    fillTicketsNumbersVector();
}

void appdatabase::initializeDatabase(QString DBName)
{
    if (database.isOpen()) {
        database.close();
        database.removeDatabase( QSqlDatabase::defaultConnection );
    }

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(DBName);
    if(!database.open()) {
        qDebug() << "dataBase opening problem\n";
    }

    int status = createTables();
    if(status == 1)
        qDebug() << "Create table error: tickets\n";
    if(status == 2)
        qDebug() << "Create table error: questions\n";
    if(status == 3)
        qDebug() << "Create table error: tickets_questions\n";
}

void appdatabase::fillTicketsNumbersVector()
{
    QSqlQuery qry;

    qry.prepare("SELECT number FROM tickets");

    if(!qry.exec()) {
        qDebug() << "error counting tickets\n" << qry.lastError();
    }
    ticketsNumbersVector.clear();
    while(qry.next()) {
        ticketsNumbersVector.push_back(qry.value(0).toInt());
    }
}

int appdatabase::createTables()
{
    QSqlQuery qry;

    qry.prepare("CREATE TABLE IF NOT EXISTS tickets ("                 // Tickets table
             "number INTEGER PRIMARY KEY AUTOINCREMENT,"
             "error_counter INTEGER,"
             "last_pass TEXT);");

    if(!qry.exec()) {
        qDebug() << "error creating table\n" << qry.lastError();
        return 1;
    }

    qry.prepare("CREATE TABLE IF NOT EXISTS questions ("               // Questions table
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "image BLOB,"
             "question TEXT,"
             "answers TEXT,"
             "comment TEXT,"
             "right_answer INTEGER);");

    if(!qry.exec()) {
        qDebug() << "error creating table\n" << qry.lastError();
        return 2;
    }

    qry.prepare("CREATE TABLE IF NOT EXISTS tickets_questions ("       // Tickets to Questions table
             "ticket_number INTEGER REFERENCES tickets(number),"
                "question_id INTEGER REFERENCES questions(id));");

    if(!qry.exec()) {
        qDebug() << "error creating table\n" << qry.lastError();
        return 3;
    }
    return 0;
}

int appdatabase::insertTicket(int num, int errors, QString passDate)
{
    QSqlQuery qry;

    qry.prepare("SELECT 1 FROM tickets WHERE number = :num");
    qry.bindValue(":num", num);

    if(!qry.exec()) {
        qDebug() << "check ticket existance " << qry.lastError();
        return 1;
    }
    qry.next();
    int exist = qry.value(0).toInt();
    if(exist) return replaceTicket(num, errors, passDate);

    qry.prepare("INSERT INTO tickets ("
                "error_counter,"
                "last_pass)"
                "VALUES (:error_counter, :last_pass);");
    qry.bindValue(":error_counter", errors);
    qry.bindValue(":last_pass", passDate);

    if(!qry.exec()) {
        qDebug() << "insert ticket: " << qry.lastError();
        return 2;
    }
    fillTicketsNumbersVector();
    return 0;
}

int appdatabase::replaceTicket(int num, int errors, QString passDate)
{
    QSqlQuery qry;

    qry.prepare("UPDATE tickets SET error_counter=:errors, last_pass=:passDate WHERE number=:num ");
    qry.bindValue(":errors", errors);
    qry.bindValue(":passDate", passDate);
    qry.bindValue(":num", num);

    if(!qry.exec()) {
        qDebug() << "update ticket: " << qry.lastError();
        return 1;
    }
    return 0;
}

int appdatabase::insertQuestion(int id, QByteArray img, QString quest, QString answ, QString comm, int right_ans)
{
    QSqlQuery qry;

    qry.prepare("SELECT 1 FROM questions WHERE id = :id");
    qry.bindValue(":id", id);
    if(!qry.exec()) {
        qDebug() << "check question existance " << qry.lastError();
        return -1;
    }
    qry.next();
    int exist = qry.value(0).toInt();
    if(exist) return replaceQuestion(id, img, quest, answ, comm, right_ans);

    qry.prepare("INSERT INTO questions ("
                "image,"
                "question,"
                "answers,"
                "comment,"
                "right_answer)"
                "VALUES (:image, :question, :answers, :comment, :right_answer);");
    qry.bindValue(":image", img);
    qry.bindValue(":question", quest);
    qry.bindValue(":answers", answ);
    qry.bindValue(":comment", comm);
    qry.bindValue(":right_answer", right_ans);

    if(!qry.exec()) {
        qDebug() << "insert question: " << qry.lastError();
        return -2;
    }

    qry.prepare("SELECT last_insert_rowid()");
    if(!qry.exec()) {
        qDebug() << "SELECT inserted: " << qry.lastError();
        return -3;
    }
    qry.next();
    return qry.value(0).toInt();
}

int appdatabase::replaceQuestion(int id, QByteArray img, QString quest, QString answ, QString comm, int right_ans)
{
    QSqlQuery qry;

    qry.prepare("UPDATE questions "
                "SET "
                "image = :image, "
                "question = :question, "
                "answers = :answers, "
                "comment = :comment, "
                "right_answer = :right_answer "
                "WHERE id = :id ");
    qry.bindValue(":image", img);
    qry.bindValue(":question", quest);
    qry.bindValue(":answers", answ);
    qry.bindValue(":comment", comm);
    qry.bindValue(":right_answer", right_ans);
    qry.bindValue(":id", id);

    if(!qry.exec()) {
        qDebug() << "update question: " << qry.lastError();
        return -1;
    }

    return id;
}

int appdatabase::insertTicketsQuestions(int id, int tickNum)
{
    QSqlQuery qry;

    qry.prepare("SELECT 1 FROM tickets_questions WHERE ticket_number = :tickNum and question_id = :id ");
    qry.bindValue(":tickNum", tickNum);
    qry.bindValue(":id", id);
    if(!qry.exec()) {
        qDebug() << "check ticket-question existance " << qry.lastError();
        return 1;
    }
    qry.next();
    int exist = qry.value(0).toInt();
    if(exist) return 0;

    qry.prepare("INSERT INTO tickets_questions ("
                "ticket_number,"
                "question_id)"
                "VALUES (:ticket_number, :question_id);");
    qry.bindValue(":ticket_number", tickNum);
    qry.bindValue(":question_id", id);

    if(!qry.exec()) {
        qDebug() << "insert ticket-question: " << qry.lastError();
        return 2;
    }

    return 0;
}

int appdatabase::loadTicketToBase()
{
    if(insertTicket(ticket.number, ticket.errorCounter, ticket.lastPass.toString("dd.MM.yyyy")))
        return 1;                                           // insert tickets error

    for(auto &quest : ticket.questions) {
        QByteArray imgbArray;
        QBuffer buffer(&imgbArray);
        buffer.open(QIODevice::WriteOnly);
        quest.image.save(&buffer, "PNG");

        QString answers = stringListToJsonArray(quest.answers);

        quest.id = insertQuestion(quest.id,
                                  imgbArray,
                                  quest.quest,
                                  answers,
                                  quest.comment,
                                  quest.rightAnswer);
        if(quest.id < 0)                                    // insert question error
            return 2;
        if(insertTicketsQuestions(quest.id, ticket.number)) // insert tickets_questions error
            return 3;
    }
    return 0;
}

int appdatabase::loadTicketFromBase(int ticketNum)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM tickets WHERE number = :ticket_number");
    qry.bindValue(":ticket_number", ticketNum);
    if(!qry.exec()) {
        qDebug() << "select ticket: " << qry.lastError();
        return 1;
    }
    qry.next();
    ticket.number = qry.value(0).toInt();
    ticket.errorCounter = qry.value(1).toInt();
    ticket.lastPass = QDate::fromString(qry.value(2).toString(), "dd.MM.yyyy");
    ticket.questions.clear();


    qry.prepare("SELECT * FROM tickets_questions "
                "JOIN questions ON questions.id = tickets_questions.question_id "
                "WHERE ticket_number = :ticket_number ");
    qry.bindValue(":ticket_number", ticketNum);
    if(!qry.exec()) {
        qDebug() << "select ticket-question: " << qry.lastError();
        return 2;
    }
    while (qry.next()) {
        question quest;
        quest.id = qry.value(2).toInt();
        quest.image.loadFromData(qry.value(3).toByteArray());
        quest.quest = qry.value(4).toString();
        quest.answers = JSONArrayToStringList(qry.value(5).toString());
        quest.comment = qry.value(6).toString();
        quest.rightAnswer = qry.value(7).toInt();

        ticket.questions.push_back(quest);
    }
    return 0;
}

int appdatabase::removeTicketFromBase(int ticketNum)
{
    loadTicketFromBase(ticketNum);

    QSqlQuery qry;

    qry.prepare("DELETE FROM tickets WHERE number = :ticket_number");
    qry.bindValue(":ticket_number", ticketNum);
    if(!qry.exec()) {
        qDebug() << "remove ticket: " << qry.lastError();
        return 1;
    }

    for(auto &i : ticket.questions) {
        qry.prepare("DELETE FROM questions WHERE id = :question_id");
        qry.bindValue(":question_id", i.id);
        if(!qry.exec()) {
            qDebug() << "remove question: " << qry.lastError();
            return 2;
        }
    }

    qry.prepare("DELETE FROM tickets_questions WHERE ticket_number = :ticket_number");
    qry.bindValue(":ticket_number", ticketNum);
    if(!qry.exec()) {
        qDebug() << "remove ticket-question: " << qry.lastError();
        return 3;
    }
    fillTicketsNumbersVector();
    return 0;
}

int appdatabase::removeQuestionFromBase(int ticketNum, int questNum)
{
    QSqlQuery qry;

    loadTicketFromBase(ticketNum);
    qry.prepare("DELETE FROM questions WHERE id = :question_id");
    qry.bindValue(":question_id", ticket.questions[questNum].id);
    if(!qry.exec()) {
        qDebug() << "remove question: " << qry.lastError();
        return 1;
    }

    qry.prepare("DELETE FROM tickets_questions WHERE question_id = :question_id");
    qry.bindValue(":question_id", ticket.questions[questNum].id);
    if(!qry.exec()) {
        qDebug() << "remove ticket-questions: " << qry.lastError();
        return 2;
    }

    return 0;
}

int appdatabase::removeImageFromBase(int ticketNum, int questNum)
{
    QSqlQuery qry;

    loadTicketFromBase(ticketNum);
    qry.prepare("UPDATE questions SET image = 0 WHERE id = :question_id");
    qry.bindValue(":question_id", ticket.questions[questNum].id);
    if(!qry.exec()) {
        qDebug() << "remove image: " << qry.lastError();
        return 1;
    }
    return 0;
}

QStringList JSONArrayToStringList(QString jsonArray)
{
    QJsonDocument doc = QJsonDocument::fromJson(jsonArray.toUtf8());
    if (!doc.isArray()) {
        qDebug() << "Error parsing json\n";
        return {};
    }

    QStringList stringList(doc.toVariant().toStringList());

    return stringList;
}

QString stringListToJsonArray(QStringList stringList)
{
    QJsonArray array = QJsonArray::fromStringList(stringList);

    QJsonDocument doc;
    doc.setArray(array);
    QString dataToString(doc.toJson());

    return dataToString;
}


