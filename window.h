#ifndef WINDOW_H
#define WINDOW_H
#include <QDateTimeEdit>
#include <QScrollArea>
#include "widgets.h"



const int MAX_COUNT_PANELS = 12;

class WINDOW : public QWidgetSpace
    {
        Q_OBJECT
    public:
        WINDOW(QWidget* parent,
                graphics *g
                );

        ~WINDOW();
        void setParentBtn(QPushButton *btn);
        QPushButton *getParentBtn();

    protected:
        QVBoxLayout* V_BODY;
        QFrame* containerPanel[MAX_COUNT_PANELS];
        QPushButton *parentBtn;
        QTimer *timerRead;
        graphics* grphcs;
        QHBoxLayout *H_BODY;
        QScrollArea *scrollArea;
        QHBoxLayout *panelContainerLayout;
        QWidget *panelContainer;
        QLayout *panelWidgets[MAX_COUNT_PANELS];
        footer* foot;

    };

#endif // WINDOW_H
