// RIGHT Motor
#define RMOTOR_DIR_FW     7     // forward
#define RMOTOR_DIR_BW     4     // backward
#define RMOTOR_PWM        5

// LEFT Motor
#define LMOTOR_DIR_FW    9    // forward
#define LMOTOR_DIR_BW    12   // backward
#define LMOTOR_PWM       6


void setup() {
  // put your setup code here, to run once:
  pinMode( RMOTOR_DIR_FW, OUTPUT );
  pinMode( RMOTOR_DIR_BW, OUTPUT );
 
  pinMode( LMOTOR_DIR_FW, OUTPUT );
  pinMode( LMOTOR_DIR_BW, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RMOTOR_DIR_FW, HIGH);
  digitalWrite(RMOTOR_DIR_BW, LOW);
  analogWrite(RMOTOR_PWM, 100);

  digitalWrite(LMOTOR_DIR_FW, HIGH);
  digitalWrite(LMOTOR_DIR_BW, LOW);
  analogWrite(LMOTOR_PWM, 100);

  delay(1000);

  digitalWrite(RMOTOR_DIR_FW, LOW);
  digitalWrite(RMOTOR_DIR_BW, HIGH);
  analogWrite(RMOTOR_PWM, 100);

  digitalWrite(LMOTOR_DIR_FW, LOW);
  digitalWrite(LMOTOR_DIR_BW, HIGH);
  analogWrite(LMOTOR_PWM, 100);

  delay(1000);  
}
