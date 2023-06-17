#ifndef HEADER_H
#define HEADER_H
#include <QObject>
#include "QtCore/qtmetamacros.h"
#include "graphics.h"
#include "widgets.h"

extern widgetMapBtn head_btn_name;
/*
class QWidgetSpace: public QWidget
    {
        Q_OBJECT
    public:
        ~QWidgetSpace(){}

    protected:

        QSize screenSize = {900, 400};
        QWidget* parent;
        graphics* grphcs;
        QSpacerItem *createSpaceV()     {

                return new QSpacerItem(20, 20,
                                       QSizePolicy::Minimum,
                                       QSizePolicy::Expanding);
            }

        QSpacerItem *createSpaceH()     {

                return new QSpacerItem(20, 20,
                                       QSizePolicy::Expanding,
                                       QSizePolicy::Minimum);
            }
        void setGraphics(graphics* g)   {

                this->grphcs = g;
            }

        QWidget *createLine()           {

                QWidget *l = new QWidget();
                l->setFixedHeight(2);
                if(grphcs) l->setStyleSheet(grphcs->get_FOOTER_COLOR());

                return l;
            }
    };
*/
class header : public QWidgetSpace
{
    Q_OBJECT

public:
    header(QWidget* parent, graphics* grcs);
    ~header(){}
    void setScreenSize(QSize screenSize);


private slots:
    void on_close_clicked();
    void on_green_clicked();
    void on_yellow_clicked();
    void on_blue_clicked();
    void on_dark_clicked();
    void on_light_clicked();

private:
    QList<QPushButton *> createButton(QLayout *panelWidgets);
    graphics* grphcs;

};


#endif // HEADER_H
