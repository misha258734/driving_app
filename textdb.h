#ifndef TEXTDB_H
#define TEXTDB_H

#include "ticket.h"
#include "question.h"
#include <QFile>
#include <QDir>

class textDB
{
public:
    textDB();

    QFile ticketFile;
    QTextStream out;
    ticket tick;
    QDir dir;
    int ticketCount = 0;


    int initializeFile(QString ticketPath, QIODevice::OpenMode mode);
    void countTicketFiles();
    void closeFile();

    int addTicketToFile();
    void addQuestToFile();

    int loadTicketFromFile(int ticketNum);

    int removeTicketFile(int ticketNum);
    int removeQuest(int questNum);
    int removeAnswer(int anwserNum);


    question getTicketQuest();
};

#endif // TEXTDB_H
