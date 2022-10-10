#include "GPS.h"

using namespace kart;

GPS::GPS(){
    latitude = referenceLatitude;
    longitude = referenceLongitude;
}
void GPS::begin(){
    Wire.begin();
    GNSS.begin();

    //I don't know what these do, but all the examples use them
    GNSS.setI2COutput(COM_TYPE_UBX);
    GNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);

    //Set measurement rate to be twice a second
    GNSS.setMeasurementRate(500); //units: ms
}
bool GPS::update(){
    //Get new data if its available
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
    Serial.print("raw lat: ");
    Serial.println(latitude);
    long relative = latitude - referenceLatitude;
    Serial.print("relative lat: ");
    Serial.println(relative);
    return relative * rawLatToMeters;
}
float GPS::getLongitudeMeters(){
    Serial.print("raw lon: ");
    Serial.println(longitude);
    long relative = longitude - referenceLongitude;
    Serial.print("relative lon: ");
    Serial.println(relative);
    return relative * rawLonToMeters;
}
Vector2 GPS::getPosVector(){
    return Vector2(getLongitudeMeters(), getLatitudeMeters());
}
Vector2 GPS::getHeadingVector(){
    //returns a unit vector indicating current heading
    //due east is (1,0)
    //due north is (0,1)
    //due west is (-1,0)
    //due south is (0,-1)
    float headingRad = heading / 100000.0 * DEG_TO_RAD;
    return Vector2(sin(headingRad), cos(headingRad));
    //note: sin and cos are switched because heading is
    //traditionally measured clockwise from due north (0,1) whereas
    //trig functions naturally go counterclockwise from (1,0).
}
