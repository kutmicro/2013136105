char BT_data;
char MEGA_data;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() {
  if(Serial1.available()) {
    BT_data=Serial1.read();
    Serial.println(BT_data);
    }
  else if (Serial.available()) {
    MEGA_data=Serial.read();
    Serial1.println(MEGA_data);
    }
}

