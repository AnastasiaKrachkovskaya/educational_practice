#include "FirstTrainingScreen.h"
#include "ui_FirstTrainingScreen.h"

FirstTrainingScreen::FirstTrainingScreen(bool isOpenInProcessTrainingMode, QWidget *parent)
    : BaseTrainingScreen(parent)
    , ui(new Ui::FirstTrainingScreen)
{
    ui->setupUi(this);
}

FirstTrainingScreen::~FirstTrainingScreen()
{
    delete ui;
}
