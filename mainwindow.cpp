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

void MainWindow::addTicketsButtons()                        // On edit ticket button
{
    for(int i = 0; i < textDataBase.ticketCount; i++) {
        QPushButton *btn = new QPushButton("Билет " + QString::number(i+1));
        QObject::connect(btn, &QPushButton::clicked,this,[=] {loadTicket(i+1);});
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
        QObject::connect(btn, &QPushButton::clicked, this, [=]{loadQuestion(i);});
        questions_btns.push_back(btn);
        ui->quests_buttons_scroll_area->layout()->addWidget(btn);
    }
    ui->app_stacked_widget->setCurrentIndex(edit_quests_page);
}
void MainWindow::loadQuestion(int questNum)                 // On edit question button
{
    current_quest = questNum;

    ui->image_label->setMinimumHeight(this->height()/5);
    ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->question_text_textEdit->setText(textDataBase.tick.questions[questNum].quest);
    ui->comment_text_textEdit->setText(textDataBase.tick.questions[questNum].comment);

    ui->app_stacked_widget->setCurrentIndex(edit_quest_page);
}

void MainWindow::removeTicketsButtons()                     // On edit ticketS back button
{
    for(auto &i : tickets_btns) {
        QObject::disconnect(i);
        ui->tickets_buttons_scroll_area->layout()->removeWidget(i);
        delete i;
    }
    tickets_btns.clear();
}

void MainWindow::removeQuestionsButtons()                   // On edit questionsS back button
{
    for(auto &i : questions_btns) {
        QObject::disconnect(i);
        ui->quests_buttons_scroll_area->layout()->removeWidget(i);
        delete i;
    }
    questions_btns.clear();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->image_label->setMinimumHeight(this->height()/5);
    ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_goto_tickets_button_released() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}             // menu -> tickets
void MainWindow::on_goto_timetable_button_released() {ui->app_stacked_widget->setCurrentIndex(timetable_page);}         // menu -> timetable
void MainWindow::on_goto_registration_button_released() {ui->app_stacked_widget->setCurrentIndex(registration_page);}   // menu -> registration
void MainWindow::on_goto_ab_tickets_button_released() {ui->app_stacked_widget->setCurrentIndex(ab_tickets_page);}       // tickets -> AB tickets
void MainWindow::on_goto_cd_tickets_button_released() {ui->app_stacked_widget->setCurrentIndex(cd_tickets_page);}       // tickets -> CD tickets
void MainWindow::on_registration_back_button_released() {ui->app_stacked_widget->setCurrentIndex(menu_page);}           // registration -> BACK menu
void MainWindow::on_timetable_back__button_released() {ui->app_stacked_widget->setCurrentIndex(menu_page);}             // timetable -> BACK menu
void MainWindow::on_tickets_back_button_released() {ui->app_stacked_widget->setCurrentIndex(menu_page);}                // tickets -> BACK menu
void MainWindow::on_ab_tickets_back_button_released() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}          // AB tickets -> BACK tickets
void MainWindow::on_cd_tickets_back_button_released() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}          // CD tickets -> BACK tickets
void MainWindow::on_goto_ab_tickets_edit_button_released() {     // AB tickets -> edit tickets
    addTicketsButtons();
    ui->app_stacked_widget->setCurrentIndex(edit_tickets_page);
}
void MainWindow::on_edit_quests_back_button_released() {         // edit quests -> BACK edit tickets
    ui->app_stacked_widget->setCurrentIndex(edit_tickets_page);
    removeQuestionsButtons();
}
void MainWindow::on_edit_tickets_back_button_released() {        // edit tickets -> BACK AB tickets
    ui->app_stacked_widget->setCurrentIndex(ab_tickets_page);
    removeTicketsButtons();
}
void MainWindow::on_edit_quest_back_button_released() {ui->app_stacked_widget->setCurrentIndex(edit_quests_page);}


void MainWindow::on_quest_image_button_clicked()
{
    currentImagePath = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"),
                                            (QDir::homePath() + "/Pictures"),
                                            tr("Image Files (*.png *.jpg *.bmp)"));
    if(currentImagePath == "") return;


    imgPix.load(currentImagePath);
    ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

}


void MainWindow::on_edit_quest_save_button_clicked()
{
    textDataBase.tick.questions[current_quest].quest = ui->question_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].comment = ui->comment_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].imagePath = currentImagePath;

    textDataBase.addTicketToFile();
}

