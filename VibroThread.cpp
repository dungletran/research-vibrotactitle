#include "VibroThread.h"

#include "QMessageBox"
#include "pthread.h"
#include "QByteArray"
#include "QIODevice"
#include "QVariant"

VibroThread::VibroThread()
{
}

void VibroThread::intializeThreshold(ThresholdSet threshold, int noLoop)
{
    itsThreshold = threshold;
    itsNoLoop = noLoop;
}

void VibroThread::terminate()
{
    chkTerminate = true;
}

void VibroThread::getCalData(showSet CalDataSet)
{
    itsCalDataSet = CalDataSet;
}

void VibroThread::run()
{
    chkTerminate = false;

    itsPort = new QextSerialPort("COM2");
    itsPort->setBaudRate(BAUD57600);
    itsPort->setFlowControl(FLOW_OFF);
    itsPort->setParity(PAR_NONE);
    itsPort->setDataBits(DATA_8);
    itsPort->setStopBits(STOP_1);
    itsPort->open(QIODevice::WriteOnly);

    double mag;
    QByteArray msg;
    msg.resize(1);
    msg[0]=0;

    //clock_t rec1,rec2;

    showSet CurrDataSet,CurrDataSet1;

    //process 1
    int loop;

    //2-loop change here
    int nloop=itsNoLoop;
    double MaxProcess1,MinProcess1,MinProcess2;

    for (loop = 1; loop < (nloop+1); loop++){
        if (loop ==1){
            MaxProcess1 = itsThreshold.Max1Process1;
            MinProcess1 = itsThreshold.Min1Process1;
            MinProcess2 = itsThreshold.Min1Process2;
        }
        if (loop ==2){
            MaxProcess1 = itsThreshold.Max2Process1;
            MinProcess1 = itsThreshold.Min2Process1;
            MinProcess2 = itsThreshold.Min2Process2;
        }
        while (chkTerminate == false){
            CurrDataSet = itsCalDataSet;

            if (CurrDataSet.HandCoordinateDiff < MaxProcess1 && CurrDataSet.HandCoordinateDiff > MinProcess1 ){
                //mag=1-(CurrDataSet.HandCoordinateDiff-MinProcess1)/((MaxProcess1-MinProcess1));
                mag=(CurrDataSet.HandCoordinateDiff-MinProcess1)/((MaxProcess1-MinProcess1)); //reverse pattern
                msg[0]=16*(int)(mag*240/16)+(int)(15*mag);

                itsPort->write(msg,1);
                Sleep(200);
                msg[0]=0;

                itsPort->write(msg,1);
                Sleep(200);
            }
            else if (CurrDataSet.HandCoordinateDiff <= MinProcess1){

                if (loop==1){
                    emit finishMappingHand1();
                }
                if (loop ==2){
                    emit finishMappingHand2();
                }

                msg[0]=255;
                itsPort->write(msg,1);
                Sleep(2000);
                msg[0]=0;
                itsPort->write(msg,1);

                break;
            }
        }
        if (chkTerminate == true){
            qDebug("Vibro is OFF SERVICE!");
            QByteArray msg;
            msg.resize(1);
            msg[0]=0;
            itsPort->write(msg,1);
            itsPort->close();
            return;
        }
        //finish process1

        Sleep(200);

        //process2

        //initial delta2

        double InitialDelta2 = itsCalDataSet.ElbowCoordinateDiff;
        Sleep(200);

        bool chk2 = false;
        while (chkTerminate == false){
            if (InitialDelta2<=MinProcess2 && chk2 == false){

                if (loop == 1){
                    emit finishMappingElbow1();
                }
                if (loop == 2){
                    emit finishMappingElbow2();
                }

                msg[0]=240;
                itsPort->write(msg,1);
                Sleep(2000);
                msg[0]=0;
                itsPort->write(msg,1);

                break;
            }
            else{
                chk2 = true;
                CurrDataSet = itsCalDataSet;

                if (CurrDataSet.ElbowCoordinateDiff > InitialDelta2 ){
                     InitialDelta2 = CurrDataSet.ElbowCoordinateDiff;
                     Sleep(200);
                     continue;
                }
                else{
                    if (CurrDataSet.ElbowCoordinateDiff > MinProcess2){
                        //mag=1-(CurrDataSet.ElbowCoordinateDiff-MinProcess2)/((InitialDelta2-MinProcess2));
                        mag=(CurrDataSet.ElbowCoordinateDiff-MinProcess2)/((InitialDelta2-MinProcess2)); //reverse pattern
                        msg[0]=16*(int)(mag*240/16);
                        itsPort->write(msg,1);
                        Sleep(200);
                        msg[0]=0;
                        itsPort->write(msg,1);
                        Sleep(200);
                    }
                    else{

                        if (loop == 1){
                            emit finishMappingElbow1();
                        }
                        if (loop == 2){
                            emit finishMappingElbow2();
                        }

                        msg[0]=240;
                        itsPort->write(msg,1);
                        Sleep(2000);
                        msg[0]=0;
                        itsPort->write(msg,1);
                        break;
                    }
                    CurrDataSet1 = itsCalDataSet;
                    if (CurrDataSet1.ElbowCoordinateDiff>CurrDataSet.ElbowCoordinateDiff){
                        InitialDelta2 = CurrDataSet1.ElbowCoordinateDiff;
                    }
                }
            }
        }
        if (chkTerminate == true)
        {
            qDebug("Vibro is OFF SERVICE!");
            QByteArray msg;
            msg.resize(1);
            msg[0]=0;
            itsPort->write(msg,1);
            itsPort->close();
            return;
        }
        //finish process2

        Sleep(200);
    }



    //process3
    //initial delta3
    double InitialDelta3 =  itsCalDataSet.ForeRollDeviations;
    Sleep(200);
    bool chk3 = false;
    while (chkTerminate == false){
        if (InitialDelta3<=itsThreshold.MinProcess3 && chk3 == false)
        {
            emit finishMapping();
            msg[0]=15;
            itsPort->write(msg,1);
            Sleep(2000);
            msg[0]=0;
            itsPort->write(msg,1);
            itsPort->close();
            chkTerminate = true;
        }
        else{
            chk3 = true;
            CurrDataSet = itsCalDataSet;
            if (CurrDataSet.ForeRollDeviations >= InitialDelta3 )
            {
                 InitialDelta3 = CurrDataSet.ForeRollDeviations;
                 Sleep(200);
                 continue;
            }
            else
            {
                if (CurrDataSet.ForeRollDeviations > itsThreshold.MinProcess3 )
                {
                    //mag=1-(CurrDataSet.ForeRollDeviations-itsThreshold.MinProcess3)/((InitialDelta3-itsThreshold.MinProcess3));
                    mag=(CurrDataSet.ForeRollDeviations-itsThreshold.MinProcess3)/((InitialDelta3-itsThreshold.MinProcess3)); //reverse pattern
                    msg[0]=(int)(15*mag);
                    itsPort->write(msg,1);
                    Sleep(200);
                    msg[0]=0;
                    itsPort->write(msg,1);
                    Sleep(200);
                }
                else
                {
                    emit finishMapping();
                    msg[0]=15;
                    itsPort->write(msg,1);
                    Sleep(2000);
                    msg[0]=0;
                    itsPort->write(msg,1);
                    itsPort->close();
                    chkTerminate = true;

                }
                CurrDataSet1 = itsCalDataSet;
                if (CurrDataSet1.ForeRollDeviations>CurrDataSet.ForeRollDeviations)
                {
                    InitialDelta3 = CurrDataSet1.ForeRollDeviations;
                }

            }
        }
    }
    if (chkTerminate == true)
    {
        qDebug("Vibro is OFF SERVICE!");
        QByteArray msg;
        msg.resize(1);
        msg[0]=0;
        itsPort->write(msg,1);
        itsPort->close();
        return;
    }
    //finish process3
}
