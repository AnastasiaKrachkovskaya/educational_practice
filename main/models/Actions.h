#ifndef ACTIONS_H
#define ACTIONS_H

#include <QString>

using namespace std;

enum class ActionType {
    PUSH_BUTTON_CLICK,
    RADIO_BUTTON_SELECT,
    TEXT_INPUT_CHANGED,
    COMBO_BOX_EXPANDED,
    COMBO_BOX_OPTION_SELECTED,
    TABLE_CHANGED,
};

/*!
 * \class BaseAction
 * \brief Базовый класс всех событий пользователя (нажатий и т.д.)
 *
 * \var actedElementId ID элемента, над которым было совершено действие
 */
class BaseAction
{
public:
    BaseAction(QString actedElementId) {
        this->actedElementId = actedElementId;
    }
    virtual ~BaseAction() {}

    QString getActedElementId() { return actedElementId; }
    virtual ActionType getActionType() = 0;
protected:
    QString actedElementId;
};

/*!
 * \brief Модель события нажатия на PushButton
 */
class PushButtonClickAction: public BaseAction {
public:
    PushButtonClickAction(QString actedElementId): BaseAction(actedElementId) {}
    ~PushButtonClickAction() {}

    ActionType getActionType() override { return ActionType::PUSH_BUTTON_CLICK; }
};

/*!
 * \brief Модель события выбора радиокнопки
 */
class RadioButtonSelectAction: public BaseAction {
public:
    RadioButtonSelectAction(QString actedElementId): BaseAction(actedElementId) {}
    ~RadioButtonSelectAction() {}

    ActionType getActionType() override { return ActionType::RADIO_BUTTON_SELECT; }
};

/*!
 * \brief Модель события изменения значения в текстовом поле
 */
class TextInputChanged: public BaseAction {
public:
    TextInputChanged(QString actedElementId, QString inputValue): BaseAction(actedElementId) {
        this->inputValue = inputValue;
    }
    ~TextInputChanged() {}

    ActionType getActionType() override { return ActionType::TEXT_INPUT_CHANGED; }
    QString getInputValue() { return this->inputValue; }
private:
    QString inputValue;
};


/*!
 * \brief Модель события раскрытия выпадающего списка
 *
 * ВОЗМОЖНО НЕ НУЖНО
 */
class ComboBoxExpandedAction: public BaseAction {
public:
    ComboBoxExpandedAction(QString actedElementId): BaseAction(actedElementId) {}
    ~ComboBoxExpandedAction() {}

    ActionType getActionType() override { return ActionType::COMBO_BOX_EXPANDED; }
};

/*!
 * \brief Модель события выбора одной из опций в выпадающем списке
 */
class ComboBoxOptionSelectedAction: public BaseAction {
public:
    ComboBoxOptionSelectedAction(QString actedElementId, QString selectedOption): BaseAction(actedElementId) {
        this->selectedOption = selectedOption;
    }

    ActionType getActionType() override { return ActionType::COMBO_BOX_OPTION_SELECTED; }

    QString getSelectedOption() { return this->selectedOption; }
private:
    QString selectedOption;
};


/*!
 * \brief Модель события изменения таблицы
 */

//TODO подумать мб тут как-то надо по-хитрому еще передавать id столбца и измененное значение
class TableChangedAction: public BaseAction {
public:
    TableChangedAction(QString actedElementId, QString inputValue, int row, int column): BaseAction(actedElementId) {
        this->inputValue = inputValue;
        this->row = row;
        this->column = column;
    }
    ~TableChangedAction() {}

    QString getInputValue() { return this->inputValue; }
    int getRow() { return this->row; }
    int getColumn() { return this->column; }

    ActionType getActionType() override { return ActionType::TABLE_CHANGED; }
private:
    QString inputValue;
    int row;
    int column;
};



#endif // ACTIONS_H
