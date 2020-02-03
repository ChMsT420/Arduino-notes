#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

//connessione display
const byte rs = 2;
const byte enable = 3;
const byte db4 = 4;
const byte db5 = 5;
const byte db6 = 6;
const byte db7 = 7;

LiquidCrystal lcd(rs, enable, db4, db5, db6, db7);

//connessione sensore temperatura + umidità
const byte pinDHT = 8;

DHT dht11(pinDHT, DHT11);


//variabili
float T = 0; //temperatura in °C
float H = 0; //umidità in %

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  dht11.begin();
}

void loop() {
  T = dht11.readTemperature();
  Serial.print("T: ");
  Serial.print(T);
  Serial.print("  ");
  H = dht11.readHumidity();
  Serial.print("H: ");
  Serial.print(H);
  Serial.println("  ");
}
