#include "xmlhandler.h"
#include "newingrdialog.h"

XMLHandler::XMLHandler() :QXmlDefaultHandler()
{
    r = new Recipe();
    currentAttributes = NULL;
    currentList = ""; //current List name
    currentSubList = "";
    currentElement = ""; // current element name
    importType = ""; // the type of recipe we're importing
    descrBuf = ""; // buffer to hold long descriptions
    buffer = ""; // buffer

    // mash step stuff:
    type = "";
    method = "";
    startTemp = 0.0;
    endTemp = 0.0;
    minutes = 0;
    rampMin = 0;
    weightLbs = 0.0;
}


//===========================================================
// SAX DocumentHandler methods
//===========================================================

bool XMLHandler::startDocument() {
    r->setAllowRecalcs(false);
    return true;
}

bool XMLHandler::endDocument() {
    r->setAllowRecalcs(true);
    // Check for new ingredients
    if (newIngr.size() > 0) {

        boolList.resize(newIngr.size(), true);
        Q_FOREACH(Ingredient* q, newIngr) {
            qDebug() << q->getName();
        }

        NewIngrDialog *newIngrDialog = new NewIngrDialog(&newIngr, &boolList, QApplication::activeWindow());
        newIngrDialog->show();
        newIngrDialog->raise();
        newIngrDialog->activateWindow();
        newIngrDialog->deleteLater();

    }
    return true;
}

/**
 * This method is called every time we encounter a new element
 * To handle other xml import types, we check for
 * a "signpost" element that indicates the file type, then
 * call out to the appropriate element handler for that file type.
 *
 */
bool XMLHandler::startElement(const QString &namespaceURI, const QString &localName,
                              const QString &qName, const QXmlAttributes &atts) {
    Q_UNUSED(namespaceURI);
    Q_UNUSED(localName);

    QString eName = localName; // element unit

    if (QString::compare(eName, "") == 0)
        eName = qName; // namespaceAware = false

    qDebug() << "processing " << eName << " List: " << currentList;
    currentElement = eName;

    if (currentAttributes != NULL) {
        qDebug() << "Current: " << currentAttributes->length();
    }

    qDebug() << "New: " << atts.length();

    if (atts.length() > 0)
        this->currentAttributes = &atts;


    if (QString::compare(eName, "STRANGEBREWRECIPE", Qt::CaseInsensitive) == 0) {
        importType = "STRANGEBREW";
        r->setAllowRecalcs(false);
        qDebug() << "StrangeBrew recipe detected.";
    } else if (QString::compare(eName, "RECIPE", Qt::CaseInsensitive) == 0) {
          for (int i = 0; i < atts.length(); i++) {
            QString s = atts.localName(i); // Attr name
            if (QString::compare("",s))
                s = atts.qName(i);
            if ((QString::compare(s, "generator") == 0 || QString::compare(s, "application") == 0)
                    && QString::compare(atts.value(i), "qbrew")){
                importType = "QBREW";

                r->setAllowRecalcs(false);
                qDebug() << "QBrew recipe detected.";
            }
        }


    } else if (importType.compare("STRANGEBREW") == 0) {
        // call SB start element
        sbStartElement(eName);
    } else if (importType.compare("QBREW") == 0) {
        // call SB start element
        qbStartElement(eName);
    }
    return true;
}

void XMLHandler::qbStartElement(QString eName){
    if (QString::compare(eName, "HOPS") == 0) {
        currentList = "HOPS";
    }
    else if (QString::compare(eName, "GRAINS") == 0) {
        currentList = "GRAINS";
    }
    else if (QString::compare(eName, "HOP") == 0) {
        // new hop
        for (int i = 0; i < currentAttributes->length(); i++) {
            QString str = currentAttributes->localName(i); // Attr name
            if (QString::compare(str, "") == 0)
                str = currentAttributes->qName(i);
            if (QString::compare(str, "quantity") == 0)
                h->setAmountAndUnits(currentAttributes->value(i));
            else if (QString::compare(str, "time", Qt::CaseInsensitive) == 0)
                h->setMinutes(currentAttributes->value(i).toInt());
            else if (QString::compare(str, "alpha", Qt::CaseInsensitive) == 0)
                h->setAlpha(currentAttributes->value(i).toDouble());
        }
    }
    else if (QString::compare(eName, "GRAIN", Qt::CaseInsensitive) == 0) {
        // new "malt"
        m = new Fermentable();
        for (int i = 0; i < currentAttributes->length(); i++) {
            QString str = currentAttributes->localName(i); // Attr name
            if (QString::compare("", str, Qt::CaseInsensitive) == 0)
                str = currentAttributes->qName(i);
            if (QString::compare(str, "quantity", Qt::CaseInsensitive) == 0)
                m->setAmountAndUnits(currentAttributes->value(i));
            else if (QString::compare(str, "color", Qt::CaseInsensitive) == 0)
                m->setLov(currentAttributes->value(i).toDouble());
            else if (QString::compare(str, "extract", Qt::CaseInsensitive) == 0)
                m->setPppg(currentAttributes->value(i).toDouble());
            else if (QString::compare(str, "ferments", Qt::CaseInsensitive) == 0)
                m->ferments(currentAttributes->value(i));
        }
    }
    // we have to do this here, because <batch> is an empty element
    else if (QString::compare(eName, "batch", Qt::CaseInsensitive)){
        for (int i = 0; i < currentAttributes->length(); i++) {
            QString str = currentAttributes->localName(i); // Attr name
            if (QString::compare("", str, Qt::CaseInsensitive) == 0)
                str = currentAttributes->qName(i);
            if (QString::compare(str, "quantity", Qt::CaseInsensitive) == 0)
                r->setAmountAndUnits(currentAttributes->value(i));
        }
    }
    // handle new misc ingredient
    else if (QString::compare(eName, "misc", Qt::CaseInsensitive) == 0) {

        for (int i = 0; i < currentAttributes->length(); i++) {
            QString str = currentAttributes->localName(i); // Attr name
            if (QString::compare("", str, Qt::CaseInsensitive) == 0)
                str = currentAttributes->qName(i);
            if (QString::compare(str, "name", Qt::CaseInsensitive) == 0)
                misc->setName(currentAttributes->value(i));

            if (QString::compare(str, "quantity", Qt::CaseInsensitive) == 0)
                misc->setAmount(currentAttributes->value(i).toDouble());
            if (QString::compare(str, "units", Qt::CaseInsensitive) == 0)
                misc->setUnits(currentAttributes->value(i));
            if (QString::compare(str, "stage", Qt::CaseInsensitive) == 0)
                misc->setStage(currentAttributes->value(i));
            if (QString::compare(str, "time", Qt::CaseInsensitive) == 0)
                misc->setTime(currentAttributes->value(i).toInt());
            if (QString::compare(str, "comments", Qt::CaseInsensitive) == 0)
                misc->setComments(currentAttributes->value(i));
        }
    }
}

/**
 * Start of an element handler when we know this is a StrangeBrew recipe
 *
 * @param eName
 */
void XMLHandler::sbStartElement(QString eName) {
    if (QString::compare(eName, "DETAILS", Qt::CaseInsensitive) == 0) {
        currentList = "DETAILS";
    } else if (QString::compare(eName, "CARB", Qt::CaseInsensitive) == 0) {
        currentList = "CARB";
    } else if (QString::compare(eName, "FERMENTABLES", Qt::CaseInsensitive) == 0){
        currentList = "FERMENTABLES";
    } else if (QString::compare(eName, "HOPS", Qt::CaseInsensitive) == 0) {
        currentList = "HOPS";
    } else if ((QString::compare(eName, "MASH", Qt::CaseInsensitive) == 0) && (QString::compare(currentList, "", Qt::CaseInsensitive) == 0)) {
        currentList = "MASH";
    } else if (QString::compare(eName, "MISC", Qt::CaseInsensitive) == 0) {
        currentList = "MISC";
    } else if (eName.compare("FERMENTATION_SCHEDULE", Qt::CaseInsensitive) == 0
               || (eName.compare("FERMENTATION_SCHEDUAL", Qt::CaseInsensitive) == 0)) {
        currentList = "FERMENTATION_SCHEDULE";
    } else if (QString::compare(eName, "WATER_PROFILE", Qt::CaseInsensitive) == 0) {
        currentList = "WATER_PROFILE";
    } else if ((QString::compare(eName, "NOTES", Qt::CaseInsensitive) == 0) && (QString::compare(currentList, "DETAILS", Qt::CaseInsensitive) != 0)) {
        // two freaking elments named NOTES - make sure we're not looking at the
        // recipe notes in <DETAILS>
        currentList = "NOTES";
    } else if (QString::compare(currentList, "WATER_PROFILE", Qt::CaseInsensitive) == 0) {
        if (QString::compare(eName, "SOURCE_WATER", Qt::CaseInsensitive) == 0) {
            currentSubList = "SOURCE_WATER";
            new (&water) WaterProfile();
        } else if (QString::compare(eName, "TARGET_WATER", Qt::CaseInsensitive) == 0) {
            currentSubList = "TARGET_WATER";
            new (&water) WaterProfile();
        } else if (QString::compare(eName, "SALTS", Qt::CaseInsensitive) == 0) {
            currentSubList = "SALTS";
        } else if (QString::compare(eName, "ACID", Qt::CaseInsensitive) == 0) {
            currentSubList = "ACID";
            new (&acid) Acid();
        } else if ((QString::compare(currentSubList, "SALTS", Qt::CaseInsensitive) == 0)
            && QString::compare(eName, "SALT", Qt::CaseInsensitive) == 0) {
            new (&salt) Salt();
        }
    } else if (QString::compare(eName, "ITEM", Qt::CaseInsensitive) == 0) { // this is an item in a
        // list
        if (QString::compare(currentList, "FERMENTABLES", Qt::CaseInsensitive) == 0) {
            m = new Fermentable();
        } else if (QString::compare(currentList, "HOPS", Qt::CaseInsensitive) == 0) {
            h = new Hop();
        } else if (QString::compare(currentList, "MISC", Qt::CaseInsensitive) == 0) {
            misc = new Misc();
        } else if (QString::compare(currentList, "FERMENTATION_SCHEDULE", Qt::CaseInsensitive) == 0
                   || (currentList.compare("FERMENTATION_SCHEDUAL", Qt::CaseInsensitive) == 0)) {
            new (&ferm) FermentStep();
        } else if (QString::compare(currentList, "NOTES", Qt::CaseInsensitive) == 0) {
            new (&note) Note();
        }
    }
}

/**
 * At the end of each element, we should check if we're looking at a list.
 * If we are, set the list to null. This way, we can tell if we're looking
 * at an element that has (stupidly) the same unit as a list... eg <MASH>is
 * in the recipe (indicating whether it's mashed or not), and the unit of
 * the mash list!
 */
bool XMLHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    Q_UNUSED(namespaceURI);
    Q_UNUSED(localName);

    qDebug() << "End Element " << currentList << ": " << qName;
    if (importType == "STRANGEBREW") {
        if ((QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0)
                && (QString::compare(currentList, "FERMENTABLES", Qt::CaseInsensitive) == 0)) {
            if (descrBuf.trimmed().compare("") != 0) {
                m->setDescription(descrBuf);
            }
            descrBuf = "";
            Fermentable *newFerm = r->addMalt(m);
            // Check to see if it needs to be added
            Fermentable *findIt = Database::findFermentable(m->getName());
            if (findIt != NULL) {
                qDebug() << "New fermentable " << m->getName() << " found";
                newIngr.append(newFerm);
            }
        } else if (QString::compare(qName, "MALT", Qt::CaseInsensitive) == 0) {
            qDebug() << "Done loading malts";
        } else if (QString::compare(qName, "HOP", Qt::CaseInsensitive) == 0) {
            qDebug() << "Done loading hops";
        } else if ((QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0)
                && (QString::compare(currentList, "HOPS", Qt::CaseInsensitive) == 0)) {
            Hop *newHop = r->addHop(h);
            Hop *findIt = Database::findHop(h->getName());
            if (findIt != NULL && findIt == *Database::hopsDB.end()) {
                newIngr.append(newHop);
            }
            qDebug() << r->getHopsListSize() << "Adding Hop" << h->getName();

        } else if (QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0
                && QString::compare(currentList, "MISC", Qt::CaseInsensitive) == 0) {

            Misc *newMisc = r->addMisc(misc);
            Misc *findIt = Database::findMisc(misc->getName());
            if (findIt != NULL && findIt == *Database::miscDB.end()) {
                newIngr.push_back(newMisc);
            }

        } else if (QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0
                && QString::compare(currentList, "NOTES", Qt::CaseInsensitive) == 0) {
            r->addNote(note);
        } else if (QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0
                && QString::compare(currentList, "MASH", Qt::CaseInsensitive) == 0) {
                r->getMash()->addStep(type, startTemp, endTemp, method, minutes, rampMin, weightLbs);
        } else if (QString::compare(qName, "ITEM", Qt::CaseInsensitive) == 0
                && QString::compare(currentList, "FERMENTATION_SCHEDULE", Qt::CaseInsensitive) == 0) {
            r->addFermentStep(ferm);
            (&ferm)->~FermentStep();
        } else if (QString::compare(qName, "SALT", Qt::CaseInsensitive) == 0) {
            // look up the effects of this salt from the DB
            try {
                Salt dbSalt = Salt::getSaltByName(salt.getName());

                salt.setChemicalEffects(dbSalt.getChemicalEffects());
                salt.setGramsPerTsp(dbSalt.getGramsPerTsp());
            } catch (QString e) {
                qDebug() << e;
                // TODO: Create a Salt DB
            }

            r->addSalt(salt);
            (&salt)->~Salt();
        } else if (QString::compare(qName, "SOURCE_WATER", Qt::CaseInsensitive) == 0) {
            currentSubList = "";
            r->setSourceWater(water);
            (&water)->~WaterProfile();
        } else if (QString::compare(qName, "TARGET_WATER", Qt::CaseInsensitive) == 0) {
            currentSubList = "";
            r->setTargetWater(water);
            (&water)->~WaterProfile();
        } else if (QString::compare(qName, "SALTS", Qt::CaseInsensitive) == 0) {
            currentSubList = "";
        } else if (QString::compare(qName, "ACID", Qt::CaseInsensitive) == 0) {
            currentSubList = "";
            qDebug() << "Should be adding an acid";
            (&acid)->~Acid();
        } // there's a problem with having two elements named "NOTES" :
          else if (QString::compare(qName, "FERMENTABLES", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "HOPS", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "DETAILS", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "CARB", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "MISC", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "FERMENTATION_SCHEDULE", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "FERMENTATION_SCHEDUAL", Qt::CaseInsensitive) == 0
                || QString::compare(qName, "WATER_PROFILE", Qt::CaseInsensitive) == 0
                || ((QString::compare(qName, "NOTES", Qt::CaseInsensitive) == 0) && (QString::compare(currentList, "DETAILS", Qt::CaseInsensitive) != 0))
                ) {
            currentList = "";
        }

          else if (QString::compare(qName, "NAME", Qt::CaseInsensitive) == 0
                    && QString::compare(qName, "DETAILS", Qt::CaseInsensitive) == 0) {
                r->setName(buffer);
                buffer="";

        }
    }
    else if (QString::compare(importType, "QBREW", Qt::CaseInsensitive) == 0) {
        if (QString::compare(qName, "GRAIN", Qt::CaseInsensitive) == 0){
            r->addMalt(m);
        }
        else if (QString::compare(qName, "HOP", Qt::CaseInsensitive) == 0){
            r->addHop(h);
        }
        else if (QString::compare(qName, "TITLE", Qt::CaseInsensitive) == 0){
            r->setName(buffer);
            buffer = "";
        }
    }
    return true;
}

/**
 * This is the "meat" of the handler->  We figure out where in the
 * document we are, based on the current list, and then start puting
 * the data into the recipe fields.
 */
bool XMLHandler::characters(const QString &ch) {

    QString s = ch;
    if (s.trimmed().compare("") !=0 &&
            importType.compare("STRANGEBREW", Qt::CaseInsensitive) == 0) {
        // SBWin uses gr instead of g, fix it:
        if (s.trimmed().compare("gr", Qt::CaseInsensitive) == 0)
            s = "g";
        sbCharacters(s.trimmed());
    }
    else if (s.trimmed().compare("") != 0 &&
             importType.compare("QBREW", Qt::CaseInsensitive) == 0) {
        qbCharacters(s.trimmed());
    }

    return true;
}

void XMLHandler::qbCharacters(QString s){
    if (currentElement.compare("GRAIN", Qt::CaseInsensitive) == 0){
        m->setName(s);
    }
    else if (currentElement.compare("HOP", Qt::CaseInsensitive) == 0){
        h->setName(s);
    }
    else if (currentElement.compare("miscingredient", Qt::CaseInsensitive) == 0){
        r->setYeastName(s);
        // TODO: there is more data in the yeast record, and there may be other misc ingredients
        // figure out how to get the yeast, and parse the other data.
    }
    else if (currentElement.compare("title", Qt::CaseInsensitive) == 0){
        buffer = buffer + s;
        // r->setName(s);
    }
    else if (currentElement.compare("brewer", Qt::CaseInsensitive) == 0){
        r->setBrewer(s);
    }
    else if (currentElement.compare("style", Qt::CaseInsensitive) == 0){
        r->setStyle(s);
    }
}

void XMLHandler::sbCharacters(QString s){
    if (currentList.compare("FERMENTABLES", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("MALT", Qt::CaseInsensitive) == 0) {
            m->setName(s);
            Fermentable *found = Database::findFermentable(s);

            if (found != NULL) {
                if (m->getCostPerU() != 0) {
                    m->setCost((*found).getCostPerU());
                }

                if(m->getDescription().compare("") == 0) {
                    m->setDescription((*found).getDescription());
                }
            } else {
                qDebug() << "Fermentable " << s << " Not found";
            }
        } else if (currentElement.compare("AMOUNT", Qt::CaseInsensitive) == 0) {
            m->setAmount(s.toDouble());
        } else if (currentElement.compare("POINTS", Qt::CaseInsensitive) == 0) {
            m->setPppg(s.toDouble());
        } else if (currentElement.compare("COSTLB", Qt::CaseInsensitive) == 0) {
            m->setCost( s );
        } else if (currentElement.compare("UNITS", Qt::CaseInsensitive) == 0) {
            m->setUnits(s);
        } else if (currentElement.compare("LOV", Qt::CaseInsensitive) == 0) {
            m->setLov(s.toDouble());
        } else if (currentElement.compare("MASHED", Qt::CaseInsensitive) == 0) {
            m->setMashed(s);
        } else if (currentElement.compare("STEEPED", Qt::CaseInsensitive) == 0) {
            m->setSteep(s);
        } else if (currentElement.compare("DescrLookup", Qt::CaseInsensitive) == 0 ||
                currentElement.compare("description", Qt::CaseInsensitive) == 0) {
            descrBuf = descrBuf + s;
        }
    }
    else if (currentList.compare("HOPS", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("HOP", Qt::CaseInsensitive) == 0) {
            h->setName(s);
            Hop *findHop = Database::findHop(s);
            if (findHop != NULL) {
                if (h->getCostPerU() == 0) {
                    h->setCost((*findHop).getCostPerU());
                }
                if(h->getDescription().compare("") == 0) {
                    h->setDescription((*findHop).getDescription());
                }
            }
        } else if (currentElement.compare("AMOUNT", Qt::CaseInsensitive) == 0) {
            h->setAmount(s.toDouble());
        } else if (currentElement.compare("ALPHA", Qt::CaseInsensitive) == 0) {
            h->setAlpha(s.toDouble());
        } else if (currentElement.compare("UNITS", Qt::CaseInsensitive) == 0) {
            h->setUnits(s);
        } else if (currentElement.compare("FORM", Qt::CaseInsensitive) == 0) {
            h->setType(s);
        } else if (currentElement.compare("COSTOZ", Qt::CaseInsensitive) == 0) {
            h->setCost( s );
        } else if (currentElement.compare("ADD", Qt::CaseInsensitive) == 0) {
            h->setAdd(s);
        } else if (currentElement.compare("DescrLookup", Qt::CaseInsensitive) == 0||
                currentElement.compare("description", Qt::CaseInsensitive) == 0) {
            h->setDescription(s);
        } else if (currentElement.compare("TIME", Qt::CaseInsensitive) == 0) {
            h->setMinutes(s.toInt());
        }
    }

    else if (currentList.compare("MISC", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("NAME", Qt::CaseInsensitive) == 0) {

            misc->setName(s);
        } else if (currentElement.compare("AMOUNT", Qt::CaseInsensitive) == 0) {
            misc->setAmount(s.toDouble());
        } else if (currentElement.compare("UNITS", Qt::CaseInsensitive) == 0) {
            misc->setUnits(s);
        } else if (currentElement.compare("COMMENTS", Qt::CaseInsensitive) == 0) {
            qDebug() << "Setting comments to " << s;
            misc->setComments(s);
        } else if (currentElement.compare("COST_PER_U", Qt::CaseInsensitive) == 0) {
            // misc->setCost( Double.parseDouble(s) );
        } else if (currentElement.compare("ADD", Qt::CaseInsensitive) == 0) {
            misc->setTime(s.toInt());
        } else if (currentElement.compare("DescrLookup", Qt::CaseInsensitive) == 0||
                currentElement.compare("description", Qt::CaseInsensitive) == 0) {
            misc->setComments(s);
        } else if (currentElement.compare("TIME", Qt::CaseInsensitive) == 0) {
            misc->setTime(s.toInt());
        } else if (currentElement.compare("STAGE", Qt::CaseInsensitive) == 0) {
            misc->setStage(s);
        }
    }
    else if (currentList.compare("NOTES", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("DATE", Qt::CaseInsensitive) == 0) {
             note.setDate(QDate::fromString(s, "MM/dd/yyyy"));
        } else if (currentElement.compare("TYPE", Qt::CaseInsensitive) == 0) {
            note.setType(s);
        } else if (currentElement.compare("NOTE", Qt::CaseInsensitive) == 0) {
            note.setNote(s);
        }
    }
    else if (currentList.compare("MASH", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("TYPE", Qt::CaseInsensitive) == 0) {
            type = s;
        } else if (currentElement.compare("TEMP", Qt::CaseInsensitive) == 0) {
            startTemp = s.toDouble();
        } else if (currentElement.compare("METHOD", Qt::CaseInsensitive) == 0) {
            method = s;
        } else if (currentElement.compare("MIN", Qt::CaseInsensitive) == 0) {
            minutes = s.toInt();
        } else if (currentElement.compare("END_TEMP", Qt::CaseInsensitive) == 0) {
            endTemp = s.toDouble();
        } else if (currentElement.compare("RAMP_MIN", Qt::CaseInsensitive) == 0) {
            rampMin = s.toInt();
        } else if (currentElement.compare("WEIGHT_LBS", Qt::CaseInsensitive) == 0) {
            weightLbs = s.toDouble();
            // these are not part of item, but general mash settings:
        } else if (currentElement.compare("THICK_DECOCT_RATIO", Qt::CaseInsensitive) == 0) {
            r->getMash()->setDecoctRatio("thick",s.toDouble());
        } else if (currentElement.compare("THIN_DECOCT_RATIO", Qt::CaseInsensitive) == 0) {
            r->getMash()->setDecoctRatio("thin", s.toDouble());
        } else if (currentElement.compare("GRAIN_TEMP", Qt::CaseInsensitive) == 0) {
            r->getMash()->setGrainTemp(s.toDouble());
        } else if (currentElement.compare("MASH_TUNLOSS_TEMP", Qt::CaseInsensitive) == 0) {
            r->getMash()->setTunLoss(s.toDouble());
        } else if (currentElement.compare("BOIL_TEMP", Qt::CaseInsensitive) == 0) {
            r->getMash()->setBoilTemp(s.toDouble());
        } else if (currentElement.compare("MASH_RATIO", Qt::CaseInsensitive) == 0) {
            r->setMashRatio(s.toDouble());
        } else if (currentElement.compare("MASH_RATIO_U", Qt::CaseInsensitive) == 0) {
            r->setMashRatioU(s);
        }

    } else if (currentList.compare("CARB", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("BOTTLETEMP", Qt::CaseInsensitive) == 0) {
            r->setBottleTemp(s.toDouble());
        } else if (currentElement.compare("SERVTEMP", Qt::CaseInsensitive) == 0) {
            r->setServTemp(s.toDouble());
        } else if (currentElement.compare("VOL", Qt::CaseInsensitive) == 0) {
            r->setTargetVol(s.toDouble());
        } else if (currentElement.compare("SUGAR", Qt::CaseInsensitive) == 0) {
            r->setPrimeSugarName(s);
        } else if (currentElement.compare("SUGARU", Qt::CaseInsensitive) == 0) {
            r->setPrimeSugarU(s);
        } else if (currentElement.compare("TEMPU", Qt::CaseInsensitive) == 0) {
            r->setCarbTempU(s);
        } else if (currentElement.compare("KEG", Qt::CaseInsensitive) == 0) {
            r->setKegged(s);
        }
    } else if (currentList.compare("DETAILS", Qt::CaseInsensitive) == 0) {
        if (currentElement.compare("NAME", Qt::CaseInsensitive) == 0) {
            r->setName(s);
            buffer = buffer + s;
        } else if (currentElement.compare("EFFICIENCY", Qt::CaseInsensitive) == 0) {
            r->setEfficiency(s.toDouble());
        } else if (currentElement.compare("ATTENUATION", Qt::CaseInsensitive) == 0) {
            r->setAttenuation(s.toDouble());
        } else if (currentElement.compare("PRESIZE", Qt::CaseInsensitive) == 0) {
            r->setPreBoil(Quantity(r->getVolUnits(), s.toDouble()));
        } else if (currentElement.compare("SIZE", Qt::CaseInsensitive) == 0) {
            r->setPostBoil(Quantity(r->getVolUnits(), s.toDouble()));
        } else if (currentElement.compare("SIZE_UNITS", Qt::CaseInsensitive) == 0) {
            // also sets postboil:
            r->setReadVolUnits(s);
//			} else if (currentElement.compare("ADDED_VOLUME", Qt::CaseInsensitive) == 0) {
//				double d = Double.parseDouble(s);
//				if ( d != 0 ) {
//					DilutedRecipe dr = new DilutedRecipe(r, new Quantity(r->getVolUnits(), d));
//					r = dr;
//				}
        } else if (currentElement.compare("STYLE", Qt::CaseInsensitive) == 0) {
            Style *n = Database::findStyle(s);
            if (n != NULL) {
                r->setStyle(n);
            } else {
                r->setStyle(s);
            }
        } else if (currentElement.compare("BOIL_TIME", Qt::CaseInsensitive) == 0) {
            r->setBoilMinutes(s.toInt());
        } else if (currentElement.compare("HOPS_UNITS", Qt::CaseInsensitive) == 0) {
            r->setHopsUnits(s);
        } else if (currentElement.compare("MALT_UNITS", Qt::CaseInsensitive) == 0) {
            r->setMaltUnits(s);
        }
        // leave this clause here to support older versions.  SB2.x puts this
        // data in the mash section
        else if (currentElement.compare("MASH_RATIO", Qt::CaseInsensitive) == 0) {
            r->setMashRatio(s.toDouble());
        } else if (currentElement.compare("MASH_RATIO_U", Qt::CaseInsensitive) == 0) {
            r->setMashRatioU(s);
        } else if (currentElement.compare("BREWER", Qt::CaseInsensitive) == 0) {
            r->setBrewer(s);
        } else if (currentElement.compare("MASH", Qt::CaseInsensitive) == 0) {
            r->setMashed(s);
        } else if (currentElement.compare("YEAST", Qt::CaseInsensitive) == 0) {
            r->setYeastName(s);
        } else if (currentElement.compare("RECIPE_DATE", Qt::CaseInsensitive) == 0) {
            r->setCreated(QDate::fromString(s, "MM/dd/yyyy"));

        // These are SBJ1.0 Extensions:
        } else if (currentElement.compare("ALC_METHOD", Qt::CaseInsensitive) == 0) {
            r->setAlcMethod(s);
        } else if (currentElement.compare("IBU_METHOD", Qt::CaseInsensitive) == 0) {
            r->setIBUMethod(s);
        } else if (currentElement.compare("COLOUR_METHOD", Qt::CaseInsensitive) == 0) {
            r->setColourMethod(s);
        } else if (currentElement.compare("EVAP", Qt::CaseInsensitive) == 0) {
            if(currentAttributes->length() > 0) {
                int i = 0;
                while(i < currentAttributes->length()) {
                    QString attrName = currentAttributes->qName(i);
                    qDebug() << "Attr name: " << attrName;
                    QString attrValue = currentAttributes->value(i);
                    if(attrName.compare("type", Qt::CaseInsensitive) == 0) {
                        if(attrValue.compare("6", Qt::CaseInsensitive) == 0) {
                            r->setEvapMethod("Percent");
                        } else {
                            r->setEvapMethod("Constant");
                        }
                    }
                    i++;
                }
            }

            r->setEvap(s.toDouble());
        } else if (currentElement.compare("EVAP_METHOD", Qt::CaseInsensitive) == 0) {
            r->setEvapMethod(s);
        }
        else if (currentElement.compare("KETTLE_LOSS", Qt::CaseInsensitive) == 0) {
            r->setKettleLoss(Quantity(r->getVolUnits(), s.toDouble()));
        }
        else if (currentElement.compare("MISC_LOSS", Qt::CaseInsensitive) == 0) {
            r->setMiscLoss(Quantity(r->getVolUnits(), s.toDouble()));
        }
        else if (currentElement.compare("TRUB_LOSS", Qt::CaseInsensitive) == 0) {
            r->setTrubLoss(Quantity(r->getVolUnits(), s.toDouble()));
        }
        else if (currentElement.compare("PELLET_HOP_PCT", Qt::CaseInsensitive) == 0) {
            r->setPelletHopPct(s.toDouble());
        }
        else if (currentElement.compare("YEAST_COST", Qt::CaseInsensitive) == 0) {
            r->getYeastObj()->setCost((s));
        }
        else if (currentElement.compare("OTHER_COST", Qt::CaseInsensitive) == 0) {
            r->setOtherCost(s.toDouble());
        }

    } else if ((currentList.compare("FERMENTATION_SCHEDUAL", Qt::CaseInsensitive) == 0)
        || (currentList.compare("FERMENTATION_SCHEDULE", Qt::CaseInsensitive) == 0)) {

        if (currentElement.compare("TYPE", Qt::CaseInsensitive) == 0) {
            ferm.setType(s);
        } else if (currentElement.compare("TEMP", Qt::CaseInsensitive) == 0) {
            ferm.setTemp(s.toDouble());
        } else if (currentElement.compare("TEMPU", Qt::CaseInsensitive) == 0) {
            ferm.setTempU(s);
        } else if (currentElement.compare("TIME", Qt::CaseInsensitive) == 0) {
            ferm.setTime(s.toInt());
        }
    } else if (currentList.compare("WATER_PROFILE", Qt::CaseInsensitive) == 0) {
        if (currentSubList.compare("ACID", Qt::CaseInsensitive) == 0) {
            if (currentElement.compare("NAME", Qt::CaseInsensitive) == 0) {
                try {
                    r->setAcid(Acid::getAcidByName(s));
                } catch (QString e) {
                    qDebug() << e;
                }
            }
        } else if (currentSubList.compare("SALTS", Qt::CaseInsensitive) == 0) {
            // Read in a salt
            if (currentElement.compare("NAME", Qt::CaseInsensitive) == 0) {
                salt.setName(s);
            } else if (currentElement.compare("COMMONNAME", Qt::CaseInsensitive) == 0) {
                salt.setCommonName(s);
            } else if (currentElement.compare("CHEM", Qt::CaseInsensitive) == 0) {
                salt.setChemicalName(s);
            } else if (currentElement.compare("AMOUNT", Qt::CaseInsensitive) == 0) {
                salt.setAmount(s.toDouble());
            }
            // TODO units!!!!
        } else {
            // Source or Target water
            if (currentElement.compare("NAME", Qt::CaseInsensitive) == 0) {
                water.setName(s);
            } else if (currentElement.compare("CA", Qt::CaseInsensitive) == 0) {
                water.setCa(s.toDouble());
            } else if (currentElement.compare("MG", Qt::CaseInsensitive) == 0) {
                water.setMg(s.toDouble());
            } else if (currentElement.compare("NA", Qt::CaseInsensitive) == 0) {
                water.setNa(s.toDouble());
            } else if (currentElement.compare("SO4", Qt::CaseInsensitive) == 0) {
                water.setSo4(s.toDouble());
            } else if (currentElement.compare("HCO3", Qt::CaseInsensitive) == 0) {
                water.setHco3(s.toDouble());
            } else if (currentElement.compare("CL", Qt::CaseInsensitive) == 0) {
                water.setCl(s.toDouble());
            } else if (currentElement.compare("HARDNESS", Qt::CaseInsensitive) == 0) {
                water.setHardness(s.toDouble());
            } else if (currentElement.compare("TDS", Qt::CaseInsensitive) == 0) {
                water.setTds(s.toDouble());
            } else if (currentElement.compare("PH", Qt::CaseInsensitive) == 0) {
                water.setPh(s.toDouble());
            } else if (currentElement.compare("ALKALINITY", Qt::CaseInsensitive) == 0) {
                water.setAlkalinity(s.toDouble());
            }
        }
    }
    else
        s = "";
}

bool XMLHandler::processingInstruction(const QString &target, const QString &data) {

    qDebug() << "PROCESS: ";
    qDebug() << "<?" << target << " " << data << "?>";
    return true;
}

//===========================================================
// SAX ErrorHandler methods
//===========================================================

// treat validation errors as fatal
bool XMLHandler::error(const QXmlParseException &exception) {
    qDebug() << exception.message();
    throw exception;
}

// dump warnings too
bool XMLHandler::warning(const QXmlParseException &exception) {
    qDebug() << "** Warning" << ", line " << exception.lineNumber()
            << ", uri " + exception.systemId();
    qDebug() << exception.message();
    return true;
}

bool XMLHandler::fatalError(const QXmlParseException &exception)
{
    Q_UNUSED(exception);
    return true;
}


