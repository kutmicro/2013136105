#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT11  // DHT타입을 DHT11로 정의한다
DHT dht(DHTPIN, DHTTYPE); // DHT설정 - dht (6번핀, dht11)
void setup() {
  Serial.begin(9600); 
  lcd.begin();
}

void loop() {
  delay(2000);  // 딜레이 2초
  int h = dht.readHumidity(); // 습도 읽어서 변수 h에 저장
  int t = dht.readTemperature(); // 온도 읽어서 변수 t에 저장
  Serial.print("Humidity: ");
  Serial.print(h); // 습도 출력
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);  // 온도 출력
  Serial.println(" C");
  
  lcd.backlight();
  lcd.print("Humidity: ");
  lcd.print(h); // 습도 출력
  lcd.setCursor(0, 1); // 밑 줄에 온도 출력(1행 첫칸)
  lcd.print("Temprature: ");
  lcd.print(t); // 온도 출력
  delay(1000); // 딜레이 1초
  lcd.clear(); // lcd 내용 지우기
}


