#include <iostream>

#include <QApplication>

#include "timeclass/date.h"
#include "gui/MainWindow.h"
using namespace std;

void test();

int main(int argc, char *argv[])
{
//    test();
    QApplication app(argc, argv);
    Ui::MainWindow ui;
    QMainWindow *w = new QMainWindow;
    ui.setupUi(w);
    w->show();
    return app.exec();
}

void test()
{
    // 构造函数
    Date d1(2021, 2, 29);
    d1.show();
    Date d2;
    d2.show();
    Date::setDefaultValue(1971, 1, 1);
    Date d3;
    d3.show();
    // 运算
    Date d(2020, 5, 26);
    d.show();
    d++;
    d.show();
    --d;
    d.show();
    d = d - 26;
    d.show();
    Date d4(2020, 2, 28);
    d4++;
    d4.show();
    d4++;
    d4.show();
    Date d5(2020, 3, 1);
    d5--;
    d5.show();
    Date d6(2019, 3, 1);
    d6--;
    d6.show();
    Date d7(2020, 5, 26);
    d7 = d7 + 6;
    d7.show();
}
