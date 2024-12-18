#include "textdb.h"

textDB::textDB() {
    out.setDevice(&ticketFile);

    dir.setPath("src/images");
    if (!dir.exists())
        dir.mkpath(".");
    dir.setPath("src/tickets");
    if (!dir.exists())
        dir.mkpath(".");

    countTicketFiles();
}

void textDB::countTicketFiles()
{
    ticketCount = 0;
    for(int i = 0; i < dir.count(); i++)
        if(dir[i].startsWith("ticket-"))
            ticketCount++;
}

int textDB::initializeFile(QString ticketPath, QIODevice::OpenMode mode)
{
    ticketFile.close();
    ticketFile.setFileName(ticketPath);
    if (!ticketFile.open(mode))
        return 1;
    countTicketFiles();

    return 0;
}
void textDB::closeFile()
{
    ticketFile.close();
    out.reset();
}

int textDB::addTicketToFile()
{
    QString filePath = QString("src/tickets/ticket-%1").arg(tick.number);
    if(initializeFile(filePath, QIODevice::WriteOnly | QIODevice::Truncate))
        return 1;

    out << QString::number(tick.errorCounter) + '\t' + tick.lastPass.toString("dd.MM.yy") + '\n';
    for(question &i : tick.questions) {
        out << i.quest + '\t' + QString::number(i.rightAnswer) + '\t' + i.imagePath + '\t' + i.comment + '\n';
        for(QString &j : i.answer)
            out << '\t' + j + '\n';
        out << "###\n";
    }
    closeFile();

    return 0;
}

int textDB::loadTicketFromFile(int ticketNum)
{
    QString textLine;
    QStringList splitLine;
    question *quest;

    if(initializeFile(QString("src/tickets/ticket-%1").arg(ticketNum), QIODevice::ReadOnly))
        return 1;

    tick.questions.clear();

    textLine = out.readLine();

    splitLine = textLine.split('\t');

    tick.errorCounter = splitLine[1].toInt();
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
    if(!dir.remove(QString("ticket-%1").arg(ticketNum)))
        return 1;
    return 0;
}
