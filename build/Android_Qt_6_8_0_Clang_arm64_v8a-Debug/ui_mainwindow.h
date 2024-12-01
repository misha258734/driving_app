/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *app_stacked_widget;
    QWidget *menu_page;
    QGridLayout *gridLayout_2;
    QGridLayout *menu_layout;
    QPushButton *goto_tickets_button;
    QPushButton *goto_timetable_button;
    QPushButton *goto_registration_button;
    QLabel *menu_title_label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *tickets_page;
    QGridLayout *gridLayout_4;
    QGridLayout *tickets_layout;
    QPushButton *goto_ab_tickets_button;
    QPushButton *goto_themes_button;
    QPushButton *goto_cd_tickets_button;
    QLabel *tickets_title_label;
    QPushButton *goto_traffic_rules_button;
    QPushButton *tickets_back_button;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QWidget *ab_tickets_page;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *ab_tickets_layout;
    QLabel *ab_tickets_title_label;
    QPushButton *goto_ab_test_button;
    QPushButton *goto_ab_marathon_button;
    QPushButton *goto_ab_errors_button;
    QPushButton *ab_tickets_back_button;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_5;
    QWidget *cd_tickets_page;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *cd_tickets_layout;
    QPushButton *goto_cd_test_button;
    QPushButton *goto_cd_marathon_button;
    QPushButton *goto_cd_errors_button;
    QLabel *cd_tickets_title_label;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_6;
    QWidget *timetable_page;
    QGridLayout *gridLayout_7;
    QListView *timetable_list_view;
    QPushButton *timetable_back__button;
    QLabel *timetable_title_label;
    QWidget *registration_page;
    QGridLayout *gridLayout_8;
    QPushButton *registration_back_button;
    QLabel *registration_title_label;
    QPushButton *registration_confirm_button;
    QListView *timetable_list_view_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(364, 627);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        app_stacked_widget = new QStackedWidget(centralwidget);
        app_stacked_widget->setObjectName("app_stacked_widget");
        menu_page = new QWidget();
        menu_page->setObjectName("menu_page");
        gridLayout_2 = new QGridLayout(menu_page);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 90, -1, -1);
        menu_layout = new QGridLayout();
        menu_layout->setObjectName("menu_layout");
        goto_tickets_button = new QPushButton(menu_page);
        goto_tickets_button->setObjectName("goto_tickets_button");
        goto_tickets_button->setMinimumSize(QSize(0, 50));

        menu_layout->addWidget(goto_tickets_button, 1, 1, 1, 1);

        goto_timetable_button = new QPushButton(menu_page);
        goto_timetable_button->setObjectName("goto_timetable_button");
        goto_timetable_button->setMinimumSize(QSize(0, 50));

        menu_layout->addWidget(goto_timetable_button, 2, 1, 1, 1);

        goto_registration_button = new QPushButton(menu_page);
        goto_registration_button->setObjectName("goto_registration_button");
        goto_registration_button->setMinimumSize(QSize(0, 50));

        menu_layout->addWidget(goto_registration_button, 3, 1, 1, 1);

        menu_title_label = new QLabel(menu_page);
        menu_title_label->setObjectName("menu_title_label");

        menu_layout->addWidget(menu_title_label, 0, 1, 1, 1);


        gridLayout_2->addLayout(menu_layout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        app_stacked_widget->addWidget(menu_page);
        tickets_page = new QWidget();
        tickets_page->setObjectName("tickets_page");
        gridLayout_4 = new QGridLayout(tickets_page);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(-1, 90, -1, -1);
        tickets_layout = new QGridLayout();
        tickets_layout->setObjectName("tickets_layout");
        tickets_layout->setHorizontalSpacing(6);
        goto_ab_tickets_button = new QPushButton(tickets_page);
        goto_ab_tickets_button->setObjectName("goto_ab_tickets_button");
        goto_ab_tickets_button->setMinimumSize(QSize(0, 50));

        tickets_layout->addWidget(goto_ab_tickets_button, 1, 1, 1, 1);

        goto_themes_button = new QPushButton(tickets_page);
        goto_themes_button->setObjectName("goto_themes_button");
        goto_themes_button->setMinimumSize(QSize(0, 50));
        goto_themes_button->setCheckable(false);
        goto_themes_button->setAutoDefault(false);

        tickets_layout->addWidget(goto_themes_button, 3, 1, 1, 1);

        goto_cd_tickets_button = new QPushButton(tickets_page);
        goto_cd_tickets_button->setObjectName("goto_cd_tickets_button");
        goto_cd_tickets_button->setMinimumSize(QSize(0, 50));

        tickets_layout->addWidget(goto_cd_tickets_button, 2, 1, 1, 1);

        tickets_title_label = new QLabel(tickets_page);
        tickets_title_label->setObjectName("tickets_title_label");
        tickets_title_label->setMinimumSize(QSize(0, 0));
        tickets_title_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        tickets_layout->addWidget(tickets_title_label, 0, 1, 1, 1);

        goto_traffic_rules_button = new QPushButton(tickets_page);
        goto_traffic_rules_button->setObjectName("goto_traffic_rules_button");
        goto_traffic_rules_button->setMinimumSize(QSize(0, 50));

        tickets_layout->addWidget(goto_traffic_rules_button, 4, 1, 1, 1);

        tickets_back_button = new QPushButton(tickets_page);
        tickets_back_button->setObjectName("tickets_back_button");
        tickets_back_button->setMinimumSize(QSize(0, 50));

        tickets_layout->addWidget(tickets_back_button, 5, 1, 1, 1);


        gridLayout_4->addLayout(tickets_layout, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 1, 1, 1, 1);

        app_stacked_widget->addWidget(tickets_page);
        ab_tickets_page = new QWidget();
        ab_tickets_page->setObjectName("ab_tickets_page");
        gridLayout_5 = new QGridLayout(ab_tickets_page);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(-1, 90, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        ab_tickets_layout = new QGridLayout();
        ab_tickets_layout->setObjectName("ab_tickets_layout");
        ab_tickets_layout->setHorizontalSpacing(6);
        ab_tickets_title_label = new QLabel(ab_tickets_page);
        ab_tickets_title_label->setObjectName("ab_tickets_title_label");
        ab_tickets_title_label->setMinimumSize(QSize(0, 0));
        ab_tickets_title_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        ab_tickets_layout->addWidget(ab_tickets_title_label, 0, 1, 1, 1);

        goto_ab_test_button = new QPushButton(ab_tickets_page);
        goto_ab_test_button->setObjectName("goto_ab_test_button");
        goto_ab_test_button->setMinimumSize(QSize(0, 50));

        ab_tickets_layout->addWidget(goto_ab_test_button, 1, 1, 1, 1);

        goto_ab_marathon_button = new QPushButton(ab_tickets_page);
        goto_ab_marathon_button->setObjectName("goto_ab_marathon_button");
        goto_ab_marathon_button->setMinimumSize(QSize(0, 50));

        ab_tickets_layout->addWidget(goto_ab_marathon_button, 2, 1, 1, 1);

        goto_ab_errors_button = new QPushButton(ab_tickets_page);
        goto_ab_errors_button->setObjectName("goto_ab_errors_button");
        goto_ab_errors_button->setMinimumSize(QSize(0, 50));

        ab_tickets_layout->addWidget(goto_ab_errors_button, 3, 1, 1, 1);

        ab_tickets_back_button = new QPushButton(ab_tickets_page);
        ab_tickets_back_button->setObjectName("ab_tickets_back_button");
        ab_tickets_back_button->setMinimumSize(QSize(0, 50));

        ab_tickets_layout->addWidget(ab_tickets_back_button, 4, 1, 1, 1);


        gridLayout_5->addLayout(ab_tickets_layout, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 276, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 1, 1, 1, 1);

        app_stacked_widget->addWidget(ab_tickets_page);
        cd_tickets_page = new QWidget();
        cd_tickets_page->setObjectName("cd_tickets_page");
        gridLayout_6 = new QGridLayout(cd_tickets_page);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(-1, 90, -1, -1);
        horizontalSpacer_9 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        cd_tickets_layout = new QGridLayout();
        cd_tickets_layout->setObjectName("cd_tickets_layout");
        cd_tickets_layout->setHorizontalSpacing(6);
        goto_cd_test_button = new QPushButton(cd_tickets_page);
        goto_cd_test_button->setObjectName("goto_cd_test_button");
        goto_cd_test_button->setMinimumSize(QSize(0, 50));

        cd_tickets_layout->addWidget(goto_cd_test_button, 1, 1, 1, 1);

        goto_cd_marathon_button = new QPushButton(cd_tickets_page);
        goto_cd_marathon_button->setObjectName("goto_cd_marathon_button");
        goto_cd_marathon_button->setMinimumSize(QSize(0, 50));

        cd_tickets_layout->addWidget(goto_cd_marathon_button, 2, 1, 1, 1);

        goto_cd_errors_button = new QPushButton(cd_tickets_page);
        goto_cd_errors_button->setObjectName("goto_cd_errors_button");
        goto_cd_errors_button->setMinimumSize(QSize(0, 50));

        cd_tickets_layout->addWidget(goto_cd_errors_button, 3, 1, 1, 1);

        cd_tickets_title_label = new QLabel(cd_tickets_page);
        cd_tickets_title_label->setObjectName("cd_tickets_title_label");
        cd_tickets_title_label->setMinimumSize(QSize(0, 0));
        cd_tickets_title_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        cd_tickets_layout->addWidget(cd_tickets_title_label, 0, 1, 1, 1);

        pushButton = new QPushButton(cd_tickets_page);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 50));

        cd_tickets_layout->addWidget(pushButton, 4, 1, 1, 1);


        gridLayout_6->addLayout(cd_tickets_layout, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 276, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_6, 1, 1, 1, 1);

        app_stacked_widget->addWidget(cd_tickets_page);
        timetable_page = new QWidget();
        timetable_page->setObjectName("timetable_page");
        gridLayout_7 = new QGridLayout(timetable_page);
        gridLayout_7->setObjectName("gridLayout_7");
        timetable_list_view = new QListView(timetable_page);
        timetable_list_view->setObjectName("timetable_list_view");

        gridLayout_7->addWidget(timetable_list_view, 1, 0, 1, 2);

        timetable_back__button = new QPushButton(timetable_page);
        timetable_back__button->setObjectName("timetable_back__button");

        gridLayout_7->addWidget(timetable_back__button, 2, 0, 1, 1);

        timetable_title_label = new QLabel(timetable_page);
        timetable_title_label->setObjectName("timetable_title_label");

        gridLayout_7->addWidget(timetable_title_label, 0, 0, 1, 2);

        app_stacked_widget->addWidget(timetable_page);
        registration_page = new QWidget();
        registration_page->setObjectName("registration_page");
        gridLayout_8 = new QGridLayout(registration_page);
        gridLayout_8->setObjectName("gridLayout_8");
        registration_back_button = new QPushButton(registration_page);
        registration_back_button->setObjectName("registration_back_button");

        gridLayout_8->addWidget(registration_back_button, 2, 0, 1, 1);

        registration_title_label = new QLabel(registration_page);
        registration_title_label->setObjectName("registration_title_label");

        gridLayout_8->addWidget(registration_title_label, 0, 0, 1, 1);

        registration_confirm_button = new QPushButton(registration_page);
        registration_confirm_button->setObjectName("registration_confirm_button");

        gridLayout_8->addWidget(registration_confirm_button, 2, 1, 1, 1);

        timetable_list_view_2 = new QListView(registration_page);
        timetable_list_view_2->setObjectName("timetable_list_view_2");

        gridLayout_8->addWidget(timetable_list_view_2, 1, 0, 1, 2);

        app_stacked_widget->addWidget(registration_page);

        gridLayout->addWidget(app_stacked_widget, 0, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        app_stacked_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        goto_tickets_button->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        goto_timetable_button->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        goto_registration_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\275\320\260 \320\277\321\200\320\260\320\272\321\202\320\270\320\272\321\203", nullptr));
        menu_title_label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\210\320\272\320\276\320\273\320\260 \321\202\320\276\320\263\321\203", nullptr));
        goto_ab_tickets_button->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213 AB", nullptr));
        goto_themes_button->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\274\321\213", nullptr));
        goto_cd_tickets_button->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213 CD", nullptr));
        tickets_title_label->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        goto_traffic_rules_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        tickets_back_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        ab_tickets_title_label->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213 AB", nullptr));
        goto_ab_test_button->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\321\213 40", nullptr));
        goto_ab_marathon_button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\260\321\204\320\276\320\275", nullptr));
        goto_ab_errors_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
        ab_tickets_back_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        goto_cd_test_button->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\321\213 40", nullptr));
        goto_cd_marathon_button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\260\321\204\320\276\320\275", nullptr));
        goto_cd_errors_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
        cd_tickets_title_label->setText(QCoreApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213 CD", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        timetable_back__button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        timetable_title_label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        registration_back_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        registration_title_label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        registration_confirm_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
