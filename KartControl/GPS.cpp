#include "GPS.h"

using namespace kart;

class GPS::Impl {
public:
    Impl();
    ~Impl();

    SFE_UBLOX_GNSS* sensor;

    long latitude;
    long longitude;
    long heading;
    const float LAT_TO_METERS = 0.0011119;
    const float LON_TO_METERS = 0.00079364;
    //location of Northfield according to Google:
    const long REFERENCE_LAT = 444583000;//units: deg*10^-7
    const long REFERENCE_LON = -931616000;//units: deg*10^-7
};

GPS::Impl::Impl() : sensor(new SFE_UBLOX_GNSS()){
    latitude = REFERENCE_LAT;
    longitude = REFERENCE_LON;
}

GPS::Impl::~Impl() {
    delete sensor;
}

GPS::GPS() : pimpl(new Impl()){
}

GPS::~GPS() {
    delete pimpl;
}

void GPS::init() {
    Wire.begin();
    pimpl->sensor->begin();

    //I don't know what these do, but all the examples use them
    pimpl->sensor->setI2COutput(COM_TYPE_UBX);
    pimpl->sensor->saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);

    //Set measurement rate to be twice a second
    pimpl->sensor->setMeasurementRate(500); //units: ms
}

void GPS::preInit() {
}

char* GPS::getName() {
    static const name[] = "GPS";
    return name;
}

int GPS::getStatus() {
    return Status::OK;
}

int GPS::getError() {
    return Error::NONE;
}

void GPS::update() {
    //Get new data if its available
    if (pimpl->sensor->getPVT()) {
        pimpl->latitude = pimpl->sensor->getLatitude();
        pimpl->longitude = pimpl->sensor->getLongitude();
        pimpl->heading = pimpl->sensor->getHeading();
    }
}

long GPS::getLatitudeRaw() {
    return pimpl->latitude;
}

long GPS::getLongitudeRaw() {
    return pimpl->longitude;
}

float GPS::getHeadingRaw() {
    return pimpl->heading;
}

float GPS::getLatitudeMeters() {
    Serial.print("raw lat: ");
    Serial.println(pimpl->latitude);
    long relative = pimpl->latitude - Impl::REFERENCE_LAT;
    Serial.print("relative lat: ");
    Serial.println(relative);
    return relative * Impl::LAT_TO_METERS;
}

float GPS::getLongitudeMeters() {
    Serial.print("raw lon: ");
    Serial.println(longitude);
    long relative = pimpl->longitude - Impl::REFERENCE_LON;
    Serial.print("relative lon: ");
    Serial.println(relative);
    return relative * Impl::LON_TO_METERS;
}

Vector2 GPS::getPosVector() {
    return Vector2(getLongitudeMeters(), getLatitudeMeters());
}

Vector2 GPS::getHeadingVector() {
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

bool GPS::isEnabled() {
    return true;
}

void GPS::shutdown() {
    pimpl->sensor->end();
}