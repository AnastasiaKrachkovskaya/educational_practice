#ifndef ACTIONSREPOSITORY_H
#define ACTIONSREPOSITORY_H

#include <list>
#include <QDebug>
#include <QException>
#include "main/models/Actions.h"
#include "main/data/XMLParser/ActionsXMLParser.h"
#include <QApplication>
#include <QElapsedTimer>
#include "main/data/env/AppEnvironment.h"

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
    static ActionsRepository* getInstance() {
        if(instance == nullptr) {
            instance = new ActionsRepository();
        }
        return instance;
    }

    /*!
     * \brief saveAction метод для сохранения события пользователя в режиме тренажера.
     * Сохраняет событие в RAM.
     * \param action событие, совершенное пользователем
     */
    void saveAction(BaseAction* action);

    /*!
     * \brief uploadActionsDataToFile метод для выгрузки всех сохраненных событий из RAM
     * в файл в формате XML.ввв
     * \throw QException при ошибке
     */
    void uploadActionsDataToFile(string userLastName);

    void startTrainingTimer();

    /*!
     * \brief loadActionsDataFromFile метод для загрузки всех событий из файла мз формата XML
     * \throw QException при ошибке
     */
    list<pair<BaseAction*, int>> loadActionsDataFromFile(string filePath);
private:
    ActionsRepository() {}
    ActionsRepository(ActionsRepository& other);

    static ActionsRepository* instance;

    ActionsRepository* appView = nullptr;

    QElapsedTimer* timer = nullptr;
    /*!
     * \brief actions список событий, RAM хранилище
     */
    list<pair<BaseAction*, int>> actions = {};

    ActionsXMLParser* actionsXmlParser = new ActionsXMLParser();

    QString getTrainingReplaysDirPath();
};

#endif // ACTIONSREPOSITORY_H
