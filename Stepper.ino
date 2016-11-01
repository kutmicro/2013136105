#include <AccelStepper.h>
#include <AFMotor.h>

AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

void forwardstep1() {
  motor1.onestep(FORWARD, SINGLE);
  }
  
void backwardstep1() {   
  motor1.onestep(BACKWARD, SINGLE);
  }
  
void forwardstep2() {
  motor2.onestep(FORWARD, SINGLE);
  }
  
void backwardstep2() {    
motor2.onestep(BACKWARD, SINGLE);
}

AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup(){      
  stepper1.setMaxSpeed(200.0);    
  stepper1.setAcceleration(100.0);    
  stepper1.moveTo(24);        
  stepper2.setMaxSpeed(300.0);    
  stepper2.setAcceleration(100.0);    
  stepper2.moveTo(1000000);    
  }
  
void loop(){    // Change direction at the limits    
  if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());    
    stepper1.run();    
    stepper2.run();
}
