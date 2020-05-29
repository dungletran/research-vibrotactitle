#ifndef DATACALCULATINGTHREAD_H
#define DATACALCULATINGTHREAD_H

#include <QThread>
#include <QMutex>

#include "MainStructure.h"

class DataCalculatingThread : public QThread
{
    Q_OBJECT

public:
    DataCalculatingThread();
    void terminate();
    //void getMasterData(ArmPosture data1, ArmLength data2);
    void getMainData(QString startDate, QString startTime, QString postIndex, QString candidateNumber, ArmPosture MasterPostureData, ArmLength ArmLengths,ArmPosture IMUoffset, QString ExpType);
    bool chkTerminate;
    showSet data;
    QString itsStartDate;
    QString itsStartTime;
    QString itsPostIndex;
    QString itsCandidateNumber;
    ArmPosture itsMasterPostureData;
    ArmPosture itsIMUoffset;
    QString itsExpType;
    ArmLength   itsArmLengths;
    QMutex mutex;
signals:
    void dataReady();

protected:
    void run();
};

#endif // DATACALCULATINGTHREAD_H
