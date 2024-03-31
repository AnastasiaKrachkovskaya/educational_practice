#ifndef BASETRAININGSCREEN_H
#define BASETRAININGSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>

class BaseTrainingScreen : public QWidget {
    Q_OBJECT

public:
    explicit BaseTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~BaseTrainingScreen();
protected:
    void setupUi();
private:
    QMenuBar* menuBar;
    QMenu* menuItem;
    QAction* startTrainingAction = new QAction("Начать тренировку");
    QAction* endTrainingAction = new QAction("Завершить тренировку");
    QAction* checkTrainingAction = new QAction("Проверить результат тренировки");

    bool isOpenInProcessTrainingMode;

    void setupProcessTrainingUi();
    void setupReplayTrainingUi();
};


#endif // BASETRAININGSCREEN_H
