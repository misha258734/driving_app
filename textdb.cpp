#include "textdb.h"

textDB::textDB() {
    out.setDevice(&ticketFile);
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
}

int textDB::addTicket(int num, QVector<question> questions, int errorCount, QDate lastPass = QDate(0, 0, 0))
{
    out << (QString::number(num) + '\t' + QString::number(errorCount) + '\t' + lastPass.toString("dd.MM.yy") + '\n');
    for(auto i : questions) {
        out << i.quest + '\t' + QString::number(i.rightAnwser) + '\n' + i.imagePath + '\t' + i.comment + '\n';
        for(auto j : i.anwsers)
            out << '\t' + j + '\n';
    }
}

ticket textDB::getTicket()
{

}

int changeTicketQuest(QString quest, QVector<QString> anwsers, int rightAnwser, QString imagePath = "", QString comment = "")
{

}
