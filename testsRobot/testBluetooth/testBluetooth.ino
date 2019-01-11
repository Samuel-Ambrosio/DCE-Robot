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



void setup(){
  Serial1.begin(9600);
  count = 0;
}

void loop()
{
   if(principio)
   {
      delay(10000);
      principio = false;
   }
   movement = count + strMD;
   Serial1.println(movement);
   count++;
   delay(1000);

   movement = count + strMuro;
   Serial1.println(movement);
   count++;
   delay(500);

   movement = count + strMF;
   Serial1.println(movement);
   count++;
   delay(1000);

   movement = count + strA;
   Serial1.println(movement);
   count++;
   delay(3000);
}
