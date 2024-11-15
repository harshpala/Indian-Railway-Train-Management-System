#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Platform.h"

const int MAX_PLATFORMS = 5;  // Maximum number of platforms per line

class Line {
private:
    std::string lineID;             // Line ID
    Platform* platforms[MAX_PLATFORMS];  // Array of pointers to platforms
    int platformCount;              // Counter for how many platforms have been added

public:
    Line(const std::string& id);    // Constructor declaration
    std::string getID() const;      // Getter for Line ID

    void addPlatform(Platform* platform);  // Add platform to the line
    Platform* getPlatform(const std::string& platformID);  // Get platform by ID (declaration)
    int getPlatformCount() const;          // Return the number of platforms
};

#endif
