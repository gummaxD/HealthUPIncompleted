#-------------------------------------------------
#
# Project created by QtCreator 2022-06-26T13:41:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HealthUp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    models/piatto.cpp \
    models/item.cpp \
    models/giorno.cpp \
    models/model.cpp \
    models/calendarmodel.cpp \
    helpers/piatti.cpp \
    views/view.cpp \
    views/calendarview.cpp \
    views/chartview.cpp \
    models/piechartmodel.cpp

HEADERS += \
    mainwindow.h \
    models/piatto.h \
    models/item.h \
    models/giorno.h \
    models/model.h \
    models/calendarmodel.h \
    helpers/piatti.h \
    views/view.h \
    views/calendarview.h \
    views/chartview.h \
    models/piechartmodel.h
