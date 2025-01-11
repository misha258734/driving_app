#ifndef APPDATABASE_H
#define APPDATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QJsonArray>
#include <QJsonDocument>

#include <QDir>
#include <QPixmap>
#include <QBuffer>

struct question
{
    int id = -1;
    QPixmap image = QPixmap();
    QString quest = "";
    QStringList answers = {};
    int rightAnswer = -1;
    QString comment = "";
};

struct ticket
{
    int number = -1;
    QVector<question> questions = {};
    int errorCounter = 0;
    QDate lastPass = QDate(0,0,0);
};

QStringList JSONArrayToStringList(QString jsonArray);
QString stringListToJsonArray(QStringList stringList);

class appdatabase
{
    QSqlDatabase database;
    QString databaseName = "ticketsData.sqlite";

public:
    ticket ticket;
    QVector<int> ticketsNumbersVector;

    appdatabase();

    int loadTicketToBase();
    int loadTicketFromBase(int ticketNum);

    int removeTicketFromBase(int ticketNum);
    int removeQuestionFromBase(int ticketNum, int questNum);
    int removeImageFromBase(int ticketNum, int questNum);

private:
    void initializeDatabase(QString DBName);
    void fillTicketsNumbersVector();

    int createTables();

    int insertTicket(int num, int errors, QString passDate);
    int replaceTicket(int num, int errors, QString passDate);
    int insertQuestion(int id, QByteArray img, QString quest, QString answ, QString comm, int right_ans);
    int replaceQuestion(int id, QByteArray img, QString quest, QString answ, QString comm, int right_ans);
    int insertTicketsQuestions(int id, int tickNum);

};

#endif // APPDATABASE_H
