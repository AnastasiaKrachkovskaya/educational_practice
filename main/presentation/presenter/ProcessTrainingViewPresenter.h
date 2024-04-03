#ifndef TRAININGPROCESSPRESENTER_H
#define TRAININGPROCESSPRESENTER_H

#include <main/models/Actions.h>
#include <QString>
#include <list>

using namespace std;

class ProcessTrainingView {
public:
    virtual ~ProcessTrainingView() {};
    virtual void showError(string error) = 0;
    virtual void startTraining() = 0;
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
        if(processTrainingView) {
            processTrainingView->startTraining();
        }
    }

    /*!
     * \brief Обработать действие в тренировке
     * \param action
     */
    void onAction(BaseAction action) {
        // TODO
    }
private:
    ProcessTrainingView* processTrainingView = nullptr;
protected:
    void processTraining() {
        if(processTrainingView) {
            processTrainingView->startTraining();
        }
    }
};

#endif // TRAININGPROCESSPRESENTER_H
