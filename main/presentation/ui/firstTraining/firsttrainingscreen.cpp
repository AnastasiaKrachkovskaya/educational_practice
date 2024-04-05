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


void FirstTrainingScreen::on_pushButton_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton->objectName())
    );
}


void FirstTrainingScreen::on_pushButton_3_clicked()
{
    sendActionToPresenter(
        new PushButtonClickAction(ui->pushButton_3->objectName())
    );
}

