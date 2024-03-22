#ifndef EXCERCISEWINDOWSTATE_H
#define EXCERCISEWINDOWSTATE_H

#include <list>
#include <Actions.h>

using namespace std;

/*!
 * \class ExcerciseWindowState
 * \brief Класс состояния окна тренажера.
 */
class ExcerciseWindowState {
public:
    class Loading;
    class TrainReplay;
    class Training;
private:
};

/*!
 * \class Loading
 * \brief.Состояние загрузки данных
 */
class ExcerciseWindowState::Loading : public ExcerciseWindowState{};

/*!
 * \class TrainReplay
 * \brief Состояние воспроизведения тренировки.
 * \var actions список событий на тренировке
 * \var replaySpeedFactor ускорение воспроизведения тренировки
 */
class ExcerciseWindowState::TrainReplay : public ExcerciseWindowState{
public:
    TrainReplay(list<BaseAction> actions) { this->actions = actions; }

    list<BaseAction> getActions() { return this->actions; }
    int getReplaySpeedFactor() { return this->replaySpeedFactor; }
private:
    list<BaseAction> actions = {};
    int replaySpeedFactor = 1;
};

/*!
 * \class Training
 * \brief Состояние тренировки
 */
class ExcerciseWindowState::Training : public ExcerciseWindowState{

};

/*!
 * \brief DefaultExcerciseWindowState
 */
ExcerciseWindowState DefaultExcerciseWindowState = ExcerciseWindowState::Loading();


#endif // EXCERCISEWINDOWSTATE_H
