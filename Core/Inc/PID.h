/*
 * PID.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Kaan Uçar
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "simpMat.h"

void calculatePID(float *outputPID, float error, float *errorInt, float *errorPrv, float Kp, float Ki, float Kd, float dt);

float saturatePID(float outputPID, float outputMax, float outputMin, float outputDefault);

void motorMixing(simpMat *invMatrix, float U1_des, float U2_des, float U3_des, float U4_des, simpMat *rotorsSquared);

#endif /* INC_PID_H_ */
