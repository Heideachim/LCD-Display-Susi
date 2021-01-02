// LCD-Anzeige mit 2 Reihen á 16 Zeichen ansteuern.
// LCD ist Hitachi HD44780 kompatibel, benötigt also relativ viele 
// Leitungen (4 Daten-, 2 Select-Leitungen, Kontrast-Poti, Beleuchtung)
//
// Beschreibung und Verdrahtung: https://starthardware.org/lcd/
//
// Zum Ansteuern wird die bereits intstallierte Arduino-Bibliothek 
// LiquidCrystal.h verwendet: Den Cursor auf die gewünschte Position
// setzen und dann einen Text ausdrucken.

#include <LiquidCrystal.h>

const int RS = 12, EN = 11;                 // Auswahl-Leitungen zum LCD
const int D4 = 5, D5 = 4, D6 = 3, D7 = 2;   // Datenleitungen zum LCD

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);  // LCD anlegen

void setup() {
  lcd.begin(16, 2);                         // LCD logische Abmessungen
}

void loop() {
  // erste Zeile: Willkommen-Botschaft:
  lcd.setCursor(0, 0);
  lcd.print("Hallo NWT!");
  // zweite Zeile: Sekunden zählen hoch:
  lcd.setCursor(0, 1);
  lcd.print("seit ");
  lcd.print(millis() / 1000);
  lcd.print(" sec");
}
