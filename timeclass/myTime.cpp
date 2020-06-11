#include "myTime.h"

#include <cstdio>
#include <cstdlib>


MyTime::MyTime(): Date()
{
    hour = minute = second = 0;
}

MyTime::MyTime(int y, int m, int d, int h, int mi, int s)
    : Date(y, m, d)
{
    hour = h;
    minute = mi;
    second = s;
}

MyTime::MyTime(MyTime& time)
{
    year = time.year;
    month = time.month;
    day = time.day;
    hour = time.hour;
    minute = time.minute;
    second = time.second;
}

void MyTime::outputTime()
{
    printf("%d %d %d %d:%d:%d\n", year, month, day,
            hour, minute, second);
}

int MyTime::getHour()
{
    return hour;
}
int MyTime::getMinute()
{
    return minute;
}
int MyTime::getSecond()
{
    return second;
}

int MyTime::isNotLegal2(int h, int m, int s)
{
    if (h < 0)
        return 1;
    if (h > 23)
        return 2;
    if (m < 0)
        return 3;
    if (m > 59)
        return 4;
    if (s < 0)
        return 5;
    if (s > 59)
        return 6;
    return 0;
}

void MyTime::calculateTime(MyTime& time, int s)
{
    time.second += s;
    while (true)
    {
        int res = isNotLegal2(time.hour, time.minute, time.second);
        if (res == 0)
            break;
        else if (res == 1)
        {
            calculateDate(time, -1);
            time.hour += 24;
        }
        else if (res == 2)
        {
//            printf("!\n");
            calculateDate(time, 1);
            time.hour -= 24;
        }
        else if (res == 3)
        {
            time.hour--;
            time.minute += 60;
        }
        else if (res == 4)
        {
            time.hour++;
            time.minute -= 60;
        }
        else if (res == 5)
        {
            time.minute--;
            time.second += 60;
        }
        else if (res == 6)
        {
            time.minute++;
            time.second -= 60;
        }
    }
}

MyTime MyTime::operator+ (int s)
{
    MyTime t(*this);
    calculateTime(t, s);
    return t;
}

MyTime MyTime::operator- (int s)
{
    MyTime t(*this);
    calculateTime(t, -s);
    return t;
}

MyTime& MyTime::operator++ ()
{
    calculateTime(*this, 1);
    return *this;
}

MyTime MyTime::operator++ (int)
{
    MyTime t(*this);
    calculateTime(*this, 1);
    return t;
}

MyTime& MyTime::operator-- ()
{
    calculateTime(*this, -1);
    return *this;
}

MyTime MyTime::operator-- (int)
{
    MyTime t(*this);
    calculateTime(*this, -1);
    return t;
}

int MyTime::calculateWeek(int y, int m, int d)
{
    // 蔡勒公式
    if (m < 3)
    {
        y--;
        m += 12;
    }
    int c =  y / 100; // 世纪
    y %= 100;
    int w = c / 4 - 2 * c + y + y / 4 + 26 * (m + 1) / 10 + d - 1;
    w = (w % 7 + 7) % 7;
    return w;
}
