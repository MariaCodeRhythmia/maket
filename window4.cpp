#include "window4.h"
#include "widgetsW4.h"

WINDOW4::WINDOW4(QWidget *p, graphics *g) : WINDOW(p, g)
{


    widgetsW4 *widgets = new  widgetsW4(this, this->grphcs);//рисовальчик виджтов

    this->setObjectName("\"objW4\"");
    this->setWindowTitle("\"gps\"");

    H_BODY->addItem(createSpaceV());
    panelWidgets[0] = widgets->getnButtonsPanel();
    panelWidgets[1] = widgets->getIOPanel();
    panelWidgets[2] = widgets->getTimePanel();


    H_BODY->addItem(createSpaceH());

    for(int i = 0; i < 3; i++) {

        containerPanel[i] = new QFrame();
        if(i == 1) containerPanel[i]->setStyleSheet(this->grphcs->get_PANEL_COLOR());
        panelWidgets[i]->setAlignment(Qt::AlignTop);
        // panelWidgets[i]->setMargin(20);
        containerPanel[i]->setLayout(panelWidgets[i]);
        H_BODY->addWidget(containerPanel[i]);
        H_BODY->addItem(createSpaceH());
    }

    H_BODY->addItem(createSpaceH());


}


