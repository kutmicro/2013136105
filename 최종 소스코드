#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11  // DHT타입을 DHT11로 정의한다
DHT dht(DHTPIN, DHTTYPE); // DHT설정 - dht (7번핀, dht11)
#define POT_PIN A8
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);
char BT_data;
char Hand_mode;
void setup() {
  Serial.begin(9600);
  lcd.begin();
  AFMS.begin();  // create with the default frequency 1.6KHz
  myMotor->setSpeed(10);  // 10 rpm   
}

void loop() {
  int h = dht.readHumidity(); // 습도 읽어서 변수 h에 저장
  int t = dht.readTemperature(); // 온도 읽어서 변수 t에 저장
  lcd.backlight();
  lcd.print("Humidity: ");
  lcd.print(h); // 습도 출력
  lcd.setCursor(0, 1); // 밑 줄에 온도 출력(1행 첫칸)
  lcd.print("Temprature: ");
  lcd.print(t); // 온도 출력
  delay(1000);
  if(h >= 70) // 습도가 70% 이상이면
    myMotor->step(300, FORWARD, SINGLE); // 블라인드 내리기
  else { // 습도가 70% 미만이면
    int illumi = 0;    // 조도(illumi)를 측정해서
    illumi = analogRead(POT_PIN);
    Serial.println(illumi);
    if(illumi >= 300)  // 조도가 300 이상이면
      myMotor->step(300, FORWARD, SINGLE); // 블라인드 내리기
    if(illumi >= 30 && illumi <= 60)  //  30 이상 60 이하일때
      myMotor->step(300, BACKWARD, SINGLE); // 블라인드 올리기
    }
  lcd.clear(); // lcd 내용 지우기
}
