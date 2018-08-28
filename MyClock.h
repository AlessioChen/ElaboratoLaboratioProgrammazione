//
// Created by alessio on 28/08/18.
//

#ifndef TIMERAPPLICATION_MYCLOCK_H
#define TIMERAPPLICATION_MYCLOCK_H

#include "QObject"
#include "Observer.h"
#include "QLabel"
#include "QTime"
#include"QComboBox"
#include "Counter.h"

class MyClock: public QObject, public Observer{
Q_OBJECT

public:
    MyClock(Counter *counter, QWidget *parent = nullptr);

    void update() override;
    void attach() override;
    void detach() override;

    Counter *myCounter;

private:
    QComboBox selectDateFormat;
    QComboBox selectTimeFormat;
    QLabel date;
    QLabel time;

private slots:
    void changeFormat();

};

#endif //TIMERAPPLICATION_MYCLOCK_H
