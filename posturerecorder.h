//============================================================================
//
//  File Name:     PostureRecorder.h
//  Description:   recording student posture data
//  Created:       17/06/2011
//  Author:        Tran Le Dung
//
//  History:
//=============================================================================


#ifndef POSTURERECORDER_H
#define POSTURERECORDER_H

#include <MainStructure.h>

class PostureRecorder
{
public:
    PostureRecorder();
    ~PostureRecorder();
    void recordData(RealtimeData recordingData, QString ExpType,
                    errorStringValue error1_1,errorStringValue error1_2,errorStringValue error2_1,errorStringValue error2_2,
                    double handMap1Instant, double elbowMap1Instant, double handMap2Instant, double elbowMap2Instant );
};

#endif // POSTURERECORDER_H
