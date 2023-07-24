#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = nullptr);
    ~StopWatch();
signals:
    void sig_Timer(uint, uint, uint);
    void sig_memCircle(uint, uint, uint, uint);
public slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void memCircle();
private:
    QTimer* timer;
    uint16_t min, sec, ms,
    minCircle, secCircle, msCircle, countCircle;
    uint16_t minTemp, secTemp, msTemp;
};

#endif // STOPWATCH_H
