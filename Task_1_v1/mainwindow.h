#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showTimer(uint, uint, uint);
    void showTimerCircle(uint, uint, uint, uint);
private:
    Ui::MainWindow *ui;
    StopWatch* stopWatch;
};
#endif // MAINWINDOW_H
