#include <Arduino.h>
//quoc is assigned to this


class Brake {
  private:
    int control1;
    int contol2;
    int pot;
  public:
    int state;
    
    Brake(int controlPin1,int controlPin2, int potentiometerPin){

      control1 = controlPin1;
      control2 = controlPin2;
      pot = potentiometerPin;
      pinMode(control1,OUTPUT);
      pinMode(control2, OUTPUT);
      state = analogRead(pot);
      removeBrake();
      
      //initialize pins for control and potentiometer, set to zero-brakes condition, 
    }
    void updateReading(){
      state = analogRead(pot);
    }
    void updateCommand(int target){
      
      //if target<state set the relay into the position that will make it move in the desired direction
      //else if target>state set the relay into a position that will make it move int the desired direction
      
    }
    void removeBrake(){
      //stop entire program to move the brake back until state is zero
    }
}
