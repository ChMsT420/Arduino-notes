void setup() {
  //  settiamo come uscite i pin a cui sono collegati i led
  pinMode(13, OUTPUT); //led verde
  pinMode(12, OUTPUT); //led giallo
  pinMode(11, OUTPUT); //led rosso
}

void loop() {
  // accendo come un semaforo i tre led
  // led rosso acceso per 5 s
  // led verde acceso per 2 s
  // led giallo acceso per 0.5 s
  digitalWrite(13, HIGH);
  delay(1500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(5000);
  digitalWrite(11, LOW);
}
