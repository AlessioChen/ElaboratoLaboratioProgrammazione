//
// Created by alessio on 01/09/18.
//

#include "TimeTest.h"
#include "iostream"

void TimeTest::timeContructorTest(){
    QCOMPARE(time.getHours(), QTime::currentTime().hour());
    QCOMPARE(time.getMinute(), QTime::currentTime().minute());
    QCOMPARE(time.getSecond(), QTime::currentTime().second());

}

void TimeTest::setGetTimeTest(){
    time.setTime(20, 21, 22);
    QVERIFY(time.getSecond() == 20);
    QVERIFY(time.getMinute() == 21);
    QVERIFY(time.getHours() == 22);

}

void TimeTest::controlFormat(){
    std::string format = "hh:mm";
    time.setTimeFormat(format);
    std::string result;
    result = std::to_string(time.getHours()) + ":" + std::to_string(time.getMinute());

    QVERIFY(time.getTimeString() == result);
}

void TimeTest::setWrongTime(){
    time.setTime(80, -50, 40);

    QVERIFY(time.getSecond() == QTime::currentTime().second());
    QVERIFY(time.getMinute() == QTime::currentTime().minute());
    QVERIFY(time.getHours() == QTime::currentTime().hour());

}


