/*
 * Programa de prueba para giro 90º.
 */
const int Pin1_motorD = 5; //pin pwm
const int Pin2_motorD = 6; //pin pwm

const int Pin1_motorI = 10;
const int Pin2_motorI = 9;

int SpeedMotor = 250; // Control de velocidad con el pwm

void setup()
{
  pinMode(Pin1_motorD, OUTPUT); 
  pinMode(Pin2_motorD, OUTPUT);
  pinMode(Pin1_motorI, OUTPUT); 
  pinMode(Pin2_motorI, OUTPUT); 
}

void ForwardMotor(int SpeedMotor)
{  
  analogWrite(Pin1_motorD,0); 
  analogWrite(Pin2_motorD,SpeedMotor);
}

void ForwardMotor(int SpeedMotor)
{  
  analogWrite(Pin1_motorI,0); 
  analogWrite(Pin2_motorI,SpeedMotor);
}