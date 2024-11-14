#include "RailwayLibrary.h"
#include <iostream>
#include <string>

void testLibrary() {
    try {
        // Step 1: Input Station ID
        std::string stationID;
        std::cout << "Enter Station ID: ";
        std::cin >> stationID;
        Station<std::string> station(stationID);

        // Step 2: Input Line IDs
        int numLines;
        std::cout << "Enter number of lines to add (up to 10): ";
        std::cin >> numLines;
        
        if (numLines < 1 || numLines > MAX_LINES) {
            std::cerr << "Invalid number of lines. Exiting." << std::endl;
            return;
        }

        for (int i = 0; i < numLines; ++i) {
            std::string lineID;
            std::cout << "Enter Line ID for line " << i + 1 << ": ";
            std::cin >> lineID;
            station.addLine(Line(lineID));
        }

        // Display station and line details
        std::cout << "\nStation ID: " << station.getID() << std::endl;
        std::cout << "Associated Lines: " << std::endl;
        for (int i = 0; i < numLines; ++i) {
            std::cout << " - Line ID: " << station.getLineID(i) << std::endl;
        }

        // Step 3: Platform Timing Validation
        Platform& platform = station.getPlatform();
        std::cout << "\nPlatform Train Timing Validation:\n";

        // Input and validate timings for Through trains
        int throughTrainMinutes;
        std::cout << "Enter timing (in minutes) for a Through train: ";
        std::cin >> throughTrainMinutes;
        try {
            platform.validateTrainTimings(throughTrainMinutes, TrainType::Through);
            std::cout << " - Through train timing (" << throughTrainMinutes << " minutes): Valid" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << " - Through train timing (" << throughTrainMinutes << " minutes): " << e.what() << std::endl;
        }

        // Input and validate timings for Stopping trains
        int stoppingTrainMinutes;
        std::cout << "Enter timing (in minutes) for a Stopping train: ";
        std::cin >> stoppingTrainMinutes;
        try {
            platform.validateTrainTimings(stoppingTrainMinutes, TrainType::Stopping);
            std::cout << " - Stopping train timing (" << stoppingTrainMinutes << " minutes): Valid" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << " - Stopping train timing (" << stoppingTrainMinutes << " minutes): " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testLibrary();
    return 0;
}
