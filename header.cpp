#include "header.h"
#include "graphics.h"
#include <cstdlib>


header::header(QWidget *parent, graphics *grphcs) {

    this->parent = parent;
    this->setParent(parent);
    this->setObjectName("header");
    this->grphcs = grphcs;

    QHBoxLayout* HEAD = new QHBoxLayout;

    HEAD->addItem(createSpaceH());
    this->setLayout(HEAD);
    createButton(HEAD);
   // this->setFixedHeight(this->parent->height()/8);

    QMetaObject::connectSlotsByName(this);
}

void header::on_close_clicked()
{
    exit(0);
}
void header::on_light_clicked()
{
    grphcs->set_light_colors();
    grphcs->set_graphics(this->parent);
    this->parent->setStyleSheet(this->grphcs->get_MAIN_COLOR());
    //this->setStyleSheet(this->grphcs->get_MAIN_COLOR());

}
void header::on_dark_clicked()
{
    grphcs -> set_dark_colors();
    grphcs -> set_graphics(this->parent);
    this->parent->setStyleSheet(this->grphcs->get_MAIN_COLOR());
   // this->setStyleSheet(this->grphcs->get_MAIN_COLOR());

}
void header::on_blue_clicked()
{
    grphcs->set_blue_colors();
    grphcs->set_graphics(this->parent);
}
void header::on_green_clicked()
{
    grphcs->set_green_colors();
    grphcs->set_graphics(this->parent);
}
void header::on_yellow_clicked()
{
    grphcs-> set_yellow_colors();
    grphcs->set_graphics(this->parent);
}



QList<QPushButton *> header::createButton(QLayout *panelWidgets){
    QList<QPushButton *> buttonList;
    QPushButton* button ;
    QVBoxLayout *layout = new QVBoxLayout;

    for(int i = 0; i < (int)head_btn_name.size(); i++)   {
        auto wgtDescription = head_btn_name.at(i);
        QString name = QString::fromStdString(std::get<0>(wgtDescription));
        QString tool = QString::fromStdString(std::get<1>(wgtDescription));
        QString objName = QString::fromStdString(std::get<2>(wgtDescription));
        button = new QPushButton(name);
        button->setObjectName(objName);
        button->setParent(this);
        button->setToolTip(tool);
        button->setMinimumSize(80, 20);
        panelWidgets->addWidget(button);

        connect(button, SIGNAL(clicked(bool)), grphcs, SLOT(add_graphics()));
    }

    panelWidgets->addItem(layout);
    grphcs->set_graphics(panelWidgets);
    return buttonList;
}
