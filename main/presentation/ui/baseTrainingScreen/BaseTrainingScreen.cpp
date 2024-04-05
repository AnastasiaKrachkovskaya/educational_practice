#include "BaseTrainingScreen.h"

/*!
 * \brief Создание меню, в котором у пользователя два выбора: Начать тренировку и завершить тренировку
 * либо в другом режиме Проверить результат тренировки
 */

BaseTrainingScreen::BaseTrainingScreen(bool isOpenInProcessTrainingMode,
                                       QWidget* parent): QWidget(parent) {
    this->isOpenInProcessTrainingMode = isOpenInProcessTrainingMode;
    this->presenter = new ExcerciseViewPresenter();
    this->presenter->connectExcerciseView(this);
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

void BaseTrainingScreen::showInstructionDialog()
{
    DialogsManager::showInstruction();
}

void BaseTrainingScreen::setupProcessTrainingUi()
{
    endTrainingAction->setEnabled(false);
    this->menuItem->addAction(startTrainingAction);
    this->menuItem->addAction(endTrainingAction);

    // привязка с помощью signal-slot события нажатия на экшен в меню
    connect(startTrainingAction, &QAction::triggered, this, &BaseTrainingScreen::onStartTrainingActionTriggered);
    connect(endTrainingAction, &QAction::triggered, this, &BaseTrainingScreen::onEndTrainingActionTriggered);
}

void BaseTrainingScreen::onStartTrainingActionTriggered()
{
    QString enteredLastName = DialogsManager::askForLastNameInput();

    if (!enteredLastName.isEmpty()) {
        presenter->initTraining(enteredLastName);
    } else {
        qDebug() << "Ввод фамилии отменен";
    }
}

void BaseTrainingScreen::onEndTrainingActionTriggered()
{
    bool reply = DialogsManager::askForEndTrainingConfirmation();
    if(presenter) {
        presenter->onTrainingEndConfirmStatusReceived(reply);
    }
}

void BaseTrainingScreen::setupReplayTrainingUi()
{
    this->menuItem->addAction(checkTrainingAction);
}

void BaseTrainingScreen::showError(string error){}

void BaseTrainingScreen::startTraining() {
    startTrainingAction->setEnabled(false);
    endTrainingAction->setEnabled(true);
}

void BaseTrainingScreen::replayAction(BaseAction action)
{
}

void BaseTrainingScreen::sendActionToPresenter(BaseAction* action) {
    if(presenter) {
        presenter -> onAction(action);
    }
}

void BaseTrainingScreen::closeTrainingView() {
    QApplication::quit();
}


BaseTrainingScreen::~BaseTrainingScreen() { }
