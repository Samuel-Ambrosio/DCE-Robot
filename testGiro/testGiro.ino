/*
 * Programa de prueba para giro 90º.
 */
const int Pin1_motorD = 5; //pin pwm
const int Pin2_motorD = 6; //pin pwm

const int Pin1_motorI = 10;
const int Pin2_motorI = 9;

const float ResolutionADC = 0.00488;


/* 3.3V +- */

void setup()
{
  pinMode(Pin1_motorD, OUTPUT); 
  pinMode(Pin2_motorD, OUTPUT);
  pinMode(Pin1_motorI, OUTPUT); 
  pinMode(Pin2_motorI, OUTPUT); 
}

void ForwardMotorD()
{  
  digitalWrite(Pin1_motorD,LOW); 
  digitalWrite(Pin2_motorD,HIGH);
}

void ForwardMotorI()
{  
  digitalWrite(Pin1_motorI,LOW); 
  digitalWrite(Pin2_motorI,HIGH);
}

void ReverseMotorD()
{
  digitalWrite(Pin1_motorD,HIGH);
  digitalWrite(Pin2_motorD,LOW);
}

void ReverseMotorI()
{
  digitalWrite(Pin1_motorI,HIGH);
  digitalWrite(Pin2_motorI,LOW);
}

void StopD()
{
  digitalWrite(Pin1_motorD,LOW);
  digitalWrite(Pin2_motorD,LOW);
}

void StopI()
{
  digitalWrite(Pin1_motorI,LOW);
  digitalWrite(Pin2_motorI,LOW);
}

void loop() {
  
   //
  float voltios;
  delay(300);
  voltios = analogRead(A6)*ResolutionADC;
  if(voltios < 3)
  {
      Serial.print("Carga baja: ");
      Serial.print(voltios);
      Serial.println(" v");
      
  }
  else
  {
      Serial.println("Voy a girar, apunta mi sentido: ");
      delay (2000);
      // GIRO 90º IZQUIERDA
      ForwardMotorD();
      ReverseMotorI();
      delay (500);

      StopD();
      StopI();
      delay(3000);
      
      Serial.println("Voy a girar, apunta mi sentido: ");
      delay (2000);
      // GIRO 90º DERECHA
      ForwardMotorI();
      ReverseMotorD();
      delay (500);

      StopD();
      StopI();
      delay(3000);
  }
}
