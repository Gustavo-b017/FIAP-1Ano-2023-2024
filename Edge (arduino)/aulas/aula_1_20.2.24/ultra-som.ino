int cm = 0;
int trig = 7;
int echo = 8;

// funcao
long lerUltra(int trig, int echo){
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);

  return pulseIn(echo, HIGH);
}
void setup() {
  Serial.begin(9600);
}

void loop() {
  cm = 0.01723 * lerUltra(trig, echo);

  Serial.print(cm);
  //println - quebra a linha
  Serial.println("cm");
  delay(100);

}
