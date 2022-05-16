#include "Motor.h"

Rover_Motor Motor;

int echoPin = 3;
int trigPin = 2;

float getDistance();

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  

  Motor.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float dist = getDistance();
  Serial.println(dist);
  
  if (dist < 10) { //장애물 감지 (20cm 이내)
    //Serial.println("stop");
    Motor.Set_Pwm(0, 0); 
    //Serial.println("backward");
    delay(500);
    Motor.Set_Pwm(-100, -100); 
    delay(500);
    
    int rnd = random(0, 2); //장애물 감지시 좌/우회전 랜덤처리
    
    if (rnd == 0) {
      //Serial.println("right");
      Motor.Set_Pwm(100, 0); 
      delay(500);
    } else {
      //Serial.println("left");
      Motor.Set_Pwm(0, 100);
      delay(500); 
    }
  } else {        //장애물 없음
    Serial.println("forward");
    Motor.Set_Pwm(100, 100); 
  }
}

float getDistance() {
  float duration, distance;

  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;
  //Serial.print(distance);
  //Serial.println("cm");  
  //delay(500);

  return distance;
}
