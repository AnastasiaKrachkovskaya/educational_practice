#ifndef ACTIONSXMLPARSER_H
#define ACTIONSXMLPARSER_H

#include <list>
#include <main/models/Actions.h>
#include <libs/tinyxml2/tinyxml2.h>

using namespace tinyxml2;

class ActionsXMLParser
{
public:
    ActionsXMLParser();

    XMLDocument* parseToXML(list<BaseAction> actions);

    list<BaseAction> parseFromXML(XMLDocument* xmlDocument);
};

#endif // ACTIONSXMLPARSER_H
