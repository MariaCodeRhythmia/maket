#include <QApplication>
#include <window1.h>
#include <window2.h>
#include <window3.h>
#include <window4.h>
#include <graphics.h>
#include <QScreen>
#include <QDebug>
#include "widgets_config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setAttribute(Qt::AA_ForceRasterWidgets, false);

    QWidget *nullW = new QWidget();
    graphics *g = new graphics(nullW);
     g->set_yellow_colors();
    // g->set_light_colors();
    // g->set_dark_colors();

    //g->set_green_colors();

    WINDOW1 *w1 = new WINDOW1(nullW, g);
    WINDOW2 *w2 = new WINDOW2(nullW, g);
    WINDOW3 *w3 = new WINDOW3(nullW, g);
    WINDOW4 *w4 = new WINDOW4(nullW, g);

    w1->show();
    w2->show();
    w3->show();
    w4->show();

    return a.exec();
}
