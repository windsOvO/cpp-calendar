#ifndef CPP_PROJECT_MYTIME_H
#define CPP_PROJECT_MYTIME_H

#include "date.h"

class MyTime: public Date
{
private:
    int hour;
    int minute;
    int second;
public:
    /*
    * isNotLegal - 判断数据是否合法
    * 0 - 合法
    * 1 - 时错误：时 < 0
    * 2 - 时错误：时 > 23
    * 3 - 分错误：分 < 0
    * 4 - 分错误：分 > 59
    * 5 - 秒错误：秒 < 0
    * 6 - 秒错误：秒 > 59
    */
    static int isNotLegal2(int h, int m, int s);
    static void calculateTime(MyTime& time, int s);
    static int calculateWeek(int y, int m, int d);
    MyTime();
    MyTime(int y, int m, int d, int h, int mi, int s);
    MyTime(MyTime& time);
    void outputTime();
    int getHour();
    int getMinute();
    int getSecond();
    MyTime operator+ (int d);
    MyTime operator- (int d);
    MyTime& operator++ ();
    MyTime operator++ (int);
    MyTime& operator-- ();
    MyTime operator-- (int);
    // 由日期推到星期几
};

#endif //CPP_PROJECT_MYTIME_H
