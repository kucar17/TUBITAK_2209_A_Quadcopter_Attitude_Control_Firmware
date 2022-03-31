/*
 * PID.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Kaan
 */

#include "PID.h"
#include "simpMat.h"

void calculatePID(float *outputPID, float error, float *errorInt, float *errorPrv, float Kp, float Ki, float Kd, float dt)
{
	*errorInt += error * dt;
	*outputPID = (Kp * error) + (Ki * *errorInt) + Kd * ((error - *errorPrv)/dt);
	*errorPrv = error;

}

float saturatePID(float outputPID, float outputMax, float outputMin, float outputDefault)
{
	if (outputPID >= outputMin && outputPID <= outputMax)
	{
		return outputPID;
	}
	else if (outputPID > outputMax)
	{
		return outputMax;
	}
	else if (outputPID < outputMin)
	{
		return outputMax;
	}
	else
	{
		return outputDefault;
	}
}

void motorMixing(simpMat *invMatrix, float U1_des, float U2_des, float U3_des, float U4_des, simpMat *rotorsSquared)
{
    simpMat inputsMatrix;
    float toAppend[4] = {U1_des, U2_des, U3_des, U4_des};
    simpMat_Init(&inputsMatrix, 4, 1, toAppend);
    simpMat_Multiply(rotorsSquared, invMatrix, &inputsMatrix);
}


