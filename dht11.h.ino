#include <DHT11.h>
#define pin A0

DHT11 t(pin);
void setup() {
  Serial.begin(9600);
}
void loop() {
  int i;
  float temp, humi;
  if((i = t.read(humi, temp)) == 0) {
    Serial.println(humi);
  }
}
