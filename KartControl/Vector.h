#include <Arduino.h>

class Vector{
  private:
    float x;
    float y;

  public:
    Vector(float x, float y);
    
    float getX();
    float getY();

    void subVectors(Vector paraVector);

    
    float magClass();
    //float magVector(Vector paraVector);

    float distVector(Vector paraVector);

    void norm();
    //void norm(Vector paraVector);
    
    float xPrVectors(Vector paraVector);
};