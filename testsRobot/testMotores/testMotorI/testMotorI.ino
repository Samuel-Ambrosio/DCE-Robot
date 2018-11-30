/*
 * Programa de prueba del motor izquierdo que se encarga de hacer girar al eje
 * en ambos sentidos con esperas de 1s.
 */
const int Pin1_motor = 10;
const int Pin2_motor = 9;
int SpeedMotor = 250; // Control de velocidad con el pwm

void setup() {
  pinMode(Pin1_motor, OUTPUT); 
  pinMode(Pin2_motor, OUTPUT); 
}

void Stop()
{
  analogWrite(Pin1_motor,0);
  analogWrite(Pin2_motor,0);
}

void ReverseMotor(int SpeedMotor)
{
  analogWrite(Pin1_motor,SpeedMotor);
  analogWrite(Pin2_motor,0);
}

void ForwardMotor(int SpeedMotor)
{  
  analogWrite(Pin1_motor,0); 
  analogWrite(Pin2_motor,SpeedMotor);
}

void loop() {
  ReverseMotor(SpeedMotor);
  delay (1000);
  
  Stop();
  delay (1000);
  
  ForwardMotor(SpeedMotor);
  delay(1000);
}
