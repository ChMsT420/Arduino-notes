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

void setup() {
  lcd.begin(16,2);
  dht11.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
