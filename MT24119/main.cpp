#include "RailwayLibrary.h"
#include <iostream>
#include <string>
using namespace std;

void testLibrary() {
    try {
        // Step 1: Input Station ID
        string stationID;
        cout << "Enter Station ID: ";
        cin >> stationID;
        Station<string> station(stationID);

        // Step 2: Input Line IDs
        int numLines;
        cout << "Enter number of lines to add (up to 10): ";
        cin >> numLines;
        
        if (numLines < 1 || numLines > MAX_LINES) {
            cerr << "Invalid number of lines. Exiting." << endl;
            return;
        }

        for (int i = 0; i < numLines; ++i) {
            string lineID;
            cout << "Enter Line ID for line " << i + 1 << ": ";
            cin >> lineID;
            station.addLine(Line(lineID));
        }

        // Display station and line details
        cout << "\nStation ID: " << station.getID() << endl;
        cout << "Associated Lines: " << endl;
        for (int i = 0; i < numLines; ++i) {
            cout << " - Line ID: " << station.getLineID(i) << endl;
        }

        // Step 3: Platform Timing Validation
        Platform& platform = station.getPlatform();
        cout << "\nPlatform Train Timing Validation:\n";

        // Input and validate timings for Through trains
        int throughTrainMinutes;
        cout << "Enter timing (in minutes) for a Through train: ";
        cin >> throughTrainMinutes;
        try {
            platform.validateTrainTimings(throughTrainMinutes, TrainType::Through);
            cout << " - Through train timing (" << throughTrainMinutes << " minutes): Valid" << endl;
        } catch (const exception& e) {
            cerr << " - Through train timing (" << throughTrainMinutes << " minutes): " << e.what() << endl;
        }

        // Input and validate timings for Stopping trains
        int stoppingTrainMinutes;
        cout << "Enter timing (in minutes) for a Stopping train: ";
        cin >> stoppingTrainMinutes;
        try {
            platform.validateTrainTimings(stoppingTrainMinutes, TrainType::Stopping);
            cout << " - Stopping train timing (" << stoppingTrainMinutes << " minutes): Valid" << endl;
        } catch (const exception& e) {
            cerr << " - Stopping train timing (" << stoppingTrainMinutes << " minutes): " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    testLibrary();
    return 0;
}
