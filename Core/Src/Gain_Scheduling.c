/*
 * Gain_Scheduling.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Kaan Uçar
 */

#include "Gain_Scheduling.h"

float Theta_Gain_Set_0_30[3] = {5.1838, 0.3882, 0};
float Theta_Gain_Set_30_50[3] = {13.3647, 11.0223, 2.8432};
float Theta_Gain_Set_50_70[3] = {8.6375, 6.8440, 0.9271};
float Theta_Gain_Set_70_90[3] = {10.5412, 5.6494, 0.5228};

float Phi_Gain_Set_0_30[3] = {5.1838, 0.3882, 0};
float Phi_Gain_Set_30_50[3] = {5.1838, 0.3882, 0};
float Phi_Gain_Set_50_70[3] = {5.1838, 0.3882, 0};
float Phi_Gain_Set_70_90[3] = {5.1838, 0.3882, 0};

float Psi_Gain_Set_0_30[3] = {5.1838, 0.3882, 0};
float Psi_Gain_Set_30_50[3] = {5.1838, 0.3882, 0};
float Psi_Gain_Set_50_70[3] = {5.1838, 0.3882, 0};
float Psi_Gain_Set_70_90[3] = {5.1838, 0.3882, 0};

void scheduleGains(float *rollGainSet, float *pitchGainSet, float *yawGainSet, float phi_deg, float theta_deg, float psi_deg)
{
	float Kp_phi, Kd_phi, Ki_phi, Kp_theta, Kd_theta, Ki_theta, Kp_psi, Kd_psi, Ki_psi;

	// ROLL GAINS SCHEDULING:
	if (phi_deg >= 0 && phi_deg < 30)
	{
	    Kp_phi = Phi_Gain_Set_0_30[0];
	    Kd_phi = Phi_Gain_Set_0_30[1];
	    Ki_phi = Phi_Gain_Set_0_30[2];
	}
	else if (phi_deg >= 30 && phi_deg < 50)
	{
	    Kp_phi = Phi_Gain_Set_30_50[0];
	    Kd_phi = Phi_Gain_Set_30_50[1];
	    Ki_phi = Phi_Gain_Set_30_50[2];
	}
	else if (phi_deg >= 50 && phi_deg < 70)
	{
	    Kp_phi = Phi_Gain_Set_50_70[0];
	    Kd_phi = Phi_Gain_Set_50_70[1];
	    Ki_phi = Phi_Gain_Set_50_70[2];
	}
	else if (phi_deg >= 70 && phi_deg < 90)
	{
	    Kp_phi = Phi_Gain_Set_70_90[0];
	    Kd_phi = Phi_Gain_Set_70_90[1];
	    Ki_phi = Phi_Gain_Set_70_90[2];
	}
	else
	{
	    Kp_phi = Phi_Gain_Set_0_30[0];
	    Kd_phi = Phi_Gain_Set_0_30[1];
	    Ki_phi = Phi_Gain_Set_0_30[2];
	}

	// PITCH GAIN SCHEDULING:
	if (theta_deg >= 0 && theta_deg < 30)
	{
	    Kp_theta = Theta_Gain_Set_0_30[0];
	    Kd_theta = Theta_Gain_Set_0_30[1];
	    Ki_theta = Theta_Gain_Set_0_30[2];
	}
	else if (theta_deg >= 30 && theta_deg < 50)
	{
	    Kp_theta = Theta_Gain_Set_30_50[0];
	    Kd_theta = Theta_Gain_Set_30_50[1];
	    Ki_theta = Theta_Gain_Set_30_50[2];
	}
	else if (theta_deg >= 50 && theta_deg < 70)
	{
	    Kp_theta = Theta_Gain_Set_50_70[0];
	    Kd_theta = Theta_Gain_Set_50_70[1];
	    Ki_theta = Theta_Gain_Set_50_70[2];
	}
	else if (theta_deg >= 70 && theta_deg < 90)
	{
	    Kp_theta = Theta_Gain_Set_70_90[0];
	    Kd_theta = Theta_Gain_Set_70_90[1];
	    Ki_theta = Theta_Gain_Set_70_90[2];
	}
	else
	{
	    Kp_theta = Theta_Gain_Set_0_30[0];
	    Kd_theta = Theta_Gain_Set_0_30[1];
	    Ki_theta = Theta_Gain_Set_0_30[2];
	}

	// YAW GAIN SCHEDULING:
	if (psi_deg >= 0 && psi_deg < 30)
	{
	    Kp_psi = Psi_Gain_Set_0_30[0];
	    Kd_psi = Psi_Gain_Set_0_30[1];
	    Ki_psi = Psi_Gain_Set_0_30[2];
	}
	else if (psi_deg >= 30 && psi_deg < 50)
	{
	    Kp_psi = Psi_Gain_Set_30_50[0];
	    Kd_psi = Psi_Gain_Set_30_50[1];
	    Ki_psi = Psi_Gain_Set_30_50[2];
	}
	else if (psi_deg >= 50 && psi_deg < 70)
	{
	    Kp_psi = Psi_Gain_Set_50_70[0];
	    Kd_psi = Psi_Gain_Set_50_70[1];
	    Ki_psi = Psi_Gain_Set_50_70[2];
	}
	else if (psi_deg >= 70 && psi_deg < 90)
	{
	    Kp_psi = Psi_Gain_Set_70_90[0];
	    Kd_psi = Psi_Gain_Set_70_90[1];
	    Ki_psi = Psi_Gain_Set_70_90[2];
	}
	else
	{
	    Kp_psi = Psi_Gain_Set_0_30[0];
	    Kd_psi = Psi_Gain_Set_0_30[1];
	    Ki_psi = Psi_Gain_Set_0_30[2];
	}


    rollGainSet[0] = Kp_phi;
    rollGainSet[1] = Kd_phi;
    rollGainSet[2] = Ki_phi;

    pitchGainSet[0] = Kp_theta;
    pitchGainSet[1] = Kd_theta;
    pitchGainSet[2] = Ki_theta;

    yawGainSet[0] = Kp_psi;
    yawGainSet[1] = Kd_psi;
    yawGainSet[2] = Ki_psi;

}

