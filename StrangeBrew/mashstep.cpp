#include "mashstep.h"

MashStep::MashStep(QString type, double startTemp, double eTemp, QString method, int min,
        int rmin) {
    setType(type);
    setStartTemp(startTemp);
    if (endTemp != 0)
        this->endTemp = eTemp;
    else
        endTemp = startTemp;
    setMethod(method);
    minutes = min;
    rampMin = rmin;
    maltUnits = CONVERTER_LB;
}

    // default constructor:
MashStep::MashStep() {
    QSettings opts("Doug Edey", "StrangeBrew");
    rampMin = 0;
    startTemp = -1;
    endTemp = -1;
    temp = -1;
    minutes = 60;
    method = "";
    type = "";
    weightLbs = 0;

}

// getter/setter methods

QString MashStep::getDirections() const {
    return directions;
}

void MashStep::setDirections(QString directions) {
    this->directions = directions;
}

double MashStep::getEndTemp() const {
    return endTemp;
}

void MashStep::setEndTemp(double endTemp) {
    if (endTemp == 0.0) {
        return;
    }
    this->endTemp = endTemp;
}

Quantity *MashStep::getInVol() {
    return &inVol;
}

void MashStep::setInVol(Quantity vol) {
    if (vol.getValue() < 0){
        return;
    }
    this->inVol = vol;
}

Quantity *MashStep::getOutVol() {
    return &outVol;
}

void MashStep::setOutVol(Quantity vol) {
    this->outVol = vol;
}

QString MashStep::getMethod() const {
    return method;
}

void MashStep::setMethod(QString method) {
    this->method = method;
}

int MashStep::getMinutes() const {
    return minutes;
}

void MashStep::setMinutes(int minutes) {
    this->minutes = minutes;
}

int MashStep::getRampMin() const {
    return rampMin;
}

void MashStep::setRampMin(int rampMin) {
    this->rampMin = rampMin;
}

double MashStep::getStartTemp() const {
    return startTemp;
}

void MashStep::setStartTemp(double startTemp) {
    this->startTemp = startTemp;
}

void MashStep::setStrikeTemp(double sTemp) {
    temp = sTemp;
}

double MashStep::getStrikeTemp() const {
    return temp;
}

QString MashStep::getType() {
    return type;
}

void MashStep::setType(QString s) {
    type = s;
}

int MashStep::compareTo(MashStep m) {
        return this->getStartTemp() > m.getStartTemp();
}

int MashStep::lessThan(MashStep a, MashStep b) {
        return a.getStartTemp() < b.getStartTemp();
}

int MashStep::moreThan(MashStep a, MashStep b) {
        return a.getStartTemp() > b.getStartTemp();
}

void MashStep::setWeightLbs(double inWeight) {
    weightLbs = inWeight;
}

void MashStep::setMaltUnits(QString inUnit)
{
    this->maltUnits = inUnit;
}

double MashStep::getWeightLbs() const {
    return weightLbs;
}

double MashStep::getWeight() const {
    return Quantity::convertUnit(CONVERTER_LB, maltUnits, weightLbs);
}

QString MashStep::toString() {
    QString temp = QString("%0 %1 %2 %3 %4 %5 %6 %7\n")
            .arg(getType(), 10)
            .arg(getStartTemp(), 6)
            .arg(getEndTemp(), 6)
            .arg(getRampMin(), 4)
            .arg(getMinutes(), 6)
            .arg(getInVol()->toString(), 6)
            .arg(getOutVol()->toString(), 6)
            .arg(getStrikeTemp(), 6);
    return temp;

}
