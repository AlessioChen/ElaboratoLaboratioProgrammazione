//
// Created by alessio on 01/09/18.
//

#ifndef TIMERAPPLICATION_DATETEST_H
#define TIMERAPPLICATION_DATETEST_H

#include <QtCore/QObject>
#include <Date.h>
#include <QTest>

class DateTest: public QObject{
Q_OBJECT
private:
    Date date;
private slots:
    void dateConstructorTest();
    void setDateTest();
    void setWrong();

};

#endif //TIMERAPPLICATION_DATETEST_H
