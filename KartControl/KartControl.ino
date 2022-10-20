#include <Arduino.h>
#include "Pinouts.h"
#include "SteeringMotor.h"
#include "SpeedController.h"
#include "GPS.h"
#include "Vector2.h"
#include "Path.h"

using namespace kart;

SteeringMotor steeringMotor(Serial2);

SpeedController speedController;

GPS gps;

void (*resetFunc)(void) = 0; //Call to reset arduino

//float path[3][2] = {{0.1, 0.8},
//                    {0.2, 0.7},
//                    {0.3, 0.7}}; //example path. just an array of coordinates in meters
int i = 0; //index variable for path

Path* path = nullptr;

void setup() {
    Serial.println("Begin setup");
    //Control box switch
    pinMode(MiscPin, INPUT_PULLUP);

    //Set pin to be ground for bluetooth ground
    pinMode(BluetoothGroundPin, OUTPUT);
    digitalWrite(BluetoothGroundPin, LOW);

    //Interrupt to count odometer ticks
    attachInterrupt(digitalPinToInterrupt(OdometerPin), odometerInterrupt, RISING);
    Serial.begin(115200);

    //Wait for start switch
    while (digitalRead(MiscPin) != 1);

    speedController.begin();
//    Serial.println(F("Speed Controller begun"));

    gps.begin();
//    Serial.println(F("GPS begun"));

    steeringMotor.begin();
//    Serial.println(F("Steering Motor begun"));

    if (!SD.begin(53)) {
        while (1);
    }
//    Serial.println(F("Serial initialized"));

    path = Path::readFromSD();
    if(!path) {
        Serial.println(F("Unable to read data.csv file, path load cancelled"));
    } else {
        Serial.println(F("Loaded data.csv. Path points:"));
        for(int v = 0; v < path->getLength(); v++) {
            Serial.print(F("Lat: "));
            Serial.print(path->get(v).getX());
            Serial.print(F(", Lon: "));
            Serial.println(path->get(v).getY());
        }
    }
    delay(2000);
}

void loop() {
    //Stop if misc switch on control box switched off
    if (digitalRead(MiscPin) != 1) {
        stop();
    }

    if (gps.update()) {
        Vector2 kartPos = gps.getPosVector();
        Vector2 targetPos = Vector2(path->get(i).getX(), path->get(i).getY());
        Vector2 nextTargetPos = Vector2(path->get(i + 1).getX(), path->get(i + 1).getY());
        float dist1 = kartPos.dist(targetPos);
        float dist2 = kartPos.dist(nextTargetPos);
        if (dist2 < dist1) { //should change to while loop...
            i++;
        }
        Vector2 kartDir = gps.getHeadingVector();
        int n = 5; //number of points to look ahead when computing targetDir. Increase this number to smooth out direction and anticipate turns
        Vector2 futureTargetPos = Vector2(path->get(i + n).getX(), path->get(i + n).getY());
        Vector2 targetDir = (futureTargetPos - kartPos).norm();
        Vector2 positionError = kartPos - targetPos;
        float horzError = positionError.crossProductMagnitude(targetDir);
        float angleError = kartDir.crossProductMagnitude(targetDir);
        float B = 1; //units: 1/m. Make this parameter larger for quick steering and smaller for smooth steering
        float A = B * B / 4; //should satisfy 4A = B^2 if we want "critical damping"
        horzError = constrain(horzError, -B / A / 2, B / A / 2);
        float turningRate = -A * horzError - B * angleError; //units: 1/m, pos=right, neg=left
        float steeringEncoder = constrain(turningRate * 4000, -1000, 1000); //units: encoder ticks
        steeringMotor.goToRaw(round(steeringEncoder));
    }
    speedController.setTarget(0.5);
    speedController.update();
    delay(10);
}

void printGPSCoords() {
    if (gps.update()) {
        Vector2 kartPos = gps.getPosVector();
        Serial.print("{ ");
        Serial.print(kartPos.getX());
        Serial.print(" , ");
        Serial.print(kartPos.getY());
        Serial.println(" } ");
    }
}

void display_freeram() {
    Serial.print(F("- SRAM left: "));
    Serial.println(freeRam());
}

int freeRam() {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

//Stop all actuators and wait
void eStop() {
    steeringMotor.eStop();
    speedController.eStop();
    while (1);
}

void stop() {
    steeringMotor.eStop();
    speedController.eStop();
    delete path;
    resetFunc();
}

void odometerInterrupt() {
    speedController.Odometer::countTick();
}
