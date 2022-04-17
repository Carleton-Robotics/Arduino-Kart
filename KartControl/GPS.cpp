#include "GPS.h"

GPS::GPS(){
    latitude = 0;
    longitude = 0;
    previousTime = 0;
    earthRadius = 6371000; //meters
    referenceLatiude = 45.4583; //location of Northfield according to Google
    referenceLongitude = 93.1616;
    degToRad = 3.14159265359/180;
}
void GPS::begin(){
    Wire.begin();
    GNSS.begin();

    GNSS.setI2COutput(COM_TYPE_UBX);
    GNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);
}

void GPS::update(){
    latitude = GNSS.getLatitude();
    longitude = GNSS.getLongitude();
}

long GPS::getLatitudeRaw(){
    return latitude;
}
long GPS::getLongitudeRaw(){
    return longitude;
}
long GPS::getLatitudeMeters(){
    float relativeDeg = latitude/10000000 - referenceLatitude;
    return relativeDeg*degToRad*earthradius;
}
long GPS::getLongitudeMeters(){
    float relativeDeg = longitude/10000000 - referenceLongitude;
    return relativeDeg*degToRad*earthradius*cos(referenceLatitude*degToRad);
}
