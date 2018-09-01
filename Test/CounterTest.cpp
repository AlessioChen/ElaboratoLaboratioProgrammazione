//
// Created by alessio on 01/09/18.
//

#include "QTime"
#include "QTest"
#include "CounterTest.h"

void CounterTest::generateCounterTest(){

    if ( QTime::currentTime().second() != 59 )
        QVERIFY(counter.getTime().getSecond() == QTime::currentTime().second() + 1);
    else {
        QVERIFY(counter.getTime().getMinute() == QTime::currentTime().minute() + 1);
    }
    //con quel +1 viene già testata la funzione increase

    counter.getDate().setDate(1, 9, 2018);
    std::string form = "dd-mm-yyyy";
    counter.setDateFormat(form);
    QVERIFY(counter.getStringDate() == "01-09-2018");

    form = "mm-dd-yyyy";
    counter.setDateFormat(form);
    QVERIFY(counter.getStringDate() == "09-01-2018");

}
