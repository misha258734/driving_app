#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "spoiler.h"
#include "appdatabase.h"

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int current_quest;
    //textDB textDataBase;
    appdatabase database;
    QPixmap imgPix;
    QString currentImagePath;
    QVBoxLayout *commentLayout;
    Spoiler *comment;

    enum app_pages {
        menu_page = 0,
        tickets_chose_page = 1,
        ab_tickets_page = 2,
        tickets_page = 3,
        quests_page = 4,
        edit_quest_page = 5,
        cd_tickets_page = 6,
        timetable_page = 7,
        registration_page = 8,
        test_page = 9,
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_goto_tickets_button_clicked();
    void on_goto_timetable_button_clicked();
    void on_goto_registration_button_clicked();
    void on_goto_ab_tickets_button_clicked();
    void on_goto_cd_tickets_button_clicked();
    void on_registration_back_button_clicked();
    void on_timetable_back_button_clicked();
    void on_ticket_chose_back_button_clicked();
    void on_ab_tickets_back_button_clicked();
    void on_cd_tickets_back_button_clicked();
    void on_goto_ab_tickets_edit_button_clicked();
    void on_quests_back_button_clicked();
    void on_tickets_back_button_clicked();
    void on_edit_quest_back_button_clicked();
    void on_quest_image_button_clicked();
    void on_edit_quest_save_button_clicked();
    void on_add_answer_button_clicked();
    void on_add_question_button_clicked();
    void on_add_ticket_button_clicked();
    void on_answers_table_itemSelectionChanged();
    void on_answers_table_cellChanged();
    void on_remove_answer_button_clicked();
    void on_remove_image_button_clicked();
    void on_goto_ab_test_button_clicked();


private:
    void prepareWidgets();

    void changePage(int pageNum);
    void clearLayout(QLayout* layout, bool deleteWidgets = true);

    void loadTicketsEdit();
    void loadQuestionsEdit(int ticketNum);
    void editQuestion(int questNum);

    void removeTicket(int ticketNum);
    void removeQuest(int questNum);


    void loadTicketsTest();
    void loadTest(int ticketNum);

    void resizeEvent(QResizeEvent*);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
