#pragma once

#include <Arduino.h>

class Vector{
  private:
    float x;
    float y;

  public:
    Vector(float x, float y);
    
    float getX();
    float getY();

    Vector subtract(Vector paraVector);

    
    float magnitude();

    float dist(Vector paraVector);

    void normalize();

    float crossProduct(Vector paraVector);
};
