/*
 * Programa de prueba del motor derecho que se encarga de hacer girar al eje
 * en ambos sentidos con esperas de 1s.
 */
const int Pin1_motorD = 5; //pin pwm
const int Pin2_motorD = 6; //pin pwm
int SpeedMotor = 250; // Control de velocidad con el pwm

void setup() {
  pinMode(Pin1_motorD, OUTPUT); 
  pinMode(Pin2_motorD, OUTPUT); 
}

void Stop()
{
  analogWrite(Pin1_motorD,0);
  analogWrite(Pin2_motorD,0);
}

void ReverseMotor(int SpeedMotor)
{
  analogWrite(Pin1_motorD,SpeedMotor);
  analogWrite(Pin2_motorD,0);
}

void ForwardMotor(int SpeedMotor)
{  
  analogWrite(Pin1_motorD,0); 
  analogWrite(Pin2_motorD,SpeedMotor);
}

void loop() {
  ReverseMotor(SpeedMotor);
  delay (1000);
  
  Stop();
  delay (1000);
  
  ForwardMotor(SpeedMotor);
  delay(1000);
}
