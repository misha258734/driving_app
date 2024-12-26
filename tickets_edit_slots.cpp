#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_goto_ab_tickets_edit_button_clicked() {     // AB tickets -> edit tickets
    ui->add_ticket_button->show();
    loadTicketsEdit();
    changePage(tickets_page);
}
void MainWindow::on_quests_back_button_clicked() {         // edit quests -> BACK edit tickets
    ui->add_question_button->show();
    changePage(tickets_page);
    clearLayout(ui->quests_buttons_scroll_area->layout());
}
void MainWindow::on_tickets_back_button_clicked() {        // edit tickets -> BACK AB tickets
    changePage(ab_tickets_page);
    clearLayout(ui->tickets_buttons_scroll_area->layout());
}
void MainWindow::on_edit_quest_back_button_clicked() {          // edit quest -> BACK edit quests
    changePage(quests_page);

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

    loadTicketsEdit();
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

    clearLayout(ui->quests_buttons_scroll_area);

    loadQuestionsEdit(textDataBase.tick.number);
}

void MainWindow::on_quest_image_button_clicked()                 // add/change quest image
{
    currentImagePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    (QDir::homePath() + "/Pictures"),
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    if(currentImagePath == "") return;


    ui->image_label->show();
    ui->remove_image_button->setEnabled(true);

    imgPix.load(currentImagePath);
    ui->image_label->setPixmap(imgPix.scaled( ui->image_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->remove_image_button->setEnabled(true);
}

void MainWindow::on_edit_quest_save_button_clicked()             // SAVE chages to file
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

    if(ui->image_label->isHidden())
        textDataBase.removeImage(current_quest);

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

void MainWindow::on_remove_image_button_clicked()
{
    ui->image_label->clear();
    ui->image_label->hide();
    ui->remove_image_button->setEnabled(false);
}
