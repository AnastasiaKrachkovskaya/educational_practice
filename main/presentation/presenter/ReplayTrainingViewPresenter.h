#ifndef ReplayTrainingViewPresenter_H
#define ReplayTrainingViewPresenter_H

#include <main/models/Actions.h>
#include <list>

using namespace std;

class ReplayTrainingView {
public:
    virtual ~ReplayTrainingView() {};
    virtual void replayAction(BaseAction action) = 0;
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
     * \brief Метод установки скорости воспроизведения.
     * \param replaySpeedFactor
     */
    void setReplaySpeedFactor(int replaySpeedFactor) {
        this->replaySpeedFactor = replaySpeedFactor;
    }

    /*!
     * \brief Воспроизвести тренировку из файла
     * \param filename
     */
    void startTrainingReplay(string filename) {
        //TODO показывать на вью загрузку и дергать репозиторий чтобы он загрузил данные из файла
        // лучше это делать отдельным потоком и не забыть обработать исключения, в случае которых показывать ошибку
    }
private:
    ReplayTrainingView* replayTrainingView = nullptr;

protected:
    int replaySpeedFactor = 1;

    /*!
     * \brief Воспроизвести тренировку из списка действий.
     * \param actions
     */
    void startReplaying(list<BaseAction> actions) {
        // TODO: воспроизведение в отдельном потоке и так же вызывать какой-нибудь delay для того чтобы
        // было время между действиями
        for(BaseAction action: actions) {
            if(replayTrainingView) {
                replayTrainingView->replayAction(action);
            }
        }
    }
};

#endif // ReplayTrainingViewPresenter_H
