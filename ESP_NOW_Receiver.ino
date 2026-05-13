#include <esp_now.h>
#include <WiFi.h>

bool buttonReceived;
//recebe a info , a data e o tamanho de data
void receiv_func(const esp_now_recv_info_t *info, const uint8_t *receivedData, int len) 
{
  //coloca a data recebida numa variável
  memcpy(&buttonReceived, receivedData, sizeof(buttonReceived));

}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(1000);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Erro");
    return;
  }
  //declarar função que é chamada quando se recebe uma variável
  esp_now_register_recv_cb(receiv_func);

}

void loop() {
  Serial.print("Mensagem recebida: ");
  Serial.println(buttonReceived);
  delay(2000);

}
