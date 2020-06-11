#include "DigitalTime.h"

#include <QTimer>
#include <QTime>
#include <QMainWindow>
#include <iostream>
#include "../timeclass/myTime.h"

DigitalTime::DigitalTime(QWidget*parent)
        : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setDigitCount(8);
//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &DigitalTime::showTime);
//    timer->start(1000);
//    showTime();

//    setWindowTitle(tr("Digital Clock"));
//    resize(150, 60);
}


void DigitalTime::showTime(MyTime* t)
{
    QTime *time = new QTime(t->getHour(), t->getMinute(), t->getSecond());
    QString text = time->toString("hh:mm:ss");
    // debug
    std::string s = text.toStdString();
//    std::cout << s << std::endl;
    if ((time->second() % 2) == 0)
        text[2] = text[5] = ' ';
    display(text);
}