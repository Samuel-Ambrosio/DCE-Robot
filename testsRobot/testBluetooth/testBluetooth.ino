char letra;

void setup(){
  Serial1.begin(9600);
}

void loop()
{
   Serial1.println("Giro Izquierda");
   delay(2000);
   Serial1.println("Avanzo");
   delay(2000);
   Serial1.println("Giro Derecha");
   delay(2000);
   Serial1.println("Giro Derecha");
   delay(2000);
   Serial1.println("Avanzo");
   delay(2000);
   Serial1.println("Giro Izquierda");
   delay(2000);
}
