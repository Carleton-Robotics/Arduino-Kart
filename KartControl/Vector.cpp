#include "Vector.h"

Vector::Vector(float initX, float initY) : x(initX), y(initY){
}

void Vector::addVectors(float addX, float addY){
    x += addX;
    y += addY;
}

void Vector::subVectors(float subX, float subY){
    x -= subX;
    y -= subY;
}

double Vector::magVector(){
    return sqrt(x * x) + (y * y));
}

double Vector::xPrVectors(float xPrX, float xPrY){
    return (x * xPrY) - (y * xPrX);
}