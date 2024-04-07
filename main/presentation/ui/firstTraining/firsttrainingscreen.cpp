#include "FirstTrainingScreen.h"
#include "ui_FirstTrainingScreen.h"

FirstTrainingScreen::FirstTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent)
    : BaseTrainingScreen(isOpenInProcessTrainingMode, parent)
    , ui(new Ui::FirstTrainingScreen)
{
    ui->setupUi(this);
    BaseTrainingScreen::setupUi();
}

FirstTrainingScreen::~FirstTrainingScreen()
{
    delete ui;
}

void FirstTrainingScreen::on_pushButtonInstr1_clicked()
{
    showInstructionDialog();
}


void FirstTrainingScreen::on_pushButton_1_1_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_1_1->objectName())
    );
}


void FirstTrainingScreen::on_pushButton_1_2_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_1_2->objectName())
    );
}


void FirstTrainingScreen::on_pushButton_1_3_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_1_3->objectName())
        );
}


void FirstTrainingScreen::on_lineEdit_1_editingFinished()
{
    sendActionToPresenter(
        new TextInputChanged(ui->lineEdit_1->objectName(), ui->lineEdit_1->text())
        );
}


void FirstTrainingScreen::on_comboBox_1_activated(int index)
{
    sendActionToPresenter(
        new ComboBoxOptionSelectedAction(ui->comboBox_1->objectName(), ui->comboBox_1->currentText())
        );
}


void FirstTrainingScreen::on_tableWidget_1_cellChanged(int row, int column)
{
    sendActionToPresenter(
        new TableChangedAction(ui->tableWidget_1->objectName(), ui->tableWidget_1->item(row, column)->text(), row, column)
        );
}


void FirstTrainingScreen::on_radioButton_1_1_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_1_1->objectName())
        );
}


void FirstTrainingScreen::on_radioButton_1_2_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_1_2->objectName())
        );
}


void FirstTrainingScreen::on_radioButton_1_3_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_1_3->objectName())
        );
}


void FirstTrainingScreen::on_radioButton_1_4_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_1_4->objectName())
        );
}

