#ifndef TICKET_H
#define TICKET_H

#include "question.h"
#include <QDate>

class ticket
{
public:
    ticket();

    int number;
    QVector<question> questions;
    int errorCounter = -1;
    QDate lastPass = QDate(0,0,0);
};

#endif // TICKET_H
