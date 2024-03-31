#include "BaseTrainingScreen.h"

BaseTrainingScreen::BaseTrainingScreen(bool isOpenInProcessTrainingMode,
                                       QWidget* parent): QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QMenuBar* menu = new QMenuBar();
    QMenu* fileMenu = new QMenu("FILLE");
    menu->addMenu(fileMenu);
    fileMenu->addAction("Test1");
    fileMenu->addAction("ts1");
    this->layout()->setMenuBar(menu);
}

BaseTrainingScreen::~BaseTrainingScreen() { }
