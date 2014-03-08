#include "sbstringutils.h"

std::map<QString, QString> string_subEntities = SBStringUtils::initSubEntities();

SBStringUtils::SBStringUtils()
{
}
/**
 * Returns a multi-line tooltip by wrapping
 * the String input in <html> and inserting breaks <br>.
 * @param len	the maximum line-length.  The method will insert
 * a break at the space closest to this number.
 * @param input	the input String.
 * @return the new multi-lined string.
 */
QString SBStringUtils::multiLineToolTip(int len, QString input) {
    QString s = "";
    int length = len;
    if (input.length() == 0)
        return "";
    if (input.length() < length)
        return input;

    int i = 0;
    int lastSpace = 0;

    while (i + length < input.length()) {
        QString temp = input.mid(i, length);
        lastSpace = temp.lastIndexOf(" ");
        s += temp.left(lastSpace) + "<br>";
        i += lastSpace + 1;
    }
    s += input.mid(i);

    s = "<html>" + s + "</html>";

    return s;
}

std::map<QString, QString> SBStringUtils::initSubEntities() {
    std::map<QString, QString> newSub;
    newSub["&"] = "&amp;";
    newSub["<"] = "&lt;";
    newSub[">"] = "&gt;";
    newSub["'"] = "&apos;";
    newSub["\""] = "&quot;";
    return newSub;
}

/**
 * Returns a string with all ocurrences of special characters
 * replaced by their corresponding xml entities.
 * @param input	the string you want to replace all special characters
 * in
 * @return a string with valid xml entites
 */
QString SBStringUtils::subEntities(QString input) {

    QString output = input;

    if (input == "")
        return "";
    for (std::map<QString, QString>::iterator it = string_subEntities.begin();
         it != string_subEntities.end(); it++) {

        output.replace(it->first, it->second);

    }

    return output;
}


QString SBStringUtils::format(double value, int decimal){

    return QString::number(value, 'f', decimal);
}

QString SBStringUtils::xmlElement(QString elem, QString content, int i) {
    QString s = "";
    for (int j = 0; j<i;j++)
        s += " ";
    s += "<" + elem + ">" + content + "</" + elem + ">\n";
    return s;
}

QString SBStringUtils::xmlElement(QString elem, double content, int i) {
    QString d = QString::number(content);
    return xmlElement(elem, d, i);
}


QString SBStringUtils::getAppPath(QString type) {
    QString appRoot = QDir::currentPath();
    QChar slash = QDir::separator();
    QString path = "";

    if (QString::compare(type,"data") == 0)
        path = appRoot + slash + "src" + slash + "ca"
            + slash + "strangebrew" + slash + "data";
    else if (QString::compare(type, "icons") == 0)
        path = appRoot + slash + "src" + slash + "ca"
        + slash + "strangebrew" + slash + "icons";
    else if (QString::compare(type, "recipes") == 0)
        path = appRoot + slash + "recipes";
    else if (QString::compare(type, "help") == 0)
        path = "file://" + appRoot + slash + "help" + slash;
    else if (QString::compare(type, "ini") == 0)
        path = appRoot + slash;
    else
        path = appRoot;

    return path;
}

QString SBStringUtils::capitalize(QString orig) {
    return orig.toUpper();
}

double SBStringUtils::round(double d, int decimalPlace){
    return QString::number(d, 'f', decimalPlace).toDouble();
}
