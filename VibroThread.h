#ifndef VIBROTHREAD_H
#define VIBROTHREAD_H

#include <QThread>
#include "MainStructure.h"
#include <qextserialport.h>
#include "QIODevice"

class VibroThread : public QThread
{
    Q_OBJECT

public:
    VibroThread();
    void terminate();
    void intializeThreshold(ThresholdSet threshold, int noLoop);
    void getCalData(showSet CalDataSet);

protected:
    void run();
    ThresholdSet itsThreshold;
    int itsNoLoop;
    showSet itsCalDataSet;
    bool chkTerminate;
    QextSerialPort *itsPort;
signals:
    void finishMapping();
    void finishMappingHand1();
    void finishMappingHand2();
    void finishMappingElbow1();
    void finishMappingElbow2();

};

#endif // VIBROTHREAD_H
