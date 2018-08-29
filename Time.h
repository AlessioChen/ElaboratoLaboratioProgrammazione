//
// Created by alessio on 26/08/18.
//

#ifndef TIMERAPPLICATION_TIME_H
#define TIMERAPPLICATION_TIME_H

#include "QString"

class Time{

public:
    Time();
    void setTime(int s, int m, int h);

    void setSecond(int second);
    void setMinute(int minute);
    void setHours(int hours);
    void setTimeFormat(const std::string &timeFormat);

    int getSecond() const;
    int getMinute() const;
    int getHours() const;
    QString &getTimeFormat();
    std::string &getTimeString();

    const Time &getTime();

private:
    int second;
    int minute;
    int hour;
    std::string timeFormat;
    std::string timeString;

};

#endif //TIMERAPPLICATION_TIME_H
