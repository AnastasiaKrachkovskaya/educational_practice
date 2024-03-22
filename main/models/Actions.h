#ifndef ACTIONS
#define ACTIONS

#include <string>

using namespace std;

/*!
 * \class BaseAction
 * \brief Базовый класс всех событий пользователя (нажатий и т.д.)
 *
 * \var actedElementId ID элемента, над которым было совершено действие
 */
class BaseAction
{
public:
    BaseAction(string actedElementId) {
        this->actedElementId = actedElementId;
    }
    virtual ~BaseAction() {}

    string getActedElementId() { return actedElementId; }
private:
    string actedElementId;
};

/*!
 * \brief The PressedAction class
 */
class PressedAction: BaseAction {
public:
    PressedAction(string actedElementId): BaseAction(actedElementId) {}
    ~PressedAction() {}
};

#endif // ACTIONS_H
