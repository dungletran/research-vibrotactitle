//============================================================================
//
//  File Name:     USBConnector.h
//  Description:   Reading data from IMU
//  Created:       17/06/2011
//  Author:        Tran Le Dung
//
//  History:
//=============================================================================



#ifndef USBCONNECTOR_H
#define USBCONNECTOR_H

#include <MainStructure.h>
#include "QtNetwork/QTcpSocket"

//getdata from ports
class USBConnector
{
public:
    USBConnector();
    ~USBConnector();
    //create socket and get data from IMU

    bool ConnectToServer();
    bool DisconnectToServer();
    ArmPosture GetDataFromServer();
    ArmPosture GetCalDataFromServer(ArmPosture IMUoffset);
    QTcpSocket *tcpSocket;

};

#endif // USBCONNECTOR_H
