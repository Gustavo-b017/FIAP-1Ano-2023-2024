#include <ArduinoJson.h> // Inclua a biblioteca ArduinoJson

int cm = 0;
int triggerPin = 7;
int echoPin = 8;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);  
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{  
  cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);

  // Criar um objeto JSON
  // doc- nome da variavel, pode ser qualquer um
  // 50 - pode ser qalquer um, mas tem que ser o bastante pra armazenar as informacoes
  
  StaticJsonDocument<50> doc;
  doc["distance_cm"] = cm; // Adicionar a variável cm ao JSON

  // Serializar o objeto JSON para enviar pela porta serial
  serializeJson(doc, Serial);
  Serial.println(); // Adicionar uma quebra de linha para separar os dados

  delay(500); 
}
