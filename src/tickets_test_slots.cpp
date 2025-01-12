#include "include/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_goto_ab_test_button_clicked()
{
    ui->add_ticket_button->hide();

    loadTicketsTest();

    changePage(tickets_page);
}


void MainWindow::on_test_back_button_clicked()
{
    changePage(tickets_page);
}

void MainWindow::on_goto_next_quest_button_clicked()
{
    currentTestQuestion++;
    if(currentTestQuestion == database.tick.questions.size()) {
        currentTestQuestion = 0;
        loadResults();
        return;
    }
    loadTest(currentTestTicket, currentTestQuestion);
}

void MainWindow::timer_slot()
{
    time--;
    ui->timer_label->setText(QString::number(time));
}
