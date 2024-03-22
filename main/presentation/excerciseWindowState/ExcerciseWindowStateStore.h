#ifndef EXCERCISEWINDOWSTATESTORE_H
#define EXCERCISEWINDOWSTATESTORE_H

#include <ExcerciseWindowState.h>

class ExcerciseWindowStateStore {
    
public:
    ExcerciseWindowStateStore();
    
    void requestTrainReplay();
    

private:
    ExcerciseWindowState* excerciseWindowState;
};

#endif // EXCERCISEWINDOWSTATESTORE_H
