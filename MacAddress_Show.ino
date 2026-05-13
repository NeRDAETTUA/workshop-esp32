#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  //Esperar 1 segundo para garantir que inicializa a wifi Station
  delay(1000);
  
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  
}