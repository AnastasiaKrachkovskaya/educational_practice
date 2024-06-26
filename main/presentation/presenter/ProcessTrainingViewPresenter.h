#ifndef TRAININGPROCESSPRESENTER_H
#define TRAININGPROCESSPRESENTER_H

#include <main/models/Actions.h>
#include <main/data/repository/ActionsRepository.h>
#include <QString>
#include <list>

using namespace std;

class ProcessTrainingView {
public:
    virtual ~ProcessTrainingView() {};
    virtual void showError(string error) = 0;
    virtual void startTraining() = 0;
    virtual void closeTrainingView() = 0;
};

/*!
 * \brief Презентер для вью прохождения тренировки.
 */
class ProcessTrainingViewPresenter {
public:
    ProcessTrainingViewPresenter() {};
    ~ProcessTrainingViewPresenter() {};

    void connectProcessTrainingView(ProcessTrainingView* processTrainingView) {
        this->processTrainingView = processTrainingView;
    }

    void initTraining(QString lastName) {
        if(processTrainingView && actionsRepository) {
            this->lastName = lastName;
            actionsRepository->startTrainingTimer();
            processTrainingView->startTraining();
        }
    }

    void onTrainingEndConfirmStatusReceived(bool isTrainingEndConfirmed) {
        if(!(actionsRepository && processTrainingView && isTrainingEndConfirmed)) {
            return;
        }

        actionsRepository ->uploadActionsDataToFile(this->lastName.toStdString());
        processTrainingView -> closeTrainingView();
    }

    /*!
     * \brief Обработать действие в тренировке
     * \param action
     */
    virtual void onAction(BaseAction* action) {
        if(actionsRepository) {
            actionsRepository->saveAction(action);
        }
    }
private:
    ProcessTrainingView* processTrainingView = nullptr;
    ActionsRepository* actionsRepository = ActionsRepository::getInstance();
    QString lastName = "";
};

#endif // TRAININGPROCESSPRESENTER_H
