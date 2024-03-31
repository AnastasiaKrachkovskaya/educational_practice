#ifndef INITIALVIEWPRESENTER_H
#define INITIALVIEWPRESENTER_H

#include "main/presentation/navigation/AppNavigator.h"
#include "main/presentation/navigation/Destination.h"
#include "main/data/env/AppEnvironment.h"

class InitialViewPresenter {
public:
    InitialViewPresenter() {};

    void onProcessTrainingModeBtnClick() {
        TrainingScreenDestination dest = TrainingScreenDestination(AppEnvironment::trainingAppNumber, true);

        AppNavigator::getInstance()->navigateTo(dest);
    }

    void onReplayTrainingModeBtnClick() {
        TrainingScreenDestination dest = TrainingScreenDestination(AppEnvironment::trainingAppNumber, false);

        AppNavigator::getInstance()->navigateTo(dest);
    }
};

#endif // INITIALVIEWPRESENTER_H
