int count;
String movement;
String strAux;
void setup(){
  Serial1.begin(9600);
  count = 0;
}

void loop()
{
   strAux = "-Giro Izquierda";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);

   strAux = "-Avanzo";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);

   strAux = "-Giro Derecha";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);

   strAux = "-Giro Derecha";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);

   strAux = "-Avanzo";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);

   strAux = "-Giro Izquierda";
   movement = count + strAux;
   Serial1.println(movement);
   count++;
   delay(2000);
}
