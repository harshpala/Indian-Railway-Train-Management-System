#include "../include/Platform.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

Platform::Platform(const std::string& id) : platformID(id) {}

std::string Platform::getID() const {
    return platformID;
}

void Platform::addTrain(const std::string& trainTime, TrainType trainType) {
    validateTrainTimings(trainTime, trainType);
    trains.push_back(trainTime + " (" + (trainType == TrainType::Through ? "Through" : "Stopping") + ")");
    std::cout << "Train at " << trainTime << " added.\n";
}

void Platform::validateTrainTimings(const std::string& newTime, TrainType trainType) {
    int newMinutes = convertToMinutes(newTime);

    for (const auto& train : trains) {
        int existingMinutes = extractTrainMinutes(train);
        int timeDifference = std::abs(newMinutes - existingMinutes);

        if ((trainType == TrainType::Through && timeDifference < 10) ||
            (trainType == TrainType::Stopping && timeDifference < 30)) {
            throw std::invalid_argument("Train timing violates constraints. Conflict with existing train at " + train);
        }
    }
    std::cout << "Train time validated.\n";
}

// Helper function to convert hh:mm string to total minutes since midnight
int Platform::convertToMinutes(const std::string& time) {
    std::istringstream iss(time);
    int hours, minutes;
    char colon;
    iss >> hours >> colon >> minutes;
    if (!iss || colon != ':' || hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
        throw std::invalid_argument("Invalid time format.");
    }
    return hours * 60 + minutes;
}

// Helper function to extract train time in minutes from a stored train string
int Platform::extractTrainMinutes(const std::string& train) {
    // Assuming stored format is "hh:mm (Type)"
    size_t pos = train.find(" ");
    if (pos == std::string::npos) {
        throw std::invalid_argument("Invalid stored train format.");
    }
    return convertToMinutes(train.substr(0, pos));
}
