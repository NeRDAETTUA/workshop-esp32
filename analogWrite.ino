#define ANALOG_PIN  17
#define Frequency 1000
#define res 10

uint16_t anValue = 1000;

void setup() {
  Serial.begin(115200);
  ledcAttach(ANALOG_PIN, Frequency, res);

}

void loop() {
  
  ledcWrite(ANALOG_PIN, anValue);
}
