//pin di segnale
const byte pinLed = 11;

//pin di connessione al sensore
const byte pinPot = A0;

//variabile per salvare il dato letto
int valPot = 0;

void setup() {
  //inizializzo pin segnale
  pinMode(pinLed, OUTPUT);
  //inizializzo la comunicazione seriale a 9600 baud
  Serial.begin(9600);
  //invio messaggio attraverso la seriale
  Serial.println("Ciao Mondo!");
}

void loop() {
  //leggo il valore analogico
  valPot = analogRead(pinPot);
  valPot = map(valPot, 0, 1023, 255, 0);
  //invio il dato alla seriale del computer
  Serial.println(valPot);
  //scrivo sul pin di segnale il valore del dato analogico
  analogWrite(pinLed, valPot);
}
