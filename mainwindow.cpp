#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    changePage(menu_page);

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

void MainWindow::addTicketsEditButtons()                        // On edit ticket button
{
    for(int i = 1; i <= textDataBase.ticketCount; i++) {
        QHBoxLayout* hBox = new QHBoxLayout;

        QPushButton *addBtn = new QPushButton("Билет " + QString::number(i));
        addBtn->setMinimumHeight(50);
        QObject::connect(addBtn, &QPushButton::clicked,this,[=] {loadTicketEdit(i);});

        QPushButton *removeBtn = new QPushButton("-");
        removeBtn->setMinimumHeight(50);
        removeBtn->setMaximumWidth(50);
        QObject::connect(removeBtn, &QPushButton::clicked,this,[=] {removeTicket(i);});

        hBox->addWidget(addBtn);
        hBox->addWidget(removeBtn);
        ui->tickets_buttons_scroll_area->addLayout(hBox);
    }

}
void MainWindow::loadTicketEdit(int ticketNum)                  // On ticket button
{
    textDataBase.loadTicketFromFile(ticketNum);

    for(int i = 0; i < textDataBase.tick.questions.count(); i++) {
        QHBoxLayout* hBox = new QHBoxLayout;

        QPushButton *addBtn = new QPushButton("Вопрос " + QString::number(i+1));
        addBtn->setMinimumHeight(50);
        QObject::connect(addBtn, &QPushButton::clicked, this, [=]{loadQuestionEdit(i);});

        QPushButton *removeBtn = new QPushButton("-");
        removeBtn->setMinimumHeight(50);
        removeBtn->setMaximumWidth(50);
        QObject::connect(removeBtn, &QPushButton::clicked, this, [=]{removeQuest(i);});

        hBox->addWidget(addBtn);
        hBox->addWidget(removeBtn);
        ui->quests_buttons_scroll_area->addLayout(hBox);
    }

    changePage(edit_quests_page);
}
void MainWindow::loadQuestionEdit(int questNum)                 // On edit question button
{
    current_quest = questNum;

    QString quest = textDataBase.tick.questions[questNum].quest;
    QString comm = textDataBase.tick.questions[questNum].comment;
    if(quest != "")
        ui->question_text_textEdit->setText(quest);
    if(comm != "")
        ui->comment_text_textEdit->setText(comm);

    ui->answers_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->answers_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    ui->answers_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    int answers = textDataBase.tick.questions[questNum].answer.size();
    for(int i = 0; i < answers; i++) {
        ui->answers_table->insertRow(ui->answers_table->rowCount());
        QString text = textDataBase.tick.questions[questNum].answer[i];
        ui->answers_table->setItem(i, 0, new QTableWidgetItem(text));
    }
    changePage(edit_quest_page);

    ui->answers_table->resizeRowsToContents();

    imgPix.load(QString("src/images/%1").arg(textDataBase.tick.questions[questNum].imagePath));
    if(!imgPix.isNull()) {
        ui->image_label->setMinimumHeight(this->height()/5);
        ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->image_label->show();
        ui->remove_image_button->setEnabled(true);
    } else {
        ui->image_label->clear();
        ui->image_label->hide();
        ui->remove_image_button->setEnabled(false);
    }

}

void MainWindow::removeTicket(int ticketNum)
{
    if(textDataBase.removeTicketFile(ticketNum)) return;

    clearLayout(ui->tickets_buttons_scroll_area->layout());

    addTicketsEditButtons();

}

void MainWindow::removeQuest(int questNum)
{
    textDataBase.removeQuestionFile(questNum);
    clearLayout(ui->quests_buttons_scroll_area->layout());
    loadTicketEdit(textDataBase.tick.number);
}

