#include <LiquidCrystal.h>              // 텍스트 LCD 라이브러리 헤더파일
LiquidCrystal lcd(1, 2, 3, 4, 5, 6, 7);  // 텍스트 LCD 핀 설정
 
void setup() {
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.noDisplay();              // 화면을 끈다.              
  delay(500);                   // 0.5초 지연
  lcd.display();                // 화면을 킨다
  delay(500);                   // 0.5초 지연
}
 
void loop() {
  lcd.print("Only I can change my life"); // 문자열 출력
  while(1){
    lcd.scrollDisplayLeft();    // LCD 화면의 글자를 왼쪽으로 이동
    delay(500);
    }
}
