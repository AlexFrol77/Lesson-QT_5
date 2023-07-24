#include "stopwatch.h"

StopWatch::StopWatch(QObject* parent) : QObject{parent}
{
    timer = new QTimer(this);
    min = sec = ms = minCircle = secCircle = msCircle = countCircle = 0;
    minTemp = secTemp = msTemp = 0;
    connect(timer, &QTimer::timeout, this, &StopWatch::startTimer);
}

StopWatch::~StopWatch()
{

}

void StopWatch::startTimer()
{
    ms++;
    if (ms >= 1000) {
        sec++;
        ms = 0;
    }
    if (sec >= 60) {
        min++;
        sec = 0;
    }
    timer->start(1);
    emit sig_Timer(min, sec, ms);
}

void StopWatch::stopTimer()
{
    timer->stop();
    emit sig_Timer(min, sec, ms);
}

void StopWatch::resetTimer()
{
    min = sec = ms = countCircle = 0;
    minCircle = secCircle = msCircle = 0;
    emit sig_Timer(min, sec, ms);
}

void StopWatch::memCircle()
{
    minTemp = min - minCircle;
    secTemp = sec - secCircle;
    if (ms < msCircle) {
        uint temp = ms + 1000;
        msTemp = temp - msCircle;
        secTemp -= 1;
    } else {
        msTemp = ms - msCircle;
    }
    countCircle++;
    emit sig_memCircle(minTemp, secTemp, msTemp, countCircle);
    minCircle = min;
    secCircle = sec;
    msCircle = ms;
}
