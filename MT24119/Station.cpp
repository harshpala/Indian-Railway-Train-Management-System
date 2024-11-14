#include "Station.h"
#include <stdexcept>

// Constructor initializes the station ID and sets lineCount to 0
template <typename T>
Station<T>::Station(T id) : stationID(id), lineCount(0) {}

// Method to add a line to the station
template <typename T>
void Station<T>::addLine(const Line& line) {
    if (lineCount < MAX_LINES) {
        lines[lineCount++] = line;
    } else {
        throw std::overflow_error("Maximum number of lines reached for this station.");
    }
}

// Method to get the station ID
template <typename T>
T Station<T>::getID() const {
    return stationID;
}

// Access the single platform for train timing validation
template <typename T>
Platform& Station<T>::getPlatform() {
    return platform;
}

// Method to get a line ID by index
template <typename T>
std::string Station<T>::getLineID(int index) const {
    if (index < 0 || index >= lineCount) {
        throw std::out_of_range("Invalid line index");
    }
    return lines[index].getID();
}
