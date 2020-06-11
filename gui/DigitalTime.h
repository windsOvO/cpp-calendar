#ifndef CPP_PROJECT_DIGITALTIME_H
#define CPP_PROJECT_DIGITALTIME_H

#include <QLCDNumber>
#include <QMainWindow>

#include "../timeclass/myTime.h"

class DigitalTime : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalTime(QWidget *parent = 0);

public slots:
    void showTime(MyTime* time);
};

#endif //CPP_PROJECT_DIGITALTIME_H
