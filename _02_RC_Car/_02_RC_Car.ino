/* 
 *   CupDrone Robot V1.0
 *  
 *   CupDrone Libaries made by Baram
 *    Code made by SteamMaker
 *   
 *   2022.04.09  
 */
 
#include "MSP.h"


cMSP  MSP;


int16_t   Dir;
int16_t   Speed;

int16_t   pwm_RMotor;
int16_t   pwm_LMotor;


void setup() {
  // put your setup code here, to run once:
  pwm_RMotor  = 0;
  pwm_LMotor  = 0;

  MSP.begin();
  initMotor();

  Serial.begin(115200);
}



void loop() {
  // put your main code here, to run repeatedly:
  if ( MSP.update() == true )
  {
    Speed = MSP.Get_Pitch()  / 2;
    Dir   = MSP.Get_Roll() / 2;

    pwm_LMotor =  Speed - Dir;
    pwm_RMotor =  Speed + Dir;   
  }

  setPwm( pwm_RMotor, pwm_LMotor );  
}
