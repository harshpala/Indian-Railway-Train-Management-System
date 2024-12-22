#include "../include/Line.h"

Line::Line(const std::string& id) : lineID(id), platformCount(0) {}

std::string Line::getID() const {
    return lineID;
}

void Line::addPlatform(Platform* platform) {
    if (platformCount < MAX_PLATFORMS) {
        platforms[platformCount++] = platform;  // Add platform and increment the counter
    } else {
        std::cout << "Cannot add more platforms to line " << lineID << ", limit reached.\n";
    }
}

// Definition of getPlatform by platform ID
Platform* Line::getPlatform(const std::string& platformID) {
    // Debugging output
    std::cout << "Searching for platform with ID: " << platformID << "\n";

    // Loop through the platforms to find the one with the matching ID
    for (int i = 0; i < platformCount; ++i) {
        std::cout << "Checking platform " << platforms[i]->getID() << " against " << platformID << "\n";  // Debugging output
        if (platforms[i]->getID() == platformID) {
            return platforms[i];  // Return platform if IDs match
        }
    }
    return nullptr;  // Return null if platform ID not found
}

int Line::getPlatformCount() const {
    return platformCount;  // Return the number of platforms added
}
