/*
 * Gain_Scheduling.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Kaan Uçar
 */

#ifndef INC_GAIN_SCHEDULING_H_
#define INC_GAIN_SCHEDULING_H_

void scheduleGains(float *rollGainSet, float *pitchGainSet, float *yawGainSet, float phi_deg, float theta_deg, float psi_deg);

#endif /* INC_GAIN_SCHEDULING_H_ */
