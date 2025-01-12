#include "include/mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::loadTicketsTest()                        // On edit ticket button
{
    for(int i = 0; i < database.ticketsNumbersVector.size(); i++) {
        int ticketNum = database.ticketsNumbersVector[i];
        QHBoxLayout* hBox = new QHBoxLayout;

        QPushButton *addBtn = new QPushButton("Билет " + QString::number(i+1));
        addBtn->setMinimumHeight(50);
        QObject::connect(addBtn, &QPushButton::clicked,this,[=] {
            loadTest(ticketNum, 0);
            time = 200;
            timer->start(1000);
        });

        hBox->addWidget(addBtn);
        ui->tickets_buttons_scroll_area->addLayout(hBox);
    }
}

void MainWindow::loadTest(int ticketNum, int questionNum)
{   
    database.loadTicketFromBase(ticketNum);
    currentTestTicket = ticketNum;
    ui->progressBar->setValue((double)questionNum/database.tick.questions.size()*100);

    ui->test_quest_label->setText(database.tick.questions[questionNum].quest);
    ui->test_comment_label->setText(database.tick.questions[questionNum].comment);
    ui->test_answers_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->test_answers_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->test_answers_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    int answers = database.tick.questions[questionNum].answers.size();
    for(int i = 0; i < answers; i++) {
        ui->test_answers_table->insertRow(ui->test_answers_table->rowCount());
        QString text = database.tick.questions[questionNum].answers[i];
        ui->test_answers_table->setItem(i, 0, new QTableWidgetItem(text));
    }
    ui->test_answers_table->resizeRowsToContents();
    changePage(test_page);
    imgPix = database.tick.questions[questionNum].image;
    if(!imgPix.isNull()) {
        ui->test_image_label->setMinimumHeight(this->height()/5);
        ui->test_image_label->setPixmap(imgPix.scaled( ui->test_image_label->size(), Qt::KeepAspectRatio));
        ui->test_image_label->show();
    } else {
        ui->test_image_label->clear();
        ui->test_image_label->hide();
    }
}

void MainWindow::loadResults()
{

}
