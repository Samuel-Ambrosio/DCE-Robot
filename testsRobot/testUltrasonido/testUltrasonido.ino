/*Para la prueba se necesitara una regla y una pared, ponga la pared a una posicion mayor a 5cm, el monitor mostrara por pantalla "Camino disponible".
 * Cuando esa pared se encuentre a una distancia inferior a 5 cm, el monitor mostrara por pantalla "Camino no disponible".
 */

int angulo=0;
#define TAM 5
unsigned long pulso; // necesitamos una variable para medir el pulso
float distancia; // otra para calcular la distancia
int pinTrigger = A3;  //pin para el ultrasonido 
int pinEcho = A4;
void setup() {
  Serial.begin(9600); // inicializamos el puerto serie
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void loop() {
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
  Serial.print("cm");
   if(distancia <TAM){//si la distancia está a menos de 5 cm...
     Serial.print(" Camino no disponible");
   }
   else{
      Serial.print(" Camino Disponible");
   }
delay(1000);
}
