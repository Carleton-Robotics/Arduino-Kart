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
}

bool GPS::update(){
    //Query the GPS module only every second.
    if (millis() - previousTime > 1100){
        latitude = GNSS.getLatitude();
        longitude = GNSS.getLongitude();
    }
}

long GPS::getLatitudeRaw(){
    return latitude;
}
long GPS::getLongitudeRaw(){
    return longitude;
}
float GPS::getLatitudeMeters(){
    float relativeDeg = latitude / 10000000 - referenceLatitude;
    return relativeDeg * DEG_TO_RAD * earthRadius;
}
float GPS::getLongitudeMeters(){
    float relativeDeg = longitude / 10000000 - referenceLongitude;
    return relativeDeg * DEG_TO_RAD * earthRadius * cos(referenceLatitude * DEG_TO_RAD);
}
