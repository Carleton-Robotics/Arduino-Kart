#include "Vector.h"

Vector::Vector(float initX, float initY) : x(initX), y(initY){

}

/*
void Vector::addVectors(float addX, float addY){
    x += addX;
    y += addY;
}

void Vector::subVectors(float subX, float subY){
    x -= subX;
    y -= subY;   
}
*/

float getX(){
    return x;
}

float getY(){
    return y;
}

float Vector::magClass(){
    return sqrt(x^2 + y^2);
}

float magVector(float magX, float magY){
    return sqrt(magX ^ 2 + magY ^ 2);    
}

float Vector::distVector(float distX, float distY){
    return sqrt((x - distX) ^ 2 + (y - distY) ^ 2);
}

float Vector::normClassX(){
    return x / magClass();
}

float Vector::normClassY(){
    return y / magClass();
}

float Vector::normX(float nmlX, float nmlY){
    return nmlX / magVector(nmlX, nmlY);
}

float Vector::normY(float nmlX, float nmlY){
    return nmlY / magVector(nmlX, nmlY);
}

float Vector::dotNorm(float dotX, float dotY, float angle){
    return abs(magVector(normClassX(), normClassY())) * 
    abs(magVector(normX(dotX, dotY), normY(dotX, dotY))) * 
    cos(angle);
}


float Vector::xPrVectors(float xPrX, float xPrY){
    return (x * xPrY) - (y * xPrX);
}