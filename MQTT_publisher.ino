#include <WiFi.h>
#include <PubSubClient.h>


const char* ssid = "Esp32 workshop";
const char* password = "VinhoVerde";
const char* mqtt_server = "broker.emqx.io";
const char* topic = "esp32/workshop/26";

WiFiClient espClient;
PubSubClient client(espClient);

/*void callback(char* topic, byte* payload, unsigned int length)  //Funcao que analisa as mensagens recebidas
{
  String message;
  Serial.println("Message Received");

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

}*/

void reconnect() {
  // Caso se perca a conexão
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");


    String clientId = "ESPClient-" + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("CONNECTED!");

      client.subscribe(topic);
    

    } else {

      int state = client.state();
      Serial.print("failed, rc=");
      Serial.print(state);
      Serial.print(" ");
     
    }
  }
}

void setup() {
  Serial.begin(115200);

  //inicializa o modulo wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Conectado ao WiFi");
  }
  delay(1000);

  client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();
  client.publish(topic, "hello");
  delay(2000);
}
