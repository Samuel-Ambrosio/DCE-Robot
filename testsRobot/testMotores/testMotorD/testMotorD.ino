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
  digitalWrite(Pin1_motorD,LOW);
  digitalWrite(Pin2_motorD,LOW);
}


void ReverseMotor()
{
  digitalWrite(Pin1_motorD,HIGH);
  digitalWrite(Pin2_motorD,LOW);
}

void ForwardMotor()
{  
  digitalWrite(Pin1_motorD,LOW); 
  digitalWrite(Pin2_motorD,HIGH);
}

void loop() {
  ReverseMotor();
  delay (1000);
  
  Stop();
  delay (1000);
  
  ForwardMotor();
  delay(1000);
}
