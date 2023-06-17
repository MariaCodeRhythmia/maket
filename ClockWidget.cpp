#include <ClockWidget.h>


ClockWidget::ClockWidget(QWidget *parent, graphics *g)
{

    if(g){
        grphcs = g;
    }
    else {
        grphcs = new graphics(this);
    }

    QTimer * t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(updateTimer()));
    t->start(1000);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&ClockWidget::update));
    timer->start(1000);

}

void ClockWidget::setTime(const QTime& time) {
    currentTime = time;
}
QTime ClockWidget::getTime() const {
    return currentTime;
}

void ClockWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    int side = qMax(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBackground(painter);
    drawClock(painter);

}
void ClockWidget::drawBackground(QPainter& painter) {
    painter.setBrush(QColor(5, 5, 5, 50));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(-90, -90, 180, 180);
}
void ClockWidget::drawClock(QPainter& painter) {
    QTime time = currentTime.isNull() ? QTime::currentTime() : currentTime;

    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    // Рисуем мин стрелку

    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0) - 3) - 90);
    painter.drawRect(-1, -70, 2, 70);

    // Рисуем час стрелку
    painter.rotate(6.0 * ((time.minute() + time.second() / 60.0) - 15) - 90);
    painter.drawRect(-2, -50, 4, 50);

    // Рисуем секундную стрелку
    painter.setBrush(grphcs->get_SHADOW());
    painter.rotate(6.0 * (time.second() - 15) - 90);
    painter.drawRect(-1, -80, 2, 80);

    painter.restore();

    // Рисуем цифры
    painter.setPen(Qt::white);
    QFont font = painter.font();
    font.setPixelSize(16);
    painter.setFont(font);

    painter.save();
    for (int i = 1; i <= 12; ++i) {
        painter.rotate(30.0);
        //painter.drawText(-8, -88, 16, 16, Qt::AlignHCenter | Qt::AlignTop, QString::number(i));
        painter.drawText(-8, -88, 16, 16, Qt::AlignHCenter | Qt::AlignTop, "|");
    }
    painter.restore();
}
void ClockWidget::updateTimer() {
    currentTime = currentTime.addSecs(1);
  //  qDebug() << currentTime;
}



