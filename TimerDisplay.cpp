//
// Created by alessio on 28/08/18.
//

#include "TimerDisplay.h"
#include "iostream"

TimerDisplay::TimerDisplay(QTimeEdit *editor, Counter *counter, QWidget *parent) : QLCDNumber(parent){
    setGeometry(20, 240, 420, 140);

    this->editor = editor;
    this->setDigitCount(9);

    myCounter = counter;
    attach();
    updateEditor();

    allowTimeOut = false;
}

void TimerDisplay::update(){

    if ( active ) {
        int s = thisTime.getSecond();
        int m = thisTime.getMinute();
        int h = thisTime.getHours();

        if ( s > 0 )
            thisTime.setSecond(s - 1);
        else if ( m > 0 ) {
            thisTime.setMinute(m - 1);
            thisTime.setSecond(59);
        } else if ( h > 0 ) {
            thisTime.setHours(h - 1);
            thisTime.setMinute(59);
            thisTime.setSecond(59);
        }
        //  std::cerr << thisTime.getSecond()<< " "<<thisTime.getMinute()<<" "<<thisTime.getHours()<<std::endl;

        text = QString::fromStdString(thisTime.getTimeString());

        display(text);

        if ( thisTime.getHours() == 0 && thisTime.getMinute() == 0 && thisTime.getSecond() == 0 )
            timeOut();
    }
}

void TimerDisplay::attach(){
    myCounter->subscribe(this);

}

void TimerDisplay::detach(){
    myCounter->unsubscribe(this);

}

Time &TimerDisplay::getTime(){
    return thisTime;
}

void TimerDisplay::updateEditor(){
    QTime t = editor->time();
    std::string form = "hh:mm:ss";

    thisTime.setHours(t.hour());
    thisTime.setMinute(t.minute());
    thisTime.setSecond(t.second());

    thisTime.setTimeFormat(form);

    text = QString::fromStdString(thisTime.getTimeString());
    display(text);

    editor->setTime(QTime(0, 0, 0));

}

void TimerDisplay::timeOut(){
    active = false;
    if ( allowTimeOut ) {
        changeColor();
        callTimeOut();
    }

}

void TimerDisplay::fromStart(){
    if ( !active && !allowTimeOut ) {
        color.setColor(QPalette::Active, QPalette::WindowText, QColor(0, 0, 0));
        this->setPalette(color);
        active = true;
        allowTimeOut = true;
        if ( !paused )
            updateEditor();

        paused = false;
    }

}

void TimerDisplay::fromStop(){
    if ( active ) {
        active = false;
        paused = true;
        allowTimeOut = false;
    }

}

void TimerDisplay::fromReset(){
    active = false;
    paused = false;
    allowTimeOut = false;
    thisTime.setTime(0, 0, 0);
    editor->setTime(QTime(0, 0, 0));
    text = QString::fromStdString(thisTime.getTimeString());
    display(text);
    hideTimeOut();

}

void TimerDisplay::changeColor(){
    color.setColor(QPalette::Active, QPalette::WindowText, QColor(255, 0, 0));
    this->setPalette(color);

}

QTimeEdit *TimerDisplay::getTimeEdit(){
    return editor;
}


