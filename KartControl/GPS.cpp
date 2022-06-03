#include "GPS.h"

GPS::GPS(){
    latitude = 0;
    longitude = 0;
    previousTime = 0;
}
void GPS::begin(){
    Wire.begin();
    GNSS.begin();

    GNSS.setI2COutput(COM_TYPE_UBX);
    GNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);

    GNSS.setMeasurementRate(500); //units: ms
}

bool GPS::update(){
    //Query the GPS module twice a second.
    if (GNSS.getPVT()){
        latitude = GNSS.getLatitude();
        longitude = GNSS.getLongitude();
        heading = GNSS.getHeading();
        return true;
    }
    return false;
}

long GPS::getLatitudeRaw(){
    return latitude;
}
long GPS::getLongitudeRaw(){
    return longitude;
}
float GPS::getHeadingRaw(){
    return heading;
}
float GPS::getLatitudeMeters(){
    float relativeDeg = latitude / 10000000 - referenceLatitude;
    return relativeDeg * DEG_TO_RAD * earthRadius;
}
float GPS::getLongitudeMeters(){
    float relativeDeg = longitude / 10000000 - referenceLongitude;
    return relativeDeg * DEG_TO_RAD * earthRadius * cos(referenceLatitude * DEG_TO_RAD);
}
Vector GPS::getPosVector(){
    return Vector(getLongitudeMeters(), getLatitudeMeters());
}
Vector GPS::getHeadingVector(){
    //returns a unit vector indicating current heading
    //due east is (1,0)
    //due north is (0,1)
    //due west is (-1,0)
    //due south is (0,-1)
    float headingRad = heading / 100000 * DEG_TO_RAD;
    return Vector(sin(headingRad), cos(headingRad));
    //note: sin and cos are switched because heading is
    //traditionally measured clockwise from due north (0,1) whereas
    //trig functions naturally go counterclockwise from (1,0).
}
