#ifndef DRAWW_H
#define DRAWW_H

#include <iostream>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDoubleSpinBox>
#include <QTimer>
#include <QListWidget>
#include "QtWidgets/qcombobox.h"
#include <QString>
#include <QMessageBox>
#include <unordered_map>
#include <qwidgetspace.h>


using namespace std;
#define widgetMapCombobox std::vector<std::pair<int, string>>
typedef std::unordered_map<int, std::tuple< string, string, string>> widgetMapBtn;
typedef std::unordered_map<int, std::tuple< string, string, string, int, int, int>> widgetMapIO;

class Label: public QLineEdit {
    Q_OBJECT
public:
    Label(QWidget *p){
        if(p->metaObject()->className() ==  QString("QWidget")) {
            this->setParent(p);
            parentWidth = p->size().width();
        }
        this->setMinimumSize(parentWidth/4, 28);
        this->setEnabled(false);
        //this->setMaximumWidth(parentWidth/8);
    }

    explicit Label(QString text, QString objName, QWidget *p){
        if(p->metaObject()->className() ==  QString("QWidget")) {
            this->setParent(p);
            parentWidth = p->size().width();
        }
        this->setText(text);
        this->setFixedSize(parentWidth/4, 28);
        //      this->setMaximumWidth(parentWidth/4);
        this->setObjectName(objName);
        this->setEnabled(false);
    }
    explicit Label(QString objName, QWidget *p){
        if(p->metaObject()->className() == QString("QWidget")) {
            this->setParent(p);
            parentWidth = p->size().width();
        }
        this->setMinimumSize(parentWidth/3, 28);
        //this->setMaximumWidth(parentWidth/3.5);
        this->setEnabled(false);
        this->setObjectName(objName);
    }
    Label * getLabelName(){
        return nameLabel;
    }

    void addLabelName(Label *l){
        if(l)
            nameLabel = l;
    }

private:
    Label * nameLabel;
    int parentWidth = 700;
};

class SpinBox: public QDoubleSpinBox {

    Q_OBJECT

public:
    SpinBox(QString objName, QWidget *p){
        if(p->metaObject()->className() ==  QString("QWidget")) {

            parentWidth = p->size().width();
        }
        this->setParent(p);
        this->setObjectName(objName);
        this->setMinimumSize(parentWidth/3, 28);
        // this->setMaximumWidth(parentWidth/3.5);
    }
    SpinBox(){}
    Label *getLabelName(){
        return nameLabel;
    }
    void addLabelName(Label *l){
        if(l)
            nameLabel = l;
    }


private:
    Label * nameLabel;
    int parentWidth = 700;
};

class footer : public QWidgetSpace
{
    Q_OBJECT

public:
    footer(QWidget* parent, graphics *grcs);
    void setScreenSize(QSize screenSize);
    QWidget* parent;
    QListWidget *footerList;
    QTimer *timer;
    QSize screenSize = {900, 400};
};

class widgets : public QWidget//убрать add graphics locator button
{
    Q_OBJECT

public:
    widgets(QWidget *parent, graphics *grcs);
    widgets(): QWidget(){
    }
    ~widgets(){}
    enum SystemType {
        _3C25E = 0x00,
        BIUS = 0x01,
        GMSK = 0x02,
        GPS = 0x03,
        LAG = 0x04
    };


    void setSize(QSize sizescreen);
    void setButtons(QLayout *panelWidgets);
    void read_file(QString namefile);
    void write_tofile(QString namefile);
    FILE *fvar;
    footer *getFooter();

protected:

    graphics* grphcs;
    SystemType type;
    QList<QWidget *> barModes;
    footer *foot;
    QWidget *parent;
    void creatFooter(int msec);
    QSize sizeScreen = {};
    QLayout* createButton(widgetMapBtn buttonNames, QList<Button*>& buttonList);
    QList<Label*> createLabel(QLayout *panelWidgets, widgetMapBtn bius_name);
    QList<Label*> createLabels(QLayout *panelWidgets, QString nameLabels, int count, QString tool);
    QList<QDoubleSpinBox *> createSpin(QLayout *panelWidgets,  widgetMapIO key );
    QComboBox * createComboBox(QLayout *panelWidgets, widgetMapCombobox items, QString objName);
    int seachCurrentIndex(widgetMapCombobox items, int key);
    int setDataIndex(QComboBox *box, widgetMapCombobox items);

private slots:
    void updateInput(){}
};




#endif // DRAWW_H
