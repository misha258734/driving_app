#include "include/mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::loadTicketsTest()                        // On edit ticket button
{
    for(int i = 0; i < database.ticketsNumbersVector.size(); i++) {
        int ticketNum = database.ticketsNumbersVector[i];
        QHBoxLayout* hBox = new QHBoxLayout;

        QPushButton *addBtn = new QPushButton("Билет " + QString::number(i+1));
        addBtn->setMinimumHeight(50);
        QObject::connect(addBtn, &QPushButton::clicked,this,[=] {loadTest(ticketNum);});

        hBox->addWidget(addBtn);
        ui->tickets_buttons_scroll_area->addLayout(hBox);
    }
}

void MainWindow::loadTest(int ticketNum)
{
    changePage(test_page);

    if(ticketNum) return;

}
