#include "stopwatch.h"

StopWatch::StopWatch(QObject* parent) : QObject{parent}
{
    timer = new QTimer(this);
    min = sec = Ms = countCircle = 0;
    connect(timer, &QTimer::timeout, this, &StopWatch::startTimer);
}

StopWatch::~StopWatch()
{

}

void StopWatch::startTimer()
{
    Ms++;
    if (Ms >= 1000) {
        sec++;
        Ms = 0;
    }
    if (sec >= 60) {
        min++;
        sec = 0;
    }
    timer->start(1);
    emit sig_Timer(min, sec, Ms);
}

void StopWatch::stopTimer()
{
    timer->stop();
    emit sig_Timer(min, sec, Ms);
}

void StopWatch::resetTimer()
{
    min = sec = Ms = countCircle = 0;
    emit sig_Timer(min, sec, Ms);
}

void StopWatch::memCircle()
{
    minCircle = min;
    secCircle = sec;
    MsCircle = Ms;
    countCircle++;
    emit sig_memCircle(minCircle, secCircle, MsCircle, countCircle);
}
