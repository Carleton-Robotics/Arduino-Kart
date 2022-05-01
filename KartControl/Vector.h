#include "Arduino.h"

class Vector{
  private:
    float x;
    float y;

  public:
    Vector(float x, float y);

    void addVectors(float addX, float addY);

    void subVectors(float subX, float subY);
    
    double magVector();
    
    double xPrVectors(float xPrX, float xPrY);
};