#ifndef STYLE_H
#define STYLE_H

#include <QString>
#include "sbstringutils.h"

class Style
{
private:
    QString name;
    QString category;
    QString catNum;
    double ogLow;
    double ogHigh;
    bool ogFlexible;
    double fgLow;
    double fgHigh;
    bool fgFlexible;
    double alcLow;
    double alcHigh;
    bool alcFlexible;
    double ibuLow;
    double ibuHigh;
    bool ibuFlexible;
    double srmLow;
    double srmHigh;
    bool srmFlexible;
    QString examples;
    // QString description;

    QString aroma;
    QString appearance;
    QString flavour;
    QString mouthfeel;
    QString impression;
    QString comments;
    QString ingredients;
    QString year;
    QString type;

public:
    Style();
    bool operator ==(Style other);
    QString getName() const;
    QString getDescription();
    double getAlcHigh() const;
    double getAlcLow() const;
    QString getCategory() const;
    QString getCatNum() const;
    QString getExamples() const;
    double getIbuHigh() const;
    double getIbuLow() const;
    double getSrmHigh() const;
    double getSrmLow() const;
    double getOgHigh() const;
    double getOgLow() const;
    QString getYear() const;
    void setName(QString n);
    void setAlcHigh(double alcHigh);
    void setAlcLow(double alcLow);
    void setCategory(QString category);
    void setCatNum(QString catNum);
    void setExamples(QString commercialEx);
    void setIbuHigh(double ibuHigh);
    void setIbuLow(double ibuLow);
    void setSrmHigh(double lovHigh);
    void setSrmLow(double lovLow);
    void setOgHigh(double ogHigh);
    void setOgLow(double ogLow);
    void setYear(QString year);
    QString toXML();
    QString toText();
    QString toString();
    bool compareTo(Style s);
    void setComplete();
    void setComments(QString comments);
    QString getComments();
    void setImpression(QString impression);
    void setMouthfeel(QString mouthfeel);
    void setFlavour(QString flavour);
    void setAroma(QString aroma);
    void setAppearance(QString appearance);
    void setIngredients(QString ingredients);

    bool operator <(const Style &other) const;
    bool operator >(const Style &other) const;
    bool operator==(const Style &other) const;

    void setFgLow(double fgLow);
    void setFgHigh(double fgHigh);
    double getFgLow() const;
    double getFgHigh() const;
};

#endif // STYLE_H
