#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

enum class TrainType { Through, Stopping };

class Platform {
private:
    std::string platformID;  // Platform ID
    std::vector<std::string> trains;  // List of trains scheduled at this platform

    // Helper functions for time validation
    int convertToMinutes(const std::string& time);  // Convert hh:mm to total minutes since midnight
    int extractTrainMinutes(const std::string& train);  // Extract train time in minutes from stored data

public:
    Platform(const std::string& id);  // Constructor to initialize Platform ID
    std::string getID() const;        // Getter for Platform ID
    void addTrain(const std::string& trainTime, TrainType trainType);  // Method to add train to platform
    void validateTrainTimings(const std::string& time, TrainType trainType);  // Method to validate train timings
};

#endif
