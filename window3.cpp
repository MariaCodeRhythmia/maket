#include "window3.h"

#include "widgetsW3.h"

WINDOW3::WINDOW3(QWidget *p, graphics *g) : WINDOW(p, g) {

    widgets_W3 *widgets3 = new widgets_W3(this, this->grphcs);

    this->setObjectName("ОКНО \"ИМЯ 3\"");
    this->setWindowTitle("ОКНО \"ИМЯ 3\"");


    panelWidgets[0] = widgets3->getnButtonsPanel();
    panelWidgets[0]->addItem(createSpaceV());
    H_BODY->addLayout(panelWidgets[0]);
    panelWidgets[1] = widgets3->getIOPanel();
    panelWidgets[2] = widgets3->getDisplayPanel();


    for(int i = 1; i < 2; i++) {

        containerPanel[i] = new QFrame();
        containerPanel[i]->setStyleSheet(this->grphcs->get_PANEL_COLOR());
        containerPanel[i]->setLayout(panelWidgets[i]);
        panelWidgets[i]->addItem(createSpaceV());
        H_BODY->addWidget(containerPanel[i]);
    }


    //H_BODY->addItem(createSpaceH());
}

WINDOW3::~WINDOW3()
{

}


