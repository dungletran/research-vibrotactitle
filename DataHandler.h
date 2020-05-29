//============================================================================
//
//  File Name:     DataHandler.h
//  Description:   Calculating corresponding data in student frame from master frame
//  Created:       17/06/2011
//  Author:        Tran Le Dung
//
//  History:
//=============================================================================


#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <MainStructure.h>

class DataHandler
{
public:
    DataHandler();
    ~DataHandler();

    mat3x3 RotateZ(double angle);
    mat3x3 RotateY(double angle);
    mat3x3 RotateX(double angle);

    mat3x1 Multp_3x3n3x1(mat3x3 matrix1, mat3x1 matrix2);
    mat3x3 Multp_3x3n3x3(mat3x3 matrix1, mat3x3 matrix2);
    mat3x1 Sum_3x1n3x1(mat3x1 matrix1, mat3x1 matrix2);
    mat3x1 Subst_3x1n3x1(mat3x1 matrix1, mat3x1 matrix2);
    mat3x1 IntVecMatrix(double a,double b, double c);

    mat3x1 processDataStep1a(ArmPosture MasterPost, ArmLength StuArmLength);
    RealCoordinate processDataStep1b(mat3x1 AnaHandCodinate, ArmPosture StudentPost, ArmLength StuArmLength);
    mat3x1 processDataStep2a(ArmPosture StudentPost, ArmLength StuArmLength);
    RealCoordinate processDataStep2b(mat3x1 AnaElbCodinate, ArmPosture StudentPost, ArmLength StuArmLength);
    double processDataStep3(ArmPosture MasterPost, ArmPosture StudentPost);

};

#endif // DATAHANDLER_H
