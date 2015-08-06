#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T12:05:31
#
#-------------------------------------------------

QT       += core gui
include(F:\Qt\QTxlsx\src\xlsx\qtxlsx.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RightFood
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    FoodItem.cpp \
    DailyRecommendedNutrition.cpp \
    TotalNutrition.cpp

HEADERS  += mainwindow.h \
    FoodItem.h \
    DailyRecommendedNutrition.h \
    TotalNutrition.h

FORMS    += mainwindow.ui
