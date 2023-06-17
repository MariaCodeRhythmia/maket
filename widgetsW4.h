#ifndef WIDGETSW4_H
#define WIDGETSW4_H
#include <widgets.h>
#include <QTimeZone>
#include <ClockWidget.h>
extern widgetMapCombobox Code;
extern widgetMapBtn wgt_btn_w4;
extern widgetMapIO wgt_io_w4;



class widgetsW4 : public widgets//убрать add graphics locator button
{
    Q_OBJECT

public:
    widgetsW4(QWidget* widget, graphics* grcs);
    QLayout *getTimePanel();
    QLayout *getnButtonsPanel();
    QLayout *getIOPanel();
private:
    struct data_gps
    {
        char transmitter_code[8]=" ";
        unsigned char hour;
        unsigned char minute;
        unsigned char second;
        unsigned short msecond;
        unsigned char day;
        unsigned char month;
        unsigned short year;
        int correction_hour;
        int correction_minute;
        int allow;
    };
protected:
    data_gps m_gps;
    QLayout *buttonsPunel;
    QLayout *IOPanel;
    QLayout *TimePanel;
    QLayout *createButtonsPanel();
    QLayout *createIOPanel();
    QLayout *createTimePanel();

    QList<QDoubleSpinBox *> spins;
    QList<Button *> buttons;
    QComboBox *transmitterCodeBox;
    void setIP(data_gps *gps, QList<QDoubleSpinBox *> spins);
    void getIP(data_gps gps, QList<QDoubleSpinBox *> spins);
    QDateTime subtractSecondsFromDateTime(QDateTime dateTime, int hour, int minute);
    //текущуя дата и время
    QDateTime currentDateTime;
    //временная зона по умолчани
    QTimeZone timeZone;
    //время пояса
    QDateTime localDateTime;
    QString localTime;
    //время по Гринвичу
    QDateTime utcDateTime;
    QString utcTime;
    //московское время
    QDateTime moscowDateTime;
    QString moscowTime;

    ClockWidget *clockLocalTime;
    ClockWidget *clockUtcTime;
    ClockWidget *clockmoscowTime;
    QTimer *timer;
    QLabel *labelLocalTime, *labelUTCTime, *labelMoscowTime;

private slots:
    void on_updateOutput_clicked();
    void on_getSystemTime_clicked();
    void on_allowRS_clicked(bool allow);
    void on_FileMaster_clicked();
    void show_time();


};



#endif // WIDGETSW4_H
