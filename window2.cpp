#include "window2.h"
#include "widgetsW2.h"

WINDOW2::WINDOW2(QWidget *p, graphics *g) : WINDOW(p, g){


    widgets_W2 *widgets = new widgets_W2(this, this->grphcs);//рисовальчик виджтов
    this->setObjectName("ОКНО \"ИМЯ 2\"");
    this->setWindowTitle("ОКНО \"ИМЯ 2\"");

    panelWidgets[0] = widgets->getnButtonsPanel();
    panelWidgets[1] = widgets->getCBoxPanel();
    panelWidgets[2] = widgets->getDisplayPanel();

    H_BODY->addItem(createSpaceH());
    V_BODY->addLayout(panelWidgets[0]);

 //   panelWidgets[0]->setAlignment(Qt::AlignTop);
   // panelWidgets[1]->setMargin(20);
    containerPanel[1] = new QFrame();
    containerPanel[1]->setStyleSheet(this->grphcs->get_PANEL_COLOR());

    panelWidgets[1]->addItem(createSpaceV());
    containerPanel[1]->setLayout(panelWidgets[1]);
    H_BODY->addWidget(containerPanel[1]);

   // panelWidgets[2]->setMargin(20);
    containerPanel[2] = new QFrame();
    containerPanel[2]->setStyleSheet(this->grphcs->get_PANEL_COLOR());

  //  panelWidgets[2]->addItem(createSpaceV());
    containerPanel[2]->setLayout(panelWidgets[2]);
    H_BODY->addWidget(containerPanel[2]);

   H_BODY->addItem(createSpaceH());
}

WINDOW2::~WINDOW2()
{

}


