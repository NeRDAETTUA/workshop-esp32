#define LED_ESP 2     //definir o led integrado na ESP32

void setup() {
  pinMode(LED_ESP,OUTPUT); //declarar o LED integrado como output

}

void loop() {
  digitalWrite(LED_ESP,HIGH);   //passar o GPIO respetivo para 1 (3.3V)
  delay(500);                   //esperar meio segundo
  digitalWrite(LED_ESP,LOW);    //passar o GPIO respetivo para 0 (0.0V)
  delay(500);                   //esperar meio segundo

}
