#include <Stepper.h>
#include <SoftwareSerial.h>

int TxPin = 2;
int RxPin = 3;
int Button = 14;
int stepsmotor = 1024;
SoftwareSerial BTSerial(TxPin, RxPin);

Stepper myStepper(stepsmotor, 8, 10, 9, 11);
void setup() {
  BTSerial.begin(9600);
  myStepper.setSpeed(22);
  pinMode(Button, INPUT);
}

void loop() {
  if(digitalRead(Button) == LOW) {
    while(digitalRead(Button) == LOW)
    myStepper.step(stepsmotor);
  }
  if(BTSerial.available()) {
    char cmd = (char)BTSerial.read();
    if(cmd == '1')
      myStepper.step(stepsmotor);

    else if(cmd == '2') 
      myStepper.step(-stepsmotor);
  }
}

