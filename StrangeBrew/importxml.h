#ifndef IMPORTXML_H
#define IMPORTXML_H
#include <QtDebug>
#include <QtXml/QXmlDefaultHandler>
#include <QXmlContentHandler>

#include "xmlhandler.h"

class ImportXML : public QXmlDefaultHandler
{
public:
    ImportXML(QString type);
    ~ImportXML();
//    bool readFile(const QString &filename);

    Recipe *readFile(const QString &filename);
    void setType(QString t);
private:
    QString type;
    XMLHandler *SBcontentHandler;// = NULL;// = new XMLHandler();

protected:

//    bool startElement(const QString &namespaceURI,
//                      const QString &localName,
//                      const QString &qName,
//                      const QXmlAttributes &attributes);
//    bool endElement(const QString &namespaceURI,
//                      const QString &localName,
//                      const QString &qName);
//    bool characters(const QString &str);
//    bool fatalError(const QXmlParseException &exception);
};

#endif // IMPORTXML_H
