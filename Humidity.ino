#include <dht11.h>
#define DHT11PIN 12 // 12번핀을 통해 온도와 습도정보를 전달합니다.
dht11 DHT11;
void setup() {
  Serial.begin(9600);// 시리얼통신 속도를 9600으로 맞춥니다.
  Serial.println("start");

}

void loop() {
 Serial.println();
 int chk=DHT11.read(DHT11PIN);// 12번핀을 통해 정보를 읽습니다.
 Serial.println("Read");
 switch(chk){ //상태를 체크합니다. ok가나와야 정상입니다.
  case 0:Serial.println("ok");break; 
  case -1:Serial.println("checksum error"); break;
  case -2:Serial.println("time out"); break; 
  default:Serial.println("unknown"); break;
 }
 Serial.print("Humidity (%):");
 Serial.println(DHT11.humidity);//습도 출력
 Serial.print("Temperature :");
 Serial.println(DHT11.temperature);//온도 출력
 delay(2000);//2초지연
}

