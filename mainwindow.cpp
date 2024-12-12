#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addTicketsButtons();

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

void MainWindow::testAdd()
{
    textDataBase.tick.errorCounter = 0;
    textDataBase.tick.lastPass = QDate::fromString("12.12.24", "dd.MM.yy");
    textDataBase.tick.number = 2;

    for(int i = 0; i <  5; i++) {
        question *quest = new question;

        quest->quest = QString::number(i+1) + ") quest";
        quest->comment = "comment";
        quest->imagePath = "imagePath";
        quest->rightAnswer = 1;
        for(int j = 0; j < 5; j++) {
            quest->answer.push_back("Answer-" + QString::number(j));
        }
        textDataBase.tick.questions.push_back(*quest);
    }
    if(textDataBase.addTicketToFile())
        qDebug() << "fileOpen1\n";
}

void MainWindow::testLoad()
{
    if(textDataBase.loadTicketFromFile(1))
         qDebug() << "fileOpen2\n";

    if(textDataBase.addTicketToFile())
        qDebug() << "fileOpen1\n";
}

void MainWindow::addTicketsButtons()
{
    for(int i = 0; i < 40; i++)
        ui->tickets_buttons_scroll_area->layout()->addWidget(new QPushButton("button-" + QString::number(i)));
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
    ui->app_stacked_widget->setCurrentIndex(tickets_page);
}
void MainWindow::on_cd_tickets_back_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(tickets_page);
}
void MainWindow::on_goto_ab_tickets_edit_button_released()
{
    ui->app_stacked_widget->setCurrentIndex(edit_ab_tickets_page);
}

