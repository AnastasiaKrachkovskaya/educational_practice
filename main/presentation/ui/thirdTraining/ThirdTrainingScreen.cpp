#include "SecondTrainingScreen.h"
#include "ui_SecondTrainingScreen.h"

SecondTrainingScreen::SecondTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent)
    : BaseTrainingScreen(isOpenInProcessTrainingMode, parent)
    , ui(new Ui::SecondTrainingScreen)
{
    ui->setupUi(this);
    BaseTrainingScreen::setupUi();
}

SecondTrainingScreen::~SecondTrainingScreen()
{
    delete ui;
}
