//importo la libreria LiquidCrystal
#include <LiquidCrystal.h>

//pin a cui è collegato il display
const byte rs = 2;
const byte enable = 3;
const byte db4 = 4;
const byte db5 = 5;
const byte db6 = 6;
const byte db7 = 7;

//creo la variabile di tipo LiquidCrystal chiamata lcd
LiquidCrystal lcd(rs, enable, db4, db5, db6, db7);

void setup() {
  //inizializzo lcd con (numero di colonne, numero di righe)
  lcd.begin(16,2);
  lcd.print("0123456789012345");
  //setto il cursore sulla seconda riga
  lcd.setCursor(0,1);
  lcd.print("abcdefghijklmno");
  delay(500);
  //cancella tutti i pixel
  lcd.clear();
  delay(500);
}

void loop() {
}
