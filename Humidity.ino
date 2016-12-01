#include "DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600); 
  lcd.begin();
}

void loop() {
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");
  
  lcd.backlight();
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("Temprature: ");
  lcd.print(t);
  delay(1000);
  lcd.clear();
}


