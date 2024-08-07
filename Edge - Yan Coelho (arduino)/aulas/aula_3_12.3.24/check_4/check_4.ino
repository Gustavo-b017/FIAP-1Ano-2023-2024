/////Json
#include <ArduinoJson.h>
const int TAMANHO = 150;  //define o tamanho do buffer para o json

///// Sensor DTH
#include "DHT.h"
#define DHTPIN  9  //define o pino usado no arduino
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); //declara a objeto da classe

// luminosidade
int ldr = A1; 

// sensor de distancia
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
  //inicialia c sensor
  dht.begin();

  //inicializa comunicação serial
  Serial.begin(9600);

 
}

void loop() 
{
  StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json
 
  // ldr
   int valLDR = analogRead(ldr);
   
  // Faz a leitura da temperatura  
  float temp = dht.readTemperature();
  // faz a leitura da humidade
  float umi = dht.readHumidity();

   cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);

  //temperatura 
  StaticJsonDocument<TAMANHO> doc;
  doc["Temperatura"] = temp; // Adicionar a variável cm ao JSON

  StaticJsonDocument<TAMANHO> dist;
  dist["distance_cm"] = cm; // Adicionar a variável cm ao JSON

  // luz
  StaticJsonDocument<TAMANHO> luz;
  luz["Luminosidade"] = ldr; // Adicionar a variável cm ao JSON


  
 

  
  serializeJson(doc, Serial);
  Serial.println();
  serializeJson(dist, Serial);
  Serial.println();
  serializeJson(luz, Serial);
   Serial.println();

  delay(4000);
}
