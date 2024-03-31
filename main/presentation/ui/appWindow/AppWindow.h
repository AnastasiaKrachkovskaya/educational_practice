#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "main/presentation/navigation/AppNavigator.h"
#include "main/presentation/navigation/Destination.h"
#include "main/presentation/ui/initialScreen/InitialScreen.h"
#include "main/presentation/ui/firstTraining/FirstTrainingScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AppWindow;
}
QT_END_NAMESPACE

class AppWindow: public QMainWindow, public AppView, public DestinationHandler
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

    void navigateTo(const BaseDestination& destination) override;
    void handleInitialScreenDestination(const InitialScreenDestination& dest) override;
    void handleTrainingScreenDestination(const TrainingScreenDestination& dest) override;

};
#endif // APPWINDOW_H
