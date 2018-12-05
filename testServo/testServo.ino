/*Programa de prueba en el que observamos en el monitor la posicion en la que esta el servo, este cambiara su posicion cada 2 segundos mostrando por pantalla su nueva posicion.
 */

#include <Servo.h>
Servo miservo;

void setup() {
  miservo.attach(11);//PIN DEL SERVO.
  Serial.begin(9600); // inicializamos el puerto serie

}

void loop() {
  delay(1500);
  miservo.write(90); //El servo se colocará en 90º (Mirara hacia el camino de alante).
  Serial.println();
  Serial.print("Camino recto");
  delay(2000); // Hará una pausa de 2seg
  
 miservo.write(5); //El servo se colocará en 5º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
  Serial.println();
  Serial.print("Camino de la Derecha");
  delay(2000); //Hará una pausa de 2 Seg
  
 miservo.write(175);  //El servo se colocará en 175º (no ponemos 0º por los limites que pueda tener el servo) (Mirará hacia el camino de la derecha).
  Serial.println();
  Serial.print("Camino de la Izquierda");
  delay(2000); //Hará una pausa de 2 Seg
  
Serial.println();
}
