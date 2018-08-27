//
// Created by alessio on 27/08/18.
//

#include "Counter.h"

Counter::Counter(){
    date = new Date();
    time = new Time();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(increase()));
    timer->start(1000);
    increase();
}

void Counter::increase(){
    if ( time->getSecond() < 59 )
        time->setSecond(time->getSecond() + 1);
    else {
        time->setSecond(0);
        if ( time->getMinute() < 59 )
            time->setMinute(time->getMinute() + 1);
        else {
            time->setMinute(0);
            if ( time->getHours() < 23 )
                time->setHours(time->getHours() + 1);
            else {
                time->setHours(0);
                date->setDay(date->getDay() + 1);
            }

        }
    }
    notify();
}

void Counter::subscribe(Observer *o){
    observers.push_back(o);

}

void Counter::unsubscribe(Observer *o){
    observers.remove(o);
}

void Counter::notify(){
    for ( auto &i: observers )
        i->update();
}

Time &Counter::getTime(){
    return *time;
}

Date &Counter::getDate(){
    return *date;
}

Counter &Counter::getCounter(){
    return *this;

}

void Counter::setDateFormat(QString &format){
    date->setFormat(format);

}

void Counter::setTimeFormat(QString &format){
    time->setTimeFormat(format);

}

std::string &Counter::getStringDate(){
    std::string day = std::to_string(date->getDay());
    if ( date->getDay() < 10 )
        day = '0' + std::to_string(date->getDay());

    std::string month = std::to_string(date->getMonth());
    if ( date->getMonth() < 10 )
        month = '0' + std::to_string(date->getMonth());

    if ( date->getDateFormat() == "day-month-year" )
        strDate = date->getdayof() + " " + date->getMonthOf() + " " + std::to_string(date->getYear());
    if ( getStringDate() == "dd-mm-yyyy" )
        strDate = day + "-" + month + "-" + std::to_string(date->getYear());
    if ( date->getDateFormat() == "mm-dd-yyyy" )
        strDate = month + "-" + day + "-" + std::to_string(date->getYear());

    return strDate;
}

std::string &Counter::getStringTime(){
    return time->getTimeString();
}



