#define ANALOG_PIN  15    //declarar o pino que se vai usar

uint16_t anRead;      //declarar a variável de leitura, int de 16 bits pois a resolução só terá 10 bits

void setup() {
  Serial.begin(115200);
  pinMode(ANALOG_PIN, INPUT);     //declarar o pino como entrada
  
}

void loop() {
  
  anRead = analogRead(ANALOG_PIN);    //ler o pino analógico
  Serial.println(anRead);           //mostrar a leitura do pino analógico
  delay(10);                        //delay para ser visível a leitura
