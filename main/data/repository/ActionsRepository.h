#ifndef ACTIONSREPOSITORY_H
#define ACTIONSREPOSITORY_H

#include <list>
#include "main/models/Actions.h"

using namespace std;

/*!
 * \class ActionsRepository
 * \brief Класс репозитория, отвечающий за сохранение событиый пользователя в режиме тренажера
 * в RAM и последующую их выгрузку в XML формате в файл.
 * \
 */
class ActionsRepository
{
public:
    ActionsRepository();

    /*!
     * \brief saveAction метод для сохранения события пользователя в режиме тренажера.
     * Сохраняет событие в RAM.
     * \param action событие, совершенное пользователем
     */
    void saveAction(BaseAction* action);

    /*!
     * \brief uploadActionsDataToFile метод для выгрузки всех сохраненных событий из RAM
     * в файл в формате XML.
     */
    void uploadActionsDataToFile();

    /*!
     * \brief loadActionsDataFromFile метод для загрузки всех событий из файла мз формата XML
     * TODO: прокидывать имя файла и добавить возвращаемый тип
     */
    list<BaseAction> loadActionsDataFromFile();
private:
    /*!
     * \brief actions список событий, RAM хранилище
     */
    list<BaseAction> actions = {};
};

#endif // ACTIONSREPOSITORY_H
