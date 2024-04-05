#ifndef ACTIONS_H
#define ACTIONS_H

#include <QString>

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
    BaseAction(QString actedElementId) {
        this->actedElementId = actedElementId;
    }
    virtual ~BaseAction() {}

    QString getActedElementId() { return actedElementId; }
    QString getActionType() { return actionType; }
protected:
    QString actedElementId;
    QString actionType;
};

/*!
 * \brief Модель события нажатия на PushButton
 */
class PushButtonClickAction: public BaseAction {
public:
    PushButtonClickAction(QString actedElementId): BaseAction(actedElementId) {}
    ~PushButtonClickAction() {}
protected:
    QString actionType = "PushButtonClickAction";
};

/*!
 * \brief Модель события выбора радиокнопки
 */
class RadioButtonSelectAction: public BaseAction {
public:
    RadioButtonSelectAction(QString actedElementId): BaseAction(actedElementId) {}
    ~RadioButtonSelectAction() {}
protected:
    QString actionType = "RadioButtonSelectAction";
};

/*!
 * \brief Модель события изменения значения в текстовом поле
 */
class TextInputChanged: public BaseAction {
public:
    TextInputChanged(QString actedElementId, QString inputValue): BaseAction(actedElementId) {}
    ~TextInputChanged() {}
protected:
    QString actionType = "TextInputChanged";
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
protected:
    QString actionType = "ComboBoxExpandedAction";
};

/*!
 * \brief Модель события выбора одной из опций в выпадающем списке
 */
class ComboBoxOptionSelectedAction: public BaseAction {
public:
    ComboBoxOptionSelectedAction(QString actedElementId): BaseAction(actedElementId) {}
    ~ComboBoxOptionSelectedAction() {}
protected:
    QString actionType = "ComboBoxOptionSelectedAction";
};


/*!
 * \brief Модель события изменения таблицы
 */

//TODO подумать мб тут как-то надо по-хитрому еще передавать id столбца и измененное значение
class TableChangedAction: public BaseAction {
public:
    TableChangedAction(QString actedElementId): BaseAction(actedElementId) {}
    ~TableChangedAction() {}
protected:
    QString actionType = "TableChangedAction";
};



#endif // ACTIONS_H
