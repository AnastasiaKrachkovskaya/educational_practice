#ifndef ExcerciseViewPresenter_H
#define ExcerciseViewPresenter_H

#include "ProcessTrainingViewPresenter.h"
#include "ReplayTrainingViewPresenter.h"
#include <QString>

class ExcerciseView: public ProcessTrainingView,
                            public ReplayTrainingView {
public:
    ~ExcerciseView() {};
};

class ExcerciseViewPresenter : protected ProcessTrainingViewPresenter,
                                 protected ReplayTrainingViewPresenter
{
public:
    ~ExcerciseViewPresenter() {}
    void connectExcerciseView(ExcerciseView* view) {
        this->connectReplayTrainingView(view);
        this->connectProcessTrainingView(view);
    };

    using ProcessTrainingViewPresenter::onAction;

    void onAction(BaseAction* action) override {
        if(this->isReplayTrainingInProcess) return;

        ProcessTrainingViewPresenter::onAction(action);
    }

    void onAppLeft() {
        qDebug() << "onAppLeft";
    }

    using ProcessTrainingViewPresenter::initTraining;
    using ProcessTrainingViewPresenter::onTrainingEndConfirmStatusReceived;

    using ReplayTrainingViewPresenter::startTrainingReplay;
private:
    QString lastName;
};

#endif // ExcerciseViewPresenter_H
