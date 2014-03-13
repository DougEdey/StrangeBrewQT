#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QDate>
#include <QLocale>
#include <QDebug>
#include <QObject>

#include "quantity.h"

class Ingredient: public QObject
{
    Q_OBJECT

private:

    Quantity amount;
    double costPerU;
    QDate dateBought;
    QString description;
    QString name;
    Quantity stock;
    QString type;
    bool modified;
    QString form;

public:
    explicit Ingredient(QObject *parent = 0);
    Ingredient(QString name, QObject *parent = 0);
    Ingredient(const Ingredient& other);
    virtual ~Ingredient() {
    }

    QString getForm() const { return form;}
    void setForm (QString f) { form = f;}

    double getAmountAs(QString s) const ;
    double getAmount() const ;
    double getStockAs(QString s) const ;
    double getStock() const;
    double getCostPerU() const;

    QDate getDate() const ;

    bool getModified() const ;
    QString getName() const;
    QString getType() const ;
    QString getUnits() const ;
    QString getUnitsAbrv() const ;
    QString getDescription() const ;
    virtual QString toString() const {
        QString res(this->getName());
        res.append(this->description);
        return res;
    }

    double getCostPerUAs(QString to) const ;

    void setAmount(double a);
    void setStock(double a);
    void setAmountAndUnits(QString a);
    void setAmountAs(double a, QString u);
    void setCost(double c);
    void setCost(QString c);
    void setDate(QString d);
    void setDescription(QString d);
    void setModified(bool b);
    void setName(QString n);
    void setType(QString t);
    void setUnits(QString a);
    void convertTo(QString newUnits);

    virtual bool operator >(const Ingredient &other) const
    {
        return name > other.name;
    }

    virtual bool operator <(const Ingredient &other) const
    {
        return name < other.name;
    }
    virtual bool operator ==(const Ingredient &other) const
    {
        return name == other.name;
    }

    virtual bool operator !=(const Ingredient &other) const
    {
        return name != other.name;
    }

    virtual bool operator ==(QString name) const
    {
        return (name.compare(this->name, Qt::CaseInsensitive) == 0);
    }

    static bool lessThan(Ingredient *a, Ingredient *b);
    static bool moreThan(Ingredient *a, Ingredient *b);
    static bool sortWeight(Ingredient *a, Ingredient *b);
    QString getStockUnits();
    void setStockUnits(QString u);
};

Q_DECLARE_METATYPE(Ingredient)
#endif // INGREDIENT_H
