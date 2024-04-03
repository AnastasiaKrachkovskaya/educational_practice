#ifndef BASETRAININGSCREEN_H
#define BASETRAININGSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include "main/presentation/presenter/ExcerciseViewPresenter.h"
#include "dialogInstruction.h"
#include "dialogFinish.h"

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
    void replayAction(BaseAction action) override;

protected:
    void setupUi();
    void showInstructionDialog();
private:
    QMenuBar* menuBar;
    QMenu* menuItem;
    QAction* startTrainingAction = new QAction("Начать тренировку");
    QAction* endTrainingAction = new QAction("Завершить тренировку");
    QAction* checkTrainingAction = new QAction("Проверить результат тренировки");

    DialogInstruction* dialogInstruction;
    DialogFinish* dialogFinish;

    bool isOpenInProcessTrainingMode;
    ExcerciseViewPresenter* presenter;

    void setupProcessTrainingUi();
    void setupReplayTrainingUi();
private slots:
    void onStartTrainingActionTriggered();
    void onEndTrainingActionTriggered();
};


#endif // BASETRAININGSCREEN_H
