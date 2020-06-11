#ifndef DATE_H
#define DATE_H

class Date
{
protected:
    int day;
    int month;
    int year;
    static int defaultDay;
    static int defaultMonth;
    static int defaultYear;
public:
    static void setDefaultValue(int y, int m, int d);
    static int getDayOfMonth(int y, int m);
    /*
     * isNotLegal - 判断数据是否合法
     * 0 - 合法
     * 1 - 年错误：年 < 0
     * 2 - 月错误：月 < 1
     * 3 - 月错误：月 > 12
     * 4 - 日错误：日 < 1
     * 5 - 日错误：日 > 规定上限
     */
    static int isNotLegal(int y, int m, int d);
    static void calculateDate(Date& date, int d);
    Date();
    Date(int y, int m, int d);
    Date(Date& date);
    int getDay();
    int getMonth();
    int getYear();
    void show();

    Date operator+ (int d);
    Date operator- (int d);
    Date& operator++ ();
    Date operator++ (int);
    Date& operator-- ();
    Date operator-- (int);
};

#endif
