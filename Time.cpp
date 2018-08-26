//
// Created by alessio on 26/08/18.
//

#include "Time.h"
#include "QTime"

Time::Time(){
    hour = QTime::currentTime().hour();
    minute = QTime::currentTime().minute();
    second = QTime::currentTime().second();
}

void Time::setTime(int s, int m, int h){
    if ( h < 0 || h > 23 )
        hour = QTime::currentTime().hour();
    else
        hour = h;

    if ( m < 0 || m > 59 )
        minute = QTime::currentTime().minute();
    else
        minute = m;

    if ( s < 0 || s > 59 )
        second = QTime::currentTime().second();
    else
        second = s;

}

void Time::setSecond(int s){
    if ( s < 0 || s > 59 )
        second = s;
    else
        second = QTime::currentTime().second();
}

void Time::setMinute(int m){
    if ( m < 0 || m > 59 )
        minute = QTime::currentTime().minute();
    else
        minute = m;
}

void Time::setHours(int h){
    if ( h < 0 || h > 23 )
        hour = QTime::currentTime().hour();
    else
        hour = h;

}

void Time::setTimeFormat(const QString &timeFormat){
    Time::timeFormat = timeFormat;
}

int Time::getSecond() const{
    return second;
}

int Time::getMinute() const{
    return minute;
}

int Time::getHours() const{
    return hour;
}

QString &Time::getTimeFormat(){
    return timeFormat;
}

std::string &Time::getTimeString(){
    std::string sec = std::to_string(second);
    if ( second < 10 )
        sec = '0' + std::to_string(second);

    std::string min = std::to_string(minute);
    if ( minute < 10 )
        min = '0' + std::to_string(minute);

    std::string h = std::to_string(hour);
    if ( hour < 10 )
        h = '0' + std::to_string(hour);

    if ( timeFormat == "hh::mm::ss" )
        timeString = h + ":" + min + ":" + sec;

    if ( timeFormat == "hh::mm" )
        timeString = h + ":" + min;

    return timeString;

}

const Time &Time::getTime(){
    return *this;
}


