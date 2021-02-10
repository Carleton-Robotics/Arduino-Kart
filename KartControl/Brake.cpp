#include <Arduino.h>
//quoc is assigned to this but Josh is doing it instead :p

class Brake {
  private:
    int input_1; //for the brake mechanism
    int input_2;
    
    unsigned char pot; //for the potentiometer
    int sensorValue;
    int brakeMin;
    int brakeMax;
    int currentPrecentage;
    int targetPrecentage;

  public:
    Brake(int controlPin1,int controlPin2, unsigned char potentiometerPin) {
      input_1 = controlPin1;
      input_2 = controlPin2;
      pot = potentiometerPin;
      pinMode(input_1, OUTPUT);
      pinMode(input_2, OUTPUT);
      pinMode(potentiometerPin, INPUT); //Might be unnessessary?
      sensorValue = analogRead(pot);
      removeBrake();
      brakeMin = 0; //These are tentative and depend on the physical device's installation
      brakeMax = 1024;
      targetPrecentage = 0;
      //initialize pins for control and potentiometer, set to zero-brakes condition, 
    }
    void updateReading() {
      sensorValue = analogRead(pot);
      currentPrecentage = (sensorValue-brakeMin)/(brakeMax-brakeMin);
      //if target<state set the relay into the position that will make it move in the desired direction
      //else if target>state set the relay into a position that will make it move int the desired direction
      if (currentPrecentage < targetPrecentage) {
        digitalWrite(input_1, LOW);
        digitalWrite(input_2, HIGH);
      }
      else if (currentPrecentage > targetPrecentage) {
        digitalWrite(input_1, HIGH);
        digitalWrite(input_2, LOW);
      }
      else if (currentPrecentage = targetPrecentage) {
        digitalWrite(input_1, HIGH);
        digitalWrite(input_2, HIGH);
      }
    }
    void updateCommand(int target){
      targetPrecentage = target;
    }
    void removeBrake() {
      //stop entire program (with while loop) to move the brake back until state is zero
      while (currentPrecentage > 0) {
        currentPrecentage = (sensorValue-brakeMin)/(brakeMax-brakeMin);
        digitalWrite(input_1, HIGH);
        digitalWrite(input_2, LOW);
      }
    }
    void emergencyBrake() {
      //stop entire program (with while loop) to move the brake into fully braked position until reaches val
      while (currentPrecentage < 100) {
        currentPrecentage = (sensorValue-brakeMin)/(brakeMax-brakeMin);
        digitalWrite(input_1, LOW);
        digitalWrite(input_2, HIGH);
      }
    }
};
