#include "note.h"


QString NOTE_PLANNING = "Planning";
QString NOTE_BREWED = "Brewed";
QString NOTE_FERMENTATION = "Fermentation";
QString NOTE_RACKED = "Racked";
QString NOTE_CONDITIONED = "Conditioned";
QString NOTE_KEGGED = "Kegged";
QString NOTE_BOTTLED = "Bottled";
QString NOTE_TASTING = "Tasting";
QString NOTE_CONTEST = "Contest";
QStringList NOTE_types = QStringList() << NOTE_PLANNING << NOTE_BREWED << NOTE_FERMENTATION <<
                        NOTE_RACKED << NOTE_CONDITIONED << NOTE_KEGGED <<
                        NOTE_BOTTLED << NOTE_TASTING << NOTE_CONTEST;

Note::Note()
{
    date = QDate::currentDate();
    type = NOTE_PLANNING;
    note = "";

}

/**
 * @return Returns the date.
 */
QDate Note::getDate() const {
    return date;
}
/**
 * @param date The date to set.
 */
void Note::setDate(QDate date) {
    this->date = date;
}
/**
 * @return Returns the note.
 */
QString Note::getNote() const {
    return this->note;
}
/**
 * @param note The note to set.
 */
void Note::setNote(QString note) {
    this->note = note;
}
/**
 * @return Returns the type.
 */
QString Note::getType() const {
    return type;
}
/**
 * @param type The type to set.
 */
void Note::setType(QString type) {
    this->type = type;
}

QString Note::toXML(){
        QString sb;
        sb.append( "    <ITEM>\n" );
        sb.append( "      <DATE>"+date.toString("MM/dd/yyyy")+"</DATE>\n" );
        sb.append( "      <TYPE>"+getType()+"</TYPE>\n" );
        sb.append( "      <NOTE>"+getNote()+"</NOTE>\n" );
        sb.append( "    </ITEM>\n" );
        return sb;
}

QString Note::toString(){
    QString sb;
    sb.append( getType()+": " );
    sb.append( getNote() );

    sb.append( " ("+date.toString()+")\n" );
    return sb;
}
