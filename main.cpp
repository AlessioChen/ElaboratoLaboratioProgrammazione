
#include <QApplication>
#include <QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include "mainwindow.h"
#include "Counter.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    MainWindow *window = new MainWindow;
    window->setGeometry(500, 200, 650, 450);

    Counter contatore;


    //bottone di start
    QPushButton start("start", window);
    start.setGeometry(20, 150, 120, 50);
    QFont font = start.font();
    font.setPointSize(15);

    //bottone di stop
    QPushButton stop("stop", window);
    stop.setGeometry(320, 150, 120, 50);
    font = stop.font();
    font.setPointSize(15);


    //editor per il tempo
    QTimeEdit editor(window);
    editor.setGeometry(140, 150, 180, 50);
    editor.setAlignment(Qt::AlignCenter);
    font = editor.font();
    font.setPointSize(15);

    window->show();

    return app.exec();

}