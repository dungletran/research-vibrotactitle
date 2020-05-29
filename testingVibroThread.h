#ifndef TESTINGVIBROTHREAD_H
#define TESTINGVIBROTHREAD_H

#include <QThread>
#include <QMutex>
#include "qextserialport.h"

#include "MainStructure.h"

class testingVibroThread : public QThread
{
    Q_OBJECT

public:
    testingVibroThread();
    void getData(int axis,double strength,double duration);
    void terminate();
    QextSerialPort *itsPort;

    QMutex mutex;

protected:
    void run();
    int  itsAxis;
    double itsStrength,itsDuration;
};

#endif // TESTINGVIBROTHREAD_H
