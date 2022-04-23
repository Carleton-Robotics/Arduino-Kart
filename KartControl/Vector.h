#include "Arduino.h"

class Vector{
  private:
    double Vector[2];

  public:
    void addVectors(double addVector[2]);

    void subVectors(double subVector[2]);
    
    double magVector();
    
    double xPrVectors(double cPrVector[2]);
};