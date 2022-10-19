
#include "Path.h"
#include <SD.h>
#include "Vector2.h"
#include <LinkedList.h>

using namespace kart;

Path::Path(LinkedList <Vector2> *waypoints) : waypoints(waypoints) {}

Vector2 Path::get(int index) {
    return waypoints->get(index);
}

int Path::getLength() {
    return waypoints->size();
}

// credit https://forum.arduino.cc/t/read-csv-or-txt-from-sd-card-into-string-or-array/225446/5
bool readLine(File &f, char *line, size_t maxLen) {
    for (size_t n = 0; n < maxLen; n++) {
        int c = f.read();
        if (c < 0 && n == 0) return false;  // EOF
        if (c < 0 || c == '\n') {
            line[n] = 0;
            return true;
        }
        line[n] = c;
    }
    return false; // line too long
}

bool readCoordinate(File &file, long *lat, long *lon, unsigned long *timestamp) {
    char line[60], *ptr, *str;
    if (!readLine(file, line, sizeof(line))) {
        return false;  // EOF or too long
    }
    Serial.println(line);
    delay(2000);
    Serial.println("before");
    delay(1000);
    *lat = strtol(line, &ptr, 10);
    Serial.println(*lat);
    delay(3000);
    Serial.println("A");
    if (ptr == line) return false;  // bad number if equal
    while (*ptr) {
        if (*ptr++ == ',') break;
    }
    Serial.print(ptr);
    Serial.print(*ptr);
    *lon = strtol(ptr, &ptr, 10);
    Serial.println("B");
    if (ptr == line) return false;  // bad number if equal
    while (*ptr) {
        if (*ptr++ == ',') break;
    }
    *timestamp = strtol(ptr, &str, 10);
    Serial.println("C");
    return str != ptr;  // true if number found
}

// credit https://docs.arduino.cc/learn/programming/sd-guide
void printDirectory(File dir, int numTabs) {
    while (true) {
        File entry = dir.openNextFile();
        if (!entry) {
            // no more files
            break;
        }
        for (uint8_t i = 0; i < numTabs; i++) {
            Serial.print('\t');
        }
        Serial.print(entry.name());
        if (entry.isDirectory()) {
            Serial.println("/");
            printDirectory(entry, numTabs + 1);
        } else {
            // files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
        }
        entry.close();
    }
}

Path *Path::readFromSD() {
    if (!SD.exists("data.csv")) {
        Serial.println(F("No file"));
        return nullptr;
    }
    File file = SD.open("data.csv");
    if (!file) {
        Serial.println(F("Unable to open file"));
        return nullptr;
    }
    LinkedList <Vector2> *waypoints = new LinkedList<Vector2>();
    while (file.available() != 0) {
        long lat, lon;
        unsigned long timestamp;
        if(!readCoordinate(file, lat, lon, timestamp)) {
            Serial.println(F("Bad coordinate"));
            return nullptr;
        }
        waypoints->add(Vector2((float) lat, (float) lon));
    }
    file.close();
    return new Path(waypoints);
}