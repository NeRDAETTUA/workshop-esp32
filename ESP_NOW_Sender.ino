#include <esp_now.h>
#include <WiFi.h>
#define BUTTON_PIN 4



uint8_t receiverAddress[] = {0x04, 0xB2, 0x47, 0x9C, 0xBF, 0x00};

esp_now_peer_info_t peerInfo;

bool button_state;

void sent_func(const esp_now_send_info_t *info, esp_now_send_status_t status) {
  Serial.print("Mensagem Enviada: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Sucesso" : "Falhanço");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(1000);    //garante que é feito o setup 

  if (esp_now_init() != ESP_OK) {         //inicializar a ESP-NOW
    Serial.println("Erro");
    return;
  }
  esp_now_register_send_cb(sent_func);    //declarar função que é chamada quando algo é enviado
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;  // definir o canal da ESP-NOW
  peerInfo.encrypt = false;   //sem encriptação

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Falha ao adicionar recetor");
    return;
  }

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  
  button_state = digitalRead(BUTTON_PIN);

  //enviar com a receiver address, transformar a variável num ponteiro para um int de 8 bits seguido do tamanho da variável 
  esp_now_send(receiverAddress, (uint8_t *)&button_state, sizeof(button_state));
  delay(2000);  
}
