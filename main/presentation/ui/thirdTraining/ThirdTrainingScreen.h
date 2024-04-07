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
    void on_pushButtonInstr3_clicked();

    void on_pushButton_3_1_clicked();

    void on_pushButton_3_2_clicked();

    void on_pushButton_3_3_clicked();

    void on_pushButton_3_4_clicked();

    void on_lineEdit_3_editingFinished();

    void on_comboBox_3_activated(int index);

    void on_tableWidget_3_cellChanged(int row, int column);

    void on_radioButton_3_1_clicked();

    void on_radioButton_3_2_clicked();

    void on_radioButton_3_3_clicked();

    void on_radioButton_3_4_clicked();

private:
    Ui::ThirdTrainingScreen *ui;
};

#endif // THIRDTRAININGSCREEN_H
