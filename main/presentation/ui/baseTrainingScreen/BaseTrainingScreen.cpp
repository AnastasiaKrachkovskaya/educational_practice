#include "BaseTrainingScreen.h"
#include <QDebug>

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
    QString enteredLastName = DialogsManager::requestLastNameInput();

    if (!enteredLastName.isEmpty()) {
        presenter->initTraining(enteredLastName);
    } else {
        qDebug() << "Ввод фамилии отменен";
    }
}

void BaseTrainingScreen::onEndTrainingActionTriggered()
{
    bool reply = DialogsManager::requestEndTrainingConfirm();
    if(presenter) {
        presenter->onTrainingEndConfirmStatusReceived(reply);
    }
}

void BaseTrainingScreen::onReplayTrainingActionTriggered()
{
    QString filePath = DialogsManager::requestReplayTrainingFilePath();

    if(filePath.isNull() || filePath.isEmpty()) return;

    double replaySpeedFactor = DialogsManager::requestReplayTrainingSpeedFactor();

    if(replaySpeedFactor == NAN) return;

    if(presenter) {
        presenter->startTrainingReplay(filePath.toStdString(), replaySpeedFactor);
    }
}

void BaseTrainingScreen::setupReplayTrainingUi()
{
    this->menuItem->addAction(checkTrainingAction);

    connect(checkTrainingAction, &QAction::triggered, this, &BaseTrainingScreen::onReplayTrainingActionTriggered);

    connect(this, &BaseTrainingScreen::replayActionSignal, this, &BaseTrainingScreen::replayActionSlot, Qt::AutoConnection);
}

void BaseTrainingScreen::replayActionSlot(BaseAction* action) {
    switch (action->getActionType()) {
    case ActionType::PUSH_BUTTON_CLICK: {
        qDebug() << "render push_button_click action";
        PushButtonClickAction* pushButtonClickAction = dynamic_cast<PushButtonClickAction*>(action);
        QPushButton* pushButton = findChild<QPushButton*>(pushButtonClickAction->getActedElementId());
        pushButton->animateClick();
        break;
    }
    case ActionType::RADIO_BUTTON_SELECT: {
        qDebug() << "render radio_button_select action";

        RadioButtonSelectAction* radioButtonSelectAction = dynamic_cast<RadioButtonSelectAction*>(action);
        QRadioButton* radioButton = findChild<QRadioButton*>(radioButtonSelectAction->getActedElementId());
        radioButton->setChecked(true);
        break;
    }
    case ActionType::TEXT_INPUT_CHANGED: {
        qDebug() << "render text_input_changed action";

        TextInputChanged* textInputChangedAction = dynamic_cast<TextInputChanged*>(action);
        QLineEdit* lineEdit = findChild<QLineEdit*>(textInputChangedAction->getActedElementId());
        lineEdit->setText(textInputChangedAction->getInputValue());
        break;
    }
    case ActionType::COMBO_BOX_EXPANDED: {
        qDebug() << "render combo_box_expanded action";

        ComboBoxExpandedAction* comboBoxExpandedAction = dynamic_cast<ComboBoxExpandedAction*>(action);
        QComboBox* comboBox = findChild<QComboBox*>(comboBoxExpandedAction->getActedElementId());
        comboBox->showPopup();
        break;
    }
    case ActionType::COMBO_BOX_OPTION_SELECTED: {
        qDebug() << "render combo_box_option_selected action";

        ComboBoxOptionSelectedAction* comboBoxOptionSelectedAction = dynamic_cast<ComboBoxOptionSelectedAction*>(action);
        QComboBox* comboBox = findChild<QComboBox*>(comboBoxOptionSelectedAction->getActedElementId());
        comboBox->setCurrentText(comboBoxOptionSelectedAction->getSelectedOption());
        comboBox->hidePopup();
        break;
    }
    case ActionType::TABLE_CHANGED: {
        qDebug() << "render table_changed action";

        TableChangedAction* tableChangedAction = dynamic_cast<TableChangedAction*>(action);
        QTableWidget* tableWidget = findChild<QTableWidget*>(tableChangedAction->getActedElementId());
        auto model = tableWidget->model();
        model->setData(model->index(tableChangedAction->getRow(), tableChangedAction->getColumn()), tableChangedAction->getInputValue());
        break;
    }
    default:
        break;
    }
}

void BaseTrainingScreen::showError(string error){}

void BaseTrainingScreen::startTraining() {
    startTrainingAction->setEnabled(false);
    endTrainingAction->setEnabled(true);
}

void BaseTrainingScreen::replayAction(BaseAction* action)
{
    // Обязательно откидываем события с WorkerThread на Ui, иначе приложение будет
    // постоянно в режиме "Не отвечает".
    emit this->replayActionSignal(action);
}

void BaseTrainingScreen::sendActionToPresenter(BaseAction* action) {
    if(presenter) {
        presenter -> onAction(action);
    }
}

void BaseTrainingScreen::closeTrainingView() {
    QApplication::quit();
}


BaseTrainingScreen::~BaseTrainingScreen() {
    if(presenter) {
        presenter->onAppLeft();
    }
}
