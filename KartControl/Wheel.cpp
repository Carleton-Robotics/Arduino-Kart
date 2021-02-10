
#include <Arduino.h>
#include <Servo.h>
//in the end we are going to want to use the serial interface with the roboclaw motor controller so this implementation is temporary.

class Wheel {

  private:
    int controlPin;
    Servo myservo;

  public:
    int state;
    
    Wheel(int controlPin) {
      controlPin = controlPin;
      myservo.attach(controlPin);
      
    }
    void updateCommand(int pos){
      myservo.write(pos);
      state = pos;
    }

    void updateReading(){
      //empty for now until we have the other library up and running
    }
    
  
}
