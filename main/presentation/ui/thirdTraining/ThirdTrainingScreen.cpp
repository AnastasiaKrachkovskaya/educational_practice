#include "ThirdTrainingScreen.h"
#include "ui_ThirdTrainingScreen.h"


ThirdTrainingScreen::ThirdTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent)
    : BaseTrainingScreen(isOpenInProcessTrainingMode, parent)
    , ui(new Ui::ThirdTrainingScreen)
{
    ui->setupUi(this);
    BaseTrainingScreen::setupUi();
}

ThirdTrainingScreen::~ThirdTrainingScreen()
{
    delete ui;
}

void ThirdTrainingScreen::on_pushButtonInstr3_clicked()
{
    showInstructionDialog();
}

void ThirdTrainingScreen::on_pushButton_3_1_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_3_1->objectName())
        );
}


void ThirdTrainingScreen::on_pushButton_3_2_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_3_2->objectName())
        );
}


void ThirdTrainingScreen::on_pushButton_3_3_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_3_3->objectName())
        );
}


void ThirdTrainingScreen::on_pushButton_3_4_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_3_4->objectName())
        );
}


void ThirdTrainingScreen::on_lineEdit_3_editingFinished()
{
    sendActionToPresenter(
        new TextInputChanged(ui->lineEdit_3->objectName(), ui->lineEdit_3->text())
        );
}


void ThirdTrainingScreen::on_comboBox_3_activated(int index)
{
    sendActionToPresenter(
        new ComboBoxOptionSelectedAction(ui->comboBox_3->objectName(), ui->comboBox_3->currentText())
        );
}


void ThirdTrainingScreen::on_tableWidget_3_cellChanged(int row, int column)
{
    sendActionToPresenter(
        new TableChangedAction(ui->tableWidget_3->objectName(), ui->tableWidget_3->item(row, column)->text(), row, column)
        );
}


void ThirdTrainingScreen::on_radioButton_3_1_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_3_1->objectName())
        );
}


void ThirdTrainingScreen::on_radioButton_3_2_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_3_2->objectName())
        );
}


void ThirdTrainingScreen::on_radioButton_3_3_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_3_3->objectName())
        );
}


void ThirdTrainingScreen::on_radioButton_3_4_clicked()
{
    sendActionToPresenter(
        new RadioButtonSelectAction(ui->radioButton_3_4->objectName())
        );
}



void ThirdTrainingScreen::on_comboBox_3_customContextMenuRequested(const QPoint &pos)
{
    sendActionToPresenter(
        new ComboBoxExpandedAction(ui->comboBox_3->objectName())
        );
}

