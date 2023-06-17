#include "widgetsW1.h"

widgets_W1::widgets_W1(QWidget *widget, graphics *grcs)
    : widgets(widget, grcs)
{
    buttonsPunel =  createButton(wgt_btn_w1, buttons);
    IOPanel = createIOPanel();
    DisplayPanel = createDisplayPanel();

    QMetaObject::connectSlotsByName(this);

}

QLayout *widgets_W1::getnButtonsPanel()
{
    return  buttonsPunel;
}
QLayout *widgets_W1::getIOPanel()
{
    return IOPanel;
}

QLayout *widgets_W1::getDisplayPanel()
{
    return DisplayPanel;
}

QLayout *widgets_W1::createIOPanel()
{
    QVBoxLayout *panelWidgets = new  QVBoxLayout;
    QLabel *name = new QLabel("Data", this);
    name->setStyleSheet(grphcs->get_ON_COLOR());
    name->setFixedHeight(30);
    name->setAlignment(Qt::AlignCenter);
    panelWidgets->addWidget(name);
    spins.append(createSpin(panelWidgets, wgt_io_w1));
    return panelWidgets;
}

QLayout *widgets_W1::createDisplayPanel()
{
    QVBoxLayout *panelWidgets = new  QVBoxLayout;
    QLabel *name = new QLabel("Result", this);
    name->setStyleSheet(grphcs->get_ON_COLOR());
    name->setFixedHeight(30);
    name->setAlignment(Qt::AlignCenter);
    panelWidgets->addWidget(name);
    list = new QListWidget();
    panelWidgets->addWidget(list);
    return panelWidgets;
}

void widgets_W1::on_objName1_valueChanged(double value)
{
    qDebug() << "objName1: " << value;
    this->value[0] = value;
}

void widgets_W1::on_objName2_valueChanged(double value)
{
    qDebug() << "objName2:" << value;
    this->value[1] = value;
}

void widgets_W1::on_objName3_valueChanged(double value)
{
    qDebug() << "objName3:" << value;

    this->value[2] = value;
}

void widgets_W1::on_objName4_valueChanged(double value)
{
    qDebug() << "objName4:" << value;
    this->value[3] = value;
}

void widgets_W1::on_objName5_valueChanged(double value)
{
    qDebug() << "objName5:" << value;

    this->value[4] = value;
}

void widgets_W1::on_objName6_valueChanged(double value)
{
    qDebug() << "objName6:" << value;

    this->value[5] = value;
}

void widgets_W1::on_updateOutput_clicked(bool click)
{
    if(click)
    {
        QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
        QMessageBox *msg  = new QMessageBox(this);

        if(maths())
            msg->information(this, "БИУС", "Данные установлены");
        else
            msg->information(this, "БИУС", "Данные не установлены");

        tmpbtn->setChecked(false);
        grphcs->set_graphics(tmpbtn, false);



    }

}

int  widgets_W1::maths()
{
    /*imit some maths*/
    list->clear();
    int const sizeV = sizeof(value)/sizeof(double);
    if(!sizeV) return 0;

    int const sizeI = sizeof(item)/sizeof(QString);
    if(!sizeI) return 0;

    if(sizeI != sizeV)
        return 0;

    for(int i =0; i < sizeV; i++ ){
        item[i].clear();
        item[i].append( "objName" +  QString::number(i) + ":: " + QString::number(value[i] + 5));
        list->addItem(item[i]);
    }
    return 1;
}
