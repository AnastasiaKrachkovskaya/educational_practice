#ifndef DESTINATION_H
#define DESTINATION_H

#include "main/data/env/AppEnvironment.h"

class InitialScreenDestination;
class TrainingScreenDestination;

class DestinationHandler {
public:
    void virtual handleInitialScreenDestination(const InitialScreenDestination& dest) = 0;
    void virtual handleTrainingScreenDestination(const TrainingScreenDestination& dest) = 0;
};

class BaseDestination{
protected:
    BaseDestination() {};
    BaseDestination(BaseDestination& other) = delete;
    void operator=(const BaseDestination &) = delete;
public:
    void virtual handleWith(DestinationHandler* handler) const = 0;
};

class InitialScreenDestination : public BaseDestination {
public:
    InitialScreenDestination() {};
    void handleWith(DestinationHandler* handler) const override {
        handler->handleInitialScreenDestination(*this);
    }
};

class TrainingScreenDestination: public BaseDestination {
private:
    bool isOpenInProcessTrainingMode;
    TrainingAppNumber trainingAppNumber;
public:
    TrainingScreenDestination(TrainingAppNumber trainingAppNumber,
                              bool isOpenInProcessTrainingMode) {
        this->trainingAppNumber = trainingAppNumber;
        this->isOpenInProcessTrainingMode = isOpenInProcessTrainingMode;
    }
    ~TrainingScreenDestination() {};

    bool getIsOpenInProcessTrainingMode() {
        return this->isOpenInProcessTrainingMode;
    }

    void handleWith(DestinationHandler* handler) const override {
        handler->handleTrainingScreenDestination(*this);
    }
};

#endif // DESTINATION_H
