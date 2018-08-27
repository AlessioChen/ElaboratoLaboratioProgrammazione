//
// Created by alessio on 27/08/18.
//

#ifndef TIMERAPPLICATION_COUNTER_H
#define TIMERAPPLICATION_COUNTER_H

#include "QObject"
#include <list>
#include "Time.h"
#include "Date.h"
#include "QTimer"
#include "Observer.h"

class Counter: public QObject{

Q_OBJECT
public:
    Counter();

    void subscribe(Observer *o);
    void unsubscribe(Observer *o);
    void notify();
    Time &getTime();
    Date &getDate();
    Counter &getCounter();

    void setDateFormat(QString &format);
    void setTimeFormat(QString &format);

    ~Counter(){
        for ( auto &i: observers )
            unsubscribe(i);
        delete date;
        delete time;

    }

    std::string &getStringTime();
    std::string &getStringDate();

public slots:
    void increase();

private:
    Date *date;
    Time *time;
    std::list <Observer *> observers;
    std::string strTime;
    std::string strDate;

};

#endif //TIMERAPPLICATION_COUNTER_H
