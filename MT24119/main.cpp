#include "RailwayLibrary.h"
#include <iostream>

void testLibrary() {
    try {
        // Create a station with string ID
        Station<std::string> station1("STN001");

        // Create a platform and validate train timings for different types
        Platform platform1;
        platform1.validateTrainTimings(15, TrainType::Through);   // Valid case for through train
        platform1.validateTrainTimings(35, TrainType::Stopping);  // Valid case for stopping train

        // Uncommenting the lines below will throw exceptions due to invalid timings
        // platform1.validateTrainTimings(5, TrainType::Through);  // Invalid case
        // platform1.validateTrainTimings(20, TrainType::Stopping); // Invalid case

        // Output station ID to demonstrate templated Station class
        std::cout << "Station ID: " << station1.getID() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testLibrary();
    return 0;
}
