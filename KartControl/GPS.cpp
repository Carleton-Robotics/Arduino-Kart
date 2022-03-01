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

void GPS::update(){
    if(millis() - previousTime < 1000){
        latitude = GNSS.getLatitude();
        longitude = GNSS.getLongitude();
        previousTime = millis();
    }
}

long GPS::getLatitude(){
    return latitude;
}
long GPS::getLongitude(){
    return longitude;
}
