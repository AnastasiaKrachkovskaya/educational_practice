#include "AppWindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
{
    AppNavigator::getInstance()->connectAppView(this);
}

AppWindow::~AppWindow() {}

void AppWindow::navigateTo(const BaseDestination& destination) {
    destination.handleWith(this);
}

void AppWindow::handleInitialScreenDestination(const InitialScreenDestination& dest)
{
    InitialScreen* initialScreen = new InitialScreen(this);
    setCentralWidget(initialScreen);
}

void AppWindow::handleTrainingScreenDestination(const TrainingScreenDestination& dest)
{
    QWidget* trainingScreenWidget = nullptr;
    bool isOpenInProcessTrainingMode = dest.getIsOpenInProcessTrainingMode();

    switch(dest.getTrainingAppNumber()) {
        case TrainingAppNumber::FIRST:
            trainingScreenWidget = new FirstTrainingScreen(isOpenInProcessTrainingMode, this);
            break;
        case TrainingAppNumber::SECOND:
            trainingScreenWidget = new SecondTrainingScreen(isOpenInProcessTrainingMode, this);
            break;
        case TrainingAppNumber::THIRD:
            trainingScreenWidget = new ThirdTrainingScreen(isOpenInProcessTrainingMode, this);
            break;
    }

    this->setCentralWidget(trainingScreenWidget);
}
