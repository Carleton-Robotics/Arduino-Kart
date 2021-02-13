#include <Arduino.h>


class Brake {
  private:
    int control1;
    int control2;
    int pot;
    int endOfTravelValue;
    int startOfTravelValue;
  public:
    int state;
    Brake(int controlPin1,int controlPin2, int potentiometerPin){
      control1 = controlPin1;
      control2 = controlPin2;
      pot = potentiometerPin;
      pinMode(control1,OUTPUT);
      pinMode(control2, OUTPUT);
      state = map(analogRead(pot),0,1024,0,100);
      endOfTravelValue = 100;
      startOfTravelValue = 900;
      updateCommand(0);
      
      //initialize pins for control and potentiometer, set to zero-brakes condition, 
    }

    
    void updateReading(){
      state = map(analogRead(pot), startOfTravelValue, endOfTravelValue,0,1000);
    }
    
    void updateCommand(int target){
      //scaledTarget = map(target,0,100,endOfTravelValue,startOfTravelValue);
      if (sqrt(sq(target-state))<10){
        digitalWrite(control1,HIGH);
        digitalWrite(control2,HIGH);
        
      }
      else if (target>state){
        digitalWrite(control1,LOW);
        digitalWrite(control2,HIGH);
      }
      else if(target<state){
        digitalWrite(control1, HIGH);
        digitalWrite(control2, LOW);
      }
      
      
    }
};
