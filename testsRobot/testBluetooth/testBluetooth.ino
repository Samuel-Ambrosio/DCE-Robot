char letra;

void setup(){
  Serial1.begin(9600);
}

void loop()
{
   /*while(Serial1.available()){
    letra = Serial1.read();
    if(letra){
      Serial.println(letra);
      Serial1.print("1");
      delay(1000);
      Serial1.print("0");
    }
    delay(10);
   }*/
   Serial1.println("Hola");
   delay(1000);
}
