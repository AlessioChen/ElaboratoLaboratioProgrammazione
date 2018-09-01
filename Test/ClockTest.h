//
// Created by alessio on 01/09/18.
//

#ifndef TIMERAPPLICATION_CLOCKTEST_H
#define TIMERAPPLICATION_CLOCKTEST_H

#include <QtCore/QObject>

class ClockTest: public QObject{
Q_OBJECT
private slots:
    void generateClockTest();

};

#endif //TIMERAPPLICATION_CLOCKTEST_H
