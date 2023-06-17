#ifndef ClockWidget_H
#define ClockWidget_H

#include "graphics.h"
#include <QMainWindow>
#include <QtWidgets>
#include <QObject>
#include <QMessageBox>

class ClockWidget : public QWidget {

    Q_OBJECT

public:
   ClockWidget(QWidget* parent = nullptr,  graphics *g = nullptr);
   void setTime(const QTime& time) ;

    QTime getTime() const;


protected:
    void paintEvent(QPaintEvent* event) override;
    void drawBackground(QPainter& painter) ;
    void drawClock(QPainter& painter);
private:
    QTime currentTime;
    QTimer* timer;
    graphics *grphcs;

private slots:
    void updateTimer();
};

#endif // ClockWidget
