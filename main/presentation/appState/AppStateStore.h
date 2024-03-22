#ifndef APPSTATESTORE_H
#define APPSTATESTORE_H

enum OpenedExcerciseWindow{
    FIRST_EXCERCISE,
    SECOND_EXERCIZE,
    THIRD_EXERCIZE
};

class AppState {
public:
    AppState(OpenedExcerciseWindow openedExcersizeWindow) {
        this->openedExcerciseWindow = openedExcersizeWindow;
    }

    OpenedExcerciseWindow getOpenedExcerciseWindow() { return this->openedExcerciseWindow; }
private:
    OpenedExcerciseWindow openedExcerciseWindow;
};

AppState DefaultAppState = AppState(FIRST_EXCERCISE);

class AppStateStore
{
public:
    AppStateStore();
    void onMenuOptionsSelected();
private:
    AppState* appState;
};

#endif // APPSTATESTORE_H
