#include "window.h"

WINDOW::WINDOW(QWidget *p,
               graphics* g)
{

    if(g)
        this->grphcs = g;
    else
        this->grphcs = new graphics(this);

    if(!p) this->parent = this;

    this->move(10, 10);
    this->topLevelWidget();
    createSpaceV();
    createSpaceH();
    V_BODY = new QVBoxLayout;
    H_BODY = new QHBoxLayout;
    scrollArea = new QScrollArea;
    panelContainer = new QWidget;
    panelContainerLayout = new QHBoxLayout(panelContainer);

    this->setStyleSheet(this->grphcs->get_MAIN_COLOR());
    //  header *head = new header(this, this->grphcs);
    //   V_BODY->addWidget(head);
    //  V_BODY->addItem(createSpaceV());
    V_BODY->addLayout(H_BODY);

    this->setLayout(V_BODY);
}
WINDOW::~WINDOW()
{

}

void WINDOW::setParentBtn(QPushButton *btn)
{
    this->parentBtn = btn;
}

QPushButton *WINDOW::getParentBtn()
{
    return this->parentBtn;
}




