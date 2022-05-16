/*
     CupDrone Reo Sensor Check Edu V1.0

     CupDrone Libaries made by Baram
     Code made by SteamMaker

     2022. 04. 09
*/

const byte sensorRight = A5;
const byte sensorLeft = A3;

int valRight = 0;
int valLeft = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  valRight = analogRead(sensorRight);
  valLeft = analogRead(sensorLeft);

  Serial.print("Right : "); Serial.print(valRight);
  Serial.print("   ");
  Serial.print("Left : "); Serial.println(valLeft);
}
