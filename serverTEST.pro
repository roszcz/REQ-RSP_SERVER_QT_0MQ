#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T09:32:49
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serverTEST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    server.h \
    client.h

FORMS    += mainwindow.ui

INCLUDEPATH += \
    'd:/kody/libs/ZeroMQ324/include'

LIBS += 'd:/kody/libs/ZeroMQ324/lib/libzmq-v120-mt-3_2_4.lib'




CONFIG += mobility
MOBILITY = 

