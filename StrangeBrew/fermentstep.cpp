#include "fermentstep.h"

QString PRIMARY = "Primary";
QString SECONDARY = "Secondary";
QString CLEARING = "Clearing";
QString AGEING = "Ageing";
QStringList ferment_types = QStringList() << PRIMARY << SECONDARY << CLEARING << AGEING;

FermentStep::FermentStep()
{
    type = QSettings().value("Ferment/Type").toString();
    tempU = QSettings().value("Ferment/TempU").toString();
    time = QSettings().value("Ferment/Time").toInt();
    temp = QSettings().value("Ferment/Temp").toDouble();
}

int FermentStep::getTypeIndex(QString s) {
    for (int i = 0; i < ferment_types.size(); i++) {
        qDebug() << "Comparing: " << ferment_types[i] << " to " << s;
        if (ferment_types[i] == s) {
            return i;
        }
    }
    return 0;
}


QString FermentStep::toXML() {
    QString out = "      <ITEM>\n";
    out.append(SBStringUtils::xmlElement("TYPE", type, 9));
    out.append(SBStringUtils::xmlElement("TIME", QString::number(time), 9));
    out.append(SBStringUtils::xmlElement("TEMP", QString::number(temp), 9));
    out.append(SBStringUtils::xmlElement("TEMPU", tempU, 9));
    out.append("      </ITEM>\n");
    return out;
}


// Getters and Setters
double FermentStep::getTemp() const {
    return temp;
}
QString FermentStep::getTempU() const {
    return tempU;
}
int FermentStep::getTime() const {
    return time;
}
QString FermentStep::getType() const {
    return type;
}
void FermentStep::setTemp(double temp) {
    this->temp = temp;
}
void FermentStep::setTempU(QString tempU) {
    this->tempU = tempU;
}
void FermentStep::setTime(int time) {
    this->time = time;
}
void FermentStep::setType(QString type) {
    this->type = type;
}


