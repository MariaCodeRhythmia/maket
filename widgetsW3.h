#ifndef WIDGETW3_H
#define WIDGETW3_H
#include <widgets.h>
#include <graphics.h>

extern widgetMapBtn wgt_btn_w3;
extern widgetMapIO wgt_io_w3;
extern widgetMapCombobox combo5_w3;
extern widgetMapCombobox combo6_w3;

class widgets_W3 : public widgets//убрать add graphics locator button
{

    Q_OBJECT

public:
    widgets_W3(QWidget* widget, graphics* grcs);

    QLayout *getnButtonsPanel();
    QLayout *getIOPanel();
    QLayout *getDisplayPanel();
    ~widgets_W3(){}

protected:

    QLayout *buttonsPunel;
    QLayout *IOPanel;
    QLayout *DisplayPanel;
    QLayout *createIOPanel();
    QLayout *createDisplayPanel();
    QList<QDoubleSpinBox *> spins;
    QList<Button *> buttons;
    QListWidget * list;
    double value[8];
    QString item[8];
    QComboBox *box[2];

private slots:
    /* Имя слота строится on_ + objectName + имя сигнала */
    void on_objName1_valueChanged(double value);
    void on_objName2_valueChanged(double value);
    void on_objName3_valueChanged(double value);
    void on_objName4_valueChanged(double value);
    void on_objName5_valueChanged(double value);
    void on_objName6_valueChanged(double value);
    void on_combo5_activated(int index);
    void on_combo6_activated(int index);
    void on_updateOutput_clicked();
    void on_fileMaster_clicked();
    void on_btn1_clicked(bool check);
    void on_btn2_clicked(bool check);
    void on_btn3_clicked(bool check);
    void on_btn4_clicked(bool check);

    int imit_maths();
};


#endif // WIDGETSW3_H




