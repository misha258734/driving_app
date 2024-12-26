#include "textdb.h"

textDB::textDB() {
    out.setDevice(&ticketFile);

    imageDir.setPath("src/images");
    if (!imageDir.exists())
        imageDir.mkpath(".");
    ticketDir.setPath("src/tickets");
    if (!ticketDir.exists())
        ticketDir.mkpath(".");

    countTicketFiles();
    imageDir.refresh();
}

void textDB::countTicketFiles()
{
    ticketDir.refresh();
    ticketCount = 0;
    for(int i = 0; i < ticketDir.count(); i++)
        if(ticketDir[i].startsWith("ticket-"))
            ticketCount++;
}


int textDB::initializeFile(QString ticketPath, QIODevice::OpenMode mode)
{
    ticketFile.close();
    ticketFile.setFileName(ticketPath);
    if (!ticketFile.open(mode))
        return 1;

    return 0;
}
void textDB::closeFile()
{
    ticketFile.close();
    out.reset();
}

void textDB::addImages()
{
    QFile imgFile;
    QString newImgPath;
    QPixmap pixmap;

    for(int i = 0; i < tick.questions.count(); i++) {
        imgFile.setFileName(tick.questions[i].imagePath);
        if(tick.questions[i].imagePath != "") {
            if(imgFile.open(QIODevice::ReadOnly)) {
                pixmap.load(tick.questions[i].imagePath);
                newImgPath = QString("image-%1:%2.png").arg(tick.number).arg(i+1);
                pixmap.save(QString("src/images/%1").arg(newImgPath), "PNG");
                tick.questions[i].imagePath = newImgPath;
                imgFile.close();
            }
        }
    }
    imageDir.refresh();
}

int textDB::addTicketToFile()
{
    QString filePath = QString("src/tickets/ticket-%1.txt").arg(tick.number);
    if(initializeFile(filePath, QIODevice::WriteOnly | QIODevice::Truncate))
        return 1;

    addImages();

    QString lastDate;
    if(tick.lastPass.isNull())
        lastDate = '0';
    else
        lastDate = tick.lastPass.toString("dd.MM.yy");

    out << QString::number(tick.errorCounter) + '\t' + lastDate + '\n';
    for(question &i : tick.questions) {
        out << i.quest + '\t' + QString::number(i.rightAnswer) + '\t' + i.imagePath + '\t' + i.comment + '\n';
        for(QString &j : i.answer)
            out << '\t' + j + '\n';
        out << "###\n";
    }
    closeFile();
    countTicketFiles();

    return 0;
}

int textDB::loadTicketFromFile(int ticketNum)
{
    QString textLine;
    QStringList splitLine;
    question *quest;

    if(initializeFile(QString("src/tickets/ticket-%1.txt").arg(ticketNum), QIODevice::ReadOnly))
        return 1;
    tick.number = ticketNum;
    tick.questions.clear();

    textLine = out.readLine();

    splitLine = textLine.split('\t');

    tick.errorCounter = splitLine[1].toInt();


    if(splitLine[1] == '0')
        tick.lastPass = QDate();
    else
        tick.lastPass = QDate::fromString(splitLine[1], "dd.MM.yy");

    while(!out.atEnd()) {
        quest = new question;

        textLine = out.readLine();

        splitLine = textLine.split('\t');
        quest->quest = splitLine[0];
        quest->rightAnswer = splitLine[1].toInt();
        quest->imagePath = splitLine[2];
        quest->comment = splitLine[3];
        while((textLine = out.readLine()) != "###") {
            quest->answer.push_back(textLine.remove(0, 1));
        }
        tick.questions.push_back(*quest);
    }
    closeFile();
    return 0;
}

int textDB::removeTicketFile(int ticketNum)
{
    if(!ticketDir.remove(QString("ticket-%1.txt").arg(ticketNum)))
        return 1;
    imageDir.refresh();
    imageDir.setNameFilters(QStringList() << QString("image-%1:*").arg(ticketNum));
    imageDir.setFilter(QDir::Files);
    foreach(QString image, imageDir.entryList())
    {
        imageDir.remove(image);
    }

    for(int i = ticketNum; i < ticketCount; i++)
    {
        if(!ticketDir.rename(QString("ticket-%1.txt").arg(i+1), QString("ticket-%1.txt").arg(i)))
            return 2;

        loadTicketFromFile(i);
        for(int j = 0; j < tick.questions.size(); j++)
            if(tick.questions[j].imagePath != "") {
                QString newImgPath = QString("image-%1:%2.png").arg(i).arg(j+1);
                imageDir.rename(tick.questions[j].imagePath, QString("image-%1:%2").arg(i).arg(j+1));
                tick.questions[j].imagePath = newImgPath;
            }
        addTicketToFile();
    }
    imageDir.setNameFilters(QStringList() << QString("*"));

    countTicketFiles();
    return 0;
}

void textDB::removeQuestionFile(int questNum)
{
    imageDir.remove(tick.questions[questNum].imagePath);

    tick.questions.remove(questNum);

    for(int i = questNum; i < tick.questions.size(); i++)
        if(tick.questions[i].imagePath != "") {
            QString newImgPath = QString("image-%1:%2.png").arg(tick.number).arg(i+1);
            imageDir.rename(tick.questions[i].imagePath, newImgPath);
            tick.questions[i].imagePath = newImgPath;
        }
    addTicketToFile();
}

void textDB::removeImage(int questNum)
{
    imageDir.remove(tick.questions[questNum].imagePath);

    tick.questions[questNum].imagePath = "";
}

