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
    int errorCounter;
    QDate lastPass;
};

#endif // TICKET_H
