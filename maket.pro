#-------------------------------------------------
#
# Project created by QtCreator 2023-02-28T13:29:37
#
#-------------------------------------------------

QT       += core
#gui opengl
#multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = maket
TEMPLATE = app

#LIBS += -lGLU -lglut
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
    ClockWidget.cpp \
    graphics.cpp \
    header.cpp \
    main.cpp \
    widgets.cpp \
    window.cpp \
    widgetsW1.cpp \
    widgetsW2.cpp \
    widgetsW3.cpp \
    widgetsW4.cpp \
    window1.cpp \
    window2.cpp \
    window3.cpp \
    window4.cpp \
    FileMaster.cpp



HEADERS += \
    ClockWidget.h \
    graphics.h \
    header.h \
    qwidgetspace.h \
    widgets.h \
    widgets_config.h \
    window.h \
    widgetsW1.h \
    widgetsW2.h \
    widgetsW3.h \
    widgetsW4.h \
    window1.h \
    window2.h \
    window4.h \
    window3.h \
    FileMaster.h

