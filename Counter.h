//
// Created by alessio on 27/08/18.
//

#ifndef TIMERAPPLICATION_COUNTER_H
#define TIMERAPPLICATION_COUNTER_H

#include "QObject"
#include "Subject.h"
#include <list>
#include "Time.h"
#include "Date.h"
#include "QTimer"

class Counter: public Subject, public QObject{

Q_OBJECT
public:
    Counter();

    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;
    Time &getTime();
    Date &getDate();
    Counter &getCounter();

    void setDateFormat(QString &format);
    void setTimeFormat(QString &format);

    ~Counter(){
        for ( auto &i: observers )
            unsubscribe(i);
    }

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
