//============================================================================
//
//  File Name:     MainStructure.h
//  Description:   Declare structures
//  Created:       17/06/2011
//  Author:        Tran Le Dung
//
//  History:
//=============================================================================

#ifndef MAINSTRUCTURE_H
#define MAINSTRUCTURE_H

#include "QString"

struct mat3x3
{
    double m11, m12, m13, m21, m22, m23, m31, m32, m33;
};

struct mat3x1
{
    double m11, m21, m31;
};

struct RotationSet
{
    double rollAngle;
    double pitchAngle;
    double yawAngle;
};



struct ArmPosture
{
    double UparmRoll;
    double UparmPitch;
    double UparmYaw;
    double ForearmRoll;
    double ForearmPitch;
    double ForearmYaw;
};

struct ArmLength
{
    double upperArm;
    double foreArm;
};


struct Coordinate
{
    double x;
    double y;
    double z;
};

struct RealCoordinate
{
    Coordinate actualCoor;
    Coordinate diff;
};

struct RealtimeData
{
    //Candidate Number
    QString CandidateNumber;
    //Master postureIndex
    QString PostIndex;
    //hand coordinate
    double HandCoordinateDiff;
    //Arm angle
    ArmPosture ArmAngles;
    //elbow coordinate
    double ElbowCoordinateDiff;
    //roll Deviation of forearm
    double ForeRollDeviations;
    //hand coordinate
    Coordinate HandCoordinate;
    //elbow coordinate
    Coordinate ElbowCoordinate;
    //time done mapping
    double  time;
    //start time;
    QString startTime;
    //start date
    QString startDate;

};

struct errorStringValue
{
    QString HandCoordinateDiff;
    QString ElbowCoordinateDiff;
    QString ForeRollDeviations;

};

struct showSet
{
    ArmPosture posture;
    //hand coordinate
    double HandCoordinateDiff;
    //elbow coordinate
    double ElbowCoordinateDiff;
    //roll Deviation of forearm
    double ForeRollDeviations;
    //hand coordinate
    Coordinate HandCoordinate;
    //elbow coordinate
    Coordinate ElbowCoordinate;
};


struct ThresholdSet
{
    double Max1Process1,Min1Process1,Max2Process1,Min2Process1,Min1Process2,Min2Process2,MinProcess3;
};


#endif // MAINSTRUCTURE_H
