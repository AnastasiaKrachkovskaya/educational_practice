#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H

#include <QWidget>
#include "ui_InitialScreen.h"
#include "main/presentation/presenter/InitialViewPresenter.h"
#include "main/data/env/AppEnvironment.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AppWindow;
}
QT_END_NAMESPACE

class InitialScreen: public QWidget, private Ui::InitialScreen {
    Q_OBJECT
private:
    InitialViewPresenter* presenter;
public:
    explicit InitialScreen(QWidget* parent = nullptr);
private slots:
    void on_processTrainingPushButton_clicked();
    void on_replayTrainingPushButton_clicked();
};

#endif // INITIALSCREEN_H
