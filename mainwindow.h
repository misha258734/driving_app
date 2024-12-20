#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include "textdb.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int current_quest;
    textDB textDataBase;
    QVector<QPushButton*> tickets_btns;
    QVector<QPushButton*> questions_btns;
    QPixmap imgPix;
    QString currentImagePath;



    enum app_pages {
        menu_page = 0,
        tickets_page = 1,
        ab_tickets_page = 2,
        edit_tickets_page = 3,
        edit_quests_page = 4,
        edit_quest_page = 5,
        cd_tickets_page = 6,
        timetable_page = 7,
        registration_page = 8,

    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void testAdd();
    void testLoad();
    void addTicketsButtons();
    void loadTicket(int ticketNum);
    void loadQuestion(int questNum);
    void removeTicketsButtons();
    void removeQuestionsButtons();

private slots:

    void on_goto_tickets_button_clicked();
    void on_goto_timetable_button_clicked();
    void on_goto_registration_button_clicked();
    void on_goto_ab_tickets_button_clicked();
    void on_goto_cd_tickets_button_clicked();
    void on_registration_back_button_clicked();
    void on_timetable_back__button_clicked();
    void on_tickets_back_button_clicked();
    void on_ab_tickets_back_button_clicked();
    void on_cd_tickets_back_button_clicked();
    void on_goto_ab_tickets_edit_button_clicked();
    void on_edit_quests_back_button_clicked();
    void on_edit_tickets_back_button_clicked();
    void on_edit_quest_back_button_clicked();
    void on_quest_image_button_clicked();
    void on_edit_quest_save_button_clicked();
    void on_add_answer_button_clicked();


    void on_add_question_button_clicked();

    void on_add_ticket_button_clicked();

    void on_answers_table_itemSelectionChanged();

    void on_answers_table_cellChanged(int row, int column);

private:
    void resizeEvent(QResizeEvent*);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
