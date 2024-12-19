#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_goto_tickets_button_clicked() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}             // menu -> tickets
void MainWindow::on_goto_timetable_button_clicked() {ui->app_stacked_widget->setCurrentIndex(timetable_page);}         // menu -> timetable
void MainWindow::on_goto_registration_button_clicked() {ui->app_stacked_widget->setCurrentIndex(registration_page);}   // menu -> registration
void MainWindow::on_goto_ab_tickets_button_clicked() {ui->app_stacked_widget->setCurrentIndex(ab_tickets_page);}       // tickets -> AB tickets
void MainWindow::on_goto_cd_tickets_button_clicked() {ui->app_stacked_widget->setCurrentIndex(cd_tickets_page);}       // tickets -> CD tickets
void MainWindow::on_registration_back_button_clicked() {ui->app_stacked_widget->setCurrentIndex(menu_page);}           // registration -> BACK menu
void MainWindow::on_timetable_back__button_clicked() {ui->app_stacked_widget->setCurrentIndex(menu_page);}             // timetable -> BACK menu
void MainWindow::on_tickets_back_button_clicked() {ui->app_stacked_widget->setCurrentIndex(menu_page);}                // tickets -> BACK menu
void MainWindow::on_ab_tickets_back_button_clicked() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}          // AB tickets -> BACK tickets
void MainWindow::on_cd_tickets_back_button_clicked() {ui->app_stacked_widget->setCurrentIndex(tickets_page);}          // CD tickets -> BACK tickets
void MainWindow::on_goto_ab_tickets_edit_button_clicked() {     // AB tickets -> edit tickets
    addTicketsButtons();
    ui->app_stacked_widget->setCurrentIndex(edit_tickets_page);
}
void MainWindow::on_edit_quests_back_button_clicked() {         // edit quests -> BACK edit tickets
    ui->app_stacked_widget->setCurrentIndex(edit_tickets_page);
    removeQuestionsButtons();
}
void MainWindow::on_edit_tickets_back_button_clicked() {        // edit tickets -> BACK AB tickets
    ui->app_stacked_widget->setCurrentIndex(ab_tickets_page);
    removeTicketsButtons();
}
void MainWindow::on_edit_quest_back_button_clicked() {          // edit quest -> BACK edit quests
    ui->app_stacked_widget->setCurrentIndex(edit_quests_page);

    ui->question_text_textEdit->setText("Текст вопроса...");
    ui->comment_text_textEdit->setText("Текст комментария...");

    ui->answers_table->setRowCount(0);

    ui->image_label->setMinimumHeight(0);
    ui->image_label->setText("Нет изображения");
}

void MainWindow::on_add_ticket_button_clicked()
{
    textDataBase.tick.number = textDataBase.ticketCount+1;
    textDataBase.tick.questions.clear();
    textDataBase.tick.errorCounter = 0;
    textDataBase.tick.lastPass = QDate();

    textDataBase.addTicketToFile();

    QPushButton *btn = new QPushButton("Билет " + QString::number(textDataBase.tick.number));
    btn->setMinimumHeight(50);
    QObject::connect(btn, &QPushButton::clicked,this,[=] {loadTicket(textDataBase.tick.number);});
    tickets_btns.push_back(btn);
    ui->tickets_buttons_scroll_area->layout()->addWidget(btn);
}

void MainWindow::on_add_question_button_clicked()
{
    question *newQuest = new question;
    newQuest->quest = "";
    newQuest->comment = "";
    newQuest->imagePath = "";
    newQuest->rightAnswer = -1;

    textDataBase.tick.questions.push_back(*newQuest);

    textDataBase.addTicketToFile();

    int questNum = textDataBase.tick.questions.count();

    QPushButton *btn = new QPushButton("Вопрос " + QString::number(questNum));
    btn->setMinimumHeight(50);
    QObject::connect(btn, &QPushButton::clicked, this, [=]{loadQuestion(questNum-1);});
    questions_btns.push_back(btn);
    ui->quests_buttons_scroll_area->layout()->addWidget(btn);

}

void MainWindow::on_quest_image_button_clicked()                 // add/change quest image
{
    currentImagePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    (QDir::homePath() + "/Pictures"),
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    if(currentImagePath == "") return;


    imgPix.load(currentImagePath);
    ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

void MainWindow::on_edit_quest_save_button_clicked()             // saves chages to file
{
    textDataBase.tick.questions[current_quest].quest = ui->question_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].comment = ui->comment_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].imagePath = currentImagePath;
    int rows = ui->answers_table->rowCount();
    textDataBase.tick.questions[current_quest].answer.clear();
    for(int i = 0; i < rows; i++) {
        QString answerText = ui->answers_table->item(i,0)->text();
        textDataBase.tick.questions[current_quest].answer.push_back(answerText);
    }

    textDataBase.addTicketToFile();
}

void MainWindow::on_add_answer_button_clicked()
{
    ui->answers_table->insertRow(ui->answers_table->rowCount());
}


