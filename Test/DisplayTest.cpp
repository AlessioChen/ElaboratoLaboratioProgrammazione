//
// Created by alessio on 01/09/18.
//

#include <Counter.h>
#include <QtWidgets/QTimeEdit>
#include <TimerDisplay.h>
#include "DisplayTest.h"
#include "QTest"

void DisplayTest::generateDisplay(){
    TimerDisplay display(new QTimeEdit, new Counter);

    Time time = display.getTime();
    QVERIFY(time.getHours() == 0);
    QVERIFY(time.getMinute() == 0);
    QVERIFY(time.getSecond() == 0);

    QTime t(5, 14, 0);
    display.getTimeEdit()->setTime(t);
    display.updateEditor();

    time = display.getTime();
    QVERIFY(time.getHours() == 5);
    QVERIFY(time.getMinute() == 14);
    QVERIFY(time.getSecond() == 0);

    display.getTimeEdit()->setTime(t);
    display.fromStart();
    display.update();

    time = display.getTime();
    QVERIFY(time.getHours() == 5);
    QVERIFY(time.getMinute() == 13);
    QVERIFY(time.getSecond() == 59);

    display.fromReset();
    time = display.getTime();
    QVERIFY(time.getHours() == 0);
    QVERIFY(time.getMinute() == 0);
    QVERIFY(time.getSecond() == 0);

    display.fromStart();
    display.update();
    QVERIFY(display.isTimeOut() == true);

}
