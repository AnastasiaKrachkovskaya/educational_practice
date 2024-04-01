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
    using ReplayTrainingViewPresenter::startTrainingReplay;
    using ReplayTrainingViewPresenter::setReplaySpeedFactor;

    /*!
     * \brief Запоминаем введеную фамилию
     */
    void setLastName(QString lastName)
    {
        this->lastName = lastName;
    }

private:
    QString lastName;
};

#endif // ExcerciseViewPresenter_H
