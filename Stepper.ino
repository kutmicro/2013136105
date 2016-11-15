#include <AccelStepper.h>
#include <AFMotor.h>

AF_Stepper motor1(200, 1);

void forwardstep1() {
  motor1.onestep(FORWARD, SINGLE);
  }
  
void backwardstep1() {   
  motor1.onestep(BACKWARD, SINGLE);
  }

AccelStepper stepper1(forwardstep1, backwardstep1);

void setup(){      
  stepper1.setMaxSpeed(200.0);    
  stepper1.setAcceleration(100.0);    
  stepper1.moveTo(24);        
  }
  
void loop(){    // Change direction at the limits    
  if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());    
    stepper1.run();    
}
