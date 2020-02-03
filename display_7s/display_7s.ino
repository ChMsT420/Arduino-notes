/*
 *Contatore: permette ad arduino di contare attraverso l'utilizzo di 2 pulsanti (+/- 1)
 *e un display 7 segmenti
 */
 
//inizializzo pin display
byte pinA = 13;
byte pinB = 12;
byte pinC = 11;
byte pinD = 10;
byte pinE =  9;
byte pinF =  8;
byte pinG =  7;
byte pinH =  6;

void setup() {
  //setto i pin del display come OUTPUT
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinH, OUTPUT);
}

void loop() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinH, LOW);
}
