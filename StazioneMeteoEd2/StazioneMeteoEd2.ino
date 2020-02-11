#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

//pin display LCD 16 colonne 2 righe
byte RS = 2;
byte E  = 3;
byte D4 = 4;
byte D5 = 5;
byte D6 = 6;
byte D7 = 7;

LiquidCrystal LCD(RS, E, D4, D5, D6, D7);  //creo la variabile LCD a cui è collegato il display

//pin DHT11
byte pinDHT = 8;
float T = 0;
float H = 0;

DHT dht11(pinDHT, DHT11);

//pin Pulsanti
byte pinB1 = 13;
byte pinB2 = 12;
byte pinB3 = 11;
byte pinB4 = 10;

//variabili state-machine
int counter = 0;

//variabili posizione del menù
int su = 0;
int giu = 1;
int destra = 0;
int sinistra = 0;

void setup() {
  pinMode(pinB1, INPUT_PULLUP);
  pinMode(pinB2, INPUT_PULLUP);
  pinMode(pinB3, INPUT_PULLUP);
  pinMode(pinB4, INPUT_PULLUP);
  
  LCD.begin(16,2);
  dht11.begin();
  LCD.print("Stazione Meteo");
  delay(1000);
  LCD.clear();
}

void loop() {
  T = dht11.readTemperature();
  H = dht11.readHumidity();
  if(counter == 0){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("Leggi T");
    LCD.setCursor(0,1);
    LCD.print("Leggi U");
    counter++;
  }
  if(counter == 1){
    LCD.blink();
    if(digitalRead(pinB1) == LOW && su != 1){
      su++;
      giu = 0;
    }
    if(digitalRead(pinB2) == LOW && giu != 1){
      giu++;
      su = 0;
    }
    if(su == 1){
      LCD.setCursor(15,0);
    }
    if(giu == 1){
      LCD.setCursor(15,1);
    }
    if(digitalRead(pinB3) == LOW){
      if(su == 1){
        counter++;
      }
      if(giu == 1){
        counter += 2;
      }
    }
  }
  if(counter == 2){
    LCD.clear();
    LCD.print("Temperatura:");
    LCD.setCursor(0,1);
    LCD.print(T);
    LCD.print(" ^C");
    delay(60);
    if(digitalRead(pinB4) == LOW){
      counter = 0;
    }
  }
  if(counter == 3){
    LCD.clear();
    LCD.print("Umidita:");
    LCD.setCursor(0,1);
    LCD.print(H);
    LCD.print(" %");
    delay(60);
    if(digitalRead(pinB4) == LOW){
      counter = 0;
    }
  }
}
