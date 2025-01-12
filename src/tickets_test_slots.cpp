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
