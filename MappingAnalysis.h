//============================================================================
//
//  File Name:     MappingAnalysis.h
//  Description:   Main Program
//  Created:       17/06/2011
//  Author:        Tran Le Dung
//
//  History:
//=============================================================================

#ifndef MAPPINGANALYSIS_H
#define MAPPINGANALYSIS_H

#include <MainStructure.h>
#include <QMainWindow>
#include <QTextBrowser>
#include <QComboBox>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QTextEdit>
#include <QLabel>

#include "DataCalculatingThread.h"
#include "VibroThread.h"
#include "testingIMUthread.h"
#include "testingVibroThread.h"
#include "time.h"


namespace Ui {
    class MappingAnalysis;
}
//main function-dealing with tasks of 3tabs in window
class MappingAnalysis : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    explicit MappingAnalysis(QWidget *parent = 0);
    //destructor
    ~MappingAnalysis();


//experiment tab

    //error after each mapping
    errorStringValue error1_1,error1_2;
    errorStringValue error2_1,error2_2;

    //mapping time recording
    clock_t init, final;
    double MappingTime;
    showSet DataSet;
    QString startTime;
    QString startDate;

    //moment hand, elbow, roll forearm are mapped
    double handMap1Instant;
    double elbowMap1Instant;
    double handMap2Instant;
    double elbowMap2Instant;

    //extract and calculating thread
    DataCalculatingThread calThread;
    //make tactile vibrating thread
    VibroThread vibroThread;

    //get Master data from file
    bool getPost();
    void show_target_para();
    ArmPosture itsMasterPost;
    ArmPosture itsTestingIMUoffset;
    ArmPosture itsExpIMUoffset;

    //experimental setting
    bool actVision;
    bool actVibro;
    bool actVideo;
    bool actPic;

    //varibale
    ArmLength itsArmLengths;

    //calibration
    QPushButton *pushButtonExpCalibration;

    //reference Posture
    QLabel *labelMappingType;
    QComboBox *comboBoxNumberLoop;
    QComboBox *comboBoxMasterSelection; //slecting reference posture
    QComboBox *comboBoxCandidateNumber;
    QTextBrowser *textBrowserMasterUpRoll;
    QTextBrowser *textBrowserMasterUpPitch;
    QTextBrowser *textBrowserMasterUpYaw;
    QTextBrowser *textBrowserMasterForeArmRoll;
    QTextBrowser *textBrowserMasterForeArmPitch;
    QTextBrowser *textBrowserMasterForeArmYaw;
    QTextBrowser *textBrowserHandCoorTargetX;
    QTextBrowser *textBrowserHandCoorTargetY;
    QTextBrowser *textBrowserHandCoorTargetZ;
    QTextBrowser *textBrowserElbowCoorTargetX;
    QTextBrowser *textBrowserElbowCoorTargetY;
    QTextBrowser *textBrowserElbowCoorTargetZ;
    QTextBrowser *textBrowserForeArmRollTarget;



    //Vision, VibroFeedback optiton
    QComboBox *comboBoxExpVisionPicVideoSelection;
    QComboBox *comboBoxExpSimSeqSelection;
    QRadioButton *radioButtonExpVisionON;
    QRadioButton *radioButtonExpVisionOFF;
    QRadioButton *radioButtonExpVibroON;
    QRadioButton *radioButtonExpVibroOFF;
    QPushButton *pushButtonExpVisionShow;

    //realtime data
    QPushButton *pushButtonExpStart;
    QPushButton *pushButtonExpStop;
    QPushButton *pushButtonExpRecord;
    QTextBrowser *textBrowserStudentUpRoll;
    QTextBrowser *textBrowserStudentUpPitch;
    QTextBrowser *textBrowserStudentUpYaw;
    QTextBrowser *textBrowserStudentForeArmRoll;
    QTextBrowser *textBrowserStudentForeArmPitch;
    QTextBrowser *textBrowserStudentForeArmYaw;
    QTextBrowser *textBrowserHandCoorDelta;
    QTextBrowser *textBrowserElbowCoorDelta;
    QTextBrowser *textBrowserForeRollAngleDelta;
    QTextBrowser *textBrowserHandCoorActualX;
    QTextBrowser *textBrowserHandCoorActualY;
    QTextBrowser *textBrowserHandCoorActualZ;
    QTextBrowser *textBrowserElbowCoorActualX;
    QTextBrowser *textBrowserElbowCoorActualY;
    QTextBrowser *textBrowserElbowCoorActualZ;
    QTextBrowser *textBrowserForeArmRollActual;

//testing tab

    testingIMUthread IMUtestThread;
    testingVibroThread VibroTestThread;
    ArmPosture IMUtestData;

    //IMU testing
    QPushButton *pushButtonIMUTestingStop;
    QPushButton *pushButtonIMUTestingTest;
    QPushButton *pushButtonIMUTestingCalibration;
    QTextBrowser *textBrowserIMUTestingUpperArmRoll;
    QTextBrowser *textBrowserIMUTestingUpperArmPitch;
    QTextBrowser *textBrowserIMUTestingUpperArmYaw;
    QTextBrowser *textBrowserIMUTestingForeArmRoll;
    QTextBrowser *textBrowserIMUTestingForeArmPitch;
    QTextBrowser *textBrowserIMUTestingForeArmYaw;
    QComboBox *comboBoxIMUSaving;
    QCheckBox *checkBoxIMUTestingSaving;
    QPushButton *pushButtontextBrowserIMUTestingRecord;

    //Vibro testing
    QPushButton *pushButtonVibroTestingStop;
    QPushButton *pushButtonVibroTestingL2HAmp;
    QPushButton *pushButtonVibroTestingLowAmp;
    QPushButton *pushButtonVibroTestingHighAmp;
    QPushButton *pushButtonVibroTestingMappingPattern;
    QPushButton *pushButtonVibroTestingTest;
    QComboBox *comboBoxVibroTestingAxis;
    QTextEdit *textEditVibroTestingStrength;
    QTextEdit *textEditVibroTestingDuration;



//Configuration tab

    QPushButton *pushButtonArmMeasureRecord;
    QPushButton *pushButtonArmMeasureStart;
    QComboBox *comboBoxArmMeasureOption;
    QTextBrowser *textEditUpperArmLength;
    QTextBrowser *textEditForeArmLength;
    QTextEdit *textEditHandThresholdMax1;
    QTextEdit *textEditHandThresholdMin1;
    QTextEdit *textEditHandThresholdMax2;
    QTextEdit *textEditHandThresholdMin2;
    QTextEdit *textEditElbowThresholdMin1;
    QTextEdit *textEditElbowThresholdMin2;
    QTextEdit *textEditRollFAThresholdMin;
    QPushButton *pushButtonThresholdRecord;
    ThresholdSet itsThreshold;

//UI
    Ui::MappingAnalysis *uiMain;



public slots:
//experiment tab
    void RecordFinishTime();
    void RecordFinishTimeElbow2();
    void RecordFinishTimeElbow1();
    void RecordFinishTimeHand1();
    void RecordFinishTimeHand2();
    void sendData2Vibro();
    void showExpData();
    void expStartClick();
    void expStopClick();
    void expRecordClick();
    void expShowClick();
    void expCalibrationClick();

//testing tab
    void showIMUdata();
    void VibroTestStartClick();
    void VibroTestStopClick();
    void PostSavingClick();
    void IMUtestStartClick();
    void IMUtestStopClick();
    void IMUtestCalibrationClick();
    void VibroTestL2HAmpClick();
    void VibroTestLowAmpClick();
    void VibroTestHighAmpClick();
    void VibroTestMappingPatternClick();

//Configuration tab
    void ArmLengthStartClick();
    void ArmLengthRecClick();
    void ThresholdRecClick();
};



#endif // MAPPINGANALYSIS_H
