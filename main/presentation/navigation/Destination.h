#ifndef DESTINATION_H
#define DESTINATION_H

#include "main/data/env/AppEnvironment.h"

class InitialScreenDestination;
class TrainingScreenDestination;

/*!
 * \brief The DestinationHandler class
 */
class DestinationHandler {
public:
    void virtual handleInitialScreenDestination(const InitialScreenDestination& dest) = 0;
    void virtual handleTrainingScreenDestination(const TrainingScreenDestination& dest) = 0;
};


/*!
 * \class BaseDestination
 * \brief Осуществляет переход между окнами
 */
class BaseDestination{
protected:
    BaseDestination() {};
    BaseDestination(BaseDestination& other) = delete;
    void operator=(const BaseDestination &) = delete;
public:
    void virtual handleWith(DestinationHandler* handler) const = 0;
};
/*!
 * \class InitialScreenDestination
 * \brief Наследуется от BaseDestination, осуществляет переход на окно с выбором режима
 */
class InitialScreenDestination : public BaseDestination {
public:
    InitialScreenDestination() {};
    void handleWith(DestinationHandler* handler) const override {
        handler->handleInitialScreenDestination(*this);
    }
};
/*!
 * \class TrainingScreenDestination
 * \brief Наследуется от BaseDestination, осуществляет переход на окно с тренажером
 */
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

    bool getIsOpenInProcessTrainingMode() const {
        return this->isOpenInProcessTrainingMode;
    }

    TrainingAppNumber getTrainingAppNumber() const {
        return this->trainingAppNumber;
    }

    void handleWith(DestinationHandler* handler) const override {
        handler->handleTrainingScreenDestination(*this);
    }
};

#endif // DESTINATION_H
