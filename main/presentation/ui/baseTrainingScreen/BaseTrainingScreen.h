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
private:
    void setupProcessTrainingUi();
    void setupReplayTrainingUi();
};


#endif // BASETRAININGSCREEN_H
