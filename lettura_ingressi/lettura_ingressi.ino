//pin a cui sono collegati i led
const byte pinLed1 = 13;
const byte pinLed2 = 12;
const byte pinLed3 = 11;

//pin a cui è collegato il pulsante
const byte pinButton1 = 8;
const byte pinButton2 = 7;
const byte pinButton3 = 6;

void setup() {
  //setto i pin come uscite
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  //setto il pin come ingresso
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
  pinMode(pinButton3, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(pinButton1) != true){
    digitalWrite(pinLed1, HIGH);
  }
  else{
    digitalWrite(pinLed1, LOW);
  }

  if(digitalRead(pinButton2) != true){
    digitalWrite(pinLed2, HIGH);
  }
  else{
    digitalWrite(pinLed2, LOW);
  }

  if(digitalRead(pinButton3) != true){
    digitalWrite(pinLed3, HIGH);
  }
  else{
    digitalWrite(pinLed3, LOW);
  }
}
