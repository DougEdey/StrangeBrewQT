#include "promashimport.h"

Recipe *ProMashImport::readRecipe(QString inputFileName) {
    Recipe *myRecipe = new Recipe();

    // File f = new File(path);
    QFile in(inputFileName);

    QTextStream inStream(&in);

    QString s = "";
    long l, l2;
    float fl;
    int x;


    // read in the name - 82 bytes
    s = inStream.read(82);

    qDebug() << "Recipe name: " << s;
    myRecipe->setName(s);

    // get the various sizes
    long hopCount;
    inStream >> hopCount;
    qDebug() << "Hop count: " << hopCount;

    long maltCount;
    inStream >> maltCount;
    qDebug() << "Malt count: " << maltCount;

    long extraCount;
    inStream >> extraCount;
    qDebug() << "Extra count: " << extraCount;

    inStream >> fl;
    inStream.read(3);
    qDebug() << "Batch size: " << fl;

    inStream >> fl;
    qDebug() << "Wort size: " << fl;

    myRecipe->setReadVolUnits("gal");
    Quantity postBoil;
    postBoil.setUnits(myRecipe->getVolUnits());
    postBoil.setAmount(fl);

    myRecipe->setPostBoil(postBoil);
    inStream.read(8);
    inStream >> fl;
    qDebug() << "%effic: " << fl*100;
    myRecipe->setEfficiency(fl*100);

    inStream >> x;
    qDebug() << "Boil time: " << x;
    myRecipe->setBoilMinutes(x);
    inStream.read(8);

    // Style
    s = inStream.read(55);
    s = inStream.read(55);
    qDebug() << "Style: " << s;
    myRecipe->setStyle(s.trimmed());



    // let's skip to start of hops

    inStream.read(921);

    // lets try to read the hops : 635 bytes
    for (int i = 0; i < hopCount; i++) {
        Hop *h = new Hop();

        s = inStream.read(55);
        qDebug() << "Hop name: " << s;
        h->setName(s);

        inStream >> fl;
        qDebug() << "Alpha: " << fl;
        h->setAlpha(fl);

        inStream.read(22);

        inStream >> x;
        qDebug() << "Form: " << x;
        inStream.read(4);

        QString descr = "";
        s = inStream.read(155);
        qDebug() << "Descr: " << s;
        descr = "Description: " + s.trimmed() + "\n";

        s = inStream.read(55);
        qDebug() << "Origin: " << s;
        descr += "Origin: " + s.trimmed() + "\n";

        s = inStream.read(155);
        qDebug() << "Use: " << s;
        descr += "Use: " + s.trimmed() + "\n";

        s = inStream.read(165);
        qDebug() << "Substitutes: " << s;
        descr += "Substitutes: " + s.trimmed() + "\n";
        h->setDescription(descr);

        inStream.read(9);

        inStream >> fl;
        qDebug() << "Amount: " << fl;
        h->setAmount(fl);
        h->setUnits("oz");

        inStream >> x;
        qDebug() << "Min:" << x;
        h->setMinutes(x);
        myRecipe->addHop(h);

        inStream.read(5);

    }

    // lets try to read the malts
    for (int i = 0; i < maltCount; i++) {
        Fermentable *m = new Fermentable();

        s = inStream.read(55);
        qDebug() << "Malt name: " << s;
        m->setName(s.trimmed());

        s = inStream.read(55);
        qDebug() << "Mfg: " << s;

        s = inStream.read(55);
        qDebug() << "Origin: " << s;

        inStream >> x;

        QString type = "";
        switch (x) {
            case 1 :
                type = "grain";
                break;
            case 2 :
                type = "extract";
                m->setMashed(false);
                break;
            case 3 :
                type = "sugar";
                m->setMashed(false);
                break;
            case 4 :
                type = "other";
        }
        qDebug() << "Type: " << type;

        QString type2 = "";
        inStream >> x;
        switch (x) {
            case 0 : {
                if (QString::compare(type, "extract"))
                    type2 = "LME";
                else if (QString::compare(type, "grain") || QString::compare(type, "sugar"))
                    type2 = "Mustmash = no";
                    m->setMashed(false);
                break;

            }
            case 1 : {
                if (QString::compare(type, "extract"))
                    type2 = "DME";
                else if (QString::compare(type, "grain") || QString::compare(type, "sugar"))
                    type2 = "Mustmash = yes";
                    m->setMashed(true);
                break;
            }
        }
        qDebug() << "Type2: " << type2;

        inStream >> fl;
        qDebug() << "pppg: " << fl;
        m->setPppg(fl);

        inStream >> fl;
        qDebug() << "srm: " << fl;
        m->setLov(fl);

        inStream.read(20);
        QString descr = "";
        s = inStream.read(155);
        qDebug() << "uses: " << s;
        descr = "Uses: " + s + "\n";

        s = inStream.read(159);
        qDebug() << "comments: " << s;
        descr += "Comments: " + s + "\n";
        m->setDescription(descr);

        inStream.read(12);
        inStream >> fl;
        qDebug() << "amount: " << fl;
        m->setAmount(fl);
        m->setUnits("lb");

        myRecipe->addMalt(m);

        inStream.read(4);
    }

    for (int i = 0; i < extraCount; i++) {
        Misc *m = new Misc();

        s = inStream.read(55);
        qDebug() << "Extra: " << s;
        m->setName(s);

        QString type = "";
        inStream >> x;

        switch (x) {
            case 0 :
                type = "spice";
                break;
            case 1 :
                type = "fruit";
                break;
            case 2 :
                type = "coffee";
                break;
            case 3 :
                type = "other";
                break;
            case 4 :
                type = "fining";
                break;
            case 5 :
                type = "herb";
                break;
        }
        qDebug() << "Type: " << type;
        m->setType(type);

        inStream >> l;
        qDebug() << "Time: " << l;

        QString use = "";
        inStream >> x;

        switch (x) {
            case 0 :
                use = "Boil";
                break;
            case 1 :
                use = "Primary";
                break;
            case 2 :
                use = "Mash";
                break;
        }
        qDebug() << "Use: " << use;
        m->setStage(use);
        inStream.read(1);

        QString units = "";
        inStream >> x;

        switch (x) {
            case 0 :
                units = "oz";
                break;
            case 1 :
                units = "g";
                break;
            case 2 :
                units = "lb";
                break;
            case 3 :
                units = "tsp";
                break;
            case 4 :
                units = "Tbs";
                break;
            case 5 :
                units = "cups";
                break;
            case 6 :
                units = "Single";
                break;
        }
        qDebug() << "Units: " << units;
        m->setUnits(units);

        inStream >> fl;
        qDebug() << "Amount: " << fl;
        m->setAmount(fl);

        s = inStream.read(222);
        qDebug() << "Usage: " << s;
        m->setDescription(s);

        s = inStream.read(222);
        qDebug() << "Comments: " << s;
        m->setComments(s);

        myRecipe->addMisc(m);

        inStream.read(145);
    }

    // yeast: 473
    Yeast *y = new Yeast();

    QString descr = "";
    s = inStream.read(55);
    qDebug() << "Yeast: " << s;
    descr = s.trimmed();

    s = inStream.read(55);
    qDebug() << "Mfg: " << s;
    descr = s.trimmed() + " " + descr;

    QString s2 = inStream.read(25);
    qDebug() << "Num: " << s2;
    descr = s2.trimmed() + " " + descr;
    y->setName(descr);

    inStream.read(2);
    descr = "";
    s = inStream.read(155);
    qDebug() << "Flavour: " << s;
    descr = "Flavour: " + s.trimmed() + "\n";

    s = inStream.read(159);
    qDebug() << "Comment: " << s;
    descr += "Comments: " + s.trimmed() + "\n";
    y->setDescription(descr);

    myRecipe->setYeast(y);

    inStream.read(22);

    // skip water
    inStream.read(106);

    // skip ?
    inStream.read(113);

    // regular mash
    inStream.read(9);

    for (int j=0; j<5; j++){
        inStream >> l;
        qDebug() << j << " rest Temp: " << l;

        inStream >> l2;
        qDebug() << j << ": rest Min: " << l2;

        QString stepType="alpha";
        switch (j){
            case 0:
                stepType = "acid";
                break;
            case 1:
                stepType = "protein";
                break;
            case 2:
                stepType = "beta";
                break;
            case 3:
                stepType = "alpha";
                break;
            case 4:
                stepType = "mashout";
                break;
        }

        if (l > 0){
            myRecipe->getMash()->addStep(stepType, l,
                    l, "infusion",  l2, 0, 0);
        }
    }


    inStream >> l;
    qDebug() << "Sparge rest Temp: " << l;
    inStream >> l2;
    qDebug() << "Sparge rest Min: "  << l2;

    // TODO: set sparge time & temp

    inStream.read(5);

    // notes:
    s = inStream.read(4028);
    qDebug() << "Notes: " << s;

    s = inStream.read(4283);
    qDebug() << "Awards: " << s;

    // skip other stuff
    inStream.read(175);

    // Custom Mash
    // in.skip(62);
    long mashCount;
    inStream >> mashCount;
    qDebug() << "Mash steps: " << mashCount;
    inStream.read(11);

    for (int i = 0; i < mashCount; i++) {
        s = inStream.read(253);
        qDebug() << "step: " << s;

        inStream >> l;
        qDebug() << "start: " << l;
        inStream >> l;
        qDebug() << "end: " << l;
        inStream >> l;
        qDebug() << "infuse temp: " << l;
        inStream >> l;
        qDebug() << "min: " << l;
        inStream >> l;
        qDebug() << "stop time: " << l;

        inStream.read(19);
    }


    in.close();
    return myRecipe;
}

QString ProMashImport::readString(QTextStream fs, int b) {
    return fs.read(b);
}

int ProMashImport::readInt(QTextStream fs) {
    QString raw = fs.read(1);
    return raw.toInt();
}

long ProMashImport::readLong(QTextStream fs) {
    return fs.read(4).toLong();
}

int ProMashImport::readShort(QTextStream fs) {
    return fs.read(2).toShort();
}

float ProMashImport::readFloat(QTextStream fs) {
    return fs.read(4).toFloat();
}

