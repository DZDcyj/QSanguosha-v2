#ifndef _TIMED_PROGRESS_BAR_H
#define _TIMED_PROGRESS_BAR_H

class TimedProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    inline TimedProgressBar()
        : m_hasTimer(false), m_autoHide(false), m_timer(0),
        m_step(0), m_max(0), m_val(0)
    {
        this->setTextVisible(false);
    }
    inline void setTimerEnabled(bool enabled)
    {
        m_mutex.lock();
        m_hasTimer = enabled;
        m_mutex.unlock();
    }
    inline void setCountdown(time_t maximum, time_t startVal = 0)
    {
        m_mutex.lock();
        m_max = maximum;
        m_val = startVal;
        m_mutex.unlock();
    }
    inline void setAutoHide(bool enabled)
    {
        m_autoHide = enabled;
    }
    inline void setUpdateInterval(time_t step)
    {
        m_step = step;
    }
    virtual void show();
    virtual void hide();

signals:
    void timedOut();

protected:
    virtual void timerEvent(QTimerEvent *);
    bool m_hasTimer;
    bool m_autoHide;
    int m_timer;
    time_t m_step, m_max, m_val;
    QRecursiveMutex m_mutex;
};

#include "protocol.h"

class QSanCommandProgressBar : public TimedProgressBar
{
    Q_OBJECT

public:
    QSanCommandProgressBar();
    inline void setInstanceType(QSanProtocol::ProcessInstanceType type)
    {
        m_instanceType = type;
    }
    void setCountdown(QSanProtocol::CommandType command);
    void setCountdown(QSanProtocol::Countdown countdown);

protected:
    virtual void paintEvent(QPaintEvent *);
    QSanProtocol::ProcessInstanceType m_instanceType;
};

#endif

