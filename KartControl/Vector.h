#include "Arduino.h"

class Vector{
  private:
    float x;
    float y;

  public:
    Vector(float x, float y);

    //void addVectors(float addX, float addY);

    //void subVectors(float subX, float subY);
    
    float getX();
    float getY();
    
    float magClass();
    float magVector();

    float distVector(float distX, float distY);

    float normClassX();
    float normClassY();
    float normX(float nmlX, float nmlY);
    float normY(float nmlX, float nmlY);

    float dotNorm(float dotX, float dotY, float angle):
    
    float xPrVectors(float xPrX, float xPrY);
};