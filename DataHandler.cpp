#include "DataHandler.h"

#include "math.h"
#include <stdlib.h>
#define PI 3.14159265

DataHandler::DataHandler(){}

DataHandler::~DataHandler(){}


//*************************************************************************************************************************************************
//Mathematical functions

mat3x3 DataHandler::RotateZ(double angle)
{
    mat3x3 rotMatrix;
    rotMatrix.m11=cos(PI*angle/180);
    rotMatrix.m12=-sin(PI*angle/180);
    rotMatrix.m13=0;
    rotMatrix.m21=sin(PI*angle/180);
    rotMatrix.m22=cos(PI*angle/180);
    rotMatrix.m23=0;
    rotMatrix.m31=0;
    rotMatrix.m32=0;
    rotMatrix.m33=1;
    return rotMatrix;
}

mat3x3 DataHandler::RotateY(double angle)
{
    mat3x3 rotMatrix;
    rotMatrix.m11=cos(PI*angle/180);
    rotMatrix.m12=0;
    rotMatrix.m13=sin(PI*angle/180);
    rotMatrix.m21=0;
    rotMatrix.m22=1;
    rotMatrix.m23=0;
    rotMatrix.m31=-sin(PI*angle/180);
    rotMatrix.m32=0;
    rotMatrix.m33=cos(PI*angle/180);
    return rotMatrix;
}

mat3x3 DataHandler::RotateX(double angle)
{
    mat3x3 rotMatrix;
    rotMatrix.m11=1;
    rotMatrix.m12=0;
    rotMatrix.m13=0;
    rotMatrix.m21=0;
    rotMatrix.m22=cos(PI*angle/180);
    rotMatrix.m23=-sin(PI*angle/180);
    rotMatrix.m31=0;
    rotMatrix.m32=sin(PI*angle/180);
    rotMatrix.m33=cos(PI*angle/180);
    return rotMatrix;
}

mat3x1 DataHandler::IntVecMatrix(double a,double b, double c)
{
    mat3x1 matrix;
    matrix.m11=a;
    matrix.m21=b;
    matrix.m31=c;
    return matrix;
}

mat3x3 DataHandler::Multp_3x3n3x3(mat3x3 matrix1, mat3x3 matrix2)
{
    mat3x3  result;
    result.m11 = matrix1.m11*matrix2.m11+matrix1.m12*matrix2.m21+matrix1.m13*matrix2.m31;
    result.m12 = matrix1.m11*matrix2.m12+matrix1.m12*matrix2.m22+matrix1.m13*matrix2.m32;
    result.m13 = matrix1.m11*matrix2.m13+matrix1.m12*matrix2.m23+matrix1.m13*matrix2.m33;
    result.m21 = matrix1.m21*matrix2.m11+matrix1.m22*matrix2.m21+matrix1.m23*matrix2.m31;
    result.m22 = matrix1.m21*matrix2.m12+matrix1.m22*matrix2.m22+matrix1.m23*matrix2.m32;
    result.m23 = matrix1.m21*matrix2.m13+matrix1.m22*matrix2.m23+matrix1.m23*matrix2.m33;
    result.m31 = matrix1.m31*matrix2.m11+matrix1.m32*matrix2.m21+matrix1.m33*matrix2.m31;
    result.m32 = matrix1.m31*matrix2.m12+matrix1.m32*matrix2.m22+matrix1.m33*matrix2.m32;
    result.m33 = matrix1.m31*matrix2.m13+matrix1.m32*matrix2.m23+matrix1.m33*matrix2.m33;
    return result;
}

mat3x1 DataHandler::Multp_3x3n3x1(mat3x3 matrix1, mat3x1 matrix2)
{
    mat3x1  result;
    result.m11 = matrix1.m11*matrix2.m11+matrix1.m12*matrix2.m21+matrix1.m13*matrix2.m31;
    result.m21 = matrix1.m21*matrix2.m11+matrix1.m22*matrix2.m21+matrix1.m23*matrix2.m31;
    result.m31 = matrix1.m31*matrix2.m11+matrix1.m32*matrix2.m21+matrix1.m33*matrix2.m31;
    return result;
}

mat3x1 DataHandler::Sum_3x1n3x1(mat3x1 matrix1, mat3x1 matrix2)
{
    mat3x1 result;
    result.m11 = matrix1.m11+matrix2.m11;
    result.m21 = matrix1.m21+matrix2.m21;
    result.m31 = matrix1.m31+matrix2.m31;
    return result;
}

mat3x1 DataHandler::Subst_3x1n3x1(mat3x1 matrix1, mat3x1 matrix2)
{
    mat3x1 result;
    result.m11 = matrix1.m11-matrix2.m11;
    result.m21 = matrix1.m21-matrix2.m21;
    result.m31 = matrix1.m31-matrix2.m31;
    return result;
}



//****************************************************************************************************************
//Reference hand coordinate

//finding hand coordinate of student based on master posture
mat3x1 DataHandler::processDataStep1a(ArmPosture MasterPost, ArmLength StuArmLength)
{
    mat3x1 ForeArmVector = IntVecMatrix(StuArmLength.foreArm,0,0);

    mat3x1 UpArmVector = IntVecMatrix(StuArmLength.upperArm,0,0);

    mat3x3 mat1 = Multp_3x3n3x3(RotateZ(-MasterPost.UparmYaw),Multp_3x3n3x3(RotateY(-MasterPost.UparmPitch),RotateX(-MasterPost.UparmRoll)));

    mat3x1 mat2 = Multp_3x3n3x1( mat1,UpArmVector);

    mat3x3 mat3 = Multp_3x3n3x3(RotateX(MasterPost.ForearmRoll),Multp_3x3n3x3(RotateY(MasterPost.ForearmPitch),RotateZ(MasterPost.ForearmYaw)));

    mat3x1 mat4 = Multp_3x3n3x1(mat3,mat2);

    mat3x1 mat5 = Sum_3x1n3x1(mat4,ForeArmVector);

    mat3x3 mat6 = Multp_3x3n3x3(RotateZ(-MasterPost.ForearmYaw),Multp_3x3n3x3(RotateY(-MasterPost.ForearmPitch),RotateX(-MasterPost.ForearmRoll)));

    mat3x1 mat7 = Multp_3x3n3x1(mat6,mat5);

    return mat7;

}


RealCoordinate DataHandler::processDataStep1b(mat3x1 AnaHandCodinate, ArmPosture StudentPost, ArmLength StuArmLength)
{

//realtime data handling

    mat3x1 ForeArmVector = IntVecMatrix(StuArmLength.foreArm,0,0);

    mat3x1 UpArmVector = IntVecMatrix(StuArmLength.upperArm,0,0);

    mat3x3 mat1 = Multp_3x3n3x3(RotateZ(-StudentPost.UparmYaw),Multp_3x3n3x3(RotateY(-StudentPost.UparmPitch),RotateX(-StudentPost.UparmRoll)));

    mat3x1 mat2 = Multp_3x3n3x1( mat1,UpArmVector);

    mat3x3 mat3 = Multp_3x3n3x3(RotateX(StudentPost.ForearmRoll),Multp_3x3n3x3(RotateY(StudentPost.ForearmPitch),RotateZ(StudentPost.ForearmYaw)));

    mat3x1 mat4 = Multp_3x3n3x1(mat3,mat2);

    mat3x1 mat5 = Sum_3x1n3x1(mat4,ForeArmVector);

    mat3x3 mat6 = Multp_3x3n3x3(RotateZ(-StudentPost.ForearmYaw),Multp_3x3n3x3(RotateY(-StudentPost.ForearmPitch),RotateX(-StudentPost.ForearmRoll)));

    mat3x1 RealHandInFixedFrame = Multp_3x3n3x1(mat6,mat5);

//difference between actual and analysis
    RealCoordinate realdata;
    realdata.diff.x = abs(AnaHandCodinate.m11-RealHandInFixedFrame.m11); //consider return value is based on fixed frame
    realdata.diff.y = abs(AnaHandCodinate.m21-RealHandInFixedFrame.m21);
    realdata.diff.z = abs(AnaHandCodinate.m31-RealHandInFixedFrame.m31);
    realdata.actualCoor.x = RealHandInFixedFrame.m11;
    realdata.actualCoor.y = RealHandInFixedFrame.m21;
    realdata.actualCoor.z = RealHandInFixedFrame.m31;

    return realdata;

}



//****************************************************************************************************************
//Reference elbow coordinate

mat3x1 DataHandler::processDataStep2a(ArmPosture StudentPost, ArmLength StuArmLength)
{
    mat3x1 UpArmVector = IntVecMatrix(StuArmLength.upperArm,0,0);

    mat3x3 mat1 = Multp_3x3n3x3(RotateZ(-StudentPost.UparmYaw),Multp_3x3n3x3(RotateY(-StudentPost.UparmPitch),RotateX(-StudentPost.UparmRoll)));

    mat3x1 mat2 = Multp_3x3n3x1( mat1,UpArmVector);

    return mat2;
}


RealCoordinate DataHandler::processDataStep2b(mat3x1 AnaElbCodinate, ArmPosture StudentPost, ArmLength StuArmLength)
{

    //realtime value of elbow coordinate in shoulder frame
    mat3x1 UpArmVector = IntVecMatrix(StuArmLength.upperArm,0,0);

    mat3x3 mat1 = Multp_3x3n3x3(RotateZ(-StudentPost.UparmYaw),Multp_3x3n3x3(RotateY(-StudentPost.UparmPitch),RotateX(-StudentPost.UparmPitch)));

    mat3x1 RealElbCodinate = Multp_3x3n3x1( mat1,UpArmVector);

    RealCoordinate realdata;
    realdata.diff.x=abs(AnaElbCodinate.m11-RealElbCodinate.m11); //consider return value is based on fixed frame
    realdata.diff.y=abs(AnaElbCodinate.m21-RealElbCodinate.m21);
    realdata.diff.z=abs(AnaElbCodinate.m31-RealElbCodinate.m31);
    realdata.actualCoor.x = RealElbCodinate.m11;
    realdata.actualCoor.y = RealElbCodinate.m21;
    realdata.actualCoor.z = RealElbCodinate.m31;

    return realdata;

}

//****************************************************************************************************************
//Reference foreArm's orientation

double DataHandler::processDataStep3(ArmPosture MasterPost, ArmPosture StudentPost)
{
    double diff;
    diff=abs(MasterPost.ForearmRoll-StudentPost.ForearmRoll);
    return diff;
}
