#include <Servo.h>
Servo miservo;

const float ResolutionADC = 0.00488;

int angulo=0;
// distancia a pared aprox
#define TAM 10
unsigned long pulso; // necesitamos una variable para medir el pulso
float distancia; // otra para calcular la distancia
bool existeCamino = false;

int pinTrigger = A3;
int pinEcho = A4;


const int Pin1_motorI = 10;
const int Pin2_motorI = 9;

// con peso final y carga aprox de 3.3V algo menos de 500
int SpeedMotor = 500; // Control de velocidad con el pwm

void setup() {
    miservo.attach(11);//PIN DEL SERVO.
    Serial.begin(9600); // inicializamos el puerto serie

    pinMode(pinTrigger, OUTPUT);
    pinMode(pinEcho, INPUT);
    
    pinMode(Pin1_motorI, OUTPUT); 
    pinMode(Pin2_motorI, OUTPUT); 
}


void ForwardMotorI(int SpeedMotor)
{  
    analogWrite(Pin1_motorI,0); 
    analogWrite(Pin2_motorI,SpeedMotor);
}


void ReverseMotorI(int SpeedMotor)
{
    analogWrite(Pin1_motorI,SpeedMotor);
    analogWrite(Pin2_motorI,0);
}


void StopI()
{
    analogWrite(Pin1_motorI,0);
    analogWrite(Pin2_motorI,0);
}

void giroD()
{
    // GIRO 90º DERECHA
    ForwardMotorI(SpeedMotor);
    delay (1000);

    StopI();
    delay(3000);
}

void giroI()
{
    // GIRO 90º IZQUIERDA
    ReverseMotorI(SpeedMotor);
    delay (1000);

    StopI();
    delay(3000);
}

void avance()
{
    // AVANCE
    ForwardMotorI(SpeedMotor);
    delay(1680);

    StopI();
    delay(3000);
}

void camino()
{
    digitalWrite(pinTrigger, HIGH); // lo activamos
    delayMicroseconds(10); // esperamos 10 microsegundos
    digitalWrite(pinTrigger, LOW); // lo desactivamos
    
    pulso = pulseIn(pinEcho, HIGH); // medimos el pulso de salida del sensor
    Serial.println();
    Serial.print("tiempo = "); // lo pasamos a milisegundos y lo sacamos por
    // el puerto serie
    Serial.print(float(pulso/1000.0));
    Serial.print("ms, distancia = "); // ahora calculamos la distancia en cm
                                        // y al puerto serie
    distancia = ((float(pulso/1000.0))*34.32)/2;
    Serial.print(distancia);
    Serial.println("cm");
    if(distancia <TAM)
    {
        existeCamino = false;
    }
    else
    {
        
        existeCamino = true;
    }
}

void loop() 
{

    StopI();
    delay(1000);
    avance();
    // COLOCAR SERVO A 90º
    Serial.println("Esperando 1s...");
    delay(1000);
    miservo.write(90);
    Serial.println("Esperando 1s...");
    delay(1000);
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
        Serial.print("Carga correcta: ");
        Serial.print(voltios);
        Serial.println(" v");
    
    
        Serial.println("Esperando 2s ...");
        delay(2000);
        miservo.write(5); //El servo se colocará en 5º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
        
        Serial.print("Camino de la Derecha");
        Serial.println();
        // US
        Serial.println("Esperando 1s ...");
        delay(1000);
        camino();
        Serial.println("Esperando 1s ...");
        delay(1000);
        
        // ¿EXISTE CAMINO A MI DERECHA?
        if(existeCamino)
        {
            // SUIGUIENDO EL CAMINO A LA DERECHA ENCONTRAMOS UN CAMINO, LUEGO NOS DESPLZAZAMOS EN ESA DIRECCION
            Serial.print("Hay camino a la derecha; simulando desplazamiento: ");
            Serial.println("");
            // COLOCAR SERVO A 90º
            miservo.write(90);
            // GIRAR 90º EN ESA DIRECCION (DERECHA) Y AVANZAR
        }
        else
        {
            Serial.print(" NO Hay camino a la derecha; mirar recto: ");
            Serial.println("");
            
            //
            Serial.println("Esperando 2s ...");
            delay(2000);

            // PROBAR AHORA SI ENFRENTE EXISTE CAMINO
            
            // Servo
            miservo.write(90); //El servo se colocará en 90º (Mirara hacia el camino de alante).
            
            Serial.print("Camino recto");
            Serial.println();
            // US
            Serial.println("Esperando 1s ...");
            delay(1000);
            camino();
            Serial.println("Esperando 1s ...");
            delay(1000);
            // ¿TENGO CAMINO DELANTE MIA?
            if(existeCamino)
            {
                Serial.print("Hay camino delante de mi; simulando desplazamiento: ");
                Serial.println("");
                // COLOCAR SERVO A 90º
                miservo.write(90);
            }
            else
            {
                Serial.print(" NO Hay camino delante; mirar izquierda: ");
                Serial.println("");

                Serial.println("Esperando 2s ...");
                delay(2000); // Hará una pausa de 2seg
                
                miservo.write(175);  //El servo se colocará en 175º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
                
                Serial.print("Camino de la Izquierda");
                Serial.println();
                // US
                Serial.println("Esperando 1s ...");
                delay(1000);
                camino();
                Serial.println("Esperando 1s ...");
                delay(1000);
                // ¿HAY CAMINO A MI IZQUIERDA?
                if(existeCamino)
                {
                    Serial.print("Hay camino a la izquierda; simulando desplazamiento: ");
                    Serial.println("");
                    // COLOCAR SERVO A 90º
                    miservo.write(90);
                }
                else
                {
                    // AL NO EXISTIR CAMINO EN NINGUNA DIRECCION TENGO QUE RETROCEDER
                    Serial.print(" NO Hay camino a la izquierda; retroceder: ");
                    Serial.println("");
                    Serial.print(" NO HE ENCONTRADO NINGUN CAMINO ESTOY TRISTE :( ");
                    Serial.println("");
                    delay(2000);
                }
                
            }
        }
    }
    delay(2000); //Hará una pausa de 2 Seg
    Serial.println();
}
