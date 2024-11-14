#ifndef STATION_H
#define STATION_H

#include <string>
#include "Platform.h"
#include "Line.h"

// Maximum number of lines per station
const int MAX_LINES = 10;

template <typename T>
class Station {
private:
    T stationID;                          // Station ID can be string or integer
    Line lines[MAX_LINES];                // Fixed-size array of lines
    int lineCount;                        // Track the number of lines added
    Platform platform;                    // Single platform associated with this station

public:
    Station(T id);                        // Constructor with ID parameter
    void addLine(const Line& line);       // Method to add a line to the station
    T getID() const;                      // Method to get the station ID
    Platform& getPlatform();              // Access platform for train timing validation
    std::string getLineID(int index) const; // Method to get a line ID by index
};

#include "Station.cpp" // Include the implementation file

#endif
