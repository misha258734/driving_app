#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    commentLayout = new QVBoxLayout();
    QLabel *lbl = new QLabel;
    lbl->setText("afasdfas312312AF Af");
    lbl->sizePolicy().setVerticalPolicy(QSizePolicy::Expanding);
    comment = new Spoiler("Комментарий");
    comment->setContentLayout(*commentLayout);
    comment->layout()->addWidget(lbl);
    ui->test_scroll_area->layout()->addWidget(comment);

    comment->sizePolicy().setVerticalPolicy(QSizePolicy::Expanding);
    changePage(menu_page);
}

void MainWindow::changePage(int pageNum)
{
    ui->app_stacked_widget->setCurrentIndex(pageNum);
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


