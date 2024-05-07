#ifndef ReplayTrainingViewPresenter_H
#define ReplayTrainingViewPresenter_H

#include "main/models/Actions.h"
#include <list>
#include "main/data/repository/ActionsRepository.h"
#include <QElapsedTimer>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>


using namespace std;

class ReplayTrainingView {
public:
    virtual ~ReplayTrainingView() {};
    virtual void replayAction(BaseAction* action) = 0;
    virtual void showError(string error) = 0;
};

/*!
 * \brief Презентер для view, который может воспроизводить процесс тренировки
 */
class ReplayTrainingViewPresenter {
public:
    ReplayTrainingViewPresenter() {};
    ~ReplayTrainingViewPresenter() {};

    void connectReplayTrainingView(ReplayTrainingView* replayTrainingView) {
        this->replayTrainingView = replayTrainingView;
    }

    /*!
     * \brief Воспроизвести тренировку из файла
     * \param filename
     */
    void startTrainingReplay(string filePath, double replaySpeedFactor) {
        try {
            isReplayTrainingInProcess = true;
            replayTrainingFuture= QtConcurrent::run([this, filePath, replaySpeedFactor]() {
                list<pair<BaseAction*, int>> actions = this->actionsRepository->loadActionsDataFromFile(filePath);\

                if(actions.empty()) return;

                qDebug() << "Starting replaying...";

                qDebug() << "Replay speed factor = " + to_string(replaySpeedFactor);
                int previousActionEllapsedTime = 0;
                for(auto actionToTime: actions) {
                    qDebug() << "Initial time = " + to_string(actionToTime.second);

                    int timeDifference = actionToTime.second - previousActionEllapsedTime;
                    int delayMillis = timeDifference / replaySpeedFactor;
                    previousActionEllapsedTime = actionToTime.second;

                    qDebug() << "Replaying action, delay = " + to_string(delayMillis);

                    QThread::currentThread()->msleep(delayMillis);
                    this->replayTrainingView->replayAction(actionToTime.first);
                }
            });
        } catch(...) {
            qDebug() << "Error happened";
        }
        isReplayTrainingInProcess = false;
    }
protected:
    bool isReplayTrainingInProcess = false;
    QFuture<void> replayTrainingFuture;

private:
    ReplayTrainingView* replayTrainingView = nullptr;
    ActionsRepository* actionsRepository = ActionsRepository::getInstance();
};

#endif // ReplayTrainingViewPresenter_H
