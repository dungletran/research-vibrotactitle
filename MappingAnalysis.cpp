#include "MappingAnalysis.h"
#include "ui_MappingAnalysis.h"

#include "USBConnector.h"
#include "DataHandler.h"
#include "posturerecorder.h"

#include <QThread>
#include <QFile>
#include <QTextStream>
#include "QLocale"
#include "QStringList"
#include "QString"
#include "pthread.h"
#include "qmessagebox.h"
#include <QPixmap>
#include <QLabel>
#include "math.h"
#include "QDataStream"
#include "QTime"
#include <qextserialport.h>
#include "QIODevice"
#include "QByteArray"
#include "QLabel"
#include "QPixmap"
#include "QVariant"


//**********************************************************************
//Constructor and Destructor
MappingAnalysis::MappingAnalysis(QWidget *parent) :
    QMainWindow(parent),
    uiMain(new Ui::MappingAnalysis)
{
    uiMain->setupUi(this);

    //initialize comp port

    //signal slot for experimental tab
    connect(&calThread,SIGNAL(dataReady()),this,SLOT(showExpData()));
    connect(&calThread,SIGNAL(dataReady()),this,SLOT(sendData2Vibro()));
    connect(&vibroThread,SIGNAL(finishMapping()),this,SLOT(RecordFinishTime()));
    connect(&vibroThread,SIGNAL(finishMappingHand1()),this,SLOT(RecordFinishTimeHand1()));
    connect(&vibroThread,SIGNAL(finishMappingHand2()),this,SLOT(RecordFinishTimeHand2()));
    connect(&vibroThread,SIGNAL(finishMappingElbow1()),this,SLOT(RecordFinishTimeElbow1()));
    connect(&vibroThread,SIGNAL(finishMappingElbow2()),this,SLOT(RecordFinishTimeElbow2()));

    //signal slot for testing tab
    connect(&IMUtestThread,SIGNAL(dataTestingReady()),this,SLOT(showIMUdata()));
}

MappingAnalysis::~MappingAnalysis()
{
    delete uiMain;
}
//End Constructor and Destructor
//***********************************************************************




/***********************************************************************
                                Experiment tab
************************************************************************/

void MappingAnalysis::expCalibrationClick()
{
    USBConnector offsetConnection;
    offsetConnection.ConnectToServer();
    itsExpIMUoffset = offsetConnection.GetDataFromServer();
    offsetConnection.DisconnectToServer();
    QMessageBox msgBox;
    msgBox.setText("Finishing calibration!");
    msgBox.exec();
}



//signal slots:
void MappingAnalysis::expStartClick()
{
     QTime time = QTime::currentTime();
     startTime = time.toString();

     QDate date = QDate::currentDate();
     startDate = date.toString();

     //vision option checking
     actVision = false;
     if (uiMain->radioButtonExpVisionON->isChecked()== true)
     {
         actVision = true;
     }
     if (uiMain->radioButtonExpVisionOFF->isChecked()== true)
     {
         actVision = false;
     }

     //vibro-tactile option checking
     actVibro = false;
     if (uiMain->radioButtonExpVibroON->isChecked()== true)
     {
         actVibro = true;
     }
     if (uiMain->radioButtonExpVibroOFF->isChecked()== true)
     {
         actVibro = false;
     }

     //type of visualization
     actVideo = false;
     actPic = false;
     if (actVision == true)
     {
        if (uiMain->comboBoxExpVisionPicVideoSelection->currentText()== "Picture")
        {
            actPic = true;
        }
        else if (uiMain->comboBoxExpVisionPicVideoSelection->currentText()== "Video")
        {
            actVideo = true;
        }
     }

     QString ExpType;
     //finding the type of experiment
     if (actVision==true && actVibro==true && uiMain->comboBoxExpSimSeqSelection->currentText()== "Simultaneous Feedback")
     {
          ExpType = "Vision,Vibro:ON;Simutaneous Feedback by ";
          if (actVideo == true)
          {
              ExpType = ExpType + "Video";
          }
          if (actPic == true)
          {
              ExpType = ExpType + "Image";
          }
     }
     else if (actVision==true && actVibro==true && uiMain->comboBoxExpSimSeqSelection->currentText()== "Sequential Feedback")
     {
          ExpType = "Vision,Vibro:ON;Sequential Feedback by ";
          if (actVideo == true)
          {
              ExpType = ExpType + "Video";
          }
          if (actPic == true)
          {
              ExpType = ExpType + "Image";
          }
     }
     if (actVision == false && actVibro == true)
     {
          ExpType = "Vision:OFF,Vibro:ON";
     }
     if (actVision == true && actVibro == false)
     {
          if (actVideo == true){
              ExpType = "Vision:ON(Video),Vibro:OFF";
          }
          if (actPic == true){
              ExpType = "Vision:ON(Image),Vibro:OFF";
          }
     }


     //get masterposture
     if (getPost())
     {

         //show target hand, elbow coordinates and fore-arm roll
         show_target_para();

         //send master posture data to calculating thread
         calThread.getMainData(startDate,startTime,uiMain->comboBoxMasterSelection->currentText(),uiMain->comboBoxCandidateNumber->currentText(),itsMasterPost,itsArmLengths,itsExpIMUoffset,ExpType);

         //initial time
         init = clock();

         //start running calculating thread
         calThread.start();

         //running vibro thread if selected
         if (actVibro == true)
         {
             //get threshold from main
             QVariant a(uiMain->comboBoxNumberLoop->currentText());
             vibroThread.intializeThreshold(itsThreshold,a.toInt());

             //start vibro-tactile thread
             vibroThread.start();
         }

      }
    //show the mapping type label
     uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
     uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
     uiMain->labelMappingType->setScaledContents(true);
     uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingHandCoor1.png"));
}

void MappingAnalysis::expStopClick()
{
    //terminate calculating data thread suddenly
    calThread.terminate();
    Sleep(100);

    if (actVibro == true)
    {
        //terminate vibro-tactile thread suddenly
        vibroThread.terminate();
    }
    Sleep(100);

    QMessageBox msgBox;
    msgBox.setText("Stop experiment!");
    msgBox.exec();
}


void MappingAnalysis::expRecordClick()
{
    //terminate calculating thread when finish mapping
    calThread.terminate();

    if (actVibro == true)
    {
        //terminate vibro-tactile thread when finish mapping
        vibroThread.terminate();
    }

    //record finishing moment if no vibro-feedback
    else
    {
        final=clock();
    }

    //calculating mapping time
    MappingTime = (double)(final-init) / ((double)CLOCKS_PER_SEC);

    RealtimeData recordingData; //set of data for recording
    QString ExpType;    //type of experiment
    ArmPosture FinalStuData;    //Final value for recording
    USBConnector usbconnector;

    //finding the type of experiment
    if (actVibro == true && actVision==true && uiMain->comboBoxExpSimSeqSelection->currentText()== "Simultaneous Feedback")
    {
         ExpType = "Vision,Vibro:ON;Simutaneous Feedback by ";
         if (actVideo == true)
         {
             ExpType = ExpType + "Video";
         }
         if (actPic == true)
         {
             ExpType = ExpType + "Image";
         }
    }
    else if (actVibro == true && actVision==true && uiMain->comboBoxExpSimSeqSelection->currentText()== "Sequential Feedback")
    {
         ExpType = "Vision,Vibro:ON;Sequential Feedback by ";
         if (actVideo == true)
         {
             ExpType = ExpType + "Video";
         }
         if (actPic == true)
         {
             ExpType = ExpType + "Image";
         }
    }
     if (actVision == false && actVibro == true)
     {
         ExpType = "Vision:OFF,Vibro:ON";
     }
     if (actVision == true && actVibro == false)
     {
         if (actVideo == true){
             ExpType = "Vision:ON(Video),Vibro:OFF";
         }
         if (actPic == true){
             ExpType = "Vision:ON(Image),Vibro:OFF";
         }

     }


    //getting data from IMU for final record
    usbconnector.ConnectToServer();
    FinalStuData = usbconnector.GetCalDataFromServer(itsExpIMUoffset);
    usbconnector.DisconnectToServer();

    //process1
    QVariant delta1(uiMain->textBrowserHandCoorDelta->toPlainText());

    //process2
    QVariant delta2(uiMain->textBrowserElbowCoorDelta->toPlainText());

    //process3
    QVariant delta3(uiMain->textBrowserForeRollAngleDelta->toPlainText());

    recordingData.startDate = startDate;
    recordingData.startTime = startTime;
    recordingData.CandidateNumber=uiMain->comboBoxCandidateNumber->currentText();
    recordingData.PostIndex= uiMain->comboBoxMasterSelection->currentText();
    recordingData.time = MappingTime;
    recordingData.ArmAngles = FinalStuData;
    recordingData.ElbowCoordinateDiff = delta2.toDouble();
    recordingData.HandCoordinateDiff = delta1.toDouble();
    recordingData.ForeRollDeviations = delta3.toDouble();

    //recording data into text file
    PostureRecorder posturerecorder;
    posturerecorder.recordData(recordingData, ExpType,error1_1,error1_2,error2_1,error2_2,handMap1Instant,elbowMap1Instant,handMap2Instant,elbowMap2Instant);

    QMessageBox msgBox;
    msgBox.setText("Data is recorded!");
    msgBox.exec();
}


void MappingAnalysis::expShowClick()
{
    actVision = false;
    if (uiMain->radioButtonExpVisionON->isChecked()== true)
    {
        actVision = true;

    }
    if (uiMain->radioButtonExpVisionOFF->isChecked()== true)
    {
        actVision = false;

    }

    actVideo = false;
    actPic = false;
    if (actVision == true)
    {
       if (uiMain->comboBoxExpVisionPicVideoSelection->currentText()== "Picture")
       {
           actPic = true;

       }
       else if (uiMain->comboBoxExpVisionPicVideoSelection->currentText()== "Video")
       {
           actVideo = true;

       }
    }

    if (actVision == true && actPic == true)
    {
         QString postIndex = uiMain->comboBoxMasterSelection->currentText();
         QString ImageDir = ":/PostureImages/posture_" + postIndex + ".png";
         QLabel *image = new QLabel();
         image->setWindowTitle( "Posture " + postIndex);
         image->resize(600,720);
         image->setPixmap( QPixmap( ImageDir ) );
         image->show();
     }
}


void MappingAnalysis::showExpData()
{
    DataSet = calThread.data;

    uiMain->textBrowserStudentUpRoll->setText(QString::number(DataSet.posture.UparmRoll,'f',2));
    uiMain->textBrowserStudentUpPitch->setText(QString::number(DataSet.posture.UparmPitch,'f',2));
    uiMain->textBrowserStudentUpYaw->setText(QString::number(DataSet.posture.UparmYaw,'f',2));
    uiMain->textBrowserStudentForeRoll->setText(QString::number(DataSet.posture.ForearmRoll,'f',2));
    uiMain->textBrowserStudentForePitch->setText(QString::number(DataSet.posture.ForearmPitch,'f',2));
    uiMain->textBrowserStudentForeYaw->setText(QString::number(DataSet.posture.ForearmYaw,'f',2));

    //hand coordinate different
    uiMain->textBrowserHandCoorDelta->setText(QString::number(DataSet.HandCoordinateDiff,'f',2));

    //elbow coordinate different
    uiMain->textBrowserElbowCoorDelta->setText(QString::number(DataSet.ElbowCoordinateDiff,'f',2));

    //fore-arm roll different
    uiMain->textBrowserForeRollAngleDelta->setText(QString::number(DataSet.ForeRollDeviations,'f',2));

    //hand coordinate
    uiMain->textBrowserHandCoorActualX->setText(QString::number(DataSet.HandCoordinate.x,'f',2));
    uiMain->textBrowserHandCoorActualY->setText(QString::number(DataSet.HandCoordinate.y,'f',2));
    uiMain->textBrowserHandCoorActualZ->setText(QString::number(DataSet.HandCoordinate.z,'f',2));

    //elbow coordinate
    uiMain->textBrowserElbowCoorActualX->setText(QString::number(DataSet.ElbowCoordinate.x,'f',2));
    uiMain->textBrowserElbowCoorActualY->setText(QString::number(DataSet.ElbowCoordinate.y,'f',2));
    uiMain->textBrowserElbowCoorActualZ->setText(QString::number(DataSet.ElbowCoordinate.z,'f',2));

    //fore-arm roll
    uiMain->textBrowserForeArmRollActual->setText(QString::number(DataSet.posture.ForearmRoll,'f',2));
}

bool MappingAnalysis::getPost()
{
    //reading posture number <ComboBox>
     bool check = false;
     QString MasterPostIndex = uiMain->comboBoxMasterSelection->currentText();

     //reading data file
     QString line;
     QStringList MasterPostData;
     //QFile MasterPostFile(":/MasterConfig/MasterPosture.txt");

     QFile MasterPostFile("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\MasterConfig\\MasterPosture.txt");

     if (MasterPostFile.open(QIODevice::ReadOnly))
     {
        QTextStream in(&MasterPostFile);
        while ( !in.atEnd() )
        {
           line = in.readLine();
           MasterPostData = line.split("|",QString::SkipEmptyParts);
           QString postIndex = MasterPostData.at(0);
           if (postIndex == MasterPostIndex)
           {
               check = true;
               QVariant var1(MasterPostData[1]);
               itsMasterPost.UparmRoll = var1.toDouble() ;
               QVariant var2(MasterPostData[2]);
               itsMasterPost.UparmPitch = var2.toDouble() ;
               QVariant var3(MasterPostData[3]);
               itsMasterPost.UparmYaw = var3.toDouble() ;
               QVariant var4(MasterPostData[4]);
               itsMasterPost.ForearmRoll = var4.toDouble() ;
               QVariant var5(MasterPostData[5]);
               itsMasterPost.ForearmPitch = var5.toDouble() ;
               QVariant var6(MasterPostData[6]);
               itsMasterPost.ForearmYaw = var6.toDouble() ;

               //expess master data
               uiMain->textBrowserMasterUpArmRoll->setText(QString::number(itsMasterPost.UparmRoll,'f',2));
               uiMain->textBrowserMasterUpArmPitch->setText(QString::number(itsMasterPost.UparmPitch,'f',2));
               uiMain->textBrowserMasterUpArmYaw->setText(QString::number(itsMasterPost.UparmYaw,'f',2));
               uiMain->textBrowserMasterForeArmRoll->setText(QString::number(itsMasterPost.ForearmRoll,'f',2));
               uiMain->textBrowserMasterForeArmPitch->setText(QString::number(itsMasterPost.ForearmPitch,'f',2));
               uiMain->textBrowserMasterForeArmYaw->setText(QString::number(itsMasterPost.ForearmYaw,'f',2));
               break;
           }
        }
     }
     MasterPostFile.close();
     if ( check == false)
     {
         QMessageBox msgBox;
         msgBox.setText("Please choose other posture, this posture doesnot exist!");
         msgBox.exec();
         return false;
     }
     else{
         return true;
     }
}

void MappingAnalysis::show_target_para()
{
    DataHandler datahandler;
    mat3x1 HandInFixedFrame = datahandler.processDataStep1a(itsMasterPost,itsArmLengths);
    mat3x1 AnaElbCoordinate = datahandler.processDataStep2a(itsMasterPost,itsArmLengths);

    uiMain->textBrowserElbowCoorTargetX->setText(QString::number(AnaElbCoordinate.m11,'f',2));
    uiMain->textBrowserElbowCoorTargetY->setText(QString::number(AnaElbCoordinate.m21,'f',2));
    uiMain->textBrowserElbowCoorTargetZ->setText(QString::number(AnaElbCoordinate.m31,'f',2));
    uiMain->textBrowserHandCoorTargetX->setText(QString::number(HandInFixedFrame.m11,'f',2));
    uiMain->textBrowserHandCoorTargetY->setText(QString::number(HandInFixedFrame.m21,'f',2));
    uiMain->textBrowserHandCoorTargetZ->setText(QString::number(HandInFixedFrame.m31,'f',2));
    uiMain->textBrowserForeArmRollTarget->setText(QString::number(itsMasterPost.ForearmRoll,'f',2));

    QMessageBox msgBox;
    msgBox.setText("Start experiment!");
    msgBox.exec();
}





void MappingAnalysis::RecordFinishTime()
{
    final = clock();
    qDebug("testing here");

    RealtimeData recordingData; //set of data for recording
    QString ExpType;    //type of experiment
    ArmPosture FinalStuData;    //Final value for recording
    //getting data from IMU for final record

    QVariant upRoll(uiMain->textBrowserStudentUpRoll->toPlainText());
    QVariant upPitch(uiMain->textBrowserStudentUpPitch->toPlainText());
    QVariant upYaw(uiMain->textBrowserStudentUpYaw->toPlainText());
    QVariant foreRoll(uiMain->textBrowserStudentForeRoll->toPlainText());
    QVariant forePitch(uiMain->textBrowserStudentForePitch->toPlainText());
    QVariant foreYaw(uiMain->textBrowserStudentForeYaw->toPlainText());

    //process1
    QVariant delta1(uiMain->textBrowserHandCoorDelta->toPlainText());

    //process2
    QVariant delta2(uiMain->textBrowserElbowCoorDelta->toPlainText());

    //process3
    QVariant delta3(uiMain->textBrowserForeRollAngleDelta->toPlainText());

    //label that we have finish the task
    uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
    uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    uiMain->labelMappingType->setScaledContents(true);
    uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/Done.png"));


    //terminate calculating thread when finish mapping
    calThread.terminate();

    //calculating mapping time
    MappingTime = (double)(final-init) / ((double)CLOCKS_PER_SEC);

    //finding the type of experiment
    if (uiMain->comboBoxExpSimSeqSelection->currentText()== "Simultaneous Feedback")
    {
         ExpType = "Vision,Vibro:ON;Simultaneous Feedback by ";
         if (actVideo == true)
         {
             ExpType = ExpType + "Video";
         }
         if (actPic == true)
         {
             ExpType = ExpType + "Image";
         }
    }
    else if (uiMain->comboBoxExpSimSeqSelection->currentText()== "Sequential Feedback")
    {
         ExpType = "Vision,Vibro:ON;Sequential Feedback by ";
         if (actVideo == true)
         {
             ExpType = ExpType + "Video";
         }
         if (actPic == true)
         {
             ExpType = ExpType + "Image";
         }
    }
    else if (uiMain->comboBoxExpSimSeqSelection->currentText()== "<None>" )
    {
         if (actVision == false && actVibro == true)
         {
             ExpType = "Vision:OFF,Vibro:ON";
         }
         if (actVision == true && actVibro == false)
         {
             ExpType = "Vision:ON,Vibro:OFF";
         }
    }

    FinalStuData.UparmRoll = upRoll.toDouble();
    FinalStuData.UparmPitch = upPitch.toDouble();
    FinalStuData.UparmYaw = upYaw.toDouble();
    FinalStuData.ForearmRoll = foreRoll.toDouble();
    FinalStuData.ForearmPitch = forePitch.toDouble();
    FinalStuData.ForearmYaw = foreYaw.toDouble();


    recordingData.startDate = startDate;
    recordingData.startTime = startTime;
    recordingData.PostIndex= uiMain->comboBoxMasterSelection->currentText();
    recordingData.CandidateNumber = uiMain->comboBoxCandidateNumber->currentText();
    recordingData.time = MappingTime;
    recordingData.ArmAngles = FinalStuData;
    recordingData.ElbowCoordinateDiff = delta2.toDouble();
    recordingData.HandCoordinateDiff = delta1.toDouble();
    recordingData.ForeRollDeviations = delta3.toDouble();

    //recording data into text file
    PostureRecorder posturerecorder;
    posturerecorder.recordData(recordingData, ExpType,error1_1,error1_2,error2_1,error2_2,handMap1Instant,elbowMap1Instant,handMap2Instant,elbowMap2Instant);

    QMessageBox msgBox;
    Sleep(2000);
    msgBox.setText("Posture is mapped! Data is recorded!");
    msgBox.exec();
}

void MappingAnalysis::sendData2Vibro()
{
    if (actVibro == true)
    {
        vibroThread.getCalData(calThread.data);
    }
}

void MappingAnalysis::RecordFinishTimeHand1()
{
    error1_1.HandCoordinateDiff=uiMain->textBrowserHandCoorDelta->toPlainText();
    error1_1.ElbowCoordinateDiff=uiMain->textBrowserElbowCoorDelta->toPlainText();
    error1_1.ForeRollDeviations = uiMain->textBrowserForeRollAngleDelta->toPlainText();

    //record moment that hand mapping is done
    clock_t time = clock();
    handMap1Instant = (double)(time-init) / ((double)CLOCKS_PER_SEC);

    uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
    uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    uiMain->labelMappingType->setScaledContents(true);
    Sleep(2000);
    uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingElbowCoor1.png"));
}

void MappingAnalysis::RecordFinishTimeElbow1()
{
    error1_2.HandCoordinateDiff=uiMain->textBrowserHandCoorDelta->toPlainText();
    error1_2.ElbowCoordinateDiff=uiMain->textBrowserElbowCoorDelta->toPlainText();
    error1_2.ForeRollDeviations = uiMain->textBrowserForeRollAngleDelta->toPlainText();

    //record moment that elbow mapping is done
    clock_t time = clock();
    elbowMap1Instant = (double)(time-init) / ((double)CLOCKS_PER_SEC);

    uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
    uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    uiMain->labelMappingType->setScaledContents(true);
    Sleep(2000);

    //2-loop change here
    if (uiMain->comboBoxNumberLoop->currentText() == "2"){
        uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingHandCoor2.png"));
    }else{
        uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingFore-armRoll.png"));
    }

}

void MappingAnalysis::RecordFinishTimeHand2()
{
    error2_1.HandCoordinateDiff=uiMain->textBrowserHandCoorDelta->toPlainText();
    error2_1.ElbowCoordinateDiff=uiMain->textBrowserElbowCoorDelta->toPlainText();
    error2_1.ForeRollDeviations = uiMain->textBrowserForeRollAngleDelta->toPlainText();

    //record moment that hand mapping is done
    clock_t time = clock();
    handMap2Instant = (double)(time-init) / ((double)CLOCKS_PER_SEC);

    uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
    uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    uiMain->labelMappingType->setScaledContents(true);
    Sleep(2000);
    uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingElbowCoor2.png"));
}

void MappingAnalysis::RecordFinishTimeElbow2()
{
    error2_2.HandCoordinateDiff=uiMain->textBrowserHandCoorDelta->toPlainText();
    error2_2.ElbowCoordinateDiff=uiMain->textBrowserElbowCoorDelta->toPlainText();
    error2_2.ForeRollDeviations = uiMain->textBrowserForeRollAngleDelta->toPlainText();

    //record moment that hand mapping is done
    clock_t time = clock();
    elbowMap2Instant = (double)(time-init) / ((double)CLOCKS_PER_SEC);

    uiMain->labelMappingType->setBackgroundRole(QPalette::Base);
    uiMain->labelMappingType->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    uiMain->labelMappingType->setScaledContents(true);
    Sleep(2000);
    uiMain->labelMappingType->setPixmap(QPixmap(":/ConfigPicture/MappingFore-armRoll.png"));
}


 /***********************************************************************
                                 Testing tab
 ************************************************************************/
void MappingAnalysis::IMUtestStartClick()
{
    //start running IMU testing thread

    IMUtestThread.start();
}


void MappingAnalysis::IMUtestCalibrationClick()
{
    QVariant offsetForeArmPitch(uiMain->textBrowserIMUTestingForeArmPitch->toPlainText());
    itsExpIMUoffset.ForearmPitch = offsetForeArmPitch.toDouble();
    QVariant offsetForeArmRoll(uiMain->textBrowserIMUTestingForeArmRoll->toPlainText());
    itsExpIMUoffset.ForearmRoll = offsetForeArmRoll.toDouble();
    QVariant offsetForeArmYaw(uiMain->textBrowserIMUTestingForeArmYaw->toPlainText());
    itsExpIMUoffset.ForearmYaw = offsetForeArmYaw.toDouble();
    QVariant offsetUpArmPitch(uiMain->textBrowserIMUTestingUpperArmPitch->toPlainText());
    itsExpIMUoffset.UparmPitch = offsetUpArmPitch.toDouble();
    QVariant offsetUpArmRoll(uiMain->textBrowserIMUTestingUpperArmRoll->toPlainText());
    itsExpIMUoffset.UparmRoll = offsetUpArmRoll.toDouble();
    QVariant offsetUpArmYaw(uiMain->textBrowserIMUTestingUpperArmYaw->toPlainText());
    itsExpIMUoffset.UparmYaw = offsetUpArmYaw.toDouble();

    QMessageBox msgBox;
    msgBox.setText("Finishing calibration!");
    msgBox.exec();
}


void MappingAnalysis::IMUtestStopClick()
{
    IMUtestThread.terminate();
}

void MappingAnalysis::PostSavingClick()
{

    if (uiMain->checkBoxIMUTestingSaving->checkState() == Qt::Checked && uiMain->comboBoxIMUSaving->currentText()!= "<None>" )
    {
        qDebug("test");

        IMUtestThread.terminate();

        QString SavingPost = uiMain->comboBoxIMUSaving->currentText();
        //store data posture at file except current posture number data

        int noPosture=0;
        QString PostData[10][7];

        //store data of current posture that you want to save
        PostData[noPosture][0] = SavingPost;
        QVariant UpArmRoll1(uiMain->textBrowserIMUTestingUpperArmRoll->toPlainText());
        QVariant UpArmRoll2(UpArmRoll1.toDouble()-itsExpIMUoffset.UparmRoll);

        QVariant UpArmPitch1(uiMain->textBrowserIMUTestingUpperArmPitch->toPlainText());
        QVariant UpArmPitch2(UpArmPitch1.toDouble()-itsExpIMUoffset.UparmPitch);

        QVariant UpArmYaw1(uiMain->textBrowserIMUTestingUpperArmYaw->toPlainText());
        QVariant UpArmYaw2(UpArmYaw1.toDouble()-itsExpIMUoffset.UparmYaw);

        QVariant ForeArmRoll1(uiMain->textBrowserIMUTestingForeArmRoll->toPlainText());
        QVariant ForeArmRoll2(ForeArmRoll1.toDouble()-itsExpIMUoffset.ForearmRoll);

        QVariant ForeArmPitch1(uiMain->textBrowserIMUTestingForeArmPitch->toPlainText());
        QVariant ForeArmPitch2(ForeArmPitch1.toDouble()-itsExpIMUoffset.ForearmPitch);

        QVariant ForeArmYaw1(uiMain->textBrowserIMUTestingForeArmYaw->toPlainText());
        QVariant ForeArmYaw2(ForeArmYaw1.toDouble()-itsExpIMUoffset.ForearmYaw);

        PostData[noPosture][1] = UpArmRoll2.toString();
        PostData[noPosture][2] = UpArmPitch2.toString();
        PostData[noPosture][3] = UpArmYaw2.toString() ;
        PostData[noPosture][4] = ForeArmRoll2.toString() ;
        PostData[noPosture][5] = ForeArmPitch2.toString() ;
        PostData[noPosture][6] = ForeArmYaw2.toString() ;
        noPosture++;

        QString line;
        QStringList MasterPostData;
        //QFile MasterPostFile(":/MasterConfig/MasterPosture.txt");
        QFile MasterPostFile("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\MasterConfig\\MasterPosture.txt");

        if (MasterPostFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&MasterPostFile);
           while ( !in.atEnd() )
           {
              line = in.readLine();
              if (line != "")
              {
                  MasterPostData = line.split("|", QString::SkipEmptyParts);
                  QString postIndex = MasterPostData.at(0);
                  if (postIndex != SavingPost)
                  {
                      PostData[noPosture][0] = MasterPostData[0];
                      PostData[noPosture][1] = MasterPostData[1];
                      PostData[noPosture][2] = MasterPostData[2];
                      PostData[noPosture][3] = MasterPostData[3];
                      PostData[noPosture][4] = MasterPostData[4];
                      PostData[noPosture][5] = MasterPostData[5];
                      PostData[noPosture][6] = MasterPostData[6];
                      noPosture++;
                  }
              }
           }
        }

        //write new data into file
        MasterPostFile.remove();


        FILE *fp;

        QString dataline;

        for (int i=0; i<noPosture; i++)
        {
            if(PostData[i][0] != "")
            {
                dataline="";
                for (int j=0; j<6;j++)
                {
                    dataline = dataline + PostData[i][j] + "|";
                }
                dataline = dataline + PostData[i][6] + "\n";
                const char *str;
                QByteArray ba;
                ba = dataline.toLatin1();
                str = ba.data();
                //fp=fopen(":/MasterConfig/MasterPosture.txt", "a+");

                fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\MasterConfig\\MasterPosture.txt", "a+");
                fprintf(fp, str);
                fclose(fp);
            }

        }

        //print message
        QMessageBox msgBox;
        msgBox.setText("Finish storing Data!");
        msgBox.exec();


    }
}

void MappingAnalysis::showIMUdata()
{

    IMUtestData = IMUtestThread.data;
    uiMain->textBrowserIMUTestingUpperArmRoll->setText(QString::number(IMUtestData.UparmRoll,'f',2));
    uiMain->textBrowserIMUTestingUpperArmPitch->setText(QString::number(IMUtestData.UparmPitch,'f',2));
    uiMain->textBrowserIMUTestingUpperArmYaw->setText(QString::number(IMUtestData.UparmYaw,'f',2));
    uiMain->textBrowserIMUTestingForeArmRoll->setText(QString::number(IMUtestData.ForearmRoll,'f',2));
    uiMain->textBrowserIMUTestingForeArmPitch->setText(QString::number(IMUtestData.ForearmPitch,'f',2));
    uiMain->textBrowserIMUTestingForeArmYaw->setText(QString::number(IMUtestData.ForearmYaw,'f',2));
}


void MappingAnalysis::VibroTestStartClick()
{
    QString aString,bString,cString;

    aString = uiMain->comboBoxVibroTestingAxis->currentText();
    bString = uiMain->textEditVibroTestingStrength->toPlainText();
    cString = uiMain->textEditVibroTestingDuration->toPlainText();

    QVariant a(aString);
    QVariant b(bString);
    QVariant c(cString);

    VibroTestThread.getData(a.toInt(),b.toDouble(),c.toDouble());
    VibroTestThread.start();
}

void MappingAnalysis::VibroTestStopClick()
{
    VibroTestThread.terminate();

}

void MappingAnalysis::VibroTestL2HAmpClick()
{

    QextSerialPort *itsPort;
    itsPort = new QextSerialPort("COM2");
    itsPort->setBaudRate(BAUD57600);
    itsPort->setFlowControl(FLOW_OFF);
    itsPort->setParity(PAR_NONE);
    itsPort->setDataBits(DATA_8);
    itsPort->setStopBits(STOP_1);
    itsPort->open(QIODevice::WriteOnly);

    QByteArray msg;
    msg.resize(1);

    int i,j;
    for (i=0; i<= 10;i++)
    {
        for (j=1;j<=3;j++)
        {

            msg[0]=16*(int)(0.1*i*240/16)+(int)(15*i*0.1);
            itsPort->write(msg,1);
            Sleep(200);
            msg[0]=0;
            itsPort->write(msg,1);
            Sleep(200);

        }
    }
    msg[0]=0;
    itsPort->write(msg,1);
    Sleep(200);
    itsPort->close();
    return;
}

void MappingAnalysis::VibroTestHighAmpClick()
{

    QextSerialPort *itsPort;
    itsPort = new QextSerialPort("COM2");
    itsPort->setBaudRate(BAUD57600);
    itsPort->setFlowControl(FLOW_OFF);
    itsPort->setParity(PAR_NONE);
    itsPort->setDataBits(DATA_8);
    itsPort->setStopBits(STOP_1);
    itsPort->open(QIODevice::WriteOnly);

    QByteArray msg;
    msg.resize(1);

    int i;
    for (i=0; i<= 10;i++)
    {
        msg[0]=127;;
        itsPort->write(msg,1);
        Sleep(200);
        msg[0]=0;
        itsPort->write(msg,1);
        Sleep(200);
    }
    msg[0]=0;
    itsPort->write(msg,1);
    Sleep(200);
    itsPort->close();
    return;
}

void MappingAnalysis::VibroTestLowAmpClick()
{

    QextSerialPort *itsPort;
    itsPort = new QextSerialPort("COM2");
    itsPort->setBaudRate(BAUD57600);
    itsPort->setFlowControl(FLOW_OFF);
    itsPort->setParity(PAR_NONE);
    itsPort->setDataBits(DATA_8);
    itsPort->setStopBits(STOP_1);
    itsPort->open(QIODevice::WriteOnly);

    QByteArray msg;
    msg.resize(1);

    int i;
    for (i=0; i<= 10;i++)
    {
        msg[0]=119;
        itsPort->write(msg,1);
        Sleep(200);
        msg[0]=0;
        itsPort->write(msg,1);
        Sleep(200);

    }
    msg[0]=0;
    itsPort->write(msg,1);
    Sleep(200);
    itsPort->close();
    return;
}

void MappingAnalysis::VibroTestMappingPatternClick()
{

    QextSerialPort *itsPort;
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
    mag = 1;
    msg[0]=255;
    itsPort->write(msg,1);
    Sleep(4000);
    msg[0]=0;
    itsPort->write(msg,1);
    Sleep(200);
    itsPort->close();
    return;
}









/***********************************************************************
                                Configuration tab
************************************************************************/
void MappingAnalysis::ArmLengthStartClick()
{
    if (uiMain->comboBoxArmMeasureOption->currentText()== "Manual Measurement")
    {
        QMessageBox msgBox;
        msgBox.setText("Please measure your arm's length as following picture, then input data into textbox!");
        msgBox.exec();
        QString ImageDir = ":/ConfigImages/ArmMeasurement.png";
        QLabel *image = new QLabel();
        image->setWindowTitle("Measuring Arm-Length Instruction");
        image->resize(800,800);
        image->setPixmap( QPixmap( ImageDir ) );

        image->show();
    }

    if (uiMain->comboBoxArmMeasureOption->currentText()== "Automatical Measurement")
    {
        QMessageBox msgBox;
        msgBox.setText("Please handle steps as following video!");
        msgBox.exec();
    }

    if (uiMain->comboBoxArmMeasureOption->currentText()== "<None>")
    {
        QMessageBox msgBox;
        msgBox.setText("Please select OPTION!");
        msgBox.exec();
    }
}

void MappingAnalysis::ArmLengthRecClick()
{
    QVariant UpLength (uiMain->textEditUpperArmLength->toPlainText());
    QVariant ForeLength (uiMain->textEditForeArmLength->toPlainText());

    itsArmLengths.upperArm = UpLength.toDouble();
    itsArmLengths.foreArm = ForeLength.toDouble();
    /*
    QVariant a(itsArmLengths.upperArm);
    const char *str;
    QByteArray ba;
    ba = a.toString().toLatin1();
    str = ba.data();
    qDebug(str);*/

    QMessageBox msgBox;
    msgBox.setText("Arm lengths are stored!");
    msgBox.exec();
}

void MappingAnalysis::ThresholdRecClick()
{
    QVariant HandThresMax1 (uiMain->textEditHandThresholdMax1->toPlainText());
    QVariant HandThresMin1 (uiMain->textEditHandThresholdMin1->toPlainText());
    QVariant HandThresMax2 (uiMain->textEditHandThresholdMax2->toPlainText());
    QVariant HandThresMin2 (uiMain->textEditHandThresholdMin2->toPlainText());
    QVariant ElbowThresMin1 (uiMain->textEditElbowThresholdMin1->toPlainText());
    QVariant ElbowThresMin2 (uiMain->textEditElbowThresholdMin2->toPlainText());
    QVariant RollFAThresMin (uiMain->textEditRollFAThresholdMin->toPlainText());

    itsThreshold.Max1Process1 = HandThresMax1.toDouble();
    itsThreshold.Min1Process1 = HandThresMin1.toDouble();
    itsThreshold.Max2Process1 = HandThresMax2.toDouble();
    itsThreshold.Min2Process1 = HandThresMin2.toDouble();
    itsThreshold.Min1Process2 = ElbowThresMin1.toDouble();
    itsThreshold.Min2Process2 = ElbowThresMin2.toDouble();
    itsThreshold.MinProcess3 = RollFAThresMin.toDouble();

    QMessageBox msgBox;
    msgBox.setText("Thresholds are recorded!");
    msgBox.exec();
}
