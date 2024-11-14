#ifndef PLATFORM_H
#define PLATFORM_H

enum class TrainType { Stopping, Through };

class Platform {
public:
    void validateTrainTimings(int minutes, TrainType trainType);
};

#endif
