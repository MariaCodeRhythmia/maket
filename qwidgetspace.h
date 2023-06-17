#ifndef QWIDGETSPACE_H
#define QWIDGETSPACE_H
#include <QSpacerItem>
#include <graphics.h>

extern QString ON_COLOR;

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


#endif // QWIDGETSPACE_H
