/*Programa de prueba para el sensor CNY70 ,el programa imprime los valores que recoje el sensor y
 * en el caso de que detecte el color negro imprime por consola: "Linea".
 */
const float ResolutionADC = 0.00488; //4.88mV
//izquierda-delante
const int CNY_1 = A1;
//derecha-frente
const int CNY_2 = A0;
//izquierda-atras
const int CNY_3 = A2;
//derecha-atras
const int CNY_4 = A5;

int negro=800;

int Value_CNY_Pin_IF = 0; //Valor que leera el sensor
int Value_CNY_Pin_DF = 0; //Valor que leera el sensor
int Value_CNY_Pin_IA = 0; //Valor que leera el sensor
int Value_CNY_Pin_DA = 0; //Valor que leera el sensor


void setup()
{
  Serial.begin(9600);
}

void loop() {
  Value_CNY_Pin_IF = analogRead(CNY_1);
  Value_CNY_Pin_DF = analogRead(CNY_2);
  Value_CNY_Pin_IA = analogRead(CNY_3);
  Value_CNY_Pin_DA = analogRead(CNY_4);
  Serial.println("El valor de la lectura es:");  
  Serial.println (Value_CNY_Pin_IF);
  Serial.println (Value_CNY_Pin_DF);
  Serial.println (Value_CNY_Pin_IA);
  Serial.println (Value_CNY_Pin_DA);
  CNY1();
  CNY2();
  CNY3();
  CNY4();
  delay(1000);
}

void CNY1 ()
{
  Value_CNY_Pin_IF = analogRead(CNY_1);
  if(Value_CNY_Pin_IF >= negro){
    Serial.println("Negro izq-frente");
    delay(1000);
  }
}

void CNY2 ()
{
  Value_CNY_Pin_DF = analogRead(CNY_2);
  if(Value_CNY_Pin_DF >= negro){
    Serial.println("Negro der-frente");
    delay(1000);
  }
}

void CNY3 ()
{
  Value_CNY_Pin_IA = analogRead(CNY_3);
  if(Value_CNY_Pin_IA >= negro){
    Serial.println("Negro izq-atras");
    delay(1000);
  }
}

void CNY4 ()
{
  Value_CNY_Pin_DA = analogRead(CNY_4);
  if(Value_CNY_Pin_DA >= negro){
    Serial.println("Negro der-atras");
    delay(1000);
  }
}
