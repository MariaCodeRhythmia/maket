#include "widgetsW2.h"
#include "FileMaster.h"
widgets_W2::widgets_W2(QWidget *widget, graphics *grcs)
    : widgets(widget, grcs)
{
    buttonsPunel =  createButton(wgt_btn_w2, buttons);
    CBoxPanel = createCBoxPanel();
    DisplayPanel = createDisplayPanel();

    QMetaObject::connectSlotsByName(this);

}

QLayout *widgets_W2::getnButtonsPanel()
{
    return  buttonsPunel;
}
QLayout *widgets_W2::getCBoxPanel()
{
    return CBoxPanel;
}
QLayout *widgets_W2::getDisplayPanel()
{
    return DisplayPanel;
}

QLayout *widgets_W2::createCBoxPanel()
{
    QVBoxLayout *panelWidgets = new  QVBoxLayout;
    QLabel *name = new QLabel("Data", this);
    name->setStyleSheet(grphcs->get_ON_COLOR());
    name->setFixedHeight(30);
    name->setAlignment(Qt::AlignCenter);
    panelWidgets->addWidget(name);

     createComboBox(panelWidgets, combo1_w2, "combo1");
     createComboBox(panelWidgets, combo2_w2, "combo2");
     createComboBox(panelWidgets, combo3_w2, "combo3");
     createComboBox(panelWidgets, combo4_w2, "combo4");
     createComboBox(panelWidgets, combo5_w2, "combo5");
     createComboBox(panelWidgets, combo6_w2, "combo6");

     return panelWidgets;
}

QLayout *widgets_W2::createDisplayPanel()
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

void widgets_W2::on_combo1_activated(int index)
{
   value[0] = index;
}
void widgets_W2::on_combo2_activated(int index)
{
   value[1] = index;
}
void widgets_W2::on_combo3_activated(int index)
{
    value[2] = index;
}
void widgets_W2::on_combo4_activated(int index)
{
    value[3] = index;
}
void widgets_W2::on_combo5_activated(int index)
{
    value[4] = index;
}
void widgets_W2::on_combo6_activated(int index)
{
    value[5] = index;
}


void widgets_W2::on_updateOutput_clicked()
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

int  widgets_W2::maths()
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
        item[i].append( "box" +  QString::number(i) + ":: " + QString::number(value[i] + i));
        list->addItem(item[i]);
    }
    return 1;
}


void widgets_W2::on_fileMaster_clicked()
{
    FileDialog *master = new FileDialog("./","W2Window", this->grphcs);

    master->setWriteFileFunction(&widgets::write_tofile);
    master->setReadFileFunction(&widgets::read_file);
    master->show();

    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);
}


