#include "USBConnector.h"

#include <QString>
#include <QVariant>
#include <QStringList>
#include "pthread.h"
#include "QDebug" //test

USBConnector::USBConnector(){}

USBConnector::~USBConnector(){}



bool USBConnector::ConnectToServer()
{
    tcpSocket = new QTcpSocket();

    tcpSocket->abort();
    tcpSocket->connectToHost("127.0.0.1",9091);
    QString string1 = "OPN";
    char    buf[512];
    tcpSocket->write(string1.toAscii());
    tcpSocket->waitForBytesWritten();
    tcpSocket->waitForReadyRead(-1);
    qint64 n=0;
    n=tcpSocket->read(buf,512);
    if (n!=0)
    {
        buf[n] = 0;
        return true;
    }

    return false;
}


ArmPosture USBConnector::GetDataFromServer()
{
    ArmPosture ArmOrientation;
    QString tmp="";
    QString string2 = "REQ";
    tcpSocket->write(string2.toAscii());
    tcpSocket->waitForBytesWritten();
    tcpSocket->waitForReadyRead(-1);
    qint64 n=0;
    char buf[512];
    if ((n=tcpSocket->read(buf,512))!=0)
    {
        buf[n] = 0;
        tmp.append(buf);
    }
    QString data(buf);
    QStringList listData = data.split(",");

    QVariant data1Yaw(listData[1]);
    QVariant data2Yaw(listData[5]);
    ArmOrientation.ForearmYaw=data2Yaw.toDouble();
    ArmOrientation.UparmYaw=data1Yaw.toDouble();

    QVariant data1Pitch(listData[2]);
    QVariant data2Pitch(listData[6]);
    ArmOrientation.ForearmPitch=data2Pitch.toDouble();
    ArmOrientation.UparmPitch=data1Pitch.toDouble();

    QVariant data1Roll(listData[3]);
    QVariant data2Roll(listData[7]);
    ArmOrientation.ForearmRoll=data2Roll.toDouble();
    ArmOrientation.UparmRoll=data1Roll.toDouble();

    return ArmOrientation;
}

ArmPosture USBConnector::GetCalDataFromServer(ArmPosture IMUoffset)
{
    ArmPosture ArmOrientation;
    QString tmp="";
    QString string2 = "REQ";
    tcpSocket->write(string2.toAscii());
    tcpSocket->waitForBytesWritten();
    tcpSocket->waitForReadyRead(-1);
    qint64 n=0;
    char buf[512];
    if ((n=tcpSocket->read(buf,512))!=0)
    {
        buf[n] = 0;
        tmp.append(buf);
    }
    QString data(buf);
    QStringList listData = data.split(",");

    QVariant data1Yaw(listData[1]);
    QVariant data2Yaw(listData[5]);
    ArmOrientation.ForearmYaw=data2Yaw.toDouble()-IMUoffset.ForearmYaw;
    ArmOrientation.UparmYaw=data1Yaw.toDouble()-IMUoffset.UparmYaw;

    QVariant data1Pitch(listData[2]);
    QVariant data2Pitch(listData[6]);
    ArmOrientation.ForearmPitch=data2Pitch.toDouble()-IMUoffset.ForearmPitch;
    ArmOrientation.UparmPitch=data1Pitch.toDouble()-IMUoffset.UparmPitch;

    QVariant data1Roll(listData[3]);
    QVariant data2Roll(listData[7]);
    ArmOrientation.ForearmRoll=data2Roll.toDouble()-IMUoffset.ForearmRoll;
    ArmOrientation.UparmRoll=data1Roll.toDouble()-IMUoffset.UparmRoll;

    return ArmOrientation;
}






bool USBConnector::DisconnectToServer()
{
    QString string3 = "CLE";
    char buf[512];
    tcpSocket->write(string3.toAscii());
    tcpSocket->waitForBytesWritten();
    tcpSocket->waitForReadyRead(-1);
    qint64 n=0;
    if ((n=tcpSocket->read(buf,512))!=0)
    {
        buf[n] = 0;
        return true;
    }
    return false;
}


