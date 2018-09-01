//
// Created by alessio on 01/09/18.
//

#include "DateTest.h"

void DateTest::dateConstructorTest(){
    QCOMPARE(date.getDay(), QDate::currentDate().day());
    QCOMPARE(date.getMonth(), QDate::currentDate().month());
    QCOMPARE(date.getYear(), QDate::currentDate().year());

}

void DateTest::setDateTest(){
    date.setDate(1, 9, 2018);

    QVERIFY(date.getYear() == 2018);
    QVERIFY(date.getMonth() == 9);
    QVERIFY(date.getDay() == 1);
    QVERIFY(date.getLeapYear() == false);
    QVERIFY(date.getMonthOf() == "settembre");
    QVERIFY(date.getdayof() == "sabato");

}

void DateTest::setWrong(){

    date.setDate(29, 2, 2014);
    QVERIFY(date.getDay() == QDate::currentDate().day());
    QVERIFY(date.getMonth() == 2);

    date.setDate(40, 5, 2022);
    QVERIFY(date.getDay() == QDate::currentDate().day());
    QVERIFY(date.getMonth() == 5);

    date.setDate(10, 30, -1000);
    QVERIFY(date.getMonth() == QDate::currentDate().month());
    QVERIFY(date.getYear() == QDate::currentDate().year());

}
