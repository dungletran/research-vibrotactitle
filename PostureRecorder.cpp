#include "PostureRecorder.h"

#include "stdio.h"
#include "QString"
#include <QDate>
#include <QVariant>
#include <QTime>
#include <QByteArray>


PostureRecorder::PostureRecorder(){}

PostureRecorder::~PostureRecorder(){}

void PostureRecorder::recordData(RealtimeData recordingData, QString ExpType, errorStringValue error1_1,errorStringValue error1_2,errorStringValue error2_1,errorStringValue error2_2, double handMap1Instant, double elbowMap1Instant, double handMap2Instant, double elbowMap2Instant )
{
    //qDebug("Test");
    FILE *fp;
    //fp=fopen(":/MappingData/MappingData.txt", "a+");
    fp=fopen("D:\\File\\Tran Dung-Files\\Study in NTU\\Research\\GUI program\\FYP\\Current research\\FYP program\\QExtSerialPort library\\Projects\\MappingAnalysis-Learning\\MappingData\\MappingData.txt", "a+");
    //QDate date = QDate::currentDate();
    //QString dateString = date.toString();
    //QTime time = QTime::currentTime();
    //QString timeString = time.toString();

    QString string,angle;
    QVariant upRoll(recordingData.ArmAngles.UparmRoll);
    QVariant upPitch(recordingData.ArmAngles.UparmPitch);
    QVariant upYaw(recordingData.ArmAngles.UparmYaw);
    QVariant foreRoll(recordingData.ArmAngles.ForearmRoll);
    QVariant forePitch(recordingData.ArmAngles.ForearmPitch);
    QVariant foreYaw(recordingData.ArmAngles.ForearmYaw);
    QVariant HandCoordinateDiff(recordingData.HandCoordinateDiff);
    QVariant ElbowCoordinateDiff(recordingData.ElbowCoordinateDiff);
    QVariant ForeRollDeviations(recordingData.ForeRollDeviations);
    QVariant finishingTime(recordingData.time);
    QVariant handMap1Moment(handMap1Instant);
    QVariant elbowMap1Moment(elbowMap1Instant);
    QVariant handMap2Moment(handMap2Instant);
    QVariant elbowMap2Moment(elbowMap2Instant);

    angle = upRoll.toString() + "|" + upPitch.toString() + "|" + upYaw.toString() + "|" +
            foreRoll.toString() + "|" + forePitch.toString() + "|" + foreYaw.toString() + "|" ;
    string = "Start Date|" + recordingData.startDate + "|Start Time|" + recordingData.startTime + "|Post Index|" + recordingData.PostIndex + "|Student Index|" + recordingData.CandidateNumber + "|ExpType|" + ExpType + "|" +
            "Final IMU angles(Up-Fore,Roll-Pitch-Yaw)|" + angle +
            "Error 1-1|" + error1_1.HandCoordinateDiff + "|" + error1_1.ElbowCoordinateDiff + "|" + error1_1.ForeRollDeviations + "|Moment 1-1|" + handMap1Moment.toString() + "|" +
            "Error 1-2|" + error1_2.HandCoordinateDiff + "|" + error1_2.ElbowCoordinateDiff + "|" + error1_2.ForeRollDeviations + "|Moment 1-2|" + elbowMap1Moment.toString() + "|" +
            "Error 2-1|" + error2_1.HandCoordinateDiff + "|" + error2_1.ElbowCoordinateDiff + "|" + error2_1.ForeRollDeviations + "|Moment 2-1|" + handMap2Moment.toString() + "|" +
            "Error 2-2|" + error2_2.HandCoordinateDiff + "|" + error2_2.ElbowCoordinateDiff + "|" + error2_2.ForeRollDeviations + "|Moment 2-2|" + elbowMap2Moment.toString() + "|" +
            "Final error|" + HandCoordinateDiff.toString() + "|" + ElbowCoordinateDiff.toString() + "|" + ForeRollDeviations.toString() + "|Finish Time|" + finishingTime.toString() + "|" + "\n";

    const char *str;
    QByteArray ba;
    ba = string.toLatin1();
    str = ba.data();

    fprintf(fp, str);
    fclose(fp);
}
