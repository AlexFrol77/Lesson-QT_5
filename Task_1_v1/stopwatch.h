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
    uint min, sec, Ms,
    minCircle, secCircle, MsCircle, countCircle;
};

#endif // STOPWATCH_H
