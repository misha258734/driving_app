#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::loadTicketsTest()                        // On edit ticket button
{
    for(int i = 1; i <= textDataBase.ticketCount; i++) {
        QHBoxLayout* hBox = new QHBoxLayout;

        QPushButton *addBtn = new QPushButton("Билет " + QString::number(i));
        addBtn->setMinimumHeight(50);
        QObject::connect(addBtn, &QPushButton::clicked,this,[=] {loadTest(i);});

        hBox->addWidget(addBtn);
        ui->tickets_buttons_scroll_area->addLayout(hBox);
    }
}

void MainWindow::loadTest(int ticketNum)
{
    changePage(test_page);

}
