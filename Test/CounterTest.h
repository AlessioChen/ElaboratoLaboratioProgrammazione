//
// Created by alessio on 01/09/18.
//

#ifndef TIMERAPPLICATION_COUNTERTEST_H
#define TIMERAPPLICATION_COUNTERTEST_H

#include <QtCore/QObject>
#include <Counter.h>

class CounterTest: public QObject{
Q_OBJECT
private:
    Counter counter;

private slots:
    void generateCounterTest();

};

#endif //TIMERAPPLICATION_COUNTERTEST_H
