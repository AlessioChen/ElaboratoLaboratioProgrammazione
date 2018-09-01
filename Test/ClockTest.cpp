//
// Created by alessio on 01/09/18.
//

#include <Counter.h>
#include <MyClock.h>
#include "ClockTest.h"
#include "iostream"
#include "QTest"

void ClockTest::generateClockTest(){

    MyClock clock(new Counter);

    QDate currentDate = QDate::currentDate();

    std::string form = "dd-mm-yyyy";
    clock.myCounter->setDateFormat(form);

    clock.update();

    QString date = clock.getDateString();

    std::string day = std::to_string(currentDate.day());
    std::string month = std::to_string(currentDate.month());
    std::string year = std::to_string(currentDate.year());

    std::string left = date.toStdString();
    std::string confront = '0' + day + '-' + '0' + month + '-' + year; //modificare in base al giorno



    QVERIFY(left == confront);

    QTime currentTime = QTime::currentTime();

    form = "hh:mm";
    ( clock.myCounter )->setTimeFormat(form);
    clock.update();
    QString time = clock.getTimeString();

    std::string hou = std::to_string(currentTime.hour());
    std::string min = std::to_string(currentTime.minute());
    std::string sec = std::to_string(currentTime.second());

    if ( currentTime.minute() < 10 )
        min = '0' + min;
    if ( currentTime.second() < 10 )
        sec = '0' + sec;
    if ( currentTime.hour() < 10 )
        hou = '0' + hou;

    left = time.toStdString();
    confront = hou + ':' + min;

    QVERIFY(left == confront);

}
