#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTestQuestion = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_slot()));

    prepareWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prepareWidgets()
{
    ui->goto_themes_button->setDisabled(true);
    ui->goto_traffic_rules_button->setDisabled(true);
    ui->goto_cd_test_button->setDisabled(true);
    ui->goto_ab_errors_button->setDisabled(true);
    ui->goto_cd_errors_button->setDisabled(true);
    ui->registration_confirm_button->setDisabled(true);

    changePage(menu_page);
}

void MainWindow::resizeScrollArea(QAbstractScrollArea *area)
{
    area->setFixedHeight(50);
    while(area->verticalScrollBar()->isVisible()) {
        area->setFixedHeight(area->height() + 10);
    }
}

void MainWindow::clearLayout(QLayout* layout, bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}
void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->test_answers_table->setMinimumWidth(ui->test_quest_label->width());
    ui->image_label->setMinimumHeight(this->height()/5);
    if(!imgPix.isNull())
        ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::changePage(int pageNum)
{
    ui->app_stacked_widget->setCurrentIndex(pageNum);
}





