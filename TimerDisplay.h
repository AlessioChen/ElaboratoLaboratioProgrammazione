//
// Created by alessio on 28/08/18.
//

#ifndef TIMERAPPLICATION_TIMERDISPLAY_H
#define TIMERAPPLICATION_TIMERDISPLAY_H

#include <QtCore/QObject>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QLCDNumber>
#include "Observer.h"
#include "Counter.h"

class TimerDisplay: public QLCDNumber, public Observer{

Q_OBJECT
public:
    TimerDisplay(QTimeEdit *editor, Counter *counter, QWidget *parent = nullptr);

    void update() override;
    void attach() override;
    void detach() override;

    Time &getTime();

    void updateEditor();
    bool isTimeOut();
    QTimeEdit *getTimeEdit();

private:
    bool active;
    bool paused;
    bool allowTimeOut;
    QTimeEdit *editor;

    QString text;
    QPalette color;
    Counter *myCounter;
    Time thisTime;
    void timeOut();
signals:
    void callTimeOut();
    void hideTimeOut();
public slots:
    void fromStart();
    void fromStop();
    void fromReset();

private slots:
    void changeColor();

};

#endif //TIMERAPPLICATION_TIMERDISPLAY_H
