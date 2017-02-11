#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley00[8] = {
  B00000,
  B00000,
  B00011,
  B00100,
  B01000,
  B01000,
  B10000,
  B10000
};
byte smiley10[8] = {
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B10001,
  B10001,
  B00000
};
byte smiley20[8] = {
  B00000,
  B00000,
  B11000,
  B00100,
  B00010,
  B00010,
  B00001,
  B00001
};
byte smiley01[8] = {
  B10000,
  B10001,
  B10000,
  B01000,
  B01000,
  B00100,
  B00011,
  B00000
};
byte smiley11[8] = {
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
  B00000,
  B11111
};
byte smiley21[8] = {
  B00001,
  B10001,
  B00001,
  B00010,
  B00010,
  B00100,
  B11000,
  B00000
};

void setup() {
  lcd.createChar(0, smiley00);
  lcd.createChar(1, smiley10);
  lcd.createChar(2, smiley20);
  lcd.createChar(4, smiley01);
  lcd.createChar(5, smiley11);
  lcd.createChar(6, smiley21);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.write(byte(6));
  delay(1000);
  lcd.createChar(6, smiley20);
}

void loop() {}
