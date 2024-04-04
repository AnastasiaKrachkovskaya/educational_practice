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

