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

void Vector::subVectors(Vector paraVector){
    x = x - paraVector.x;
    y = y - paraVector.y;   
}

float Vector::magClass(){
    return sqrt(pow(x, 2) + pow(x, 2));
}
/*
float magVector(Vector paraVector){
    return sqrt(pow(paraVector.x, 2) + pow(paraVector.y, 2));    
}
*/
float Vector::distVector(Vector paraVector){
    return sqrt(pow((x - paraVector.x), 2) + pow((y - paraVector.y), 2));
}

void Vector::norm(){
   x = x / magClass();
   y = y/ magClass();
}
/*
void Vector::norm(Vector paraVector){
    paraVector.x = paraVector.x / magVector(paraVector.x, paraVector.y);
    paraVector.y = paraVector.y / magVector(paraVector.x, paraVector.y)
}
*/
float Vector::xPrVectors(Vector paraVector){
    return (x * paraVector.y) - (y * paraVector.x);
}