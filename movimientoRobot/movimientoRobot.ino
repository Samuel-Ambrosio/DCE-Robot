/*
 * Avance teniendo en cuenta las lineas negras
 */

 const int tiempoAvance = 800;

//izquierda-delante
const int CNY_1 = A1;
//derecha-frente
const int CNY_2 = A0;
//izquierda-atras
const int CNY_3 = A2;
//derecha-atras
const int CNY_4 = A5;

bool A0negro=false;
bool A1negro=false;
bool A2negro=false;
bool A5negro=false;

const int negro=800;

int Value_CNY_Pin_IF = 0; //Valor que leera el sensor
int Value_CNY_Pin_DF = 0; //Valor que leera el sensor
int Value_CNY_Pin_IA = 0; //Valor que leera el sensor
int Value_CNY_Pin_DA = 0; //Valor que leera el sensor

const int Pin1_motorD = 5; //pin pwm
const int Pin2_motorD = 6; //pin pwm

const int Pin1_motorI = 10;
const int Pin2_motorI = 9;

const float ResolutionADC = 0.00488;

/* 3.45V +- */

void setup()
{
  pinMode(Pin1_motorD, OUTPUT); 
  pinMode(Pin2_motorD, OUTPUT);
  pinMode(Pin1_motorI, OUTPUT); 
  pinMode(Pin2_motorI, OUTPUT); 
  Serial.begin(9600); // inicializamos el puerto serie
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

void CNY1 ()
{
  Value_CNY_Pin_IF = analogRead(CNY_1);
  if(Value_CNY_Pin_IF >= negro)
  {
    Serial.println("Para I");
    StopI();
    A1negro=true;
  }
}

void CNY2 ()
{
  Value_CNY_Pin_DF = analogRead(CNY_2);
  if(Value_CNY_Pin_DF >= negro)
  {
    Serial.println("Para D");
    StopD();
    A0negro=true;
  }
}

void CNY3 ()
{
  
  Value_CNY_Pin_IA = analogRead(CNY_3);
  if(Value_CNY_Pin_IA >= negro)
  {
    Serial.println("Para I");
    StopI();
    A2negro=true;
  }
}

void CNY4 ()
{
  
  Value_CNY_Pin_DA = analogRead(CNY_4);
  if(Value_CNY_Pin_DA >= negro)
  {
    Serial.println("Para D");
    StopD();
    A5negro=true;
  }
}

void loop() {
  /*
        delay(700);
    // AVANCE
        ForwardMotorD();
        ForwardMotorI();
        delay(tiempoAvance);

        StopD();
        StopI();
        delay(3000);
    */
      //
      delay(1000);
      ForwardMotorD();
      ForwardMotorI();

      while(!A0negro || !A1negro)
      {
        CNY1();
        CNY2();
      }
      A1negro=false;
      A0negro=false;
      delay(1000);
      ForwardMotorD();
      ForwardMotorI();
      while(!A2negro || !A5negro)
      {
        CNY3();
        CNY4();
      }
      A2negro=false;
      A5negro=false;
      ForwardMotorD();
      ForwardMotorI();
      delay(300);
      StopD();
      StopI();
  
}

/*
      Serial.println("Probemos movimiento con CNYs delanteros");
      delay(2500);

        ForwardMotorD();
        ForwardMotorI();
        CNY1();
        CNY2();
        while(!A0negro && !A1negro)
        {
          CNY1();
          CNY2();
        }
        if(A0negro && !A1negro)
        {
          StopI();
          while(!A1negro)
          {
            CNY1();
          }
          ForwardMotorI();
        }
        else if(!A0negro && A1negro)
        {
          StopD();
          while(!A0negro)
          {
            CNY2();
          }
          ForwardMotorD();
        }
        delay(500);
        StopD();
        StopI();
        */

/*
      Serial.println("Probemos movimiento con CNYs traseros");
      delay(2500);
      
        ForwardMotorD();
        ForwardMotorI();
        CNY3();
        CNY4();
        while(!A2negro && !A5negro)
        {
          CNY3();
          CNY4();
        }
        if(A2negro && !A5negro)
        {
          StopI();
          while(!A2negro)
          {
            CNY3();
          }
          ForwardMotorI();
        }
        else if(!A2negro && A5negro)
        {
          StopD();
          while(!A5negro)
          {
            CNY4();
          }
          ForwardMotorD();
        }
        delay(500);
        StopD();
        StopI();
      
      */
