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
