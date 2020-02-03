//pin a cui sono collegati i led
const byte pinLed1 = 13;
const byte pinLed2 = 12;
const byte pinLed3 = 11;

//setto i pin come uscite
void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
}

//comando l'attivazione/disattivazione dei pin
void loop() {
  for(int i = 0; i < 10; i++){
    digitalWrite(pinLed1, HIGH);
    delay(500);
    digitalWrite(pinLed1, LOW);
    delay(500);
  }
  
  for(int i = 0; i < 5; i++){
    digitalWrite(pinLed2, HIGH);
    delay(500);
    digitalWrite(pinLed2, LOW);
    delay(500);
  }

  digitalWrite(pinLed3, HIGH);
  delay(500);
  digitalWrite(pinLed3, LOW);
  delay(500);
}
