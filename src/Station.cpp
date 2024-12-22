#include "../include/Station.h"
#include <iostream>

template <typename T>
Station<T>::Station(T id) : stationID(id), lineCount(0), platform(new Platform("DefaultPlatform")) {}

template <typename T>
Station<T>::~Station() {
    delete platform;
    for (int i = 0; i < lineCount; ++i) {
        delete lines[i];
    }
}

template <typename T>
void Station<T>::addLine(Line* line) {
    if (lineCount < 10) {
        lines[lineCount++] = line;
    } else {
        std::cout << "Cannot add more lines. Maximum limit reached.\n";
    }
}

template <typename T>
T Station<T>::getID() const {
    return stationID;
}

template <typename T>
Platform* Station<T>::getPlatform() const {
    return platform;
}

template <typename T>
Line* Station<T>::findLine(const std::string& lineID) const {
    for (int i = 0; i < lineCount; ++i) {
        if (lines[i]->getID() == lineID) {
            return lines[i];
        }
    }
    return nullptr;  // Return nullptr if the line is not found
}

// Explicit instantiation for std::string
template class Station<std::string>;
