/*
*  Данный класс содержит функции для установки графических эффектов на виджеты,
*  а также функции для получения значений цветовой схемы для дальнейшего использования в графическом оформлении приложения.
*
*  Функции set_graphics(QLayout *QL),  (QWidget *w)принимает указатель на объект , который содержит виджеты,
*   на которые необходимо установить графический эффект.
*
*  Функция set_graphics(QWidget *wgt, bool status)принимает указатель на объект класса QWidget и флаг status,
*  который определяет, должен ли быть установлен графический эффект на этот объект.
*
*  Функции get_***_COLOR(), возвращают соответствующие значения цветовой схемы,
*  которые могут быть использованы для дальнейшего оформления виджетов.
*
*  Функция add_graphics() устанавливает графический эффект на кнопку,определяет какая кнопка нажата.
*
*  Функции set_***_colors() задают цветовую цветовую схемы соответственно
*/
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <cstdlib>
#include <QLabel>
#include <QDebug>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGraphicsEffect>
#include <QListWidget>

class Button: public QPushButton {
    /* Имя слота строится on_ + objectName + имя сигнала */

    Q_OBJECT
public:
    Button( QWidget *p ) {
        this->setCheckable(true);
        if(p->metaObject()->className() == QString("QWidget")) {

            parentWidth = p->size().width();
        }

        this->setParent(p);
        this->setFocusPolicy(Qt::NoFocus);
        this->setMinimumSize(parentWidth/54, 20);
        this->setMaximumSize(parentWidth/54, 30);
    }
    Button(QString text, QWidget *p ) {
        this->setText(text);
        if(p->metaObject()->className() ==  QString("QWidget")) {

            parentWidth = p->size().width();
        }
        this->setParent(p);
        this->setCheckable(true);
        this->setFocusPolicy(Qt::NoFocus);
        this->setMinimumSize(parentWidth/3.5, 35);
        this->setMaximumSize(parentWidth/4, 40);
    }
    Button(QString text, QString ObjName, QWidget *p) {
        this->setText(text);
        this->setCheckable(true);
        if(p->metaObject()->className() ==  QString("QWidget")) {

            parentWidth = p->size().width();
        }
        this->setParent(p);
        this->setObjectName(ObjName);
        this->setFocusPolicy(Qt::NoFocus);
        this->setMinimumSize(parentWidth/4, 35);
        //this->setMaximumSize(parentWidth/4, 40);
    }
private:
    int parentWidth = 700;
    //void setGraphicsPallete(graphics *g){
    //    if(g!=nullptr)
    //      grphcs = g;
    //}

    // private slots:
    //  void on_locator_clicked(bool);
    //  void on_light_clicked();
    //  void on_dark_clicked();
    //  void on_blue_clicked();
    //  void on_green_clicked();
    //  void on_yellow_clicked();
    //  void on_close_clicked();

    //  private:
    // graphics *grphcs = nullptr;
    //  void enterEvent(QEvent *e){
    //       if(grphcs != nullptr) this->setStyleSheet(grphcs->get_HOVER_ON());
    //   }
    //void leaveEvent(QEvent *e){
    //        if(grphcs != nullptr) this->setStyleSheet(grphcs->get_HOVER_OFF());
    //   }
};
class graphics: public QObject{

    Q_OBJECT
public:
    graphics(QWidget *parent);

    void set_light_colors();
    void set_dark_colors();
    void set_blue_colors();
    void set_green_colors();
    void set_yellow_colors();
    void set_graphics(QLayout *QL);
    void set_graphics(QWidget *wgt, bool status);
    //  void set_graphics(QWidget* w);
    void set_graphics(QObject* obj);
    QString get_HOVER_ON();
    QString get_HOVER_OFF();
    QString get_MAIN_COLOR();
    QString get_MAIN_THEME();
    QString get_FOOTER_COLOR();
    QString get_ON_COLOR ();
    QString get_DISPLAY_COLOR();
    QColor  get_SHADOW();
    QString get_PANEL_COLOR ();
    QColor  get_ELLIPSE_COLOR ();

public slots:
    void add_graphics();
    void add_graphics(bool state);
    void press();

private:
    QWidget* parent;


    QString MAIN_COLOR =
            " background-color: rgb(150, 150, 150); "

            " QPushButton { "
            " border-style: solid;"
            " border-width: 1px;"
            " border-radius: 4px;"
            " border-color: rgb(68, 68, 68);"
            " }"
            " border-style: solid;"
            " border-width: 1px;"
            " border-radius: 3px;"
           // " border-color: rgba(138, 138, 138, .4);"
            " color: rgb(40, 40, 40);  "
            " font-weight: bold;"
            " font-size: 14px;"
            ;

    QString ON_COLOR =
            "background-color:rgb(100, 160, 200);"
            "border-style: solid;"
            "border-width: 1px;"
            "border-radius: 4px;"
            //           "border-color: rgb(25, 195, 255);"
            "border-color: rgb(120, 124, 125);"
            "color: rgb(60, 60, 60); "
            "font-weight: bold;"
            "font-size: 14px;"
            ;

    QString FOOTER_COLOR =
            "background-color: rgb(160, 160, 160);"
            "color: rgb(55,55,55);"
            "font-weight: bold;"
            "font-size: 14px;"
            ;

    QString PANEL_COLOR =
            "QListWidget { "
            "background-color: rgba(255, 255, 255, .2);"
           // "border-color: rgb(120, 124, 125);"
            //"border-style: solid;"
            //"border-width: 1px;"
            //"border-radius: 4px;"
            "}"

            "QLabel, QDoubleSpinBox, QComboBox, QLineEdit { "
            "background-color:rgba(255, 255, 255, .2);"
            "}"
            ;

    QColor ELLIPSE_COLOR = QColor (170, 170, 170);

    QString HOVER_ON =
            "border-style: solid;"
            "border-width: 1px;"
            "border-radius: 4px;"
            "border-color: rgba(75, 161, 245, .6);"
            ;

    QString HOVER_OFF =
            "border-style: solid;  "
            "border-width: 1px;  "
            "border-radius: 3px;  "
            "border-color: rgb(110, 110, 110);"
            ;

    QString DISPLAY_COLOR =
            "background-color:rgba(250, 250, 68, 80); "
            "border-style: solid;"
            "border-width: 1px;"
            "border-radius: 3px;"
            "border-color: rgba(75, 161, 245, 220); "
            "font-weight: bold;"
            "font-size: 14px;"
            ;

    QString RED_COLOR =
            "QLabel, QPushButton, QDoubleSpinBox { "
            "background-color: rgb(175, 65, 85);"
            "border-style: solid;"
            "border-width: 2px;"
            "border-radius: 2px;"
            "border-color:rgb(255, 10, 80); "
            "color:rgb(70,70,70); "
            "font-weight: bold;"
            "font-size: 16px; "
            "padding: 2px;"
            "margin: 2px;"
            "min-width:80px;"
            "min-height:25px;"
            "}" ;

    QColor SHADOW = QColor(100, 195, 240);

};


#endif // GRAPHICS_H
