#ifndef EXCERCISEWINDOWSTATE_H
#define EXCERCISEWINDOWSTATE_H

class ExcerciseWindowState {
public:
    class Loading;
    class TrainReplay;
    class Training;
private:
};

class ExcerciseWindowState::Loading : public ExcerciseWindowState{

};

class ExcerciseWindowState::TrainReplay : public ExcerciseWindowState{

};
class ExcerciseWindowState::Training : public ExcerciseWindowState{

};

ExcerciseWindowState DefaultExcerciseWindowState = ExcerciseWindowState::Loading();

class ExcerciseWindowStateStore
{
public:
    ExcerciseWindowStateStore();
    void requestTrainReplay();
private:
    ExcerciseWindowState* appState;
};

#endif // EXCERCISEWINDOWSTATE_H
