#include <Arduino.h>

class Vector{
  private:
    float x;
    float y;

  public:
    Vector(float x, float y);
    
    float getX();
    float getY();

    void subtract(Vector paraVector);

    
    float magnitude();

    float dist(Vector paraVector);

    void normalize();

    float xPrVectors(Vector paraVector);
};
