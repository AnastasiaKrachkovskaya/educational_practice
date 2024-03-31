#ifndef TRAININGPROCESSPRESENTER_H
#define TRAININGPROCESSPRESENTER_H

#include <main/models/Actions.h>
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

    void connectProcessTrainingView(ProcessTrainingView* ProcessTrainingView) {
        this->ProcessTrainingView = ProcessTrainingView;
    }

    /*!
     * \brief Обработать действие в тренировке
     * \param action
     */
    void onAction(BaseAction action) {
        // TODO
    }
private:
    ProcessTrainingView* ProcessTrainingView = nullptr;
protected:
    void processTraining() {
        if(ProcessTrainingView) {
            ProcessTrainingView->startTraining();
        }
    }
};

#endif // TRAININGPROCESSPRESENTER_H
