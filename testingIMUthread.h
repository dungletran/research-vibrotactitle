#ifndef TESTINGIMUTHREAD_H
#define TESTINGIMUTHREAD_H

#include <QThread>
#include <QMutex>

#include "MainStructure.h"

class testingIMUthread : public QThread
{
    Q_OBJECT

public:
    testingIMUthread();
    void terminate();
    bool chkTerminate;
    ArmPosture data;
    QMutex mutex;

signals:
    void dataTestingReady();

protected:
    void run();
};




#endif // TESTINGIMUTHREAD_H
