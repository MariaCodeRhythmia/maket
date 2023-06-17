/*
 * Данный класс содержит функции для установки графических эффектов на виджеты,
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

#include "graphics.h"

void graphics::set_graphics(QLayout *QL)
    {
        const int count_wgt=QL -> count();

        QGraphicsDropShadowEffect* effect[count_wgt];

        for(int f=0;f<count_wgt;f++)
        {
            effect[f] = new QGraphicsDropShadowEffect();
            effect[f]->setBlurRadius(55.0);
            effect[f]->setOffset(4);
            effect[f]->setColor(QColor(0, 0, 10, 180));

            QWidget *wgt= (QWidget*) QL -> itemAt(f) -> widget();
            QString metaObject = wgt ? wgt->metaObject()->className(): NULL;

            if ( metaObject == QString("QPushButton") ||
                 metaObject == QString("Button"))
            {
                wgt->setGraphicsEffect(effect[f]);
                wgt->setStyleSheet(MAIN_COLOR);
            }

        }
    }

void graphics::set_graphics(QWidget *wgt, bool status)
    {
        QGraphicsDropShadowEffect* effect;
        effect = new QGraphicsDropShadowEffect();

        if(status) {
            effect->setBlurRadius(55.0);
            effect->setOffset(4);
            effect->setColor( SHADOW);
            wgt->setStyleSheet(ON_COLOR);
        }
        else {
            effect->setBlurRadius(55.0);
            effect->setOffset(4);
            effect->setColor(QColor(0, 0, 10, 180));
            wgt->setStyleSheet(MAIN_COLOR);
        }

        wgt->setGraphicsEffect(effect);

    }

void graphics::set_graphics(QObject* obj)
    {
        const int count_wgt = obj->children().count();
        QGraphicsDropShadowEffect* effect[count_wgt];

        for (int f = 0; f < count_wgt; f++) {
            QWidget* wgt = qobject_cast<QWidget*>(obj->children().at(f));
            QString metaObject = wgt ? wgt->metaObject()->className(): NULL;
            if (wgt) {
                if ( metaObject == QString("QPushButton") ||
                     metaObject == QString("Button")){
                    QPushButton* btn = qobject_cast<QPushButton*>(wgt);

                    effect[f] = new QGraphicsDropShadowEffect();
                    effect[f]->setBlurRadius(55.0);
                    effect[f]->setOffset(4);
                    if(btn->isChecked()){
                        effect[f]->setColor(SHADOW);
                        btn->setStyleSheet(ON_COLOR);
                    }
                    else {
                        effect[f]->setColor(QColor(0, 0, 10, 180));
                        btn->setStyleSheet(MAIN_COLOR);
                    }
                    btn->setGraphicsEffect(effect[f]);
                }
                if (( metaObject == QString("QLabel") ||
                      metaObject == QString("QComboBox") ||
                      metaObject == QString("QDoubleSpinBox")) &&
                        (obj->objectName() != "header")){
                    wgt->setStyleSheet(PANEL_COLOR);
                }
                if(metaObject == QString("QWidget")){
                    wgt->setStyleSheet(MAIN_COLOR);
                }
                set_graphics(wgt);
            }
        }
    }

QString graphics::get_HOVER_ON()
    {
        return this->HOVER_ON;
    }

QString graphics::get_HOVER_OFF()
    {
        return this->HOVER_OFF;
    }

QString graphics::get_MAIN_COLOR() {
        return this->MAIN_COLOR;
    }

QString graphics::get_MAIN_THEME() {
        return this->MAIN_COLOR;
    }

QString graphics::get_FOOTER_COLOR() {
        return this->FOOTER_COLOR;
    }

QString graphics::get_ON_COLOR() {
        return this->ON_COLOR;
    }

QString graphics::get_DISPLAY_COLOR() {
        return this->DISPLAY_COLOR;
    }

QColor graphics::get_SHADOW() {

    return this->SHADOW;
    }

QString graphics::get_PANEL_COLOR() {
        return this->PANEL_COLOR;
    }

QColor graphics::get_ELLIPSE_COLOR() {
        return this->ELLIPSE_COLOR;
    }

void graphics::add_graphics()
    {
        QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());

        bool check = tmpbtn->isChecked();
        QGraphicsDropShadowEffect* effect;


        effect = new QGraphicsDropShadowEffect();

        if(check)   {
            effect->setBlurRadius(45.0);
            effect->setOffset(2);
            effect->setColor(SHADOW);
            tmpbtn->setStyleSheet(ON_COLOR);
        }
        else {
            effect->setBlurRadius(55.0);
            effect->setOffset(4);
            effect->setColor(QColor(0, 0, 10, 180));
            tmpbtn->setStyleSheet(MAIN_COLOR);
        }

        tmpbtn->setGraphicsEffect(effect);
    }

void graphics::add_graphics(bool state)
    {
        QGraphicsDropShadowEffect* effect;

        QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());

        effect = new QGraphicsDropShadowEffect();

        if(state)   {
            effect->setBlurRadius(55.0);
            effect->setOffset(2);
            effect->setColor(SHADOW);
            tmpbtn->setStyleSheet(ON_COLOR);
        }
        else {
            effect->setBlurRadius(55.0);
            effect->setOffset(4);
            effect->setColor(QColor(0, 0, 10, 180));
            tmpbtn->setStyleSheet(MAIN_COLOR);
        }
  tmpbtn->setGraphicsEffect(effect);
    }

void graphics::press()
    {
        QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
        tmpbtn->setStyleSheet(ON_COLOR);
    }

graphics::graphics(QWidget *parent){
    /* QString osName = QSysInfo::productType();
    if(osName == "macos"){
       PANEL_COLOR.append("QComboBox,"
                           "QLabel,"
                           "QDoubleSpinBox,"
                           "QLineEdit"
                               "{"
                                 "border-style:  solid;"
                                 "border-width:  1px;"
                                 "border-radius: 3px;"
                                 "border-color:  rgb(195, 195, 195); "
                                "}");
   }
   */ if(!parent){
            QMessageBox *msg  = new QMessageBox();
            msg->information(parent, "класс graphics", "Не задан родительский объект ");
            exit(2);
        }
        this->parent = parent;
    }

void graphics::set_light_colors()
    {
        MAIN_COLOR.clear();
        FOOTER_COLOR.clear();
      //  PANEL_COLOR.clear();

        MAIN_COLOR.append("background-color: rgb(170, 170, 170);"
                          "color: rgb(60,60,60); "
                          "font-weight: bold;"
                          "border-radius: 5px;  "
                                                          );


/*        MAIN_COLOR.append("background-color: rgb(170, 170, 170);  "
                          "border-style: solid; "
                          "border-width: 1px; "
                          "border-radius: 5px;  "
                          "border-color: rgb(110, 110, 110); "
                          "color: rgb(60,60,60); "
                          "font-weight: bold;"
                          "min-width:80px;"
                          "min-height:25px;");
*/

        FOOTER_COLOR.append("background-color: rgb(160, 160, 160); "
                            "color: rgb(55,55,55); "
                            "font-weight: bold;"
                            //"min-width:80px;"
                           // "min-height:25px;"
                            );

       /* PANEL_COLOR.append( "background-color: rgba(255, 255, 255, .1); "
                            "border-radius: 2px; "
                            "border-color: rgb(140, 140, 140); "
                            "color: rgb(70,70,70); "
                            "font-weight: bold;"
                            "min-width:80px;"
                            "min-height:25px;");*/

        ELLIPSE_COLOR = QColor (170, 170, 170);

        parent->setStyleSheet(MAIN_COLOR);
    }

void graphics::set_dark_colors()
    {
        MAIN_COLOR.clear();
        FOOTER_COLOR.clear();
      //  PANEL_COLOR.clear();



        MAIN_COLOR.append ("background-color: rgb(90, 90, 90);  "
                          "border-radius: 5px;  "
                          "color: rgb(240,240,240); "
                          "font-weight: bold;"
                          );

        FOOTER_COLOR.append("background-color: rgb(70, 70, 70);  "
                            "color: rgb(255,255,255); "
                            "font-weight: bold;");

        ELLIPSE_COLOR = QColor (90, 90, 90);

     /*   PANEL_COLOR.append ("background-color: rgba(255, 255, 255, .1);"
                            "border-radius: 5px;  "
                            "color: rgb(240,240,240);"
                            );

      */
        parent->setStyleSheet(MAIN_COLOR);

    }

void graphics::set_blue_colors()
    {
        ON_COLOR.clear();
        DISPLAY_COLOR.clear();
        HOVER_ON.clear();

        ON_COLOR.append("background-color:rgba(70, 165, 240, 155);   "
                        "border-style: solid; "
                        "border-width: 1px; "
                        "border-radius: 5px;  "
                        "border-color: rgba(70, 85, 100, 230);  "
                        "color:rgb(255, 255, 255); "
                        "font-weight: bold;"
                       );

        DISPLAY_COLOR.append("background-color:rgba(70, 165, 240,80);  "
                             "border-style: solid; "
                             "border-width: 1px; "
                             "border-radius: 4px;  "
                             "border-color: rgba(75, 161, 245, 220);   "
                             "font-weight: bold;");

        HOVER_ON.append( "border-style: solid; "
                         "border-width: 1px; "
                         "border-radius: 4px;  "
                         "border-color: rgba(75, 161, 245, .6);   "
                         "font-weight: bold;");

        SHADOW = QColor(70, 169, 241);


    }

void graphics::set_green_colors()
    {
        ON_COLOR.clear();
        DISPLAY_COLOR.clear();
        HOVER_ON.clear();

        ON_COLOR.append("background-color:rgba(48, 183, 61, 140);   "
                        "border-style: solid; "
                        "border-width: 1px; "
                        "border-radius: 5px;  "
                        "border-color: rgba(70, 100, 85, 230);  "
                        "color:rgb(55, 55, 55); "
                        "font-weight: bold;"
                        "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                        "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");

        HOVER_ON.append("border-style: solid; "
                        "border-width: 1px; "
                        "border-radius: 4px;  "
                        "border-color: rgba(105, 195, 81, .6);   "
                        "font-weight: bold;"
                        "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                        "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");

        DISPLAY_COLOR.append("background-color:rgb(110, 160, 125);  "
                             "border-style: solid; "
                             "border-width: 1px; "
                             "border-radius: 4px;  "
                             "border-color: rgba(105, 195, 81, 220);   "
                             "font-weight: bold;"
                             "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                             "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");
        SHADOW = QColor(58, 200, 29);

    }

void graphics::set_yellow_colors()
    {
        ON_COLOR.clear();
        DISPLAY_COLOR.clear();
        HOVER_ON.clear();

        ON_COLOR.append("background-color:rgba(250, 250, 68, 155);   "
                        "border-style: solid; "
                        "border-width: 1px; "
                        "border-radius: 5px;  "
                        "border-color: rgba(70, 100, 85, 230);  "
                        "color:rgb(55, 55, 55);"
                        "font-weight: bold;"
                        "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                        "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");

        HOVER_ON.append("border-style: solid; "
                        "border-width: 1px; "
                        "border-radius: 4px; "
                        "border-color: rgba(250, 250, 68, .6);   "
                        "font-weight: bold;"
                        "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                        "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");

        DISPLAY_COLOR.append("background-color:rgba(250, 250, 68, 80);  "
                             "border-style: solid; "
                             "border-width: 1px; "
                             "border-radius: 4px;  "
                             "border-color: rgba(250, 250, 68, 220);   "
                             "font-weight: bold;"
                             "QLabel::tool { background-color: rgb(200, 200, 200); color: rgb(255, 255, 255);}"
                             "QDoubleSpinBox::tool { background-color: rgb(200, 200, 200);color: rgb(255, 255, 255); }");

        SHADOW = QColor(250, 250, 68);
    }

