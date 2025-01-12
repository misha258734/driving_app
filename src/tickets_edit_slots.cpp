#include "include/mainwindow.h"
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
    if(database.ticketsNumbersVector.empty())
        database.tick.number = 1;
    else
        database.tick.number = database.ticketsNumbersVector.last()+1;
    database.tick.questions.clear();
    database.tick.errorCounter = 0;
    database.tick.lastPass = QDate();

    database.loadTicketToBase();

    clearLayout(ui->tickets_buttons_scroll_area);

    loadTicketsEdit();
}

void MainWindow::on_add_question_button_clicked()
{
    database.tick.questions.push_back(question());

    database.loadTicketToBase();

    clearLayout(ui->quests_buttons_scroll_area);

    loadQuestionsEdit(database.tick.number);
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
    database.tick.questions[current_quest].quest = ui->question_text_textEdit->toPlainText();
    database.tick.questions[current_quest].comment = ui->comment_text_textEdit->toPlainText();
    database.tick.questions[current_quest].image = imgPix;
    int rows = ui->answers_table->rowCount();
    database.tick.questions[current_quest].rightAnswer = ui->answers_table->selectionModel()->currentIndex().row()+1;
    database.tick.questions[current_quest].answers.clear();
    for(int i = 0; i < rows; i++) {
        bool itemNotEmpty = ui->answers_table->item(i, 0);
        if(itemNotEmpty)
        {
            QString answerText = ui->answers_table->item(i,0)->text();
            database.tick.questions[current_quest].answers.push_back(answerText);
        }
    }

    if(ui->image_label->isHidden())
        database.tick.questions[current_quest].image = QPixmap();

    on_edit_quest_back_button_clicked();

    database.loadTicketToBase();
}

void MainWindow::on_add_answer_button_clicked()                  // on selection cell in answers table
{
    ui->answers_table->insertRow(ui->answers_table->rowCount());
    resizeScrollArea(ui->answers_table);
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


void MainWindow::on_question_text_textEdit_textChanged()
{
    resizeScrollArea(ui->question_text_textEdit);
}
void MainWindow::on_answers_table_cellChanged(int, int)
{
    resizeScrollArea(ui->answers_table);
}
void MainWindow::on_comment_text_textEdit_textChanged()
{
    resizeScrollArea(ui->comment_text_textEdit);
}

