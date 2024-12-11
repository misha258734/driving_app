#ifndef TEXTDB_H
#define TEXTDB_H

#include "ticket.h"
#include "question.h"
#include <QFile>

class textDB
{
public:
    textDB();

    QFile ticketFile;
    QTextStream out;

    int initializeFile(QString ticketPath, QIODevice::OpenMode mode);
    void closeFile();

    int addTicket(int num, QVector<question> questions, int errorCount, QDate lastPass);
    ticket getTicket();
    int changeTicketQuest(QString quest, QVector<QString> anwsers, int rightAnwser, QString imagePath = "", QString comment = "");
    question getTicketQuest();
};

#endif // TEXTDB_H
