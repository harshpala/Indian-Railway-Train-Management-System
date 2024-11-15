#ifndef STATION_H
#define STATION_H

#include <string>
#include "Line.h"
#include "Platform.h"

template <typename T>
class Station {
private:
    T stationID;
    Line* lines[10];  // Array for storing lines (up to 10 lines per station)
    int lineCount;
    Platform* platform;  // Single shared platform for the station

public:
    Station(T id);      // Constructor
    ~Station();         // Destructor

    void addLine(Line* line);          // Add a line to the station
    T getID() const;                   // Get the station ID
    Platform* getPlatform() const;     // Get the platform
    Line* findLine(const std::string& lineID) const;  // Find a line by ID
};

#endif
