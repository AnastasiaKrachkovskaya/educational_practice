#ifndef FIRSTTRAININGSCREEN_H
#define FIRSTTRAININGSCREEN_H

#include <QWidget>
#include "main/presentation/ui/baseTrainingScreen/BaseTrainingScreen.h"
#include "ui_FirstTrainingScreen.h"

/*!
 * \brief Окно первого тренажера
 */

class FirstTrainingScreen : public BaseTrainingScreen, public Ui::FirstTrainingScreen {
    Q_OBJECT

public:
    explicit FirstTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~FirstTrainingScreen();
private slots:
    void on_pushButtonInstr1_clicked();

private:
    Ui::FirstTrainingScreen *ui;
};

#endif // FIRSTTRAININGSCREEN_H
