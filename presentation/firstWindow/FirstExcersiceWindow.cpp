#include "FirstExcerciseWindow.h"
#include "ui_FirstExcersiceWindow.h"

FirstExcerciseWindow::FirstExcerciseWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::FirstExcerciseWindow)
{
    ui->setupUi(this);
}

FirstExcerciseWindow::~FirstExcerciseWindow()
{
    delete ui;
}

void FirstExcerciseWindow::on_id_push_btn_clicked() {
    while (true) {

    }
}
