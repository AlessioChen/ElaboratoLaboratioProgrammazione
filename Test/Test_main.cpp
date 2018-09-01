//
// Created by alessio on 01/09/18.
//

#include "TimeTest.h"
#include "DateTest.h"
#include "DisplayTest.h"
#include "ClockTest.h"
#include "CounterTest.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    TimeTest test1;
    DateTest test2;
    DisplayTest test3;
    CounterTest test4;
    ClockTest test5;

    QTest::qExec(&test1);
    QTest::qExec(&test2);
    QTest::qExec(&test3);
    QTest::qExec(&test4);
    QTest::qExec(&test5);

}