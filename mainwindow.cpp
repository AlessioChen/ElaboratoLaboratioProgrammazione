#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    //mostra l'orario corrente
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showCurrentTime()));
    timer->start(1000);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showCurrentTime(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->data_label->setText(time_text);

}
