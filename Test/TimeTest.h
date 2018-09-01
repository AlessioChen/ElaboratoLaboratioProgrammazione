//
// Created by alessio on 01/09/18.
//

#ifndef TIMERAPPLICATION_TIMETEST_H
#define TIMERAPPLICATION_TIMETEST_H

#include "QObject"
#include "QTest"
#include "Time.h"

class TimeTest: public QObject{
Q_OBJECT

private:
    Time time;
private slots:
    void timeContructorTest();
    void setGetTimeTest();
    void controlFormat();
    void setWrongTime();

};

#endif //TIMERAPPLICATION_TIMETEST_H
