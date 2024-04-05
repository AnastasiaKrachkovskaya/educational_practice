#include "ActionsRepository.h"

ActionsRepository* ActionsRepository::instance = nullptr;

void ActionsRepository::saveAction(BaseAction* action)
{

}

void ActionsRepository::uploadActionsDataToFile()
{
    qDebug() << "Выгрузка в файл";
}

list<BaseAction> ActionsRepository::loadActionsDataFromFile()
{

}

