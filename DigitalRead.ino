#define DIGITAL_PIN   4

uint16_t digRead;

void setup() {
  pinMode(DIGITAL_PIN, INPUT);
  Serial.begin(115200);

}

void loop() {
  digRead = digitalRead(DIGITAL_PIN);
  if(digRead==1) 
  {
    Serial.println("3.3V");
  }
  else
  {
    Serial.println("0.0V");
  }
  delay(100);
}
