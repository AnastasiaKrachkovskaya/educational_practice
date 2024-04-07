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

    void on_pushButton_2_1_clicked();

    void on_pushButton_2_2_clicked();

    void on_lineEdit_2_editingFinished();

    void on_comboBox_2_activated(int index);

    void on_tableWidget_2_cellChanged(int row, int column);

    void on_radioButton_2_1_clicked();

    void on_radioButton_2_2_clicked();

    void on_radioButton_2_3_clicked();

    void on_radioButton_2_4_clicked();

private:
    Ui::SecondTrainingScreen *ui;
};

#endif // SECONDTRAININGSCREEN_H
