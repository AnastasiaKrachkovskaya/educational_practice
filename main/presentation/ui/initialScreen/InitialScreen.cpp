#include "InitialScreen.h"

InitialScreen::InitialScreen(QWidget* parent): QWidget(parent) {
    setupUi(this);
    this->presenter = new InitialViewPresenter();

    // добавление номера тренажера в заголовок экрана
    QString trainingAppNumberStr = QString::number((int)AppEnvironment::trainingAppNumber);
    QString basePrimaryLabelText = this->primaryTextLabel->text();
    QString resultPrimaryLabelText = basePrimaryLabelText + trainingAppNumberStr;
    this->primaryTextLabel->setText(resultPrimaryLabelText);
}

void InitialScreen::on_processTrainingPushButton_clicked()
{
    presenter->onProcessTrainingModeBtnClick();
}


void InitialScreen::on_replayTrainingPushButton_clicked()
{
    presenter->onReplayTrainingModeBtnClick();
}
