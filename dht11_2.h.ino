#include <LiquidCrystal.h>
#include <DHT11.h>

LiquidCrystal lcd(3,4,10,11,12,13);
DHT11 dht11(6);

void setup() {

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  int err;
  float humi;
  float tem;

  if ((err = dht11.read(humi, tem)) == 0) {
    char humiCharValue[10];
    dtostrf(humi, 4, 1, humiCharValue);

    String humiDisplayStr = "Humidity: ";
    humiDisplayStr += (String)humiCharValue;
    humiDisplayStr += " %";

    lcd.setCursor(0,0);
    lcd.print(humiDisplayStr);

    char temCharValue[10];
    dtostrf(tem, 4, 1, temCharValue);

    String temDisplayStr = "Temper  : ";
    temDisplayStr += (String)temCharValue;
    temDisplayStr += "'C";

    lcd.setCursor(0,1);
    lcd.print(temDisplayStr);
  }


  else {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
  }

  delay(DHT11_RETRY_DELAY);
}

