/*
     CupDrone Reo LineTracer Edu V1.0

     CupDrone Libaries made by Baram
     Code made by SteamMaker

     2022. 04. 09
*/
     
const byte sensroRight = 5;
const byte sensorLeft = 3;


void setup() {
  // put your setup code here, to run once:
  initMotor();

  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  int valRight = analogRead(1);
  int valLeft = analogRead(2);

  if (valRight < 100 && valLeft > 100) {
    setDirout_RMotor(1); setPwm_RMotor(150);
    setDirout_LMotor(0); setPwm_LMotor(20);
  } else if (valRight > 100 && valLeft < 100) {
    setDirout_RMotor(0); setPwm_RMotor(20);
    setDirout_LMotor(1); setPwm_LMotor(150);
  } else {
    setDirout_RMotor(0); setPwm_RMotor(100);
    setDirout_LMotor(0); setPwm_LMotor(100);
  }
}
