#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum app_pages {
        menu_page = 0,
        tickets_page = 1,
        ab_tickets_page = 2,
        cd_tickets_page = 3,
        timetable_page = 4,
        registration_page = 5
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int but_num = 1;

private slots:

    void on_goto_tickets_button_released();

    void on_goto_timetable_button_released();

    void on_goto_registration_button_released();

    void on_goto_ab_tickets_button_clicked();

    void on_goto_cd_tickets_button_released();

    void on_registration_back_button_released();

    void on_timetable_back__button_released();

    void on_tickets_back_button_released();

    void on_ab_tickets_back_button_released();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
