#include "ActionsRepository.h"

ActionsRepository* ActionsRepository::instance = nullptr;

void ActionsRepository::saveAction(BaseAction* action)
{
    if(this->timer) {
        qDebug() << "Saving action";

        pair<BaseAction*, int> actionToTime;
        actionToTime.first = action;

        actionToTime.second = this->timer->elapsed();


        if(action->getActionType() == ActionType::COMBO_BOX_OPTION_SELECTED) {
            ComboBoxExpandedAction* comboBoxExpandedAction = new ComboBoxExpandedAction(action->getActedElementId());

            int comboBoxExpandedActionTime = actionToTime.second;
            if(this->actions.size() <= 1) {
                comboBoxExpandedActionTime = std::min(actionToTime.second / 2, 1000);
            } else {
                int prevActionTime = this->actions.end()->second;
                comboBoxExpandedActionTime = std::min((actionToTime.second + prevActionTime) / 2, actionToTime.second - 1000);
            }

            pair<BaseAction*, int> comboBoxActionToTime;
            comboBoxActionToTime.first = comboBoxExpandedAction;
            comboBoxActionToTime.second = comboBoxExpandedActionTime;
            this->actions.push_back(comboBoxActionToTime);
        }

        this->actions.push_back(actionToTime);
    }
}

void ActionsRepository::uploadActionsDataToFile(string userLastName)
{
    delete timer;
    timer = nullptr;

    XMLDocument* actionsXML =  this->actionsXmlParser->parseToXML(this->actions);

    int actionsAmount = this->actions.size();
    qDebug() << "Saving actions into file, actions size = " + std::to_string(actionsAmount);
    qDebug() << this->actions.size();

    string trainingAppNumberAsString;
    switch(AppEnvironment::trainingAppNumber) {
        case TrainingAppNumber::FIRST:
            trainingAppNumberAsString = "1";
            break;
        case TrainingAppNumber::SECOND:
            trainingAppNumberAsString = "2";
            break;
        case TrainingAppNumber::THIRD:
            trainingAppNumberAsString = "3";
            break;
    }

    // example: /Krachkovskaya-training_1.xml
    string fileName = "/" + userLastName + "-" + "training_" +  trainingAppNumberAsString + ".xml";

    string resultFilePath = QApplication::applicationDirPath().toStdString() + fileName;

    XMLError result = actionsXML->SaveFile(resultFilePath.c_str());

    qDebug() << "Saving result: " + to_string(result);
}

list<pair<BaseAction*, int>> ActionsRepository::loadActionsDataFromFile(string filePath)
{
    try {
        qDebug() << "Loading actions from file";

        //string resultFilePath = QApplication::applicationDirPath().toStdString() + "/SavedData.xml";

        XMLDocument* actionsXMLDocument = new XMLDocument();

        XMLError loadFileResult = actionsXMLDocument->LoadFile(filePath.c_str());

        list<pair<BaseAction*, int>> parsingResult = this->actionsXmlParser->parseFromXML(actionsXMLDocument);

        qDebug() << "result successfull, size = " + to_string(parsingResult.size());

        return parsingResult;
    } catch (XMLParsingException exception) {
        qDebug() << "ERROR: " + exception.getDescription() + " ";
    } catch (...) {
        qDebug() << "ERROR: UNKNOWN";
    }

    return list<pair<BaseAction*, int>>();
}

void ActionsRepository::startTrainingTimer() {
    this->timer = new QElapsedTimer();
    this->timer->start();
}

