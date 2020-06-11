#include "MainWindow.h"

#include <string>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QPushButton>

void Ui_MainWindow::initialTime()
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    dateAndTime = new MyTime(date.year(), date.month(), date.day(),
            time.hour(), time.minute(), time.second());
//    dateAndTime = new MyTime(date.year(), date.month(), date.day(),
//                             23, 59, 50);
    displayMonth = date.month();
    displayYear = date.year();
}

void Ui_MainWindow::startTime()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ui_MainWindow::updateTime);
    timer->start(1000);
}

void Ui_MainWindow::updateTime()
{
    TimeWidget->showTime(dateAndTime);
    int tmpDay = dateAndTime->getDay();
    (*dateAndTime)++;
    if (tmpDay != dateAndTime->getDay())
        setCalendar(dateAndTime->getYear(), dateAndTime->getMonth(),
                    dateAndTime->getDay());
    dateAndTime->outputTime();
}

void Ui_MainWindow::initBtn(QMainWindow *MainWindow)
{
    // sender&receiver都需要是QObject
//    connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
    connect(button_prev, SIGNAL(clicked()), this, SLOT(lastMonth()));
    connect(button_next, SIGNAL(clicked()), this, SLOT(nextMonth()));
}


void Ui_MainWindow::setupUi(QMainWindow *MainWindow)
{
    /// 获得时间
    initialTime();
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(575, 478);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));

        /// 数字时钟
        TimeWidget = new DigitalTime(centralwidget);
        TimeWidget->setObjectName(QStringLiteral("TimeWidget"));
        TimeWidget->setGeometry(QRect(340, 10, 201, 61));

        /// 日历部分
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 150, 481, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setSpacing(0);

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                label[i][j] = new QLabel(gridLayoutWidget);
//                std::string labelName = "label_" + std::to_string(i) + std::to_string(i);
//                label[i][j]->setObjectName(QStringLiteral(labelName.c_str()));
                label[i][j]->setStyleSheet("border:1px solid black;");

                gridLayout->addWidget(label[i][j], i, j, 1, 1);
            }
        }

        /// 星期几标识
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 120, 481, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        label_Mon = new QLabel(horizontalLayoutWidget);
        label_Mon->setObjectName(QStringLiteral("label_Mon"));

        horizontalLayout->addWidget(label_Mon, 0, Qt::AlignHCenter);

        label_Tue = new QLabel(horizontalLayoutWidget);
        label_Tue->setObjectName(QStringLiteral("label_Tue"));

        horizontalLayout->addWidget(label_Tue, 0, Qt::AlignHCenter);

        label_Wed = new QLabel(horizontalLayoutWidget);
        label_Wed->setObjectName(QStringLiteral("label_Wed"));

        horizontalLayout->addWidget(label_Wed, 0, Qt::AlignHCenter);

        label_Thu = new QLabel(horizontalLayoutWidget);
        label_Thu->setObjectName(QStringLiteral("label_Thu"));

        horizontalLayout->addWidget(label_Thu, 0, Qt::AlignHCenter);

        label_Fri = new QLabel(horizontalLayoutWidget);
        label_Fri->setObjectName(QStringLiteral("label_Fri"));

        horizontalLayout->addWidget(label_Fri, 0, Qt::AlignHCenter);

        label_Sat = new QLabel(horizontalLayoutWidget);
        label_Sat->setObjectName(QStringLiteral("label_Sat"));

        horizontalLayout->addWidget(label_Sat, 0, Qt::AlignHCenter);

        label_Sun = new QLabel(horizontalLayoutWidget);
        label_Sun->setObjectName(QStringLiteral("label_Sun"));

        horizontalLayout->addWidget(label_Sun, 0, Qt::AlignHCenter);

        button_prev = new QPushButton(centralwidget);
        button_prev->setObjectName(QStringLiteral("button_prev"));
        button_prev->setGeometry(QRect(50, 80, 71, 32));
        button_next = new QPushButton(centralwidget);
        button_next->setObjectName(QStringLiteral("button_next"));
        button_next->setGeometry(QRect(472, 80, 71, 32));
        label_Signature = new QLabel(centralwidget);
        label_Signature->setObjectName(QStringLiteral("label_Signature"));
        label_Signature->setGeometry(QRect(50, 20, 161, 31));
        label_Date = new QLabel(centralwidget);
        label_Date->setObjectName(QStringLiteral("label_Date"));
        label_Date->setGeometry(QRect(260, 70, 71, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        /// 初始化日历 —— 一定要放后面
        setCalendar(dateAndTime->getYear(), dateAndTime->getMonth(),
                        dateAndTime->getDay());

        QMetaObject::connectSlotsByName(MainWindow);
        initBtn(MainWindow); // 需要在实例化后面
    } // setupUi
    startTime(); /// 最后开启时间
}


void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Date&Time", Q_NULLPTR));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
            label[i][j]->setText(QApplication::translate("MainWindow", "", Q_NULLPTR));
    }
    label_Mon->setText(QApplication::translate("MainWindow", "\345\221\250\346\227\245", Q_NULLPTR));
    label_Tue->setText(QApplication::translate("MainWindow", "\345\221\250\344\270\200", Q_NULLPTR));
    label_Wed->setText(QApplication::translate("MainWindow", "\345\221\250\344\272\214", Q_NULLPTR));
    label_Thu->setText(QApplication::translate("MainWindow", "\345\221\250\344\270\211", Q_NULLPTR));
    label_Fri->setText(QApplication::translate("MainWindow", "\345\221\250\345\233\233", Q_NULLPTR));
    label_Sat->setText(QApplication::translate("MainWindow", "\345\221\250\344\272\224", Q_NULLPTR));
    label_Sun->setText(QApplication::translate("MainWindow", "\345\221\250\345\205\255", Q_NULLPTR));

    /// button
    button_prev->setText(QApplication::translate("MainWindow", "\344\270\212\346\234\210", Q_NULLPTR));
    button_next->setText(QApplication::translate("MainWindow", "\344\270\213\346\234\210", Q_NULLPTR));

    /// signature
    label_Signature->setText(QApplication::translate("MainWindow", "by winds-\350\275\257\344\273\266zy1801\346\233\271\346\265\252", Q_NULLPTR));
    /// date
    label_Date->setText(QApplication::translate("MainWindow", "     \345\271\264   \346\234\210", Q_NULLPTR));
} // retranslateUi


// 手写itoa
void itoa(int n, char* str)
{
    if (n < 10)
    {
        str[0] = n + '0';
        str[1] = 0;
        return;
    }
    else
    {
        str[0] = n / 10 + '0';
        str[1] = n % 10 + '0';
        str[2] = 0;
        return;
    }
}

void Ui_MainWindow::setCalendar(int y, int m, int d)
{
    // 先情空
    for (int i = 0; i < 42; i++)
    {
        label[0][i]->setStyleSheet("border:1px solid black;");
        label[0][i]->setText(QApplication::translate("MainWindow", "", Q_NULLPTR));
    }
    // 今年&今月
    std::string yearAndMonth = std::to_string(y) + "\345\271\264" +
            std::to_string(m) + "\346\234\210";
    label_Date->setText(yearAndMonth.c_str());
    int w = MyTime::calculateWeek(y, m, 1);
    // 计算日历的开始位置，注意日历星期天在第一个
    // 星期天-数组0，星期1-数组1
    int days = MyTime::getDayOfMonth(y, m);
    for (int i = 0; i < days; i++)
    {
        char dayLabel[3];
        itoa(i + 1, dayLabel);
        label[0][i + w]->setText(QApplication::translate("MainWindow", dayLabel, Q_NULLPTR));
        label[0][i + w]->setAlignment(Qt::AlignCenter);
        // 今日
        if (d != 0 && d == i + 1)
            label[0][i + w]->setStyleSheet("color:red; border:1px solid black;");
    }
}

void Ui_MainWindow::lastMonth()
{
    if (displayMonth == 1)
    {
        displayYear--;
        displayMonth = 12;
    }
    else
        displayMonth--;
    if (displayMonth == dateAndTime->getMonth() && displayYear == dateAndTime->getYear()) // 最初日历界面
    {
        setCalendar(dateAndTime->getYear(), dateAndTime->getMonth(),
                    dateAndTime->getDay());
        return;
    }
    printf("%d %d\n", displayYear, displayMonth);
    setCalendar(displayYear, displayMonth); // 不用第三个参数就不会标明日期
}

void Ui_MainWindow::nextMonth()
{
    if (displayMonth == 12)
    {
        displayYear++;
        displayMonth = 1;
    }
    else
        displayMonth++;
    if (displayMonth == dateAndTime->getMonth() && displayYear == dateAndTime->getYear()) // 最初日历界面
    {
        setCalendar(dateAndTime->getYear(), dateAndTime->getMonth(),
                    dateAndTime->getDay());
        return;
    }
    printf("%d %d\n", displayYear, displayMonth);
    setCalendar(displayYear, displayMonth); // 不用第三个参数就不会标明日期
}