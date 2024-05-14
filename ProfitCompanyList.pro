#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T12:23:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Question2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    company.cpp \
    list.cpp \
    companyprofit.cpp \
    companynonprofit.cpp

HEADERS  += mainwindow.h \
    company.h \
    list.h \
    companyprofit.h \
    companynonprofit.h

FORMS    += mainwindow.ui
