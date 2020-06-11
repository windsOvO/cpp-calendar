#include "date.h"

#include <iostream>
using namespace std;

// 静态成员初始化需要放在.cpp中
int Date::defaultDay = 1;
int Date::defaultMonth = 1;
int Date::defaultYear = 1970;

void Date::setDefaultValue(int y, int m, int d)
{
    if (isNotLegal(y, m, d))
    {
        cout << "默认值不合法！" << endl;
        return;
    }
    defaultDay = d;
    defaultMonth = m;
    defaultYear = y;
}

int Date::getDayOfMonth(int y, int m)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    if (m == 2)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400  == 0)
            return 29;
        else
            return 28;
    }
    // calculateDate中的边界特殊情况
    if (m == 0)
        return 31;
    return 0;
}

int Date::isNotLegal(int y, int m, int d)
{
    if (y < 0)
        return 1;
    if (m < 1)
        return 2;
    if (m > 12)
        return 3;
    if (d < 1)
        return 4;
    if (d > getDayOfMonth(y, m))
        return 5;
    return 0;
}


Date::Date()
{
    day = defaultDay;
    month = defaultMonth;
    year = defaultYear;
}

Date::Date(int y, int m, int d)
{
    if (isNotLegal(y, m, d))
    {
        cout << "初始值不合法！" << endl;
        day = defaultDay;
        month = defaultMonth;
        year = defaultYear;
        return;
    }
    day = d;
    month = m;
    year = y;
}

Date::Date(Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::show()
{
    cout << year << "年" << month << "月" << day << "日" << endl;
}

/*
 * isNotLegal - 判断数据是否合法
 * 0 - 合法
 * 1 - 年错误：年 < 0
 * 2 - 月错误：月 < 1
 * 3 - 月错误：月 > 12
 * 4 - 日错误：日 < 1
 * 5 - 日错误：日 > 规定上限
 */
void Date::calculateDate(Date& date, int d)
{
    date.day += d;
    while (true)
    {
        int res = isNotLegal(date.year, date.month, date.day);
        if (res == 0)
            break;
        else if (res == 1)
        {
            cout << "年份小于0" << endl;
            date.day -= d; // 还原
            break;
        }
        else if (res == 2)
        {
            date.year--;
            date.month += 12;
        }
        else if (res == 3)
        {
            date.year++;
            date.month -= 12;
        }
        else if (res == 4)
        {
            date.month--; // 存在month = 0的情况
            date.day += getDayOfMonth(date.year, date.month);
        }
        else if (res == 5)
        {
            date.day -= getDayOfMonth(date.year, date.month);
            date.month++;
        }
    }
}

Date Date::operator+ (int d)
{
    Date date(*this);
    calculateDate(date, d);
    return date;
}
Date Date::operator- (int d)
{
    Date date(*this);
    calculateDate(date, -d);
    return date;
}

Date& Date::operator++ ()
{
    calculateDate(*this, 1);
    return *this;
}

Date Date::operator++ (int)
{
    Date date(*this);
    calculateDate(*this, 1);
    return date;
}

Date& Date::operator-- ()
{
    calculateDate(*this, -1);
    return *this;
}

Date Date::operator-- (int)
{
    Date date(*this);
    calculateDate(*this, -1);
    return date;
}