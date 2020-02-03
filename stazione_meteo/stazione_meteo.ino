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

//pin pulsanti
const byte pinUp = 9;
const byte pinDown = 10;
const byte pinLeft = 11;
const byte pinRight = 12;

//variabili
float T = 0; //temperatura in °C
float H = 0; //umidità in %

int colonna_cursore = 0;
int riga_cursore = 0;

//contatore macchina a stati
int stato_stazione = 0;

void setup() {
  //inizializzo la comunicazione seriale
  Serial.begin(9600);
  //inizializzo il display lcd
  lcd.begin(16,2);
  //inizializzo sensore di temperatura
  dht11.begin();
  //inizializzo pulsanti comandi
  pinMode(pinUp, INPUT_PULLUP);
  pinMode(pinDown, INPUT_PULLUP);
  pinMode(pinLeft, INPUT_PULLUP);
  pinMode(pinRight, INPUT_PULLUP);
  //accendo la stazione meteo
  lcd.print("Stazione meteo");
  riga_cursore++; //equivalente a: "riga_cursore = riga_cursore + 1;"
  lcd.setCursor(colonna_cursore, riga_cursore);
  lcd.print("Loading...");
  delay(2000);
  lcd.clear();
  riga_cursore--; //equivalente a: "riga_cursore = riga_cursore - 1;"
  lcd.setCursor(colonna_cursore, riga_cursore);
}

void loop(){
  //verifico di essere nel primo stato della macchina
  //cioè nel menù principale
  if(stato_stazione == 0){
    lcd.blink();
    lcd.setCursor(0,0);
    lcd.print("Leggi T");
    lcd.setCursor(0,1);
    lcd.print("Leggi U");
    
    //verifico la selezione
    if(digitalRead(pinUp) != HIGH){
      riga_cursore--;
      if(riga_cursore < 0){
        riga_cursore = 0;
      }
    }
    if(digitalRead(pinDown) != HIGH){
      riga_cursore++;
      if(riga_cursore > 1){
        riga_cursore = 1;
      }
    }
    colonna_cursore = 15;
    lcd.setCursor(colonna_cursore, riga_cursore);
    if(digitalRead(pinLeft) != HIGH){
      //non faccio nulla
      ;
    }
    if(digitalRead(pinRight) != HIGH){
      if(riga_cursore == 0){
        stato_stazione = 1;
      }
      if(riga_cursore == 1){
        stato_stazione = 2;
      }
    }
  }
  if(stato_stazione == 1){
    lcd.clear();
    lcd.noBlink();
    colonna_cursore = 0;
    riga_cursore = 0;
    lcd.setCursor(colonna_cursore, riga_cursore);
    stato_stazione = 3;
  }
  if(stato_stazione == 3){
    T = dht11.readTemperature();
    lcd.print("Temperatura: ");
    lcd.print(T);
    lcd.print(" ^C");
    delay(10);
    lcd.clear();
  }
  if(stato_stazione == 2){
    lcd.clear();
    lcd.noBlink();
    colonna_cursore = 0;
    riga_cursore = 0;
    lcd.setCursor(colonna_cursore, riga_cursore);
    stato_stazione = 4;
  }
  if(stato_stazione == 4){
    H = dht11.readHumidity();
    lcd.print("Umidita': ");
    lcd.print(H);
    lcd.print(" %");
    delay(10);
    lcd.clear();
  }
}
