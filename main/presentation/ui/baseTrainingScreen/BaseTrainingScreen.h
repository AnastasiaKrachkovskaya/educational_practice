#ifndef BASETRAININGSCREEN_H
#define BASETRAININGSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QString>
#include <QApplication>
#include <QRadioButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QStringLiteral>
#include "main/presentation/presenter/ExcerciseViewPresenter.h"
#include "main/presentation/ui/dialogs/DialogsManager.h"
#include "main/models/Actions.h"

/*!
 * \brief Визуальная часть меню
 */
class BaseTrainingScreen : public QWidget, public ExcerciseView {
    Q_OBJECT

public:
    explicit BaseTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~BaseTrainingScreen();

    void showError(string error) override;
    void startTraining() override;
    void replayAction(BaseAction* action) override;
    void closeTrainingView() override;

protected:
    void setupUi();
    void showInstructionDialog();
    void sendActionToPresenter(BaseAction* action);
private:
    QMenuBar* menuBar;
    QMenu* menuItem;
    QAction* startTrainingAction = new QAction("Начать тренировку");
    QAction* endTrainingAction = new QAction("Завершить тренировку");
    QAction* checkTrainingAction = new QAction("Проверить результат тренировки");

    bool isOpenInProcessTrainingMode;
    ExcerciseViewPresenter* presenter;

    void setupProcessTrainingUi();
    void setupReplayTrainingUi();
private slots:
    void onStartTrainingActionTriggered();
    void onEndTrainingActionTriggered();
    void onReplayTrainingActionTriggered();
    void replayActionSlot(BaseAction* action);
signals:
    void replayActionSignal(BaseAction* action);
};


#endif // BASETRAININGSCREEN_H
