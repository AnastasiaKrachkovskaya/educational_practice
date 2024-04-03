#include "dialogFinish.h"
#include "ui_dialogFinish.h"

DialogFinish::DialogFinish(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFinish)
{
    ui->setupUi(this);
}

DialogFinish::~DialogFinish()
{
    delete ui;
}
