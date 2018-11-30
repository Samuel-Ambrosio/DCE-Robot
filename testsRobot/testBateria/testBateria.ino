const float ResolutionADC = 0.00488;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  float voltios;
  delay(300);
  voltios = analogRead(A6)*ResolutionADC;
  if(voltios >= 3.3){
    Serial.print("Carga correcta: ");
    Serial.print(voltios);
    Serial.println(" v");
  }
  else{
    Serial.print("Carga baja: ");
    Serial.print(voltios);
    Serial.println(" v");
  }
}
