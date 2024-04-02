#include "dialogInstruction.h"

DialogInstruction::DialogInstruction(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInstruction)
{
    ui->setupUi(this);
}

DialogInstruction::~DialogInstruction()
{
    delete ui;
}
