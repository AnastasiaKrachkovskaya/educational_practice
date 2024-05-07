#include "SecondTrainingScreen.h"
#include "ui_SecondTrainingScreen.h"

SecondTrainingScreen::SecondTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent)
    : BaseTrainingScreen(isOpenInProcessTrainingMode, parent)
    , ui(new Ui::SecondTrainingScreen)
{
    ui->setupUi(this);
    BaseTrainingScreen::setupUi();

    //QString objectName =ui->pushButton_3->objectName();
    //qDebug() << "Object name:" << objectName;
}

SecondTrainingScreen::~SecondTrainingScreen()
{
    delete ui;
}

void SecondTrainingScreen::on_pushButtonInstr2_clicked()
{
    showInstructionDialog();
}

void SecondTrainingScreen::on_pushButton_2_1_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_2_1->objectName())
        );
}


void SecondTrainingScreen::on_pushButton_2_2_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_2_2->objectName())
        );
}


void SecondTrainingScreen::on_lineEdit_2_editingFinished()
{
    sendActionToPresenter(
        new TextInputChanged(ui->lineEdit_2->objectName(), ui->lineEdit_2->text())
        );
}


void SecondTrainingScreen::on_comboBox_2_activated(int index)
{
    sendActionToPresenter(
        new ComboBoxOptionSelectedAction(ui->comboBox_2->objectName(), ui->comboBox_2->currentText())
        );
}


void SecondTrainingScreen::on_tableWidget_2_cellChanged(int row, int column)
{
    sendActionToPresenter(
        new TableChangedAction(ui->tableWidget_2->objectName(), ui->tableWidget_2->item(row, column)->text(), row, column)
        );
}


void SecondTrainingScreen::on_radioButton_2_1_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_2_1->objectName())
        );
}


void SecondTrainingScreen::on_radioButton_2_2_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_2_2->objectName())
        );
}


void SecondTrainingScreen::on_radioButton_2_3_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_2_3->objectName())
        );
}


void SecondTrainingScreen::on_radioButton_2_4_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_2_4->objectName())
        );
}

