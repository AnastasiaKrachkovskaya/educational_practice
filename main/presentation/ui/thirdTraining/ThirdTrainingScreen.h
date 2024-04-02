#ifndef THIRDTRAININGSCREEN_H
#define THIRDTRAININGSCREEN_H

#include <QWidget>
#include "main/presentation/ui/baseTrainingScreen/BaseTrainingScreen.h"
#include "ui_ThirdTrainingScreen.h"

/*!
 * \brief Окно третьего тренажера
 */

class ThirdTrainingScreen : public BaseTrainingScreen, public Ui::ThirdTrainingScreen {
    Q_OBJECT

public:
    explicit ThirdTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent = nullptr);
    ~ThirdTrainingScreen();
private slots:
    void on_pushButton_5_clicked();

private:
    Ui::ThirdTrainingScreen *ui;
};

#endif // THIRDTRAININGSCREEN_H
