
#ifndef ARDUINO_KART_PATH_H
#define ARDUINO_KART_PATH_H

#include "Vector2.h"
#include <SD.h>
#include <LinkedList.h>

namespace kart {
    class Path {
    private:
        LinkedList<Vector2>* waypoints;
    public:

        Path(LinkedList<Vector2>* waypoints);

        Vector2 get(int index);

        int getLength();

        static Path* readFromSD();
    };
}


#endif //ARDUINO_KART_PATH_H
