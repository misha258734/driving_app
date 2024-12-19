#ifndef TEXTDB_H
#define TEXTDB_H

#include "ticket.h"
#include "question.h"
#include <QFile>
#include <QDir>

struct textDB
{
    textDB();

    QFile ticketFile;
    QTextStream out;
    ticket tick;
    QDir ticketDir, imageDir;
    int ticketCount = 0;


    int initializeFile(QString ticketPath, QIODevice::OpenMode mode);
    void countTicketFiles();

    void closeFile();

    int addTicketToFile();
    void addImages();

    int loadTicketFromFile(int ticketNum);

    int removeTicketFile(int ticketNum);
    int removeImageFile(int imageNum);

    question getTicketQuest();
};

#endif // TEXTDB_H
