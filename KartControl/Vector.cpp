#include "Vector.h"
#include <Arduino.h>

Vector::Vector(float initX, float initY) : x(initX), y(initY){
    
}
float Vector::getX(){
    return x;
}
float Vector::getY(){
    return y;
}
Vector Vector::subtract(Vector paraVector){
    return Vector(x - paraVector.getX(), y - paraVector.getY());
}
float Vector::magnitude(){
    return sqrt(pow(x, 2) + pow(y, 2));
}
float Vector::dist(Vector paraVector){
    return sqrt(pow((x - paraVector.getX()), 2) + pow((y - paraVector.getY()), 2));
}
void Vector::normalize(){
   float mag = magnitude();
   x = x / mag;
   y = y / mag;
}
float Vector::crossProduct(Vector paraVector){
    return (x * paraVector.getY()) - (y * paraVector.getX());
}
