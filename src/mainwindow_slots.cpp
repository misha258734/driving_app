#include "include/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->image_label->setMinimumHeight(this->height()/5);
    if(!imgPix.isNull())
        ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_goto_tickets_button_clicked() {changePage(tickets_chose_page);}             // menu -> tickets
void MainWindow::on_goto_timetable_button_clicked() {changePage(timetable_page);}         // menu -> timetable
void MainWindow::on_goto_registration_button_clicked() {changePage(registration_page);}   // menu -> registration
void MainWindow::on_goto_ab_tickets_button_clicked() {changePage(ab_tickets_page);}       // tickets -> AB tickets
void MainWindow::on_goto_cd_tickets_button_clicked() {changePage(cd_tickets_page);}       // tickets -> CD tickets
void MainWindow::on_registration_back_button_clicked() {changePage(menu_page);}           // registration -> BACK menu
void MainWindow::on_timetable_back_button_clicked() {changePage(menu_page);}             // timetable -> BACK menu
void MainWindow::on_ticket_chose_back_button_clicked() {changePage(menu_page);}                // tickets -> BACK menu
void MainWindow::on_ab_tickets_back_button_clicked() {changePage(tickets_chose_page);}          // AB tickets -> BACK tickets
void MainWindow::on_cd_tickets_back_button_clicked() {changePage(tickets_chose_page);}          // CD tickets -> BACK tickets




