#ifndef FIRSTTRAININGSCREEN_H
#define FIRSTTRAININGSCREEN_H

#include <QWidget>
#include "main/models/Actions.h"
#include "main/presentation/ui/baseTrainingScreen/BaseTrainingScreen.h"
#include "ui_FirstTrainingScreen.h"

#include <QString>

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

    void on_pushButton_1_1_clicked();

    void on_pushButton_1_2_clicked();

    void on_pushButton_1_3_clicked();

    void on_lineEdit_1_editingFinished();

    void on_comboBox_1_activated(int index);

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::FirstTrainingScreen *ui;
};

#endif // FIRSTTRAININGSCREEN_H
