#include "widgetsW3.h"
#include "FileMaster.h"
widgets_W3::widgets_W3(QWidget *widget, graphics *grcs)
    : widgets(widget, grcs)
{
    buttonsPunel =  createButton(wgt_btn_w3, buttons);
    IOPanel = createIOPanel();
    DisplayPanel = createDisplayPanel();

    QMetaObject::connectSlotsByName(this);

}

QLayout *widgets_W3::getnButtonsPanel()
{
    return  buttonsPunel;
}
QLayout *widgets_W3::getIOPanel()
{
    return IOPanel;
}

QLayout *widgets_W3::getDisplayPanel()
{
    return DisplayPanel;
}

QLayout *widgets_W3::createIOPanel()
{
    QVBoxLayout *panelWidgets = new  QVBoxLayout;
    QLabel *name = new QLabel("Data", this);
    name->setStyleSheet(grphcs->get_ON_COLOR());
    name->setFixedHeight(30);
    name->setAlignment(Qt::AlignCenter);
    panelWidgets->addWidget(name);
    spins.append(createSpin(panelWidgets, wgt_io_w3));
    createComboBox(panelWidgets, combo5_w3, "combo5");
    createComboBox(panelWidgets, combo6_w3, "combo6");
    return panelWidgets;
}

QLayout *widgets_W3::createDisplayPanel()
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


void widgets_W3::on_objName1_valueChanged(double value)
{
    qDebug() << "objName1: " << value;
    this->value[0] = value;
}

void widgets_W3::on_objName2_valueChanged(double value)
{
    qDebug() << "objName2:" << value;
    this->value[1] = value;
}

void widgets_W3::on_objName3_valueChanged(double value)
{
    qDebug() << "objName3:" << value;

    this->value[2] = value;
}

void widgets_W3::on_objName4_valueChanged(double value)
{
    qDebug() << "objName4:" << value;
    this->value[3] = value;
}

void widgets_W3::on_objName5_valueChanged(double value)
{
    qDebug() << "objName5:" << value;

    this->value[4] = value;
}

void widgets_W3::on_objName6_valueChanged(double value)
{
    qDebug() << "objName6:" << value;

    this->value[5] = value;
}

void widgets_W3::on_combo5_activated(int index)
{
    int  i = seachCurrentIndex(combo5_w3, index);

    value[6] = combo5_w3.at(i).first;
}

void widgets_W3::on_combo6_activated(int index)
{
    int  i = seachCurrentIndex(combo6_w3, index);

    value[7] = combo6_w3.at(i).first;
}

void widgets_W3::on_updateOutput_clicked()
{

    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
    QMessageBox *msg  = new QMessageBox(this);

    if(imit_maths())
        msg->information(this, "БИУС", "Данные установлены");
    else
        msg->information(this, "БИУС", "Данные не установлены");

    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);

}

void widgets_W3::on_fileMaster_clicked()
{
    FileDialog *master = new FileDialog("./","W3Window", this->grphcs);

    master->show();

    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);
}

void widgets_W3::on_btn1_clicked(bool check)
{
    qDebug () << "btn" << check;
}

void widgets_W3::on_btn2_clicked(bool check)
{
    qDebug () << "btn" << check;
}

void widgets_W3::on_btn3_clicked(bool check)
{
    qDebug () << "btn" << check;
}

void widgets_W3::on_btn4_clicked(bool check)
{
    qDebug () << "btn" << check;
}


int  widgets_W3::imit_maths()
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
        item[i].append( QString::number(i) + ":: " + QString::number(value[i]));
        list->addItem(item[i]);
    }
    return 1;
}
