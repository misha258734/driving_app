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

void MainWindow::addTicketsButtons()                        // On edit ticket button
{
    for(int i = 1; i <= textDataBase.ticketCount; i++) {
        QPushButton *btn = new QPushButton("Билет " + QString::number(i));
        btn->setMinimumHeight(50);
        QObject::connect(btn, &QPushButton::clicked,this,[=] {loadTicket(i);});
        tickets_btns.push_back(btn);
        ui->tickets_buttons_scroll_area->layout()->addWidget(btn);
    }
}
void MainWindow::loadTicket(int ticketNum)                  // On ticket button
{
    textDataBase.loadTicketFromFile(ticketNum);

    qDebug() << ticketNum << "ticket loaded\n";

    for(int i = 0; i < textDataBase.tick.questions.count(); i++) {
        QPushButton *btn = new QPushButton("Вопрос " + QString::number(i+1));
        btn->setMinimumHeight(50);
        QObject::connect(btn, &QPushButton::clicked, this, [=]{loadQuestion(i);});
        questions_btns.push_back(btn);
        ui->quests_buttons_scroll_area->layout()->addWidget(btn);
    }
    ui->app_stacked_widget->setCurrentIndex(edit_quests_page);
}
void MainWindow::loadQuestion(int questNum)                 // On edit question button
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
    int answers = textDataBase.tick.questions[questNum].answer.size();
    for(int i = 0; i < answers; i++) {
        ui->answers_table->insertRow(ui->answers_table->rowCount());
        QString text = textDataBase.tick.questions[questNum].answer[i];
        ui->answers_table->setItem(i, 0, new QTableWidgetItem(text));
    }
    ui->app_stacked_widget->setCurrentIndex(edit_quest_page);

    imgPix.load(textDataBase.tick.questions[questNum].imagePath);
    if(!imgPix.isNull()) {
        ui->image_label->setMinimumHeight(this->height()/5);
        ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void MainWindow::removeTicketsButtons()                     // On edit ticketS back button
{
    for(auto &i : tickets_btns) {
        QObject::disconnect(i);
        ui->scroll_area_2->layout()->removeWidget(i);
        delete i;
    }
    tickets_btns.clear();
}

void MainWindow::removeQuestionsButtons()                   // On edit questionsS back button
{
    for(auto &i : questions_btns) {
        QObject::disconnect(i);
        ui->scroll_area->layout()->removeWidget(i);
        delete i;
    }
    questions_btns.clear();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->image_label->setMinimumHeight(this->height()/5);
    if(!imgPix.isNull())
        ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


