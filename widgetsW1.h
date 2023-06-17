#ifndef WIDGETSW1_H
#define WIDGETSW1_H
#include <widgets.h>
#include <graphics.h>

extern widgetMapBtn wgt_btn_w1;
extern widgetMapIO wgt_io_w1;


class widgets_W1 : public widgets//убрать add graphics locator button
{

    Q_OBJECT

public:
    widgets_W1(QWidget* widget, graphics* grcs);

    QLayout *getnButtonsPanel();
    QLayout *getIOPanel();
    QLayout *getDisplayPanel();
    ~widgets_W1(){}

protected:

    QLayout *buttonsPunel;
    QLayout *IOPanel;
    QLayout *DisplayPanel;
    QLayout *createIOPanel();
    QLayout *createDisplayPanel();
    QList<QDoubleSpinBox *> spins;
    QList<Button *> buttons;
    QListWidget * list;
    double value[6];
    QString item[6];


private slots:
    /* Имя слота строится on_ + objectName + имя сигнала */
    void on_objName1_valueChanged(double value);
    void on_objName2_valueChanged(double value);
    void on_objName3_valueChanged(double value);
    void on_objName4_valueChanged(double value);
    void on_objName5_valueChanged(double value);
    void on_objName6_valueChanged(double value);

    void on_updateOutput_clicked(bool click);
    int maths();
};


#endif // WIDGETSW1_H




