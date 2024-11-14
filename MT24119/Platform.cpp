#include "Platform.h"
#include <stdexcept>

void Platform::validateTrainTimings(int minutes, TrainType trainType) {
    if (trainType == TrainType::Through && minutes < 10) {
        throw std::invalid_argument("Through trains must have a minimum interval of 10 minutes.");
    } else if (trainType == TrainType::Stopping && minutes < 30) {
        throw std::invalid_argument("Stopping trains must have a minimum interval of 30 minutes.");
    }
}
