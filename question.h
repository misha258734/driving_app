#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>


struct question
{
    question();

    QString imagePath;
    QString quest;
    QVector<QString> answer;
    int rightAnswer;
    QString comment;
};

#endif // QUESTION_H
