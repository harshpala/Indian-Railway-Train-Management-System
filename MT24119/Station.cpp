#include "Station.h"

template <typename T>
Station<T>::Station(T id) : stationID(id) {}

template <typename T>
void Station<T>::addLine(const Line& line) {
    lines.push_back(line);
}

template <typename T>
T Station<T>::getID() const {
    return stationID;
}
