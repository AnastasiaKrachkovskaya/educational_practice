#ifndef ACTIONSXMLPARSER_H
#define ACTIONSXMLPARSER_H

#include <list>
#include <main/models/Actions.h>
#include <libs/tinyxml2/tinyxml2.h>

using namespace tinyxml2;
\
#define ACTIONS_NODE_KEY "Actions"
#define ACTION_ELEMENT_KEY "Action"
#define ACTION_TYPE_ELEMENT_KEY "ActionType"
#define ACTED_OBJECT_ID_ELEMENT_KEY "ActedElementId"
#define ELAPSED_TIME_ELEMENT_KEY "ElapsedTime"

#define TEXT_INPUT_CHANGED_VALUE_ELEMENT_KEY "InputValue"
#define COMBO_BOX_SELECTED_ACTION_ELEMENT_KEY "SelectedAction"

#define TABLE_CHANGED_ROW_ELEMENT_KEY "Row"
#define TABLE_CHANGED_COLUMN_ELEMENT_KEY "Column"
#define TABLE_CHANGED_VALUE_ELEMENT_KEY "Value"

#define PUSH_BUTTON_CLICK_ACTION_TYPE_VALUE "PushButtonClick"
#define RADIO_BUTTON_SELECT_ACTION_TYPE_VALUE "RadioButtonSelect"
#define TEXT_INPUT_CHANGED_ACTION_TYPE_VALUE "TextInputChanged"
#define COMBO_BOX_EXPANDED_ACTION_TYPE_VALUE "ComboBoxExpanded"
#define COMBO_BOX_OPTION_SELECTED_ACTION_TYPE_VALUE "ComboBoxOptionSelected"
#define TABLE_CHANGED_ACTION_TYPE_VALUE "TableChanged"

/*!
 * \brief The ActionsXMLParser class
 * Класс, отвечающий за парсинг событий в XMLDocument
 * Так же парсит события из XMLDocument.
 */
class ActionsXMLParser
{
public:
    ActionsXMLParser();

    XMLDocument* parseToXML(list<pair<BaseAction*, int>> actions);

    list<pair<BaseAction*, int>> parseFromXML(XMLDocument* xmlDocument);

private:

    // functions to parse into xml
    void parsePushButtonClickAction(PushButtonClickAction* action, XMLElement* outputActionElement);
    void parseRadioButtonSelectAction(RadioButtonSelectAction* action, XMLElement* outputActionElement);
    void parseTextInputChangedAction(TextInputChanged* action, XMLElement* outputActionElement);
    void parseComboBoxExpandedAction(ComboBoxExpandedAction* action, XMLElement* outputActionElement);
    void parseComboBoxOptionSelectedAction(ComboBoxOptionSelectedAction* action, XMLElement* outputActionElement);
    void parseTableChangedAction(TableChangedAction* action, XMLElement* outputActionElement);


    // functions to parse out from xml
    PushButtonClickAction* retrievePushButtonClickActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);
    RadioButtonSelectAction* retrieveRadioButtonSelectActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);
    TextInputChanged* retrieveTextInputChangedActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);
    ComboBoxExpandedAction* retrieveComboBoxExpandedActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);
    ComboBoxOptionSelectedAction* retrieveComboBoxOptionSelectedActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);
    TableChangedAction* retrieveTableChangedActionFromXMLElement(XMLElement* actionXMLElement, QString actedElementId);

    // return: int or exception
    int retrieveIntValue(XMLElement* element);
};

/*!
 * \brief The XMLParsingException class
 *  Exception класс ошибки парсинга XML.
 */
class XMLParsingException {
public:
    XMLParsingException(string description, int lineNumber) {
        this->description = description;
        this->lineNumber = lineNumber;
    }
    string getDescription() { return this->description; }
    int getLineNumber() { return this->getLineNumber(); }
private:
    string description;
    int lineNumber;
};

#endif // ACTIONSXMLPARSER_H
