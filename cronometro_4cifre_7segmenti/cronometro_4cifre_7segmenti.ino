/*
 * Cronometro con display 4 cifre 7 segmenti
 * e 2 pulsanti
 */
//pin gestione cifre
byte pinC_1 = 13;
byte pinC_2 = 12;
byte pinC_3 = 11;
byte pinC_4 = 10;

//pin gestione segmenti
byte pinA = 9;
byte pinB = 7;
byte pinC = 5;
byte pinD = 3;
byte pinE = 2;
byte pinF = 8;
byte pinG = 6;
byte pinH = 4;

//variabile contatore cifra
int n_cifra = 0;

//variabili contatore numero
int unita = -1;
int decine = -1;
int centinaia = -1;
int migliaia = -1;

//funzioni per scrivere i numeri decimali sul display
void ZERO(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
  digitalWrite(pinH, LOW);
}

void UNO(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinH, LOW);
}

void DUE(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void TRE(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void QUATTRO(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void CINQUE(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void SEI(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void SETTE(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinH, LOW);
}

void OTTO(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

void NOVE(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinH, LOW);
}

//spengo il display
void CLR(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinH, LOW);
}

void attivazione_cifre(int unita, int decine, int centinaia, int migliaia){
  if(unita >= 0){
    digitalWrite(pinC_1, LOW);
  }
  if(decine >= 0){
    digitalWrite(pinC_2, LOW);
  }
  if(centinaia >= 0){
    digitalWrite(pinC_3, LOW);
  }
  if(migliaia >= 0){
    digitalWrite(pinC_4, LOW);
  }
}

void setup() {
  //inizializzo come uscite i pin del display
  pinMode(pinC_1, OUTPUT);
  pinMode(pinC_2, OUTPUT);
  pinMode(pinC_3, OUTPUT);
  pinMode(pinC_4, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinH, OUTPUT);
  //inizializzo il display in modalità OFF
  digitalWrite(pinC_1, HIGH);
  digitalWrite(pinC_2, HIGH);
  digitalWrite(pinC_3, HIGH);
  digitalWrite(pinC_4, HIGH);
  CLR();
}

void loop() {
  attivazione_cifre(unita, decine, centinaia, migliaia);
  unita++;
  if(unita == 0){
    ZERO();
    delay(100);
  }
  if(unita == 1){
    UNO();
    delay(100);
  }
  if(unita == 2){
    DUE();
    delay(100);
  }
  if(unita == 3){
    TRE();
    delay(100);
  }
  if(unita == 4){
    QUATTRO();
    delay(100);
  }
  if(unita == 5){
    CINQUE();
    delay(100);
  }
  if(unita == 6){
    SEI();
    delay(100);
  }
  if(unita == 7){
    SETTE();
    delay(100);
  }
  if(unita == 8){
    OTTO();
    delay(100);
  }
  if(unita == 9){
    NOVE();
    delay(100);
  }
  if(decine = 1){
    UNO();
    delay(100);
  }
  if(decine = 2){
    UNO();
    delay(100);
  }
  if(decine = 3){
    UNO();
    delay(100);
  }
  if(decine = 4){
    UNO();
    delay(100);
  }
  if(decine = 5){
    UNO();
    delay(100);
  }
  if(decine = 6){
    UNO();
    delay(100);
  }
  if(decine = 7){
    UNO();
    delay(100);
  }
  if(decine = 8){
    UNO();
    delay(100);
  }
  if(decine = 9){  
    UNO();
    delay(100);
  }
  if(unita == 9 && decine == -1){
    decine = decine + 2;
    unita = -1;
  }
  else if(unita == 9 && decine != -1){
    decine++;
    unita = -1;
  }
}
