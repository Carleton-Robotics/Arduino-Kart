#include "Vector.h"
#include <Arduino.h>

Vector::Vector(float initX, float initY) : x(initX), y(initY){
    //
}

float getX(){
    return x;
}

float getY(){
    return y;
}

void Vector::subtract(Vector paraVector){
    x = x - paraVector.getX();
    y = y - paraVector.getY();
}

float Vector::magnitude(){
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector::dist(Vector paraVector){
    return sqrt(pow((x - paraVector.getX()), 2) + pow((y - paraVector.getY()), 2));
}

void Vector::normalize(){
   x = x / magnitude();
   y = y / magnitude();
}

float Vector::crossProduct(Vector paraVector){
    return (x * paraVector.getY()) - (y * paraVector.getX());
}
