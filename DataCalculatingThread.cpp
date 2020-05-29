#include "DataCalculatingThread.h"

#include "DataHandler.h"
#include "USBConnector.h"
#include "math.h"
#include "QDebug"
#include "pthread.h"
#include "QString"
#include "QVariant"

DataCalculatingThread::DataCalculatingThread() : QThread()
{
}

void DataCalculatingThread::terminate()
{
    chkTerminate = true;
}

void DataCalculatingThread::getMainData(QString startDate, QString startTime, QString postIndex, QString candidateNumber, ArmPosture MasterPostureData, ArmLength ArmLengths, ArmPosture IMUoffset, QString ExpType)
{
    itsStartDate = startDate;
    itsStartTime = startTime;
    itsPostIndex = postIndex;
    itsCandidateNumber = candidateNumber;
    itsMasterPostureData = MasterPostureData;
    itsArmLengths = ArmLengths;
    itsIMUoffset = IMUoffset;
    itsExpType = ExpType;
}

void DataCalculatingThread::run()
{
    clock_t oldRecord,newRecord;
    double delta_time,oldTime,newTime;

    oldRecord = clock();

    chkTerminate = false;

    ArmPosture StuData;

    Coordinate diff1,diff2,handcoor,elbowcoor;
    double diff3;
    double delta1,delta2,delta3;

    DataHandler datahandler;
    qDebug("test");
    //open USB connection
    USBConnector usbconnector;
    if (usbconnector.ConnectToServer() == false)
    {
        qDebug("Can not connect to IMU...");
        return;
    }

    //get analytical value of hand coordinate based on master posture
    mat3x1 HandInFixedFrame = datahandler.processDataStep1a(itsMasterPostureData,itsArmLengths);

    //process2
    //Analytical Elbow coordinate based on master posture
    mat3x1 AnaElbCoordinate = datahandler.processDataStep2a(itsMasterPostureData,itsArmLengths);

    FILE *fp;

    if (itsPostIndex == "1"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture1.txt", "a+");
    }else if (itsPostIndex == "2"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture2.txt", "a+");
    }else if (itsPostIndex == "3"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture3.txt", "a+");
    }else if (itsPostIndex == "4"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture4.txt", "a+");
    }else if (itsPostIndex == "5"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture5.txt", "a+");
    }else if (itsPostIndex == "6"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture6.txt", "a+");
    }else if (itsPostIndex == "7"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture7.txt", "a+");
    }else if (itsPostIndex == "8"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture8.txt", "a+");
    }else if (itsPostIndex == "9"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture9.txt", "a+");
    }else if (itsPostIndex == "10"){
        fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture10.txt", "a+");
    }

    QString string;
    QVariant upRoll(itsMasterPostureData.UparmRoll);
    QVariant upPitch(itsMasterPostureData.UparmPitch);
    QVariant upYaw(itsMasterPostureData.UparmYaw);
    QVariant foreRoll(itsMasterPostureData.ForearmRoll);
    QVariant forePitch(itsMasterPostureData.ForearmPitch);
    QVariant foreYaw(itsMasterPostureData.ForearmYaw);
    QVariant foreArmLength(itsArmLengths.foreArm);
    QVariant upperArmLength(itsArmLengths.upperArm);

    string = "Start Date|" + itsStartDate + "|Start Time|" + itsStartTime + "|Post Index|" + itsPostIndex + "|Student Index|" + itsCandidateNumber + "|ExpType|" + itsExpType + "|" +
            "Master's posture data|" + upRoll.toString()+ "|" + upPitch.toString() + "|" + upYaw.toString() + "|" +
            foreRoll.toString()+ "|" + forePitch.toString() + "|" + foreYaw.toString() + "|" +
            foreArmLength.toString() + "|" + upperArmLength.toString()+ "|" + "\n";

    const char *str;
    QByteArray ba;
    ba = string.toLatin1();
    str = ba.data();

    fprintf(fp, str);


    //Initialize IMU data
    ArmPosture oldIMU,newIMU,oldVec,newVec,oldAcc,newAcc;
    oldIMU = usbconnector.GetCalDataFromServer(itsIMUoffset);
    oldVec.ForearmPitch=oldVec.ForearmRoll=oldVec.ForearmYaw=oldVec.UparmPitch=oldVec.UparmRoll=oldVec.UparmYaw=0;
    oldAcc.ForearmPitch=oldAcc.ForearmRoll=oldAcc.ForearmYaw=oldAcc.UparmPitch=oldAcc.UparmRoll=oldAcc.UparmYaw=0;
    oldTime=0;

    //record hand, elbow, forearm velocity and accelerarion
    double handVel, elbowVel;
    double handAcc, elbowAcc;
    Coordinate oldHandCoor, oldElbowCoor;

    Coordinate handVelVector,elbowVelVector;
    Coordinate oldHandVelVector,oldElbowVelVector;

    Coordinate handAccVector,elbowAccVector;

    //Initialize hand, elbow coordinate data
    RealCoordinate a = datahandler.processDataStep1b(HandInFixedFrame,StuData,itsArmLengths);
    diff1 = a.diff;
    delta1 = sqrt(pow(diff1.x,2) +pow(diff1.y,2) + pow(diff1.z,2));
    oldHandCoor = a.actualCoor;
    RealCoordinate b = datahandler.processDataStep2b(AnaElbCoordinate,StuData,itsArmLengths);
    diff2 = b.diff;
    delta2 = sqrt(pow(diff2.x,2) +pow(diff2.y,2) + pow(diff2.z,2));
    oldElbowCoor = b.actualCoor;

    oldHandVelVector.x=oldHandVelVector.y=oldHandVelVector.z=oldElbowVelVector.x=oldElbowVelVector.y=oldElbowVelVector.z=0;


    while (chkTerminate == false)
    {
        mutex.lock();

        StuData = usbconnector.GetCalDataFromServer(itsIMUoffset);
        newIMU = StuData;
        newRecord = clock();

        //process1
        RealCoordinate a1 = datahandler.processDataStep1b(HandInFixedFrame,StuData,itsArmLengths);
        diff1 = a1.diff;
        delta1 = sqrt(pow(diff1.x,2) +pow(diff1.y,2) + pow(diff1.z,2));
        handcoor = a1.actualCoor;

        //process2
        RealCoordinate b1 = datahandler.processDataStep2b(AnaElbCoordinate,StuData,itsArmLengths);
        diff2 = b1.diff;
        delta2 = sqrt(pow(diff2.x,2) +pow(diff2.y,2) + pow(diff2.z,2));
        elbowcoor = b1.actualCoor;

        //process3
        diff3 = datahandler.processDataStep3(itsMasterPostureData,StuData);
        delta3 = diff3;

        //store data
        data.posture = StuData;
        data.HandCoordinateDiff = delta1;
        data.HandCoordinate = handcoor;
        data.ElbowCoordinateDiff = delta2;
        data.ElbowCoordinate = elbowcoor;
        data.ForeRollDeviations = delta3;

        emit dataReady();


        delta_time =(double)(newRecord-oldRecord) / ((double)CLOCKS_PER_SEC);

        //record hand, elbow velocity

        handVelVector.x = handcoor.x-oldHandCoor.x;
        handVelVector.y = handcoor.y-oldHandCoor.y;
        handVelVector.z = handcoor.z-oldHandCoor.z;
        elbowVelVector.x = elbowcoor.x-oldElbowCoor.x;
        elbowVelVector.y = elbowcoor.y-oldElbowCoor.y;
        elbowVelVector.z = elbowcoor.z-oldElbowCoor.z;

        handVel = sqrt(pow(handVelVector.x,2) +pow(handVelVector.y,2) + pow(handVelVector.z,2))/delta_time;
        elbowVel = sqrt(pow(elbowVelVector.x,2) +pow(elbowVelVector.y,2) + pow(elbowVelVector.z,2))/delta_time;

        handAccVector.x = handVelVector.x - oldHandVelVector.x;
        handAccVector.y = handVelVector.y - oldHandVelVector.y;
        handAccVector.z = handVelVector.z - oldHandVelVector.z;
        elbowAccVector.x = elbowVelVector.x - oldElbowVelVector.x;
        elbowAccVector.y = elbowVelVector.y - oldElbowVelVector.y;
        elbowAccVector.z = elbowVelVector.z - oldElbowVelVector.z;

        handAcc = sqrt(pow(handAccVector.x,2) +pow(handAccVector.y,2) + pow(handAccVector.z,2))/delta_time;
        elbowAcc = sqrt(pow(elbowAccVector.x,2) +pow(elbowAccVector.y,2) + pow(elbowAccVector.z,2))/delta_time;


        //new IMU velocity
        newVec.ForearmPitch = (newIMU.ForearmPitch-oldIMU.ForearmPitch)/delta_time;
        newVec.ForearmYaw = (newIMU.ForearmYaw-oldIMU.ForearmYaw)/delta_time;
        newVec.ForearmRoll = (newIMU.ForearmRoll-oldIMU.ForearmRoll)/delta_time;
        newVec.UparmPitch = (newIMU.UparmPitch-oldIMU.UparmPitch)/delta_time;
        newVec.UparmYaw = (newIMU.UparmYaw-oldIMU.UparmYaw)/delta_time;
        newVec.UparmRoll = (newIMU.UparmRoll-oldIMU.UparmRoll)/delta_time;

        //new IMU acceleration
        newAcc.ForearmPitch = (newVec.ForearmPitch-oldVec.ForearmPitch)/delta_time;
        newAcc.ForearmYaw = (newVec.ForearmYaw-oldVec.ForearmYaw)/delta_time;
        newAcc.ForearmRoll = (newVec.ForearmRoll-oldVec.ForearmRoll)/delta_time;
        newAcc.UparmPitch = (newVec.UparmPitch-oldVec.UparmPitch)/delta_time;
        newAcc.UparmYaw = (newVec.UparmYaw-oldVec.UparmYaw)/delta_time;
        newAcc.UparmRoll = (newVec.UparmRoll-oldVec.UparmRoll)/delta_time;

        newTime = oldTime + delta_time;

        //replace old data with new data
        oldElbowCoor = elbowcoor;
        oldHandCoor = handcoor;
        oldHandVelVector = handVelVector;
        oldElbowVelVector = elbowVelVector;
        oldAcc = newAcc;
        oldVec = newVec;
        oldIMU = newIMU;
        oldRecord = newRecord;
        oldTime = newTime;

        //Writing data into file

        QVariant recordTime(newTime);

        //fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\ContinuousMappingData\\Posture.txt", "a+");
        string = recordTime.toString()+"|" +
                //IMU angular data
                "IMU data|" + QString::number(newIMU.UparmRoll,'f',2)+"|"+QString::number(newIMU.UparmPitch,'f',2)+"|"+QString::number(newIMU.UparmYaw,'f',2)+"|"+QString::number(newIMU.ForearmRoll,'f',2)+"|"+QString::number(newIMU.ForearmPitch,'f',2)+"|"+QString::number(newIMU.ForearmYaw,'f',2)+"|"+
                //IMU angular velocity
                "IMU angVel|" + QString::number(newVec.UparmRoll,'f',2)+"|"+QString::number(newVec.UparmPitch,'f',2)+"|"+QString::number(newVec.UparmYaw,'f',2)+"|"+QString::number(newVec.ForearmRoll,'f',2)+"|"+QString::number(newVec.ForearmPitch,'f',2)+"|"+QString::number(newVec.ForearmYaw,'f',2)+"|"+
                //IMU angular acceleration
                "IMU angAcc|" + QString::number(newAcc.UparmRoll,'f',2)+"|"+QString::number(newAcc.UparmPitch,'f',2)+"|"+QString::number(newAcc.UparmYaw,'f',2)+"|"+QString::number(newAcc.ForearmRoll,'f',2)+"|"+QString::number(newAcc.ForearmPitch,'f',2)+"|"+QString::number(newAcc.ForearmYaw,'f',2)+"|"+
                //hand coordinate-elbow coordinate-roll forearm angle error
                "error|" +QString::number(delta1,'f',2)+"|"+QString::number(delta2,'f',2)+"|"+QString::number(delta3,'f',2)+"|" +
                //hand,elbow, roll forearm velocity
                "vel|" +QString::number(handVel,'f',2)+"|"+QString::number(elbowVel,'f',2)+"|"+QString::number(newVec.ForearmRoll,'f',2)+"|"+
                //hand,elbow,roll forearm acceleration
                "acc|" +QString::number(handAcc,'f',2)+"|"+QString::number(elbowAcc,'f',2)+"|"+QString::number(newAcc.ForearmRoll,'f',2)+"|"+ "\n";

        ba = string.toLatin1();
        str = ba.data();

        fprintf(fp, str);

        mutex.unlock();
        Sleep(150);

    }
    fclose(fp);
    //close IMU
    usbconnector.DisconnectToServer();
    qDebug("Terminating Continuous data recorder Thread!");
}
