#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_goto_tickets_button_clicked() {changePage(tickets_page);}             // menu -> tickets
void MainWindow::on_goto_timetable_button_clicked() {changePage(timetable_page);}         // menu -> timetable
void MainWindow::on_goto_registration_button_clicked() {changePage(registration_page);}   // menu -> registration
void MainWindow::on_goto_ab_tickets_button_clicked() {changePage(ab_tickets_page);}       // tickets -> AB tickets
void MainWindow::on_goto_cd_tickets_button_clicked() {changePage(cd_tickets_page);}       // tickets -> CD tickets
void MainWindow::on_registration_back_button_clicked() {changePage(menu_page);}           // registration -> BACK menu
void MainWindow::on_timetable_back__button_clicked() {changePage(menu_page);}             // timetable -> BACK menu
void MainWindow::on_tickets_back_button_clicked() {changePage(menu_page);}                // tickets -> BACK menu
void MainWindow::on_ab_tickets_back_button_clicked() {changePage(tickets_page);}          // AB tickets -> BACK tickets
void MainWindow::on_cd_tickets_back_button_clicked() {changePage(tickets_page);}          // CD tickets -> BACK tickets
void MainWindow::on_goto_ab_tickets_edit_button_clicked() {     // AB tickets -> edit tickets
    addTicketsButtons();
    changePage(edit_tickets_page);
}
void MainWindow::on_edit_quests_back_button_clicked() {         // edit quests -> BACK edit tickets
    changePage(edit_tickets_page);
    clearLayout(ui->quests_buttons_scroll_area->layout());
}
void MainWindow::on_edit_tickets_back_button_clicked() {        // edit tickets -> BACK AB tickets
    changePage(ab_tickets_page);
    clearLayout(ui->tickets_buttons_scroll_area->layout());
}
void MainWindow::on_edit_quest_back_button_clicked() {          // edit quest -> BACK edit quests
    changePage(edit_quests_page);

    ui->question_text_textEdit->setText("Текст вопроса...");
    ui->comment_text_textEdit->setText("Текст комментария...");

    ui->answers_table->setRowCount(0);

    ui->image_label->setMinimumHeight(0);
    ui->image_label->setText("Нет изображения");

    ui->answers_table->clear();
}

void MainWindow::on_add_ticket_button_clicked()
{
    textDataBase.tick.number = textDataBase.ticketCount+1;
    textDataBase.tick.questions.clear();
    textDataBase.tick.errorCounter = 0;
    textDataBase.tick.lastPass = QDate();

    textDataBase.addTicketToFile();

    clearLayout(ui->tickets_buttons_scroll_area);

    addTicketsButtons();


    // QHBoxLayout* hBox = new QHBoxLayout;

    // QPushButton *addBtn = new QPushButton("Билет " + QString::number(textDataBase.tick.number));
    // addBtn->setMinimumHeight(50);
    // QObject::connect(addBtn, &QPushButton::clicked,this,[=] {loadTicket(textDataBase.tick.number);});

    // QPushButton *removeBtn = new QPushButton("-");
    // removeBtn->setMinimumHeight(50);
    // removeBtn->setMaximumWidth(50);
    // QObject::connect(removeBtn, &QPushButton::clicked,this,[=] {removeTicket(textDataBase.tick.number);});

    // hBox->addWidget(addBtn);
    // hBox->addWidget(removeBtn);

    // ui->tickets_buttons_scroll_area->addLayout(hBox);
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

    QHBoxLayout* hBox = new QHBoxLayout;

    int questNum = textDataBase.tick.questions.count();
    QPushButton *addBtn = new QPushButton("Вопрос " + QString::number(questNum));
    addBtn->setMinimumHeight(50);
    QObject::connect(addBtn, &QPushButton::clicked, this, [=]{loadQuestion(questNum-1);});

    QPushButton *removeBtn = new QPushButton("-");
    removeBtn->setMinimumHeight(50);
    removeBtn->setMaximumWidth(50);
    QObject::connect(removeBtn, &QPushButton::clicked, this, [=]{removeQuest(questNum-1);});

    hBox->addWidget(addBtn);
    hBox->addWidget(removeBtn);
    ui->quests_buttons_scroll_area->addLayout(hBox);

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

    ui->remove_icon_button->setEnabled(true);
}

void MainWindow::on_edit_quest_save_button_clicked()             // save chages to file
{
    textDataBase.tick.questions[current_quest].quest = ui->question_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].comment = ui->comment_text_textEdit->toPlainText();
    textDataBase.tick.questions[current_quest].imagePath = currentImagePath;
    int rows = ui->answers_table->rowCount();
    textDataBase.tick.questions[current_quest].answer.clear();
    textDataBase.tick.questions[current_quest].rightAnswer = ui->answers_table->selectionModel()->currentIndex().row()+1;
    for(int i = 0; i < rows; i++) {
        bool itemNotEmpty = ui->answers_table->item(i, 0);
        if(itemNotEmpty)
        {
            QString answerText = ui->answers_table->item(i,0)->text();
            textDataBase.tick.questions[current_quest].answer.push_back(answerText);
        }
    }

    on_edit_quest_back_button_clicked();

    textDataBase.addTicketToFile();
}

void MainWindow::on_add_answer_button_clicked()                  // on selection cell in answers table
{
    ui->answers_table->insertRow(ui->answers_table->rowCount());
}

void MainWindow::on_remove_answer_button_clicked()
{
    int selectedCell = ui->answers_table->selectionModel()->currentIndex().row();
    ui->answers_table->removeRow(selectedCell);
}

void MainWindow::on_answers_table_itemSelectionChanged()
{
    bool itemSelected = ui->answers_table->selectionModel()->selectedIndexes().count() == 1;
    int selectedCell = ui->answers_table->selectionModel()->currentIndex().row();
    bool itemNotEmpty = ui->answers_table->item(selectedCell, 0);
    if(itemNotEmpty)
        itemNotEmpty = ui->answers_table->item(selectedCell, 0)->text() != "";
    ui->edit_quest_save_button->setEnabled(itemSelected & itemNotEmpty);
    ui->remove_answer_button->setEnabled(itemSelected);
}

void MainWindow::on_answers_table_cellChanged()
{
    ui->answers_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    on_answers_table_itemSelectionChanged();
}



