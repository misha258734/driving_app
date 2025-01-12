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
    ui->test_answer_button->show();
    ui->goto_next_quest_button->hide();
    ui->test_comment_frame->hide();

    currentTestQuestion++;
    if(currentTestQuestion == database.tick.questions.size()) {
        currentTestQuestion = 0;
        loadResults();
        return;
    }
    loadTest(currentTestTicket, currentTestQuestion);
}

void MainWindow::on_test_answer_button_clicked()
{
    ui->test_answer_button->hide();
    ui->goto_next_quest_button->show();
    ui->test_comment_frame->show();
    int answer = database.tick.questions[currentTestQuestion].rightAnswer;
    int chose = ui->test_answers_table->selectionModel()->currentIndex().row()+1;
    bool rightAnswer = answer == chose;
    if(rightAnswer) {
        ui->test_answers_table->item(chose-1, 0)->setBackground(QColor(0, 255, 0, 127));
    } else {
        ui->test_answers_table->item(chose-1, 0)->setBackground(QColor(255, 0, 0, 127));
    }
    ui->test_answers_table->clearSelection();
    ui->test_answers_table->resizeRowsToContents();

}

void MainWindow::timer_slot()
{

    if(seconds == 0) {
        seconds = 59;
        minutes--;
    } else {
        seconds--;
    }
    if(minutes == 0) {
        stopTest();
    }
    ui->timer_label->setText(QString::number(minutes) + QString(":%1").arg( seconds, 2, 10, QChar('0')));
}
