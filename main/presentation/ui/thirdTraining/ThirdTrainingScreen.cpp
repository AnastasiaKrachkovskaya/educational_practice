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
