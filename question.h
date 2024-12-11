#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>


class question
{
public:
    question();

    QString imagePath;
    QString quest;
    QVector<QString> anwsers;
    int rightAnwser;
    QString comment;
};

#endif // QUESTION_H
