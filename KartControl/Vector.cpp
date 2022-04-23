#include "Vector.h"
#include <cmath>

void Vector::addVectors(double addVector[2]){
    Vector[0] = Vector[0] + addVector[0];
    Vector[1] = Vector[1] + addVector[1];
}

void Vector::subVectors(double subVector[2]){
    Vector[0] = Vector[0] - subVector[0];
    Vector[1] = Vector[1] - subVector[1];
}

double Vector::magVector(){
    return sqrt((Vector[0] * Vector[0]) + (Vector[1] * Vector[1]));
}

double Vector::xPrVectors(double xPrVector[2]){
    return (Vector[0]*xPrVector[1]) - (Vector[1]*xPrVector[0]);
}