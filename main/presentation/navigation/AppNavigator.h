#ifndef APPNAVIGATOR_H
#define APPNAVIGATOR_H

#include "Destination.h"

/*!
 * \brief Навигация по приложению
 */

class AppView{
public:
    virtual void navigateTo(const BaseDestination& destination) = 0;
};

/*!
 * \brief The AppNavigator class
 * Навигатор приложения
 * initialScreen -> [NUMBER]TrainingScreen
 */
class AppNavigator {
private:
    AppNavigator() {}
    AppNavigator(AppNavigator& other);

    static AppNavigator* instance;

    AppView* appView = nullptr;
public:
    static AppNavigator* getInstance() {
        if(instance == nullptr) {
            instance = new AppNavigator();
        }
        return instance;
    }

    void navigateTo(const BaseDestination& destination) {
        if(appView) {
            appView->navigateTo(destination);
        }
    }

    void connectAppView(AppView* appView) {
        this->appView = appView;
        InitialScreenDestination initialDestination = InitialScreenDestination();
        appView->navigateTo(initialDestination);
    }
};

#endif // APPNAVIGATOR_H
