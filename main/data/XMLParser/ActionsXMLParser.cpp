#include "ActionsXMLParser.h"
#include <QDebug>

ActionsXMLParser::ActionsXMLParser() {}

XMLDocument* ActionsXMLParser::parseToXML(list<pair<BaseAction*, int>> actions)
{
    XMLDocument* xmlDocument = new XMLDocument();

    XMLElement* actionsNode = xmlDocument->NewElement(ACTIONS_NODE_KEY);
    xmlDocument->InsertFirstChild(actionsNode);

    for(pair<BaseAction*, int> actionToTime: actions) {
        BaseAction* action = actionToTime.first;
        int actionTime = actionToTime.second;

        XMLElement* actionElement = actionsNode->InsertNewChildElement(ACTION_ELEMENT_KEY);

        XMLElement* actedObjectIdElement = actionElement->InsertNewChildElement(ACTED_OBJECT_ID_ELEMENT_KEY);
        actedObjectIdElement->SetText(action->getActedElementId().toStdString().c_str());

        XMLElement* elapsedTimeElement = actionElement->InsertNewChildElement(ELAPSED_TIME_ELEMENT_KEY);
        elapsedTimeElement->SetText(actionTime);

        switch (action->getActionType()) {
        case ActionType::PUSH_BUTTON_CLICK:
            parsePushButtonClickAction(dynamic_cast<PushButtonClickAction*>(action), actionElement);
            break;
        case ActionType::RADIO_BUTTON_SELECT:
            parseRadioButtonSelectAction(dynamic_cast<RadioButtonSelectAction*>(action), actionElement);
            break;
        case ActionType::TEXT_INPUT_CHANGED:
            parseTextInputChangedAction(dynamic_cast<TextInputChanged*>(action), actionElement);
            break;
        case ActionType::COMBO_BOX_EXPANDED:
            parseComboBoxExpandedAction(dynamic_cast<ComboBoxExpandedAction*>(action), actionElement);
            break;
        case ActionType::COMBO_BOX_OPTION_SELECTED:
            parseComboBoxOptionSelectedAction(dynamic_cast<ComboBoxOptionSelectedAction*>(action), actionElement);
            break;
        case ActionType::TABLE_CHANGED:
            parseTableChangedAction(dynamic_cast<TableChangedAction*>(action), actionElement);
            break;
        default:
            return nullptr;
            break;
        }
    }

    return xmlDocument;
}

void ActionsXMLParser::parsePushButtonClickAction(PushButtonClickAction* action, XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(PUSH_BUTTON_CLICK_ACTION_TYPE_VALUE);
}

void ActionsXMLParser::parseRadioButtonSelectAction(RadioButtonSelectAction* action, XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(RADIO_BUTTON_SELECT_ACTION_TYPE_VALUE);
}

void ActionsXMLParser::parseTextInputChangedAction(TextInputChanged* action, XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(TEXT_INPUT_CHANGED_ACTION_TYPE_VALUE);

    XMLElement* inputValueElement = outputActionElement->InsertNewChildElement(TEXT_INPUT_CHANGED_VALUE_ELEMENT_KEY);
    inputValueElement->SetText(action->getInputValue().toStdString().c_str());
}

void ActionsXMLParser::parseComboBoxExpandedAction(ComboBoxExpandedAction* action, XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(COMBO_BOX_EXPANDED_ACTION_TYPE_VALUE);
}

void ActionsXMLParser::parseComboBoxOptionSelectedAction(ComboBoxOptionSelectedAction* action,XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(COMBO_BOX_OPTION_SELECTED_ACTION_TYPE_VALUE);

    XMLElement* comboBoxSelectedActionElement = outputActionElement->InsertNewChildElement(COMBO_BOX_SELECTED_ACTION_ELEMENT_KEY);
    comboBoxSelectedActionElement->SetText(action->getSelectedOption().toStdString().c_str());
}

void ActionsXMLParser::parseTableChangedAction(TableChangedAction* action, XMLElement* outputActionElement) {
    XMLElement* actionTypeElement = outputActionElement->InsertNewChildElement(ACTION_TYPE_ELEMENT_KEY);
    actionTypeElement->SetText(TABLE_CHANGED_ACTION_TYPE_VALUE);

    XMLElement* tableChangedRowElement = outputActionElement->InsertNewChildElement(TABLE_CHANGED_ROW_ELEMENT_KEY);
    tableChangedRowElement->SetText(action->getRow());

    XMLElement* tableChangedColumnElement = outputActionElement->InsertNewChildElement(TABLE_CHANGED_COLUMN_ELEMENT_KEY);
    tableChangedColumnElement->SetText(action->getColumn());

    XMLElement* tableChangedValueElement = outputActionElement->InsertNewChildElement(TABLE_CHANGED_VALUE_ELEMENT_KEY);
    tableChangedValueElement->SetText(action->getInputValue().toStdString().c_str());
}

list<pair<BaseAction*, int>> ActionsXMLParser::parseFromXML(XMLDocument *xmlDocument) {
    XMLNode* actionsXMLRoot = xmlDocument->FirstChild();

    if(actionsXMLRoot == nullptr) throw XMLParsingException("Root is nullptr", 0);

    XMLElement* actionXMLElement = actionsXMLRoot->FirstChildElement(ACTION_ELEMENT_KEY);

    if(actionXMLElement == nullptr) throw XMLParsingException("Actions are empty", actionsXMLRoot->GetLineNum());

    list<pair<BaseAction*, int>> actionsToTime;

    while(actionXMLElement != nullptr) {
        XMLElement* actionTypeElement = actionXMLElement->FirstChildElement(ACTION_TYPE_ELEMENT_KEY);
        if(actionTypeElement == nullptr) throw XMLParsingException(string(ACTION_TYPE_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());

        string actionTypeStr = actionTypeElement->GetText();

        XMLElement* elapsedTimeElement = actionXMLElement->FirstChildElement(ELAPSED_TIME_ELEMENT_KEY);
        if(elapsedTimeElement == nullptr) throw XMLParsingException(string(ELAPSED_TIME_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());

        int elapsedTime = retrieveIntValue(elapsedTimeElement);

        XMLElement* actedObjectIdElement = actionXMLElement->FirstChildElement(ACTED_OBJECT_ID_ELEMENT_KEY);
        if(actedObjectIdElement == nullptr) throw XMLParsingException(string(ACTED_OBJECT_ID_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());

        QString actedElementId = actedObjectIdElement->GetText();
        if(actedElementId.isEmpty() || actedElementId.isNull()) throw XMLParsingException(string(ACTED_OBJECT_ID_ELEMENT_KEY) + " is null", actedObjectIdElement->GetLineNum());

        BaseAction* action = nullptr;

        if(actionTypeStr == PUSH_BUTTON_CLICK_ACTION_TYPE_VALUE) {
            action = this->retrievePushButtonClickActionFromXMLElement(actionXMLElement, actedElementId);
        } else if(actionTypeStr == RADIO_BUTTON_SELECT_ACTION_TYPE_VALUE) {
            action = this->retrieveRadioButtonSelectActionFromXMLElement(actionXMLElement, actedElementId);
        } else if(actionTypeStr == TEXT_INPUT_CHANGED_ACTION_TYPE_VALUE) {
            action = this->retrieveTextInputChangedActionFromXMLElement(actionXMLElement, actedElementId);
        } else if(actionTypeStr == COMBO_BOX_EXPANDED_ACTION_TYPE_VALUE) {
            action = this->retrieveComboBoxExpandedActionFromXMLElement(actionXMLElement, actedElementId);
        } else if(actionTypeStr == COMBO_BOX_OPTION_SELECTED_ACTION_TYPE_VALUE) {
            action = this->retrieveComboBoxOptionSelectedActionFromXMLElement(actionXMLElement, actedElementId);
        } else if(actionTypeStr == TABLE_CHANGED_ACTION_TYPE_VALUE) {
            action = this->retrieveTableChangedActionFromXMLElement(actionXMLElement, actedElementId);
        } else {
            throw XMLParsingException("Unknown value in ActionType", actionTypeElement->GetLineNum());
        }

        pair<BaseAction*, int> actionToTime;
        actionToTime.first = action;
        actionToTime.second = elapsedTime;
        actionsToTime.push_back(actionToTime);

        actionXMLElement = actionXMLElement->NextSiblingElement(ACTION_ELEMENT_KEY);
    }

    return actionsToTime;
}

PushButtonClickAction* ActionsXMLParser::retrievePushButtonClickActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    return new PushButtonClickAction(actedElementId);
}

RadioButtonSelectAction* ActionsXMLParser::retrieveRadioButtonSelectActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    return new RadioButtonSelectAction(actedElementId);
}

TextInputChanged* ActionsXMLParser::retrieveTextInputChangedActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    XMLElement* inputValueElement = actionXMLElement->FirstChildElement(TEXT_INPUT_CHANGED_VALUE_ELEMENT_KEY);
    if(inputValueElement == nullptr) throw XMLParsingException(string(TEXT_INPUT_CHANGED_VALUE_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());

    QString inputValue = inputValueElement->GetText();
    if(inputValue.isEmpty() || inputValue.isNull()) throw XMLParsingException(string(TEXT_INPUT_CHANGED_VALUE_ELEMENT_KEY) + " is null", inputValueElement->GetLineNum());

    return new TextInputChanged(actedElementId, inputValue);
}

ComboBoxExpandedAction* ActionsXMLParser::retrieveComboBoxExpandedActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    return new ComboBoxExpandedAction(actedElementId);
}

ComboBoxOptionSelectedAction* ActionsXMLParser::retrieveComboBoxOptionSelectedActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    XMLElement* selectedActionElement = actionXMLElement->FirstChildElement(COMBO_BOX_SELECTED_ACTION_ELEMENT_KEY);
    if(selectedActionElement == nullptr) throw XMLParsingException(string(COMBO_BOX_SELECTED_ACTION_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());

    QString selectedAction = selectedActionElement->GetText();
    if(selectedAction.isEmpty() || selectedAction.isNull()) throw XMLParsingException(string(COMBO_BOX_SELECTED_ACTION_ELEMENT_KEY) + " is null", selectedActionElement->GetLineNum());

    return new ComboBoxOptionSelectedAction(actedElementId, selectedAction);
}

TableChangedAction* ActionsXMLParser::retrieveTableChangedActionFromXMLElement(XMLElement* actionXMLElement,  QString actedElementId) {
    XMLElement* rowChangedActionElement = actionXMLElement->FirstChildElement(TABLE_CHANGED_ROW_ELEMENT_KEY);
    if(rowChangedActionElement == nullptr) throw XMLParsingException(string(TABLE_CHANGED_ROW_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());
    int row = retrieveIntValue(rowChangedActionElement);

    XMLElement* columnChangedActionElement = actionXMLElement->FirstChildElement(TABLE_CHANGED_COLUMN_ELEMENT_KEY);
    if(columnChangedActionElement == nullptr) throw XMLParsingException(string(TABLE_CHANGED_COLUMN_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());
    int column = retrieveIntValue(columnChangedActionElement);

    XMLElement* valueChangedActionElement = actionXMLElement->FirstChildElement(TABLE_CHANGED_VALUE_ELEMENT_KEY);
    if(columnChangedActionElement == nullptr) throw XMLParsingException(string(TABLE_CHANGED_VALUE_ELEMENT_KEY) + " is null", actionXMLElement->GetLineNum());
    QString value = valueChangedActionElement->GetText();
    if(value.isEmpty() || value.isNull()) throw XMLParsingException(string(TABLE_CHANGED_VALUE_ELEMENT_KEY) + " is null", valueChangedActionElement->GetLineNum());

    return new TableChangedAction(actedElementId, value, row, column);
}


int ActionsXMLParser::retrieveIntValue(XMLElement* element) {
    qDebug() << "Converting int value...";
    QString valueString = element->GetText();
    bool isConvertSuccess;
    int value = valueString.toInt(&isConvertSuccess);
    if(isConvertSuccess) {
        qDebug() << "Converted value = " + to_string(value);
        return value;
    } else {
        throw XMLParsingException("Can't retrieve int value", element->GetLineNum());
    }
}
