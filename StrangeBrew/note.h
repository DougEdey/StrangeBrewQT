#ifndef NOTE_H
#define NOTE_H

#include <QStringList>
#include <QString>
#include <QDate>

class Note
{

private:
    QDate date;
    QString type;
    QString note;

public:
    Note();
    QDate getDate() const;
    void setDate(QDate date);
    QString getNote() const;
    void setNote(QString note);
    QString getType() const;
    void setType(QString type);
    QString toXML();
    QString toString();
};
extern QString PLANNING;
extern QString BREWED;
extern QString FERMENTATION;
extern QString RACKED;
extern QString CONDITIONED;
extern QString KEGGED;
extern QString BOTTLED;
extern QString TASTING;
extern QString CONTEST;
extern QStringList NOTE_types;


#endif // NOTE_H
