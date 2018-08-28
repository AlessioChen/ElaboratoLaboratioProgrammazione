//
// Created by alessio on 28/08/18.
//

#include "TimerDisplay.h"

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
        if ( thisTime.getSecond() > 0 )
            thisTime.setSecond(thisTime.getSecond() - 1);
        else if ( thisTime.getMinute() > 0 ) {
            thisTime.setMinute(thisTime.getMinute() - 1);
            thisTime.setSecond(59);
        } else if ( thisTime.getHours() > 0 ) {
            thisTime.setHours(thisTime.getHours() - 1);
            thisTime.setMinute(59);
            thisTime.setSecond(59);
        }

    }

    text = QString::fromStdString(thisTime.getTimeString());
    display(text);

    if ( thisTime.getHours() == 0 && thisTime.getMinute() == 0 && thisTime.getSecond() == 0 )
        timeOut();

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
    QTime time = editor->time();
    QString form = "hh:mm:ss";

    thisTime.setHours(time.hour());
    thisTime.setMinute(time.minute());
    thisTime.setSecond(time.second());

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

}


