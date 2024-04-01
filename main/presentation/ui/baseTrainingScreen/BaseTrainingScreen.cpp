#include "BaseTrainingScreen.h"

/*!
 * \brief Создание меню, в котором у пользователя два выбора: Начать тренировку и завершить тренировку.
 */

BaseTrainingScreen::BaseTrainingScreen(bool isOpenInProcessTrainingMode,
                                       QWidget* parent): QWidget(parent) {
    this->isOpenInProcessTrainingMode = isOpenInProcessTrainingMode;
}

void BaseTrainingScreen::setupUi() {
    this->menuBar = new QMenuBar();
    this->menuItem = new QMenu("Меню");

    if(this->isOpenInProcessTrainingMode) {
        setupProcessTrainingUi();
    } else {
        setupReplayTrainingUi();
    }

    this->menuBar->addMenu(menuItem);
    this->layout()->setMenuBar(this->menuBar);
}

void BaseTrainingScreen::setupProcessTrainingUi()
{
    this->menuItem->addAction(startTrainingAction);
    endTrainingAction->setEnabled(false);
    this->menuItem->addAction(endTrainingAction);
}

void BaseTrainingScreen::setupReplayTrainingUi()
{
    this->menuItem->addAction(checkTrainingAction);
}

BaseTrainingScreen::~BaseTrainingScreen() { }
