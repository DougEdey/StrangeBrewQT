#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include <QXmlDefaultHandler>
#include "recipe.h"

class XMLHandler : public QXmlDefaultHandler
{
private:
    Recipe *r;
    Fermentable m;
    Hop h;
    Misc misc;
    Note note;
    QXmlAttributes currentAttributes;
    FermentStep ferm;
    Salt salt;
    Acid acid;
    WaterProfile water;

    QString currentList; //current List name
    QString currentSubList;
    QString currentElement; // current element name
    QString importType; // the type of recipe we're importing
    QString descrBuf; // buffer to hold long descriptions
    QString buffer; // buffer

    // mash step stuff:
    QString type;
    QString method;
    double startTemp;
    double endTemp;
    int minutes;
    int rampMin;
    double weightLbs;

    // New Ingredients
    QList<Ingredient*> newIngr;
    std::vector<bool> boolList;

public:

    XMLHandler();
    Recipe *getRecipe() {return r;}
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    void qbStartElement(QString eName);
    void sbStartElement(QString eName);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &ch);
    void qbCharacters(QString s);
    void sbCharacters(QString s);
    bool warning(const QXmlParseException &exception);
    bool fatalError(const QXmlParseException &exception);
    bool processingInstruction(const QString &target, const QString &data);
    bool error(const QXmlParseException &exception);
    bool startDocument();
    bool endDocument();
};

#endif // XMLHANDLER_H
