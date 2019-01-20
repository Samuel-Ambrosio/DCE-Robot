/*
 *  Programa de prueba del motor izquierdo que se encarga de hacer girar al eje
 *  en ambos sentidos con esperas de 1s.
 */

const int Pin1_motor = 10;
const int Pin2_motor = 9;
int SpeedMotor = 250; // Control de velocidad con el pwm

void setup()
{
    pinMode(Pin1_motor, OUTPUT); 
    pinMode(Pin2_motor, OUTPUT); 
}

void Stop()
{
  digitalWrite(Pin1_motor,LOW);
  digitalWrite(Pin2_motor,LOW);
}

void ReverseMotor()
{
  digitalWrite(Pin1_motor,HIGH);
  digitalWrite(Pin2_motor,LOW);
}

void ForwardMotor()
{  
  digitalWrite(Pin1_motor,LOW); 
  digitalWrite(Pin2_motor,HIGH);
}

void loop()
{
    ReverseMotor();
    delay (1000);
    
    Stop();
    delay (1000);
    
    ForwardMotor();
    delay(1000);
}
