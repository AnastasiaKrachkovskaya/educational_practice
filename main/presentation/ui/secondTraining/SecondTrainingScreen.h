#ifndef SECONDTRAININGSCREEN_H
#define SECONDTRAININGSCREEN_H

#include <QWidget>
#include "main/presentation/ui/baseTrainingScreen/BaseTrainingScreen.h"
#include "ui_SecondTrainingScreen.h"

/*!
 * \brief Окно второго тренажера
 */

class SecondTrainingScreen : public BaseTrainingScreen, public Ui::SecondTrainingScreen {
    Q_OBJECT

public:
    explicit SecondTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~SecondTrainingScreen();
private slots:
    void on_pushButtonInstr2_clicked();

private:
    Ui::SecondTrainingScreen *ui;
};

#endif // SECONDTRAININGSCREEN_H
