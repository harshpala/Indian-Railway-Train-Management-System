#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include "Platform.h"
#include "Line.h"

// Template class for Station to allow flexible ID types (string or integer)
template <typename T>
class Station {
private:
    T stationID;                      // Station ID can be string or integer
    std::vector<Line> lines;          // Lines associated with the station
    Platform platform;                // Platform associated with this station

public:
    Station(T id);                    // Constructor with ID parameter
    void addLine(const Line& line);   // Method to add a line to the station
    T getID() const;                  // Method to get the station ID
};

#include "Station.cpp" // Template implementations must be included here
#endif
