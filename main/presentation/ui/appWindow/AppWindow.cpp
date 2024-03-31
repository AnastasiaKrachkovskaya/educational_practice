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
    FirstTrainingScreen* firstTrainingScreen = new FirstTrainingScreen(
        dest.getIsOpenInProcessTrainingMode(), this
        );
    this->setCentralWidget(firstTrainingScreen);
}
