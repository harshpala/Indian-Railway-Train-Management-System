#include "Station.h"

// Constructor
template <typename T>
Station<T>::Station(T id) : stationID(id) {}

// Method to add a line to the station
template <typename T>
void Station<T>::addLine(const Line& line) {
    lines.push_back(line);
}

// Method to get the station ID
template <typename T>
T Station<T>::getID() const {
    return stationID;
}

// Access platform for train timing validation
template <typename T>
Platform& Station<T>::getPlatform() {
    return platform;
}
