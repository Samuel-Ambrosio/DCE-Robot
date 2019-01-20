#include <Servo.h>
Servo miservo;

int count;
String movement;
String strGI = "-Giro Izquierda";
String strGD = "-Giro Derecha";
String strA = "-Avanzo";
String strG180 = "-Giro 180";
String strMI = "-Miro Izquierda";
String strMD = "-Miro Derecha";
String strMF = "-Miro Frente";
String strMuro = "-Muro";

bool principio = true;

int angulo=0;
// distancia a pared aprox
#define TAM 10
unsigned long pulso; // necesitamos una variable para medir el pulso
float distancia; // otra para calcular la distancia
// variable para controlar la direccion a tomar
bool existeCamino = false;

// Tiempo para avanzar aprox 1200
const int tiempoAvance = 1000;
// Tiempo para girar aprox 90º
const int tiempoGiro = 500;

int pinTrigger = A3;
int pinEcho = A4;

const int Pin1_motorD = 5; //pin pwm
const int Pin2_motorD = 6; //pin pwm

const int Pin1_motorI = 10;
const int Pin2_motorI = 9;

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

void setup()
{
    miservo.attach(11);//PIN DEL SERVO.
    Serial1.begin(9600); // inicializamos el puerto serie

    pinMode(pinTrigger, OUTPUT);
    pinMode(pinEcho, INPUT);

    pinMode(Pin1_motorD, OUTPUT); 
    pinMode(Pin2_motorD, OUTPUT);
    pinMode(Pin1_motorI, OUTPUT); 
    pinMode(Pin2_motorI, OUTPUT); 

    count = 0;
}

void loop()
{
    if(principio)
    {
        delay(10000);
        principio = false;
    }
    delay(300);
    miservo.write(90);
    delay(300);
    // Miro frente
    movement = count + strMF;
    Serial1.println(movement);
    count++;
    delay(1000);
    
    // 1. CONECTAR BT
    // HACER {
    // 2. CAMINO
    //      2.1 PARED DERECHA
    miservo.write(5); //El servo se colocará en 5º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
    // Miro derecha
    movement = count + strMD;
    Serial1.println(movement);
    count++;
    delay(1000);
    // US
    delay(300);
    camino();
    delay(300);
    //          ¿HAY CAMINO?
    if(existeCamino)
    {
        // SUIGUIENDO EL CAMINO A LA DERECHA ENCONTRAMOS UN CAMINO, LUEGO NOS DESPLZAZAMOS EN ESA DIRECCION
        delay(300);
        // COLOCAR SERVO A 90º
        miservo.write(90);
        // GIRAR 90º EN ESA DIRECCION (DERECHA)
        delay(300);
        // Miro frente
        movement = count +  strMF;
        Serial1.println(movement);
        count++;
        delay(1000);
        
         // Giro derecha
        movement = count +  strGD;
        Serial1.println(movement);
        count++;
        delay(1000);

        ForwardMotorI();
        ReverseMotorD();
        delay (tiempoGiro);

        StopD();
        StopI();
        delay(1000);
       
    }
    else
    {
        // Muro
        movement = count +  strMuro;
        Serial1.println(movement);
        count++;
        delay(1000);
        //      2.2 PARED FRENTE
        // Miro frente
        movement = count +  strMF;
        Serial1.println(movement);
        count++;
        delay(1000);

        // Servo
        miservo.write(90); //El servo se colocará en 90º (Mirara hacia el camino de alante).
        delay(300);
        // US
        delay(300);
        camino();
        delay(300);
        //          ¿HAY CAMINO?
        if(existeCamino)
        {
            delay(300);
            // COLOCAR SERVO A 90º
            miservo.write(90);
            // NO GIRA PUES ELIGE FRENTE
        }
        else
        {
            // Muro
            movement = count +  strMuro;
            Serial1.println(movement);
            count++;
            delay(1000);
            //      2.3 PARED IZQUIERDA
            // Miro izquierda
            movement = count + strMI;
            Serial1.println(movement);
            count++;
            delay(1000);
            miservo.write(175);  //El servo se colocará en 175º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
            delay(300);
            // US
            delay(300);
            camino();
            delay(300);
            //          ¿HAY CAMINO?
            if(existeCamino)
            {
                // Miro frente
                movement = count +  strMF;
                Serial1.println(movement);
                count++;
                delay(1000);
                // COLOCAR SERVO A 90º
                miservo.write(90);
                delay(300);
                // Giro izquierda
                movement = count +  strGI;
                Serial1.println(movement);
                count++;
                delay(1000);
                // GIRO IZQUIERDA
                // GIRO 90º DERECHA
                ForwardMotorD();
                ReverseMotorI();
                delay (tiempoGiro);

                StopD();
                StopI();
                delay(1000);
            }
            else
            {
                // AL NO EXISTIR CAMINO EN NINGUNA DIRECCION TENGO QUE RETROCEDER
                delay(300);
                // Muro
                movement = count +  strMuro;
                Serial1.println(movement);
                count++;
                delay(1000);
                // Miro frente
                movement = count +  strMF;
                Serial1.println(movement);
                count++;
                delay(1000);
                // COLOCAR SERVO A 90º
                miservo.write(90);
                delay(300);
                // Giro 180º
                movement = count +  strG180;
                Serial1.println(movement);
                count++;
                delay(1000);
                // GIRO 180º DERECHA
                ForwardMotorI();
                ReverseMotorD();
                delay (tiempoGiro*2);

                StopD();
                StopI();
                delay(1000);
            }
        }
    }
    // 3. AVANZA POR PRIMER CAMINO
    // Avanzo
    movement = count +  strA;
    Serial1.println(movement);
    count++;
    delay(1000);
    /*
    ForwardMotorD();
    ForwardMotorI();
    delay(tiempoAvance);

    StopD();
    StopI();
    delay(2000);
    */
    //      3.1 RECALIBRA GIRO
    delay(300);
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
    // 4. ¿ES SALIDA?
    // } HASTA SALIDA
    // (VUELTA A CASA)

}

// Control de camino mediante US
void camino()
{
    digitalWrite(pinTrigger, HIGH); // lo activamos
    delayMicroseconds(10); // esperamos 10 microsegundos
    digitalWrite(pinTrigger, LOW); // lo desactivamos
    
    pulso = pulseIn(pinEcho, HIGH); // medimos el pulso de salida del sensor
    distancia = ((float(pulso/1000.0))*34.32)/2;
    if(distancia < TAM)
    {
        existeCamino = false;
    }
    else
    {
        existeCamino = true;
    }
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
        StopI();
        A1negro=true;
    }
}

void CNY2 ()
{
    Value_CNY_Pin_DF = analogRead(CNY_2);
    if(Value_CNY_Pin_DF >= negro)
    {
        StopD();
        A0negro=true;
    }
}

void CNY3 ()
{
  
    Value_CNY_Pin_IA = analogRead(CNY_3);
    if(Value_CNY_Pin_IA >= negro)
    {
        StopI();
        A2negro=true;
    }
}

void CNY4 ()
{
  
    Value_CNY_Pin_DA = analogRead(CNY_4);
    if(Value_CNY_Pin_DA >= negro)
    {
        StopD();
        A5negro=true;
    }
}