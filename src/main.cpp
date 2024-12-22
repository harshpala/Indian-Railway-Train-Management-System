#include "../include/RailwayLibrary.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

// Constants for maximum limits
const int MAX_STATIONS = 100;

// Menu options
enum class MenuOption {
    AddStation = 1,
    AddLineToStation,
    AddTrain,
    Exit
};

// Station storage
Station<std::string>* stations[MAX_STATIONS];  // Array of station pointers
int stationCount = 0;  // Current number of stations

// Utility function to display the main menu
MenuOption displayMainMenu() {
    int choice;
    while (true) {
        std::cout << "\nMain Menu:\n"
                  << "1. Add Station\n"
                  << "2. Add Line to Station\n"
                  << "3. Add Train\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";

        // Try reading the integer input
        if (std::cin >> choice) {
            // Valid input, break the loop
            std::cin.ignore();  // Clear the newline character after integer input
            return static_cast<MenuOption>(choice);
        } else {
            // Invalid input, handle the error
            std::cout << "Invalid input. Please enter a valid menu option (1-4).\n";
            std::cin.clear();  // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input in the buffer
        }
    }
}

// Utility function to find a station by ID
Station<std::string>* findStation(const std::string& id) {
    for (int i = 0; i < stationCount; ++i) {
        if (stations[i]->getID() == id) {
            return stations[i];
        }
    }
    return nullptr;
}

// Function to ensure valid integer input
int getValidIntInput(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input) {
            std::cin.ignore();
            return input;
        } else {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Function to ensure valid train time format (hh:mm AM/PM)
bool isValidTimeFormat(const std::string& time) {
    std::istringstream iss(time);  // Create the istringstream object
    int hours, minutes;
    char colon, ampm[3];  // AM/PM suffix
    if (!(iss >> hours >> colon >> minutes >> ampm) || colon != ':' || hours < 1 || hours > 12 || minutes < 0 || minutes >= 60) {
        return false;
    }
    if (ampm[0] != 'A' && ampm[0] != 'P') {
        return false;
    }
    return true;
}

int main() {
    while (true) {
        MenuOption option = displayMainMenu();

        switch (option) {
            case MenuOption::AddStation: {
                if (stationCount >= MAX_STATIONS) {
                    std::cout << "Maximum station limit reached.\n";
                    break;
                }
                std::string stationID;
                std::cout << "Enter Station ID: ";
                std::getline(std::cin, stationID);
                stations[stationCount++] = new Station<std::string>(stationID);
                std::cout << "Station " << stationID << " added.\n";
                break;
            }
            case MenuOption::AddLineToStation: {
                std::string stationID;
                std::cout << "Enter Station ID to add lines: ";
                std::getline(std::cin, stationID);
                Station<std::string>* station = findStation(stationID);
                if (station) {
                    int numLines = getValidIntInput("Enter number of lines to add: ");
                    for (int i = 0; i < numLines; ++i) {
                        std::string lineID;
                        std::cout << "Enter Line ID for line " << i + 1 << ": ";
                        std::getline(std::cin, lineID);
                        Line* newLine = new Line(lineID);
                        station->addLine(newLine);
                        std::cout << "Line " << lineID << " added to Station " << stationID << ".\n";
                    }
                } else {
                    std::cout << "Station not found.\n";
                }
                break;
            }
            case MenuOption::AddTrain: {
                std::string stationID, lineID;
                std::cout << "Enter Station ID: ";
                std::getline(std::cin, stationID);
                Station<std::string>* station = findStation(stationID);
                if (station) {
                    std::cout << "Enter Line ID: ";
                    std::getline(std::cin, lineID);
                    Line* line = station->findLine(lineID);
                    if (line) {
                        std::string trainTime;
                        while (true) {
                            std::cout << "Enter train time (in hh:mm AM/PM format): ";
                            std::getline(std::cin, trainTime);
                            if (isValidTimeFormat(trainTime)) {
                                break;
                            } else {
                                std::cout << "Invalid time format. Please use hh:mm AM/PM format.\n";
                            }
                        }
                        int trainType = getValidIntInput("Enter Train Type (1 for Through, 2 for Stopping): ");
                        TrainType type = static_cast<TrainType>(trainType);

                        // Assuming station->getPlatform() and line->addTrain are correctly implemented
                        try {
                            station->getPlatform()->addTrain(trainTime, type);
                            std::cout << "Train added successfully to line " << lineID << ".\n";
                        } catch (const std::exception& e) {
                            std::cout << "Error adding train: " << e.what() << "\n";
                        }
                    } else {
                        std::cout << "Line ID not found.\n";
                    }
                } else {
                    std::cout << "Station ID not found.\n";
                }
                break;
            }
            case MenuOption::Exit:
                std::cout << "Exiting program. Goodbye!\n";
                for (int i = 0; i < stationCount; ++i) {
                    delete stations[i];  // Cleanup
                }
                return 0;
        }
    }
}
