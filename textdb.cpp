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

    for(int i = 0; i < tick.questions.count(); i++) {
        imgFile.setFileName(tick.questions[i].imagePath);
        imgFile.setFileName(tick.questions[i].imagePath);
        if(tick.questions[i].imagePath != "") {
            if(imgFile.open(QIODevice::ReadOnly)) {
                newImgPath = QString("src/images/image-%1:%2").arg(tick.number).arg(i+1);
                QFile::copy(tick.questions[i].imagePath, newImgPath);
                tick.questions[i].imagePath = newImgPath;
                imgFile.close();
            }
        }
    }
}

int textDB::addTicketToFile()
{
    QString filePath = QString("src/tickets/ticket-%1").arg(tick.number);
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

    if(initializeFile(QString("src/tickets/ticket-%1").arg(ticketNum), QIODevice::ReadOnly))
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
    if(!ticketDir.remove(QString("ticket-%1").arg(ticketNum)))
        return 1;
    for(int i = ticketNum; i < ticketCount; i++)
    {
        if(!ticketDir.rename(QString("ticket-%1").arg(i+1), QString("ticket-%1").arg(i)))
            return 2;
    }
    countTicketFiles();
    return 0;
}

int textDB::removeImageFile(int imageNum)
{
    if(!ticketDir.remove(QString("ticket-%1").arg(imageNum)))
        return 1;
    return 0;
}
