#ifndef WIDGETW2_H
#define WIDGETW2_H
#include <widgets.h>
#include <graphics.h>

extern widgetMapBtn wgt_btn_w2;
extern widgetMapIO wgt_io_w2;
extern widgetMapCombobox combo1_w2;
extern widgetMapCombobox combo2_w2;
extern widgetMapCombobox combo3_w2;
extern widgetMapCombobox combo4_w2;
extern widgetMapCombobox combo5_w2;
extern widgetMapCombobox combo6_w2;

class widgets_W2 : public widgets//убрать add graphics locator button
{
    Q_OBJECT
public:
    widgets_W2(QWidget* widget, graphics* grcs);
    QLayout *getnButtonsPanel();
    QLayout *getCBoxPanel();
    QLayout *getDisplayPanel();
    ~widgets_W2(){}

protected:
    QLayout *buttonsPunel;
    QLayout *CBoxPanel;
    QLayout *DisplayPanel;
    QLayout *createCBoxPanel();
    QLayout *createDisplayPanel();
    QList<QDoubleSpinBox *> spins;
    QList<Button *> buttons;
    QListWidget * list;
    double value[6];
    QString item[6];
    QComboBox *box[6];

private slots:
    /* Имя слота строится on_ + objectName + имя сигнала */

    void on_combo1_activated(int index);
    void on_combo2_activated(int index);
    void on_combo3_activated(int index);
    void on_combo4_activated(int index);
    void on_combo5_activated(int index);
    void on_combo6_activated(int index);
    void on_updateOutput_clicked();
    void on_fileMaster_clicked();
    int maths();
};


#endif // WIDGETSW2_H




