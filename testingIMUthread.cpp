#include "testingIMUthread.h"

#include "USBConnector.h"
#include "QDebug" //test
#include "pthread.h" //test

testingIMUthread::testingIMUthread() : QThread()
{
}

void testingIMUthread::terminate()
{
    chkTerminate = true;
}

void testingIMUthread::run()
{
    chkTerminate = false;

    //open USB connection
    USBConnector usbconnector;

    if (usbconnector.ConnectToServer()== false)
    {
        qDebug("Cannot connect to server!");
        return;
    }

    while (chkTerminate == false)
    {
        mutex.lock();

        data = usbconnector.GetDataFromServer();

        mutex.unlock();

        emit dataTestingReady();
    }
    //close IMU
    usbconnector.DisconnectToServer();
    qDebug("Terminating Testing IMU Thread!");
}
