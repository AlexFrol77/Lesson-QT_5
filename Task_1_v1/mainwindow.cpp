#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopWatch = new StopWatch(this);
    ui->pb_circl->setEnabled(false);
    ui->pb_startStop->setCheckable(true);
    connect(ui->pb_startStop, &QPushButton::clicked, this, [this] () {
        if (ui->pb_startStop->isChecked()) {
            ui->pb_circl->setEnabled(true);
            ui->pb_startStop->setText("Стоп");
            stopWatch->startTimer();
        } else {
            ui->pb_circl->setEnabled(false);
            ui->pb_startStop->setText("Старт");
            stopWatch->stopTimer();
        }
    });
    connect(ui->pb_reset, &QPushButton::clicked, stopWatch, &StopWatch::resetTimer);
    connect(ui->pb_reset, &QPushButton::clicked, this, [this] () {ui->tBr_showCircle->clear();});
    connect(stopWatch, &StopWatch::sig_Timer, this, &MainWindow::showTimer);
    connect(ui->pb_circl, &QPushButton::clicked, stopWatch, &StopWatch::memCircle);
    connect(stopWatch, &StopWatch::sig_memCircle, this, &MainWindow::showTimerCircle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTimer(uint min, uint sec, uint Ms)
{
    ui->lb_timerMin->setText(QString::number(min) + " : ");
    ui->lb_timerSec->setText(QString::number(sec) + " : ");
    ui->lb_timerMs->setText(QString::number(Ms));
}

void MainWindow::showTimerCircle(uint minCircle, uint secCircle, uint MsCircle, uint countCircle)
{
    ui->tBr_showCircle->append("Круг: " + QString::number(countCircle) +
                               " Min : " + QString::number(minCircle) +
                               " Sec : " + QString::number(secCircle) +
                               " Ms : " + QString::number(MsCircle));
}
