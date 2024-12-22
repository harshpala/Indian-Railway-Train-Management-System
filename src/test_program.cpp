#include "../include/RailwayLibrary.h"
#include <iostream>
#include <string>
#include <limits>

// Function to test valid inputs and ensure proper handling of the user data
void testValidData() {
    std::cout << "\nTesting valid data...\n";

    // Add a station
    std::string stationID = "STN001";
    std::cout << "Adding Station " << stationID << "...\n";
    Station<std::string>* station = new Station<std::string>(stationID);
    std::cout << "Station " << stationID << " added successfully.\n";

    // Add lines to the station
    int numLines = 2;
    std::cout << "Adding " << numLines << " lines to Station " << stationID << "...\n";
    for (int i = 0; i < numLines; ++i) {
        std::string lineID = "L" + std::to_string(i + 1);
        Line* line = new Line(lineID);
        station->addLine(line);
        std::cout << "Line " << lineID << " added to Station " << stationID << ".\n";
    }

    // Add trains to the first line
    std::cout << "Adding trains to Line L1...\n";
    station->getPlatform()->addTrain("10:30 AM", TrainType::Through);  // Valid train time
    station->getPlatform()->addTrain("10:35 AM", TrainType::Stopping); // Valid train time

    std::cout << "Train timings validated successfully.\n";
}

// Function to test incorrect inputs and ensure errors are handled properly
void testInvalidData(Station<std::string>* station) {
    std::cout << "\nTesting invalid data...\n";

    // Attempt to add lines to a non-existing station
    std::string nonExistentStationID = "NONEXISTENT";
    Station<std::string>* nonExistentStation = nullptr; // Non-existing station
    if (nonExistentStation == nullptr) {
        std::cout << "Station " << nonExistentStationID << " not found. Cannot add lines.\n";
    }

    // Try adding a train with an invalid time format
    std::cout << "Attempting to add train with invalid time format...\n";
    try {
        station->getPlatform()->addTrain("25:61 AM", TrainType::Through); // Invalid time
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // Attempt to add a conflicting train time
    std::cout << "Attempting to add train with conflicting time...\n";
    try {
        station->getPlatform()->addTrain("10:30 AM", TrainType::Stopping); // Conflict with existing train
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "=== Railway Library Test Program ===\n";

    // Test valid data handling
    testValidData();

    // Find the station that we just created in the testValidData
    Station<std::string>* station = new Station<std::string>("STN001");

    // Test invalid data handling
    testInvalidData(station);

    std::cout << "\nTest completed.\n";
    return 0;
}
