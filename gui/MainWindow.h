#ifndef CPPPROJECTJL2476_H
#define CPPPROJECTJL2476_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "DigitalTime.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow: public QObject
{
    Q_OBJECT // 在类中使用信号/槽时一定要加Q_OBJECT宏

private:
    MyTime* dateAndTime;
    int displayYear; // 日历显示中的年和月
    int displayMonth;

public:
    QWidget *centralwidget;
    DigitalTime *TimeWidget;
    QWidget *gridLayoutWidget;
    /// Date
    QGridLayout *gridLayout;
    QLabel *label[6][7];
    /// week
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Mon;
    QLabel *label_Tue;
    QLabel *label_Wed;
    QLabel *label_Thu;
    QLabel *label_Fri;
    QLabel *label_Sat;
    QLabel *label_Sun;
    /// other
    QPushButton *button_prev;
    QPushButton *button_next;
    QLabel *label_Date;
    QLabel *label_Signature;

    void initialTime();
    void startTime();
    void initBtn(QMainWindow *MainWindow);
    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);
    void setCalendar(int y, int m, int d = 0);

private slots: // 信号槽函数
    void lastMonth();
    void nextMonth();
    void updateTime();
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CPPPROJECTJL2476_H