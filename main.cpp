
#include <QApplication>
#include <QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include "mainwindow.h"
#include "Counter.h"
#include "MyClock.h"
#include "TimerDisplay.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    Counter contatore;

    MainWindow *window = new MainWindow;
    window->setGeometry(500, 200, 650, 450);

    QColor green(0, 170, 0);
    QColor red(255, 0, 0);
    QPalette color;


    //bottone di start
    QPushButton start("start", window);
    start.setGeometry(20, 150, 120, 50);
    QFont font = start.font();
    font.setPointSize(15);
    color.setColor(QPalette::Active, QPalette::ButtonText, green);
    start.setPalette(color);

    //bottone di stop
    QPushButton stop("stop", window);
    stop.setGeometry(320, 150, 120, 50);
    font = stop.font();
    font.setPointSize(15);

    color.setColor(QPalette::Active, QPalette::ButtonText, red);
    stop.setPalette(color);

    //bottone di reset
    QPushButton reset("reset", window);
    reset.setGeometry(140, 200, 180, 50);
    font = reset.font();
    font.setPointSize(15);


    //editor per il tempo
    QTimeEdit editor(window);
    editor.setGeometry(140, 150, 180, 50);
    editor.setAlignment(Qt::AlignCenter);
    font = editor.font();
    font.setPointSize(15);

    //display del tempo
    MyClock current_time(&contatore, window);
    TimerDisplay timer(&editor, &contatore, window);
    timer.setGeometry(20, 260, 420, 140);

    //scritta fine timer
    QLabel timeout("TIME OUT!!", window);
    timeout.setGeometry(350, 210, 160, 50);
    timeout.setAlignment(Qt::AlignCenter);
    color.setColor(QPalette::Active, QPalette::WindowText, red);
    timeout.setPalette(color);
    timeout.setVisible(false);


    //connessioni
    TimerDisplay::connect(&timer, SIGNAL(callTimeOut()), &timeout, SLOT(show()));
    TimerDisplay::connect(&timer, SIGNAL(hideTimeOut()), &timeout, SLOT(hide()));

    QPushButton::connect(&start, SIGNAL(clicked()), &timer, SLOT(fromStart()));
    QPushButton::connect(&stop, SIGNAL(clicked()), &timer, SLOT(fromStop()));
    QPushButton::connect(&reset, SIGNAL(clicked()), &timer, SLOT(fromReset()));

    app.setActiveWindow(window);
    window->show();

    return app.exec();

}