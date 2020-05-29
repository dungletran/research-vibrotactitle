
#include "testingVibroThread.h"

#include "pthread.h"
#include "QByteArray"
#include "QIODevice"

#include "QDebug"//test
#include "QVariant" //test
#include "QByteArray"//test


testingVibroThread::testingVibroThread() : QThread()
{
    //port = new QextSerialPort("COM2");
}

void testingVibroThread::terminate()
{
    QByteArray msg;
    msg.resize(1);
    msg[0]=0;
    qDebug("Vibro is OFF SERVICE!");
    itsPort->write(msg,1);
    itsPort->close();
}


void testingVibroThread::run()
{

    //initialize tactile
    itsPort = new QextSerialPort("COM2");
    itsPort->setBaudRate(BAUD9600);
    itsPort->setFlowControl(FLOW_OFF);
    itsPort->setParity(PAR_NONE);
    itsPort->setDataBits(DATA_8);
    itsPort->setStopBits(STOP_1);
    itsPort->open(QIODevice::WriteOnly);

    mutex.lock();
    //vibrate

    if (itsAxis == 1)
    {
        QByteArray msg;
        msg.resize(1);
        msg[0]=16*(int)(itsStrength*240/16);
        qDebug("Start Testing Vibro Thread at axis 1!");

        qDebug("test");
        QVariant a(msg[0]);
        const char *str;
        QByteArray ba;
        ba = a.toString().toLatin1();
        str = ba.data();
        qDebug(str);


        itsPort->write(msg,1);
        Sleep((int)itsDuration*1000);
        msg[0]=0;
        qDebug("Stop Testing Vibro Thread at axis 1!");
        itsPort->write(msg,1);
    }
    if (itsAxis == 2)
    {
        QByteArray msg;
        msg.resize(1);
        msg[0]=(int)(15*itsStrength);
        qDebug("Start Testing Vibro Thread at axis 2!");

        qDebug("test");
        QVariant a(msg[0]);
        const char *str;
        QByteArray ba;
        ba = a.toString().toLatin1();
        str = ba.data();
        qDebug(str);



        itsPort->write(msg,1);
        Sleep((int)itsDuration*1000);
        msg[0]=0;
        qDebug("Stop Testing Vibro Thread at axis 2!");
        itsPort->write(msg,1);
    }

    /*
    QVariant a(itsDuration);
    const char *str;
    QByteArray ba;
    ba = a.toString().toLatin1();
    str = ba.data();
    qDebug(str);
    */
    itsPort->close();

    mutex.unlock();

    qDebug("Terminating Testing Vibro Thread!");
}

void testingVibroThread::getData(int axis, double strength, double duration)
{
    itsAxis = axis;
    itsStrength = strength;
    itsDuration = duration;
}
