QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
VPATH += ./src
SOURCES += \
    appdatabase.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_slots.cpp \
    spoiler.cpp \
    # textdb.cpp \
    tickets_edit.cpp \
    tickets_edit_slots.cpp \
    tickets_test.cpp \
    tickets_test_slots.cpp

VPATH += ./include
HEADERS += \
    appdatabase.h \
    mainwindow.h \
    spoiler.h \
    # textdb.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    style.qrc
