// RIGHT Motor
#define RMOTOR_DIR_FW     7     // forward
#define RMOTOR_DIR_BW     4     // backward
#define RMOTOR_PWM        5

// LEFT Motor
#define LMOTOR_DIR_FW    9    // forward
#define LMOTOR_DIR_BW    12   // backward
#define LMOTOR_PWM       6


#define MOTOR_FW        0
#define MOTOR_BW        1
#define MOTOR_RW        2
#define MOTOR_LW        3
#define MOTOR_STOP      4



int16_t pwmRM;
int16_t pwmLM;


void initMotor() 
{
  pinMode( RMOTOR_DIR_FW, OUTPUT );
  pinMode( RMOTOR_DIR_BW, OUTPUT );
 
  pinMode( LMOTOR_DIR_FW, OUTPUT );
  pinMode( LMOTOR_DIR_BW, OUTPUT );

  setDirout_RMotor(MOTOR_STOP);
  setDirout_LMotor(MOTOR_STOP);

  setPwm_RMotor(0);
  setPwm_LMotor(0);
}


void setPwm(int16_t pwmRM, int16_t pwmLM)
{
  if ( pwmRM >  255 )  pwmRM =  255;
  if ( pwmRM < -255 )  pwmRM = -255;

  if ( pwmLM >  255 ) pwmLM =  255;
  if ( pwmLM < -255 ) pwmLM = -255;

  if ( pwmRM == 0 )
  {
    setDirout_RMotor ( MOTOR_STOP );
    setPwm_RMotor ( 0 );
  }
  else if ( pwmRM > 0 )
  {
    setDirout_RMotor ( MOTOR_FW );
    setPwm_RMotor ( pwmRM);
  }
  else
  {
    setDirout_RMotor ( MOTOR_BW );
    setPwm_RMotor ( -pwmRM );
  }

  if ( pwmLM == 0 )
  {
    setDirout_LMotor ( MOTOR_STOP );
    setPwm_LMotor ( 0 );
  }
  else if (pwmLM > 0 )
  {
    setDirout_LMotor ( MOTOR_FW );
    setPwm_LMotor ( pwmLM);
  }
  else
  {
    setDirout_LMotor ( MOTOR_BW );
    setPwm_LMotor ( -pwmLM );
  }
}



void setPwm_RMotor(uint16_t pwmData)
{
  if(pwmData > 255) pwmData = 255;

  pwmRM = pwmData;

  analogWrite( RMOTOR_PWM, pwmData);  
}



void setPwm_LMotor(uint16_t pwmData)
{
  if(pwmData > 255) pwmData = 255;

  pwmLM = pwmData;

  analogWrite( LMOTOR_PWM, pwmData);  
}



void setDirout_RMotor(uint8_t DirData) 
{
  switch ( DirData )
  {
    case MOTOR_FW:
      digitalWrite( RMOTOR_DIR_FW, LOW );
      digitalWrite( RMOTOR_DIR_BW, HIGH);
      break;

    case MOTOR_BW:
      digitalWrite( RMOTOR_DIR_FW, HIGH );
      digitalWrite( RMOTOR_DIR_BW, LOW );
      break;

    case MOTOR_STOP:
      digitalWrite( RMOTOR_DIR_FW, LOW );
      digitalWrite( RMOTOR_DIR_BW, LOW );
      break;

    default:
      digitalWrite( RMOTOR_DIR_FW, LOW );
      digitalWrite( RMOTOR_DIR_BW, LOW );
      break;
  }
}

void setDirout_LMotor(uint8_t DirData) 
{
  switch ( DirData )
  {
    case MOTOR_FW:
      digitalWrite( LMOTOR_DIR_FW, LOW );
      digitalWrite( LMOTOR_DIR_BW, HIGH);
      break;

    case MOTOR_BW:
      digitalWrite( LMOTOR_DIR_FW, HIGH );
      digitalWrite( LMOTOR_DIR_BW, LOW );
      break;

    case MOTOR_STOP:
      digitalWrite( LMOTOR_DIR_FW, LOW );
      digitalWrite( LMOTOR_DIR_BW, LOW );
      break;

    default:
      digitalWrite( LMOTOR_DIR_FW, LOW );
      digitalWrite( LMOTOR_DIR_BW, LOW );
      break;
  }
}
