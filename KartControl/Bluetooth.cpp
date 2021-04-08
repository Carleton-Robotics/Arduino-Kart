#include "Bluetooth.h"

void Bluetooth::begin(){
    pinMode(12, OUTPUT);
    ble->begin();
    ble->info();
};
void Bluetooth::connect(){
    digitalWrite(12, HIGH);
    while(!ble->isConnected()){
        delay(500);
    }
    digitalWrite(12, LOW);
};
void Bluetooth::updateValues(){
    while(ble->available() >= receivedPacketSize){
        for(int i = 0; i < receivedPacketSize; i++){
            packet[i] = ble->read();
        }
    }
};
int Bluetooth::getThrottle(){
    return packet[0];
}
int Bluetooth::getWheel(){
    return packet[1];
}
int Bluetooth::getBrake(){
    return packet[2];
}
void Bluetooth::send(char a, char b, char c){ //Up to 20 parameters can be addes
    char toSend[] = {a, b, c, '\0'}; //Must add new variables to array
    ble->write(toSend); //Phone code must know the number of variables to expect
}