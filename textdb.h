#ifndef TEXTDB_H
#define TEXTDB_H

#include <QDir>
#include <QPixmap>

struct question
{
    QString imagePath;
    QString quest;
    QVector<QString> answer;
    int rightAnswer;
    QString comment;
};

struct ticket
{
    int number;
    QVector<question> questions;
    int errorCounter = -1;
    QDate lastPass = QDate(0,0,0);
};

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
    int removeQuestionFile(int questNum);
};

#endif // TEXTDB_H
