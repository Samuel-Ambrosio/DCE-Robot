/*Programa de prueba para el sensor CNY70 ,el programa imprime los valores que recoje el sensor y
 * en el caso de que detecte el color negro imprime por consola: "Linea".
 */
const float ResolutionADC = 0.00488; //4.88mV
const int CNY_1 = A1;

int time1=0;
int time2=0;

int Value_CNY_Pin = 0; //Valor que leera el sensor

float Voltage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Value_CNY_Pin = analogRead(CNY_1);
  Voltage = Value_CNY_Pin * ResolutionADC;
  Serial.print("El valor de la lectura es:");  
  Serial.println (Value_CNY_Pin);
  //CNY1();
  delay(1000);
}
/*
void CNY1 (){
  Value_CNY_Pin = analogRead(CNY_1);
  if(Value_CNY_Pin >= negro){
    Serial.println("Linea encontrada");
  }
}*/
