#include "widgetsW4.h"
#include "FileMaster.h"
widgetsW4::widgetsW4(QWidget *widget, graphics *grcs)
    : widgets(widget, grcs)
{
    this->type = GPS;
    buttonsPunel = createButton(wgt_btn_w4, buttons);
    IOPanel = createIOPanel();
    TimePanel = createTimePanel();

    QMetaObject::connectSlotsByName(this);
}

QLayout *widgetsW4::getTimePanel()
{
    return TimePanel;
}
QLayout *widgetsW4::getnButtonsPanel()
{
    return  buttonsPunel;
}
QLayout *widgetsW4::getIOPanel()
{
    return IOPanel;
}
QLayout *widgetsW4::createIOPanel()
{
    QVBoxLayout *panelWidgets = new  QVBoxLayout;
    QLabel *name = new QLabel("Data");
    name->setStyleSheet(grphcs->get_ON_COLOR());
    name->setFixedHeight(30);
    name->setAlignment(Qt::AlignCenter);
    panelWidgets->addWidget(name);
    transmitterCodeBox = createComboBox(panelWidgets, Code, "transmitter");
    spins.append(createSpin(panelWidgets, wgt_io_w4));
    getIP(m_gps, spins);

    return panelWidgets;
}
QLayout *widgetsW4::createTimePanel()
{

    QVBoxLayout *panelWidgets = new  QVBoxLayout;

    QLabel *label1 = new  QLabel("Local Time:");
    labelLocalTime = new  QLabel();
    clockLocalTime = new  ClockWidget(this, this->grphcs);

    label1->setMinimumWidth(200);
    label1->setAlignment(Qt::AlignCenter);
    labelLocalTime->setAlignment(Qt::AlignCenter);


    QLabel *label2 = new  QLabel("UTC Time:");
    clockUtcTime = new  ClockWidget(this, this->grphcs);
    labelUTCTime = new  QLabel();

    label2->setAlignment(Qt::AlignCenter);
    labelUTCTime->setAlignment(Qt::AlignCenter);

    QLabel *label3 = new  QLabel("Moscow Time:");
    clockmoscowTime = new  ClockWidget(this, this->grphcs);
    labelMoscowTime = new  QLabel();

    label3->setAlignment(Qt::AlignCenter);
    labelMoscowTime->setAlignment(Qt::AlignCenter);

    // Получаем текущую дату и время
    currentDateTime = QDateTime::currentDateTime();

    // Получаем временную зону по умолчанию
    timeZone = QTimeZone::systemTimeZone();

    // Рассчитываем время пояса
    localDateTime = currentDateTime.toTimeZone(timeZone);
    localTime = localDateTime.toString("hh:mm:ss");

    // Рассчитываем время по Гринвичу
    utcDateTime = currentDateTime.toUTC();
    utcTime = utcDateTime.toString("hh:mm:ss");

    // Рассчитываем московское время
    QTimeZone moscowTimeZone("Europe/Moscow");
    moscowDateTime = currentDateTime.toTimeZone(moscowTimeZone);
    moscowTime = moscowDateTime.toString("hh:mm:ss");


    labelLocalTime->setText(localTime);
    labelUTCTime->setText(utcTime);
    labelMoscowTime->setText(moscowTime);

    clockLocalTime->setTime(localDateTime.time());
    clockUtcTime->setTime(utcDateTime.time());
    clockmoscowTime->setTime( moscowDateTime.time());

    clockLocalTime->setMinimumSize(180,180);
    clockUtcTime->setMinimumSize(180,180);
    clockmoscowTime->setMinimumSize(180,180);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(show_time()));
    timer->start(1000);

    // Добавляем лейблы в layout
    panelWidgets->addWidget(label1);
    panelWidgets->addWidget(labelLocalTime);
    panelWidgets->addWidget(clockLocalTime);
    panelWidgets->addWidget(label2);
    panelWidgets->addWidget(labelUTCTime);
    panelWidgets->addWidget(clockUtcTime);
    panelWidgets->addWidget(label3);
    panelWidgets->addWidget(labelMoscowTime);
    panelWidgets->addWidget(clockmoscowTime);

    return panelWidgets;

}
void widgetsW4::on_updateOutput_clicked()
{
    if(spins.empty())  return;

    setIP(&m_gps, spins);

    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());

    QMessageBox *msg  = new QMessageBox(this);

    msg->information(this, " ", "Данные установлены");
    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);
}
void widgetsW4::on_getSystemTime_clicked()
{
    QTime gpsTime = QTime::currentTime();
    spins[0]->setValue(gpsTime.hour());
    spins[1]->setValue(gpsTime.minute());
    spins[2]->setValue(gpsTime.second());
    spins[3]->setValue(gpsTime.msec());

    QDate gpsDate = QDate::currentDate();
    spins[6]->setValue(gpsDate.year());
    spins[5]->setValue(gpsDate.month());
    spins[4]->setValue(gpsDate.dayOfWeek());

    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
    QMessageBox *msg  = new QMessageBox(this);
    msg->information(this, "GPS", "Время считано");
    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);
}

void widgetsW4::on_allowRS_clicked(bool allow)
{
    m_gps.allow = allow;
}
void widgetsW4::on_FileMaster_clicked()
{
    FileDialog *master = new FileDialog("./","prefix", this->grphcs);
    master->show();
    QPushButton* tmpbtn = qobject_cast<QPushButton*>(sender());
    tmpbtn->setChecked(false);
    grphcs->set_graphics(tmpbtn, false);
}

void widgetsW4::show_time()
{
    localDateTime .setTime(localDateTime.time().addMSecs(1));
    labelLocalTime->setText(localDateTime.time().toString("hh:mm:ss"));

    utcDateTime .setTime(utcDateTime.time().addMSecs(1));
    labelUTCTime->setText(utcDateTime.time().toString("hh:mm:ss"));

    moscowDateTime .setTime(moscowDateTime.time().addMSecs(1));
    labelMoscowTime->setText(moscowDateTime.time().toString("hh:mm:ss"));
}
void widgetsW4::setIP(data_gps *gps, QList<QDoubleSpinBox *> spins)
{
    if(spins.empty()) return;
    gps->hour =     spins[0] -> value();
    gps->minute =   spins[1] -> value();
    gps->second =   spins[2] -> value();
    gps->msecond =  spins[3] -> value();
    gps->day =      spins[4] -> value();
    gps->month =    spins[5] -> value();
    gps->year =     spins[6] -> value();

    gps->correction_hour =      spins[7] -> value();
    gps->correction_minute =    spins[8] -> value();

    QString transmitterCode = transmitterCodeBox->currentText();
    qstrncpy(gps->transmitter_code, transmitterCode.toLocal8Bit().data(), sizeof(gps->transmitter_code));

    QTime gpsTime;
    gpsTime.setHMS( spins[0]->value(),//hour
            spins[1]->value(),//minute
            spins[2]->value(),//second;
            spins[3]->value());//msec;

    currentDateTime.setTime(gpsTime);

    localDateTime = currentDateTime;
    clockLocalTime->setTime(currentDateTime.time());

    // Рассчитываем время по Гринвичу добавляем, надо отнимать
    utcDateTime = subtractSecondsFromDateTime(currentDateTime, spins[7]->value(), spins[8]->value());
    clockUtcTime->setTime(utcDateTime.time());
    // Рассчитываем московское время
    clockmoscowTime->setTime((moscowDateTime.addSecs(3 * 3600)).time());
    moscowDateTime = moscowDateTime.addSecs(3 * 3600);
    //moscowTime = moscowDateTime.toString("hh:mm:ss");

}
void widgetsW4::getIP(data_gps gps, QList<QDoubleSpinBox *> spins)
{
    if(spins.empty()) return;
    spins[0] -> setValue(gps.hour);
    spins[1] -> setValue(gps.minute);
    spins[2] -> setValue(gps.second);
    spins[3] -> setValue(gps.day);
    spins[4] -> setValue(gps.month);
    spins[5] -> setValue(gps.year);
    spins[6] -> setValue(gps.msecond);
    spins[7] -> setValue(gps.correction_hour);
    spins[8] -> setValue(gps.correction_minute);
    transmitterCodeBox->setCurrentText(QString(gps.transmitter_code));
}

QDateTime widgetsW4::subtractSecondsFromDateTime( QDateTime dateTime, int hour, int minute)
{

    QDate date = dateTime.date();
    QTime time = dateTime.time();
    int curentMinute = 0;
    int curentHoure = 0;
    int Day = date.day();

    if((time.minute() - minute) < 0) {
        curentMinute = (time.minute() - minute)*(-1);
        hour += 1;
    } else {
        curentMinute = time.minute() - minute;
    }

    if((time.hour() - hour) < 0) {
        curentHoure = (time.hour() - hour)*(-1);
        Day -= 1;
    } else {
        curentHoure = time.hour() - hour;
    }

    time.setHMS(curentHoure, curentMinute, time.second());
    date.setDate(date.year(), date.month(), Day);

    QDateTime DT;
    DT.setDate(date);
    DT.setTime(time);

    // Возвращение новой даты и времени
    return DT;

}




