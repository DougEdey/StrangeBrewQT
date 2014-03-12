#include "importxml.h"

ImportXML::ImportXML(QString type)
{
    this->type = type;
    SBcontentHandler = NULL;
}

ImportXML::~ImportXML() {
    delete SBcontentHandler;
}

void ImportXML::setType(QString t) {
    type = t;
}

Recipe *ImportXML::readFile(const QString &filename) {
    if (SBcontentHandler == NULL) {
        SBcontentHandler = new XMLHandler();
    }
    QFile file(filename);
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;

    if (type.compare("sb", Qt::CaseInsensitive) == 0) {
        reader.setContentHandler(this->SBcontentHandler);
    }

    reader.setErrorHandler(this);

    reader.parse(inputSource);

    return this->SBcontentHandler->getRecipe();
}

