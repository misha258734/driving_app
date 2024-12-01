#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->app_stacked_widget->setCurrentIndex(menu_page);

    ui->goto_themes_button->setDisabled(true);
    ui->goto_traffic_rules_button->setDisabled(true);
    ui->goto_ab_test_button->setDisabled(true);
    ui->goto_cd_test_button->setDisabled(true);
    ui->goto_ab_marathon_button->setDisabled(true);
    ui->goto_cd_marathon_button->setDisabled(true);
    ui->goto_ab_errors_button->setDisabled(true);
    ui->goto_cd_errors_button->setDisabled(true);
    ui->registration_confirm_button->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_goto_tickets_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(tickets_page);
}


void MainWindow::on_goto_timetable_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(timetable_page);
}


void MainWindow::on_goto_registration_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(registration_page);
}


void MainWindow::on_goto_ab_tickets_button_clicked()
{
    ui->app_stacked_widget->setCurrentIndex(ab_tickets_page);
}



void MainWindow::on_goto_cd_tickets_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(cd_tickets_page);
}


void MainWindow::on_registration_back_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(menu_page);
}


void MainWindow::on_timetable_back__button_released()
{
    ui->app_stacked_widget->setCurrentIndex(menu_page);
}


void MainWindow::on_tickets_back_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(menu_page);
}


void MainWindow::on_ab_tickets_back_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(menu_page);
}


void MainWindow::on_pushButton_released()
{
    ui->app_stacked_widget->setCurrentIndex(menu_page);
}

