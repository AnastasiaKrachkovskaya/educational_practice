#ifndef SECONDTRAININGSCREEN_H
#define SECONDTRAININGSCREEN_H

#include <QWidget>
#include "main/presentation/ui/baseTrainingScreen/BaseTrainingScreen.h"
#include "ui_SecondTrainingScreen.h"

class SecondTrainingScreen : public BaseTrainingScreen, public Ui::SecondTrainingScreen {
    Q_OBJECT

public:
    explicit SecondTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~SecondTrainingScreen();
private:
    Ui::SecondTrainingScreen *ui;
};

#endif // SECONDTRAININGSCREEN_H
