#include "database.h"

QSettings Database::preferences("Doug Edey", "StrangeBrew");

QList<Hop*> Database::hopsDB = QList<Hop*>();
QList<Hop*> Database::stockHopsDB = QList<Hop*>();

QList<Fermentable*> Database::fermDB = QList<Fermentable*>();
QList<Fermentable*> Database::stockFermDB = QList<Fermentable*>();

QList<Yeast*> Database::yeastDB = QList<Yeast*>();
QList<Style*> Database::styleDB  = QList<Style*>();
QList<Misc*> Database::miscDB = QList<Misc*>();
QList<PrimeSugar*> Database::primeSugarDB = QList<PrimeSugar*>();
QList<WaterProfile*> Database::waterDB  = QList<WaterProfile*>();

QStringList Database::styleYears = QStringList();
QString Database::styleFileName = "";
QString Database::dbPath = QApplication::applicationDirPath() + QDir::separator() + "data";
QString Database::dbName = dbPath+QDir::separator()+"sb_ingredients.db";
QString Database::lastErrorString = "";

QString Database::lastError() {
    QString temp = lastErrorString;
    lastErrorString = "";
    return temp;
}

QSqlDatabase Database::connectDB() {

    QFile dbFile(dbName);
    if (!dbFile.exists()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Could not find the Database at: " + dbName);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        QApplication::quit();

    }

    QSqlDatabase conn = QSqlDatabase::addDatabase("QSQLITE", dbName);

    qDebug() << "Config file is at " << preferences.fileName();
    qDebug() << dbName;
    conn.setDatabaseName(dbName);


    if (!conn.open())
    {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        QApplication::quit();

     }
    return conn;
}

// This is now a singleton
Database::Database() {

    QSqlDatabase conn = connectDB();

    QStringList tableList = conn.tables();
    QSqlQuery stat(conn);

    if (!tableList.contains("styleguide")) {
        // no Style guide
        qDebug() << "Creating styleguide table";

        QString sqlQuery("create table styleguide (Item INT AUTO_INCREMENT,Name, Category, OG_Low, OG_High, Alc_Low, Alc_High, IBU_Low, IBU_High, Lov_Low, Lov_High,");
        sqlQuery.append("Appearance, Aroma, Flavor, Mouthfeel, Impression, Comments, Ingredients, Comm_examples, Year );");

        stat.exec(sqlQuery);

    }

    if (!tableList.contains("fermentables")) {
        // no fermentables
        qDebug() << "Creating fermentables table";
        stat.exec("create table fermentables (Item INT AUTO_INCREMENT,Name UNIQUE,Yield,Lov,Cost,Stock,Units,Mash,Descr,Steep,Modified, Ferments );");
    } else {
        qDebug() <<  "Checking for fermentables updates";

        // This will cover us if we need to add new rows in the future, to enable people to update the DB
        map<QString, QString> newColumns;

        newColumns["Ferments"] = "bool";

        QSqlRecord fermRecord = conn.record("fermentables");

        // Iterate the Map
        typedef std::map<QString, QString>::iterator it_type;

        it_type colIt = newColumns.begin();

        for (; colIt != newColumns.end(); ++colIt) {

            if (!fermRecord.field(colIt->first).isValid()) {
                stat.exec("ALTER TABLE fermentables ADD " + colIt->first + " DEFAULT " + colIt->second);
            }
        }

    }

    if (!tableList.contains("hops")) {
        // no hops
        qDebug() << "Creating hops table";
        stat.exec("create table hops (Item INT AUTO_INCREMENT,Name,Alpha,Cost,Stock,Units,Descr,Storage,Date,Modified,Type);");
    } else {

        // This will cover us if we need to add new rows in the future, to enable people to update the DB
        map<QString, QString> newColumns;

        newColumns["Type"] = "pellet";

        QSqlRecord fermRecord = conn.record("hops");

        // Iterate the Map
        typedef std::map<QString, QString>::iterator it_type;

        it_type colIt = newColumns.begin();

        for (; colIt != newColumns.end(); ++colIt) {

            if (!fermRecord.field(colIt->first).isValid()) {
                stat.exec("ALTER TABLE hops ADD " + colIt->first + " DEFAULT " + colIt->second);
            }
        }
    }

    if(!tableList.contains("misc")) {
        // no misc
        qDebug() << "Creating misc table";
        stat.exec("create table misc (Item INT AUTO_INCREMENT,Name,Descr,Stock,Units,Cost,Stage,Modified);");
    }

    if(!tableList.contains("prime")) {
        // no prime
        qDebug() << "Creating prime table";
        stat.exec("create table prime  ( Item INT AUTO_INCREMENT,Name,Yield,Units,Descr);");
    }

    if(!tableList.contains("yeast")) {
        // no yeast
        qDebug() << "Creating yeast table";
        stat.exec("create table yeast (Item INT AUTO_INCREMENT,Name,Cost,Descr,Modified);");
    }

    if(!tableList.contains("water_profiles")) {
        // no water_profiles
        qDebug() << "Creating water_profiles table";
        stat.exec("create table water_profiles ( Item INT AUTO_INCREMENT, Name,Descr,Ca,Mg,Na,SO4,HCO3,Cl,Hardness,TDS,PH,Alk);");
    }

    if(!tableList.contains("mash_profiles")) {
        // no water_profiles
        qDebug() << "Creating mash_profiles table";
        stat.exec("create table mash_profiles ( Item INT AUTO_INCREMENT, Name,Step,StartTempF,EndTempF,Time,Method);");
        // insert the default values
    }
        QString insert = "INSERT INTO mash_profiles (Name, Step, StartTempF, EndTempF, Time, Method) "
                "VALUES(:name, :step, :startTempF, :endTempF, :time, :method);";

        stat.prepare(insert);

        prepareMashProfileInsert(stat, "Single Infusion w/Sparge", 0, 156, 156, 60, INFUSION);
        prepareMashProfileInsert(stat, "Single Infusion w/Sparge", 1, 170, 170, 60, FLY);

        prepareMashProfileInsert(stat, "Triple Decoction", 0, 104, 104, 10, INFUSION);
        prepareMashProfileInsert(stat, "Triple Decoction", 1, 122, 122, 20, DECOCTION_THICK);
        prepareMashProfileInsert(stat, "Triple Decoction", 2, 141, 141, 30, DECOCTION_THICK);
        prepareMashProfileInsert(stat, "Triple Decoction", 3, 104, 104, 10, DECOCTION_THICK);
        prepareMashProfileInsert(stat, "Triple Decoction", 4, 104, 104, 10, FLY);

        prepareMashProfileInsert(stat, "Fix 3 Rest Schedule", 0, 104, 104, 30, INFUSION);
        prepareMashProfileInsert(stat, "Fix 3 Rest Schedule", 1, 140, 140, 30, INFUSION);
        prepareMashProfileInsert(stat, "Fix 3 Rest Schedule", 2, 158, 158, 30, INFUSION);
        prepareMashProfileInsert(stat, "Fix 3 Rest Schedule", 3, 170, 170, 60, INFUSION);




    qDebug() << "Created Database succesfully!";

    this->readDB(this->preferences.value("Style/Year").toString());
}

void Database::prepareMashProfileInsert(QSqlQuery connection, QString name, int step, int startTempF, int endTempF, int time, QString method) {
    // insert the default values
    QString insert = "INSERT INTO mash_profiles (Name, Step, StartTempF, EndTempF, Time, Method) VALUES(:name, :step, :startTempF, :endTempF, :time, :method);";
    connection.prepare(insert);
    connection.bindValue(":name", name);
    connection.bindValue(":step", step);
    connection.bindValue(":startTempF", startTempF);
    connection.bindValue(":endTempF", endTempF);
    connection.bindValue(":time", time);
    connection.bindValue(":method", method);

    //QString insert = "INSERT INTO mash_profiles (Name, Step, StartTempF, EndTempF, Time, Type)"
    //        "VALUES('"+name+"', '"+step+"', '"+startTempF+"', '"+endTempF+"', '"+time+"', '"+method+"');";

    if(!connection.exec()) {
        qDebug() << "Couldn't insert the query: " << connection.lastError().text();
        qDebug() << connection.executedQuery();

    }

}

Database& Database::getInstance() {

    static Database instance;
    return instance;
}

Database::~Database() {
    qDebug() << "Closing Database";
    fermDB.clear();
    hopsDB.clear();
    miscDB.clear();
    yeastDB.clear();
    styleDB.clear();
    waterDB.clear();

    QSqlDatabase conn = QSqlDatabase::database(dbName);
    conn.removeDatabase("QSQLITE");
    conn.close();
}

int Database::inDB(Yeast *o){
    Yeast *y;
    for (int i=0; i<yeastDB.size(); i++){
        y = yeastDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(Fermentable *o){
    Fermentable *y;
    for (int i=0; i<fermDB.size(); i++){
        y = fermDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(Hop *o){
    Hop *y;
    for (int i=0; i<hopsDB.size(); i++){
        y = hopsDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(Misc *o){
    Misc *y;
    for (int i=0; i<miscDB.size(); i++){
        y = miscDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(Style *o){
    Style *y;
    for (int i=0; i<styleDB.size(); i++){
        y = styleDB.at(i);
        if (o->getName() == y->getName()) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(PrimeSugar *o){
    PrimeSugar *y;
    for (int i=0; i<primeSugarDB.size(); i++){
        y = primeSugarDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}

int Database::inDB(WaterProfile *o){
    WaterProfile *y;
    for (int i=0; i<waterDB.size(); i++){
        y = waterDB.at(i);
        if (o == y) {
            return i;
        }
    }
    return -1;
}


bool Database::readDB(QString styleYear){

    // check to see if the style guide is in the DB already
    styleDB.clear();
    stockFermDB.clear();
    fermDB.clear();
    stockHopsDB.clear();
    hopsDB.clear();
    yeastDB.clear();
    waterDB.clear();

    if (!readFermentables()
            || !readPrimeSugar()
            || !readHops()
            || !readYeast()
            || !readMisc()
            || !importStyles(styleYear)
            || !readWater()) {
        return false;
    }


    // sort
    qDebug() << "Style DB Size: " << styleDB.size();

    sort(styleDB.begin(), styleDB.end());
    sort(fermDB.begin(), fermDB.end(), Fermentable::lessThan);
    sort(hopsDB.begin(), hopsDB.end());
    sort(yeastDB.begin(), yeastDB.end());
    sort(waterDB.begin(), waterDB.end());

    return true;

}

bool Database::readFermentables() {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery statement(conn);
    statement.exec("SELECT * FROM fermentables");

    // we weren't clearing this when updating
    stockFermDB.clear();

    QSqlRecord rec = statement.record();
    int nameCol = rec.indexOf("Name");
    int yieldCol = rec.indexOf("Yield");
    int lovCol = rec.indexOf("Lov");
    int costCol = rec.indexOf("Cost");
    int unitsCol = rec.indexOf("Units");
    int mashCol = rec.indexOf("Mash");
    int steepCol = rec.indexOf("Steep");
    int fermentsCol = rec.indexOf("Ferments");
    int stockCol = rec.indexOf("Stock");
    int descrCol = rec.indexOf("descr");
    //int modifiedCol = rec.indexOf("Modified");

    Fermentable *f;
    while (statement.next()) {
        f = new Fermentable();
        //Item,Name,Yield,Lov,Cost,Stock,Units,Mash,Descr,Steep,Modified
        if (statement.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        f->setName(statement.value(nameCol).toString());
        f->setPppg(statement.value(yieldCol).toDouble());
        f->setLov(statement.value(lovCol).toDouble());
        f->setCost(statement.value(costCol).toDouble());
        f->setUnits(statement.value(unitsCol).toString());
        f->setMashed(statement.value(mashCol).toBool());
        f->setSteep(statement.value(steepCol).toBool());
        f->ferments(statement.value(fermentsCol).toBool());

        if (QString::compare(statement.value(stockCol).toString(), "") != 0) {
            f->setStock(statement.value(stockCol).toDouble());
        }
        else
            f->setStock(0);


        f->setDescription(statement.value(descrCol).toString() );
        f->setModified(statement.value(stockCol).toBool());
        fermDB.append(f);

        // check to see if we have nonStock set

        if(f->getStock() > 0.00 ) {
            qDebug() << "Adding to Stock DB";
            stockFermDB.append(f);
        }

    }

    qDebug() << "Ferm Found " << fermDB.size();

    sort(fermDB.begin(), fermDB.end());

    return true;
}

/*void Database::writeFermentables(QString item, QString name, QString yield, QString lov, QString cost, QString units,
            QString mash, QString descr, QString steep, QString modified) {
    qDebug() << "Write fermentable specific Not implemented";
}*/

bool Database::writeFermentable(Fermentable &f) {
    // Don't need to do this anymore, we store as soon as we add anything to the DB!
    qDebug() << "Saving fermentables to Database";
    QSqlDatabase conn = connectDB();
    QSqlQuery selectFerm(conn);
    selectFerm.prepare("SELECT COUNT(*) FROM fermentables WHERE name = :name;");

    QSqlQuery selectSpecificFerm(conn);
    QString sqlQuery = "SELECT COUNT(*) FROM fermentables ";
    sqlQuery.append("WHERE name = :name AND Yield = :yield AND Lov=:lov AND Cost=:cost AND Stock=:stock AND");
    sqlQuery.append(" Units=:units AND Mash=:mash AND Descr=:descr AND Steep=:steep AND Ferments=:ferments;");
    selectSpecificFerm.prepare(sqlQuery);


    QSqlQuery insertFerm(conn);
    sqlQuery.clear();
    sqlQuery.append("insert into fermentables (Name,Yield,Lov,Cost,Stock,Units,Mash,Descr,Steep, Ferments) ");
    sqlQuery.append("values(:name, :yield, :lov, :cost, :stock, :units, :mash, :descr, :steep, :ferments)");

    insertFerm.prepare(sqlQuery);

    QSqlQuery updateFerm(conn);
    sqlQuery.clear();
    sqlQuery.append("UPDATE fermentables SET Yield=:yield, Lov=:lov, Cost=:cost, Stock=:stock,");
    sqlQuery.append(" Units=:units, Mash=:mash, Descr=:descr, Steep=:steep, Ferments=:ferments " );
    sqlQuery.append(" WHERE name = :name");
    updateFerm.prepare(sqlQuery);



    selectFerm.bindValue(":name", f.getName());
    if(!selectFerm.exec()) {
        qDebug() << "Failed to select " << f.getName();
        qDebug() << conn.lastError().text();

        lastErrorString = conn.lastError().text();
        return false;
    }

    selectFerm.next();
    qDebug() << "Result size " << selectFerm.value(0).toInt();

    if(selectFerm.value(0).toInt() == 0){
        qDebug() << "Adding fermentable " << f.getName();
        insertFerm.bindValue(":name", f.getName());
        insertFerm.bindValue(":yield", f.getPppg());
        insertFerm.bindValue(":lov", f.getLov());
        insertFerm.bindValue(":cost", f.getCostPerU());
        insertFerm.bindValue(":stock", f.getStock());
        insertFerm.bindValue(":units", f.getUnitsAbrv());
        insertFerm.bindValue(":mash", f.getMashed());
        insertFerm.bindValue(":descr", f.getDescription());
        insertFerm.bindValue(":steep", f.getSteep());
        insertFerm.bindValue(":ferments", f.ferments());
        insertFerm.exec();
    } else {

        selectSpecificFerm.bindValue(":name", f.getName());
        selectSpecificFerm.bindValue(":yield", f.getPppg());
        selectSpecificFerm.bindValue(":lov", f.getLov());
        selectSpecificFerm.bindValue(":cost", f.getCostPerU());
        selectSpecificFerm.bindValue(":stock", f.getStock());
        selectSpecificFerm.bindValue(":units", f.getUnitsAbrv());
        selectSpecificFerm.bindValue(":mash", f.getMashed());
        selectSpecificFerm.bindValue(":descr", f.getDescription());
        selectSpecificFerm.bindValue(":steep", f.getSteep());
        selectSpecificFerm.bindValue(":ferments", f.ferments());

        if(!selectSpecificFerm.exec()) {
            qDebug() << "Failed to specific select " << f.getName();
            qDebug() << conn.lastError().text();


            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }

        selectSpecificFerm.next();

        // we have a name match, see if anything has changed
        if(selectSpecificFerm.value(0).toInt() == 0) {

            qDebug() << "Fermentables Update: " << f.getName();
            updateFerm.bindValue(":yield", f.getPppg());
            updateFerm.bindValue(":lov", f.getLov());
            updateFerm.bindValue(":cost", f.getCostPerU());
            updateFerm.bindValue(":stock", f.getStock());
            updateFerm.bindValue(":units", f.getUnitsAbrv());
            updateFerm.bindValue(":mash", f.getMashed());
            updateFerm.bindValue(":descr", f.getDescription());
            updateFerm.bindValue(":steep", f.getSteep());
            updateFerm.bindValue(":ferments", f.ferments());
            // where cause
            updateFerm.bindValue(":name", f.getName());

            if (!updateFerm.exec()) {
                qDebug() << conn.lastError().text();
                lastErrorString = conn.lastError().text();
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();

                lastErrorString = conn.lastError().text();
                return false;
            }

        }
    }
    return true;
}

bool Database::writeFermentables(QList<Fermentable*> replacement) {
    fermDB = replacement;
    return writeFermentables();
}

bool Database::writeFermentables() {
    // Don't need to do this anymore, we store as soon as we add anything to the DB!
    qDebug() << "Saving fermentables to Database";
    QSqlDatabase conn = connectDB();
    QSqlQuery selectFerm(conn);
    selectFerm.prepare("SELECT COUNT(*) FROM fermentables WHERE name = :name;");

    QSqlQuery selectSpecificFerm(conn);
    QString sqlQuery = "SELECT COUNT(*) FROM fermentables ";
    sqlQuery.append("WHERE name = :name AND Yield = :yield AND Lov=:lov AND Cost=:cost AND Stock=:stock AND");
    sqlQuery.append(" Units=:units AND Mash=:mash AND Descr=:descr AND Steep=:steep AND Ferments=:ferments;");
    selectSpecificFerm.prepare(sqlQuery);


    QSqlQuery insertFerm(conn);
    sqlQuery.clear();
    sqlQuery.append("insert into fermentables (Name,Yield,Lov,Cost,Stock,Units,Mash,Descr,Steep, Ferments) ");
    sqlQuery.append("values(:name, :yield, :lov, :cost, :stock, :units, :mash, :descr, :steep, :ferments)");

    insertFerm.prepare(sqlQuery);

    QSqlQuery updateFerm(conn);
    sqlQuery.clear();
    sqlQuery.append("UPDATE fermentables SET Yield=:yield, Lov=:lov, Cost=:cost, Stock=:stock,");
    sqlQuery.append(" Units=:units, Mash=:mash, Descr=:descr, Steep=:steep, Ferments=:ferments " );
    sqlQuery.append(" WHERE name = :name");
    updateFerm.prepare(sqlQuery);


    int i = 0;
    // sort the list first
    sort(fermDB.begin(), fermDB.end());

    while (i < fermDB.size()) {
        Fermentable *f = fermDB.at(i);
        i++;

        selectFerm.bindValue(":name", f->getName());
        if(!selectFerm.exec()) {
            qDebug() << "Failed to select " << f->getName();
            qDebug() << conn.lastError().text();
            lastErrorString = conn.lastError().text();
            return false;
        }

        selectFerm.next();
        qDebug() << "Result size " << selectFerm.value(0).toInt();

        if(selectFerm.value(0).toInt() == 0){
            qDebug() << "Adding fermentable " << f->getName();
            insertFerm.bindValue(":name", f->getName());
            insertFerm.bindValue(":yield", f->getPppg());
            insertFerm.bindValue(":lov", f->getLov());
            insertFerm.bindValue(":cost", f->getCostPerU());
            insertFerm.bindValue(":stock", f->getStock());
            insertFerm.bindValue(":units", f->getUnitsAbrv());
            insertFerm.bindValue(":mash", f->getMashed());
            insertFerm.bindValue(":descr", f->getDescription());
            insertFerm.bindValue(":steep", f->getSteep());
            insertFerm.bindValue(":ferments", f->ferments());
            insertFerm.exec();
        } else {

            selectSpecificFerm.bindValue(":name", f->getName());
            selectSpecificFerm.bindValue(":yield", f->getPppg());
            selectSpecificFerm.bindValue(":lov", f->getLov());
            selectSpecificFerm.bindValue(":cost", f->getCostPerU());
            selectSpecificFerm.bindValue(":stock", f->getStock());
            selectSpecificFerm.bindValue(":units", f->getUnitsAbrv());
            selectSpecificFerm.bindValue(":mash", f->getMashed());
            selectSpecificFerm.bindValue(":descr", f->getDescription());
            selectSpecificFerm.bindValue(":steep", f->getSteep());
            selectSpecificFerm.bindValue(":ferments", f->ferments());

            if(!selectSpecificFerm.exec()) {
                qDebug() << "Failed to specific select " << f->getName();
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                lastErrorString = conn.lastError().text();
                return false;
            }

            selectSpecificFerm.next();

            // we have a name match, see if anything has changed
            if(selectSpecificFerm.value(0).toInt() == 0) {

                qDebug() << "Fermentables Update: " << f->getName();
                updateFerm.bindValue(":yield", f->getPppg());
                updateFerm.bindValue(":lov", f->getLov());
                updateFerm.bindValue(":cost", f->getCostPerU());
                updateFerm.bindValue(":stock", f->getStock());
                updateFerm.bindValue(":units", f->getUnitsAbrv());
                updateFerm.bindValue(":mash", f->getMashed());
                updateFerm.bindValue(":descr", f->getDescription());
                updateFerm.bindValue(":steep", f->getSteep());
                updateFerm.bindValue(":ferments", f->ferments());
                // where cause
                updateFerm.bindValue(":name", f->getName());

                if (!updateFerm.exec()) {
                    qDebug() << conn.lastError().text();

                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText(conn.lastError().text());
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    lastErrorString = conn.lastError().text();
                    return false;
                }

            }
        }
    }
    //clear the list
    fermDB.clear();
    stockFermDB.clear();

    qDebug() << "Trying to update DB at: " << dbPath;
    readFermentables();

    return true;
}

bool Database::readHops() {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    // Open the database and read the Hops
    QSqlQuery statement(conn);
    statement.exec("SELECT * FROM hops");

    hopsDB.clear();

    QSqlRecord rec = statement.record();
    int nameCol = rec.indexOf("Name");
    int alphaCol = rec.indexOf("Alpha");
    int costCol = rec.indexOf("Cost");
    int unitsCol = rec.indexOf("Units");
    int stockCol = rec.indexOf("Stock");
    int descrCol = rec.indexOf("Descr");
    int storageCol = rec.indexOf("Storage");
    int dateCol = rec.indexOf("Date");
    int modifiedCol = rec.indexOf("Modified");
    int typeCol = rec.indexOf("Type");


    while (statement.next()) {
        Hop *h = new Hop();
        //Item,Name,Alpha,Cost,Stock,Units,Descr,Storage,Date,Modified
        if (statement.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        h->setName(statement.value(nameCol).toString());
        h->setAlpha(statement.value(alphaCol).toDouble());

        if (QString::compare(statement.value(costCol).toString(), "") != 0)
            h->setCost(statement.value(costCol).toDouble());

        h->setUnits(statement.value(unitsCol).toString());

        if (QString::compare(statement.value(stockCol).toString(), "") != 0)
            h->setStock(statement.value(stockCol).toDouble());

        h->setDescription(statement.value(descrCol).toString());

        if (QString::compare(statement.value(storageCol).toString(), "") != 0)
            h->setStorage(statement.value(storageCol).toDouble());

        h->setDate(statement.value(dateCol).toString());

        h->setModified(statement.value(modifiedCol).toBool());

        { // test for the type
            QString tempType = statement.value(typeCol).toString();
            if (QString::compare(tempType, "false") == 0) {
                tempType = preferences.value("Hops/Type").toString();
            }

            h->setType(tempType);
        }

        hopsDB.push_back(h);

        if (h->getStock() > 0) {
            stockHopsDB.push_back(h);
        }

        //Item,Name,Yield,Lov,Cost,Stock,Units,Mash,Descr,Steep,Modified


    }
    qDebug() << "Hops Found " << hopsDB.size();

    sort(hopsDB.begin(), hopsDB.end());

    return true;

}


bool Database::writeHop(Hop &h) {
        // Name,Alpha,Cost,Stock,Units,Descr,Storage,Date,Modified
    qDebug() << "Write Hops to DB";

    QSqlDatabase conn = connectDB();
    QSqlQuery selectHops(conn);
    selectHops.prepare("SELECT COUNT(*) FROM hops WHERE name = :name;");

    QSqlQuery selectSpecificHop(conn);
    QString sqlQuery = "SELECT COUNT(*) FROM hops WHERE name = :name";
    sqlQuery.append(" AND Alpha=:alpha AND Cost=:cost AND Stock=:stock AND ");
    sqlQuery.append("Units=:units AND Descr=:descr AND Storage=:storage AND Type=:type;");

    selectSpecificHop.prepare(sqlQuery);

    QSqlQuery insertHop(conn);
    sqlQuery.clear();
    sqlQuery.append("insert into hops (Name,Alpha,Cost,Stock,Units,Descr,Storage,Date, Type) ");
    sqlQuery.append("values(:name, :alpha, :cost, :stock, :units, :descr, :storage, :date, :type)");
    insertHop.prepare(sqlQuery);

    QSqlQuery updateHop(conn);
    sqlQuery.clear();
    sqlQuery.append("UPDATE hops SET Alpha=:alpha,Cost=:cost,Stock=:stock,");
    sqlQuery.append("Units=:units,Descr=:descr,Storage=:storage,Date=:date,Type=:type ");
    sqlQuery.append("WHERE name = :name");
    updateHop.prepare(sqlQuery);

    //Sort the list
    sort(hopsDB.begin(), hopsDB.end());
     selectHops.bindValue(":name", h.getName());

    if (!selectHops.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        lastErrorString = conn.lastError().text();
        return false;
    }

    selectHops.next();
    // Does this hop exist?
    if(selectHops.value(0).toInt() == 0){
        insertHop.bindValue(":name", h.getName());
        insertHop.bindValue(":alpha", h.getAlpha());
        insertHop.bindValue(":cost", h.getCostPerU());
        insertHop.bindValue(":stock", h.getStock());
        insertHop.bindValue(":units", h.getUnitsAbrv());
        insertHop.bindValue(":descr", h.getDescription());
        insertHop.bindValue(":storage", h.getStorage());
        insertHop.bindValue(":date", h.getDate());
        insertHop.bindValue(":type", h.getType());

        if (!insertHop.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            lastErrorString = conn.lastError().text();
            return false;
        }
    } else { // check to see if we need to update this hop

        selectSpecificHop.bindValue(":name", h.getName());
        selectSpecificHop.bindValue(":alpha", h.getAlpha());
        selectSpecificHop.bindValue(":cost", h.getCostPerU());
        selectSpecificHop.bindValue(":stock", h.getStock());
        selectSpecificHop.bindValue(":units", h.getUnitsAbrv());
        selectSpecificHop.bindValue(":descr", h.getDescription());
        selectSpecificHop.bindValue(":storage", h.getStorage());
        selectSpecificHop.bindValue(":type", h.getType());


        if(!selectSpecificHop.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            lastErrorString = conn.lastError().text();
            return false;
        }

        selectSpecificHop.next();

        if(selectSpecificHop.value(0).toInt() == 0) {
            // update required
            updateHop.bindValue(":alpha", h.getAlpha());
            updateHop.bindValue(":cost", h.getCostPerU());
            updateHop.bindValue(":stock", h.getStock());
            updateHop.bindValue(":units", h.getUnitsAbrv());
            updateHop.bindValue(":descr", h.getDescription());
            updateHop.bindValue(":storage", h.getStorage());
            updateHop.bindValue(":date", h.getDate().toString());
            updateHop.bindValue(":type", h.getType());
            // where
            updateHop.bindValue(":name", h.getName());

            if(!updateHop.exec()) {
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                lastErrorString = conn.lastError().text();
                return false;
            }
        }

    }

    return true;

}

bool Database::writeHops(QList<Hop *> replacement) {
    hopsDB = replacement;
    return writeHops();
}

bool Database::writeHops() {
        // Name,Alpha,Cost,Stock,Units,Descr,Storage,Date,Modified
    qDebug() << "Write Hops to DB";

    QSqlDatabase conn = connectDB();
    QSqlQuery selectHops(conn);
    selectHops.prepare("SELECT COUNT(*) FROM hops WHERE name = :name;");

    QSqlQuery selectSpecificHop(conn);
    QString sqlQuery = "SELECT COUNT(*) FROM hops WHERE name = :name";
    sqlQuery.append(" AND Alpha=:alpha AND Cost=:cost AND Stock=:stock AND ");
    sqlQuery.append("Units=:units AND Descr=:descr AND Storage=:storage AND Type=:type;");

    selectSpecificHop.prepare(sqlQuery);

    QSqlQuery insertHop(conn);
    sqlQuery.clear();
    sqlQuery.append("insert into hops (Name,Alpha,Cost,Stock,Units,Descr,Storage,Date, Type) ");
    sqlQuery.append("values(:name, :alpha, :cost, :stock, :units, :descr, :storage, :date, :type)");
    insertHop.prepare(sqlQuery);

    QSqlQuery updateHop(conn);
    sqlQuery.clear();
    sqlQuery.append("UPDATE hops SET Alpha=:alpha,Cost=:cost,Stock=:stock,");
    sqlQuery.append("Units=:units,Descr=:descr,Storage=:storage,Date=:date,Type=:type ");
    sqlQuery.append("WHERE name = :name");
    updateHop.prepare(sqlQuery);

    //Sort the list
    sort(hopsDB.begin(), hopsDB.end());

    int i = 0;

    while (i < hopsDB.size()) {
        Hop *h = hopsDB.at(i);

        selectHops.bindValue(":name", h->getName());

        if (!selectHops.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            lastErrorString = conn.lastError().text();
            return false;
        }

        selectHops.next();
        // Does this hop exist?
        if(selectHops.value(0).toInt() == 0){
            insertHop.bindValue(":name", h->getName());
            insertHop.bindValue(":alpha", h->getAlpha());
            insertHop.bindValue(":cost", h->getCostPerU());
            insertHop.bindValue(":stock", h->getStock());
            insertHop.bindValue(":units", h->getUnitsAbrv());
            insertHop.bindValue(":descr", h->getDescription());
            insertHop.bindValue(":storage", h->getStorage());
            insertHop.bindValue(":date", h->getDate());
            insertHop.bindValue(":type", h->getType());

            if (!insertHop.exec()) {
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                lastErrorString = conn.lastError().text();
                return false;
            }
        } else { // check to see if we need to update this hop

            selectSpecificHop.bindValue(":name", h->getName());
            selectSpecificHop.bindValue(":alpha", h->getAlpha());
            selectSpecificHop.bindValue(":cost", h->getCostPerU());
            selectSpecificHop.bindValue(":stock", h->getStock());
            selectSpecificHop.bindValue(":units", h->getUnitsAbrv());
            selectSpecificHop.bindValue(":descr", h->getDescription());
            selectSpecificHop.bindValue(":storage", h->getStorage());
            selectSpecificHop.bindValue(":type", h->getType());


            if(!selectSpecificHop.exec()) {
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                lastErrorString = conn.lastError().text();
                return false;
            }

            selectSpecificHop.next();

            if(selectSpecificHop.value(0).toInt() == 0) {
                // update required
                updateHop.bindValue(":alpha", h->getAlpha());
                updateHop.bindValue(":cost", h->getCostPerU());
                updateHop.bindValue(":stock", h->getStock());
                updateHop.bindValue(":units", h->getUnitsAbrv());
                updateHop.bindValue(":descr", h->getDescription());
                updateHop.bindValue(":storage", h->getStorage());
                updateHop.bindValue(":date", h->getDate().toString());
                updateHop.bindValue(":type", h->getType());
                // where
                updateHop.bindValue(":name", h->getName());

                if(!updateHop.exec()) {
                    qDebug() << conn.lastError().text();

                    QMessageBox msgBox;
                    msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText(conn.lastError().text());
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.exec();
                    lastErrorString = conn.lastError().text();
                    return false;
                }
            }

        }
        i++;
    }

    //clear the list
    hopsDB.clear();
    stockHopsDB.clear();

    readHops();

    return true;
}


bool Database::readYeast() {
    // load from the database
    qDebug() << "Loading Yeast";
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery yeasts(conn);
    yeasts.exec("SELECT * FROM yeast");
    yeastDB.clear();

    if(!yeasts.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        lastErrorString = conn.lastError().text();
        return false;
    }


    int nameCol = yeasts.record().indexOf("Name");
    int costCol = yeasts.record().indexOf("Cost");
    int descrCol = yeasts.record().indexOf("Descr");
    int modifiedCol = yeasts.record().indexOf("Modified");

    while (yeasts.next()) {
        Yeast *y = new Yeast();
        if (yeasts.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        y->setName(yeasts.value(nameCol).toString());

        if (QString::compare(yeasts.value(costCol).toString(), "") != 0)
            y->setCost(yeasts.value(costCol).toDouble());

        y->setDescription(yeasts.value(descrCol).toString());
        if (modifiedCol != -1)
            y->setModified(yeasts.value(modifiedCol).toBool());
        yeastDB.push_back(y);
    }

    qDebug() << "Yeast count: " << yeastDB.size();

    sort(yeastDB.begin(), yeastDB.end(), Yeast::lessThan);

    return true;
}

bool Database::writeYeast(Yeast &y) {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectYeast(conn);
    selectYeast.prepare("SELECT COUNT(*) FROM Yeast WHERE name = :name;");

    QSqlQuery insertYeast(conn);
    insertYeast.prepare("insert into yeast (Name,Cost,Descr) values(:name, :cost, :descr)");

    QSqlQuery updateYeast(conn);
    QString sqlQuery = QString();
    sqlQuery.append("UPDATE yeast SET Cost=:cost,Descr=:descr");
    sqlQuery.append("WHERE name = :name");
    updateYeast.prepare(sqlQuery);
    //Item,Name,Cost,Descr,Modified

    selectYeast.bindValue(":name", y.getName());
    if(!selectYeast.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    selectYeast.next();
    if(selectYeast.value(0).toInt() == 0) {

        insertYeast.bindValue(":name", y.getName());
        insertYeast.bindValue(":cost", y.getCostPerU());
        insertYeast.bindValue(":descr", y.getDescription());

        if(!insertYeast.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }
    } else {
        // Update the current one
        updateYeast.bindValue(":name", y.getName());
        updateYeast.bindValue(":cost", y.getCostPerU());
        updateYeast.bindValue(":descr", y.getDescription());

        if(!updateYeast.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }
    }
    return true;
}

bool Database::writeYeast() {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectYeast(conn);
    selectYeast.prepare("SELECT COUNT(*) FROM Yeast WHERE name = :name;");

    QSqlQuery insertYeast(conn);
    insertYeast.prepare("insert into yeast (Name,Cost,Descr) values(:name, :cost, :descr)");

    // Sort the Yeast
    sort(yeastDB.begin(), yeastDB.end(), Yeast::lessThan);
    int i = 0;
    while (i < yeastDB.size()) {
        //Item,Name,Cost,Descr,Modified
        Yeast *y = yeastDB.at(i);
        i++;
        selectYeast.bindValue(":name", y->getName());
        if(!selectYeast.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }

        selectYeast.next();
        if(selectYeast.value(0).toInt() == 0) {

            insertYeast.bindValue(":name", y->getName());
            insertYeast.bindValue(":cost", y->getCostPerU());
            insertYeast.bindValue(":descr", y->getDescription());

            if(!insertYeast.exec()) {
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();

                lastErrorString = conn.lastError().text();
                return false;
            }
        }
    }
    return false;
}

 bool Database::readStyles(){
    if (!readStyleYears())
        return false;

    QSqlDatabase conn = connectDB();
    QSqlQuery styleList(conn);

    if (!styleList.exec("SELECT * FROM styleguide")) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    QSqlRecord record = styleList.record();
    styleDB.clear();
    qDebug() << "Reading styles";

    int nameCol = record.indexOf("Name");
    int categoryCol = record.indexOf("Category");
    int subcategoryCol = record.indexOf("Subcategory");
    int ogLowCol = record.indexOf("OG_Low");
    int ogHighCol = record.indexOf("OG_High");
    int fgLowCol = record.indexOf("FG_Low");
    int fgHighCol = record.indexOf("FG_High");
    int alcLowCol = record.indexOf("Alc_Low");
    int alcHighCol = record.indexOf("Alc_High");
    int ibuLowCol = record.indexOf("IBU_Low");
    int ibuHighCol = record.indexOf("IBU_High");
    int lovLowCol = record.indexOf("Lov_Low");
    int lovHighCol = record.indexOf("Lov_High");
    int commercialCol = record.indexOf("Comm_examples");
    int yearCol = record.indexOf("Year");
    int commentsCol = record.indexOf("Comments");
    int aromaCol = record.indexOf("Aroma");
    int appearanceCol = record.indexOf("Appearance");
    int mouthfeelCol = record.indexOf("Mouthfeel");
    int impressionCol = record.indexOf("Impression");
    int ingredientsCol = record.indexOf("Ingredients");


    while (styleList.next()) {
        if (styleList.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        Style *s = new Style();
        //Item,Name, Category,OG_Low,OG_High,Alc_Low,Alc_High,IBU_Low,IBU_High,Lov_Low,Lov_High,Comm_examples,Descr
        s->setName(styleList.value(nameCol).toString());
        s->setCategory(styleList.value(categoryCol).toString());
        s->setCatNum(styleList.value(subcategoryCol).toString());
        s->setOgLow(styleList.value(ogLowCol).toDouble());
        s->setOgHigh(styleList.value(ogHighCol).toDouble());
        s->setFgLow(styleList.value(fgLowCol).toDouble());
        s->setFgHigh(styleList.value(fgHighCol).toDouble());
        s->setAlcLow(styleList.value(alcLowCol).toDouble());
        s->setAlcHigh(styleList.value(alcHighCol).toDouble());
        s->setIbuLow(styleList.value(ibuLowCol).toDouble());
        s->setIbuHigh(styleList.value(ibuHighCol).toDouble());
        s->setSrmLow(styleList.value(lovLowCol).toDouble());
        s->setSrmHigh(styleList.value(lovHighCol).toDouble());
        s->setExamples(styleList.value(commercialCol).toString());
        s->setYear(styleList.value(yearCol).toString());
        s->setAroma(styleList.value(aromaCol).toString());
        s->setAppearance(styleList.value(appearanceCol).toString());
        s->setMouthfeel(styleList.value(mouthfeelCol).toString());
        s->setImpression(styleList.value(impressionCol).toString());
        s->setIngredients(styleList.value(ingredientsCol).toString());
        s->setComments(styleList.value(commentsCol).toString());
        s->setComplete();
        styleDB.push_back(s);
    }

    return true;
}

bool Database::readStyleYears() {
    QSqlDatabase conn = connectDB();
    QSqlQuery styleList(conn);
    styleYears.clear();

    if (!styleList.exec("SELECT year FROM styleguide GROUP BY year")) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    while (styleList.next()) {
        styleYears.append(styleList.value(0).toString());
    }

    return false;
}

bool Database::importStyles(QString year) {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectYear(conn);


    qDebug() << "Loading styles for " << year;

    selectYear.prepare("SELECT * FROM styleguide WHERE year = :year");

    selectYear.bindValue(":year", year);

    if(!selectYear.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }
    //Item,Name, Category, OG_Low, OG_High, IBU_Low, IBU_High, Lov_Low, Lov_High,"
    //Appearance, Aroma, Flavor, Mouthfeel, Impression, Comments, Ingredients, Year
    QSqlRecord record = selectYear.record();

    int nameCol = record.indexOf("Name");
    int categoryCol = record.indexOf("Category");
    int catNumCol = record.indexOf("Subcategory");
    int ogLowCol = record.indexOf("OG_Low");
    int ogHighCol = record.indexOf("OG_High");
    int fgLowCol = record.indexOf("FG_Low");
    int fgHighCol = record.indexOf("FG_High");
    int alcLowCol = record.indexOf("Alc_Low");
    int alcHighCol = record.indexOf("Alc_High");
    int ibuLowCol = record.indexOf("IBU_Low");
    int ibuHighCol = record.indexOf("IBU_High");
    int lovLowCol = record.indexOf("Lov_Low");
    int lovHighCol = record.indexOf("Lov_High");
    int commercialCol = record.indexOf("Comm_examples");
    int appearanceCol = record.indexOf("Appearance");
    int aromaCol = record.indexOf("Aroma");
    int flavourCol = record.indexOf("Flavour");
    // check alt spelling of flavour
    if (flavourCol == -1) {
        flavourCol = record.indexOf("Flavor");
    }
    int mouthfeelCol = record.indexOf("Mouthfeel");
    int impressionCol = record.indexOf("Impression");
    int commentsCol = record.indexOf("Comments");
    int ingredientsCol = record.indexOf("Ingredients");

    while(selectYear.next()) {
        Style *s = new Style();

        s->setName(selectYear.value(nameCol).toString());
        s->setCategory(selectYear.value(categoryCol).toString());
        s->setCatNum(selectYear.value(catNumCol).toString());
        s->setOgLow(selectYear.value(ogLowCol).toDouble());
        s->setOgHigh(selectYear.value(ogHighCol).toDouble());
        s->setFgLow(selectYear.value(fgLowCol).toDouble());
        s->setFgHigh(selectYear.value(fgHighCol).toDouble());
        s->setAlcLow(selectYear.value(alcLowCol).toDouble());
        s->setAlcHigh(selectYear.value(alcHighCol).toDouble());
        s->setIbuLow(selectYear.value(ibuLowCol).toDouble());
        s->setIbuHigh(selectYear.value(ibuHighCol).toDouble());
        s->setSrmLow(selectYear.value(lovLowCol).toDouble());
        s->setSrmHigh(selectYear.value(lovHighCol).toDouble());
        s->setExamples(selectYear.value(commercialCol).toString());
        s->setAppearance(selectYear.value(appearanceCol).toString());
        s->setAroma(selectYear.value(aromaCol).toString());
        s->setFlavour(selectYear.value(flavourCol).toString());
        s->setMouthfeel(selectYear.value(mouthfeelCol).toString());
        s->setImpression(selectYear.value(impressionCol).toString());
        s->setComments(selectYear.value(commentsCol).toString());
        s->setIngredients(selectYear.value(ingredientsCol).toString());

//		qDebug() << "Adding style " + s->getName() + s->toText());
        s->setComplete();
        styleDB.push_back(s);
    }

    selectYear.clear();

    qDebug() << "Loaded Styles" << styleDB.size();

    return true;
}

bool Database::readMisc() {
    // Get the fields from the database
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectMisc(conn);

    qDebug() << "Loading misc ingredients";


    if(!selectMisc.exec("SELECT * FROM misc;")){
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    miscDB.clear();

    int nameCol = selectMisc.record().indexOf("Name");
    int costCol = selectMisc.record().indexOf("Cost");
    int descrCol = selectMisc.record().indexOf("Descr");
    int unitsCol = selectMisc.record().indexOf("Units");
    int stageCol = selectMisc.record().indexOf("Stage");
    int modifiedCol = selectMisc.record().indexOf("Modified");

    // get the first line and set up the index:
    while(selectMisc.next()) {
        if (selectMisc.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        Misc *m = new Misc();

        m->setName(selectMisc.value(nameCol).toString());
        m->setCost(selectMisc.value(costCol).toDouble());
        m->setDescription(selectMisc.value(descrCol).toString());
        m->setUnits(selectMisc.value(unitsCol).toString());
        m->setStage(selectMisc.value(stageCol).toString());
        m->setModified(selectMisc.value(modifiedCol).toBool());

        miscDB.push_back(m);
    }

    qDebug() << "Loaded Misc ingredients " << miscDB.size();

    return true;
}

bool Database::writeMisc() {
    qDebug() << "Write misc called";
    QSqlDatabase conn = connectDB();
    QSqlQuery selectMisc(conn);
    selectMisc.prepare("SELECT COUNT(*) FROM misc WHERE name = :name;");

    QSqlQuery insertMisc(conn);
    insertMisc.prepare("insert into misc (Name,Descr,Stock,Units,Cost,Stage)"
                       "values(:name, :descr, :stock, :units, :cost, :stage  )");

    int i = 0;

    while (i < miscDB.size()) {
        Misc *m = miscDB.at(i);
        selectMisc.bindValue(":name", m->getName());

        if (!selectMisc.exec()){
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }

        selectMisc.next();
        if(selectMisc.value(0).toInt() == 0) {
            //Name,Descr,Stock,Units,Cost,Stage

            insertMisc.bindValue(":name", m->getName());
            insertMisc.bindValue(":cost", m->getCostPerU());
            insertMisc.bindValue(":descr", m->getDescription());
            insertMisc.bindValue(":units", m->getUnitsAbrv());
            insertMisc.bindValue(":stage", m->getStage());
            insertMisc.bindValue(":stock", m->getStock());

            if(!insertMisc.exec()) {
                qDebug() << conn.lastError().text();

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText(conn.lastError().text());
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();

                lastErrorString = conn.lastError().text();
                return false;
            }

        }

        i++;
    }

    return true;
}


bool Database::writeMisc(Misc &m) {
    qDebug() << "Write misc called";
    QSqlDatabase conn = connectDB();
    QSqlQuery selectMisc(conn);
    selectMisc.prepare("SELECT COUNT(*) FROM misc WHERE name = :name;");

    QSqlQuery insertMisc(conn);
    insertMisc.prepare("insert into misc (Name,Descr,Stock,Units,Cost,Stage)"
                       "values(:name, :descr, :stock, :units, :cost, :stage  )");

    QSqlQuery updateMisc(conn);
    QString updateSQL = "UPDATE misc SET Descr=:descr, Stock=:stock,Units=:units,";
    updateSQL.append("Cost=:cost,Stage=:stage ");
    updateSQL.append("WHERE Name=:name");


    selectMisc.bindValue(":name", m.getName());

    if (!selectMisc.exec()){
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    selectMisc.next();
    if(selectMisc.value(0).toInt() == 0) {
        //Name,Descr,Stock,Units,Cost,Stage

        insertMisc.bindValue(":name", m.getName());
        insertMisc.bindValue(":cost", m.getCostPerU());
        insertMisc.bindValue(":descr", m.getDescription());
        insertMisc.bindValue(":units", m.getUnitsAbrv());
        insertMisc.bindValue(":stage", m.getStage());
        insertMisc.bindValue(":stock", m.getStock());

        if(!insertMisc.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }

    } else {
        updateMisc.bindValue(":name", m.getName());
        updateMisc.bindValue(":cost", m.getCostPerU());
        updateMisc.bindValue(":descr", m.getDescription());
        updateMisc.bindValue(":units", m.getUnitsAbrv());
        updateMisc.bindValue(":stage", m.getStage());
        updateMisc.bindValue(":stock", m.getStock());

        if(!updateMisc.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }
    }

    return true;
}

bool Database::writePrimeSugar(PrimeSugar &p) {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectPrime(conn);
    selectPrime.prepare("SELECT COUNT(*) FROM prime WHERE name = :name;");


    QSqlQuery insertPrime(conn);
    insertPrime.prepare("insert into prime (Name,Yield,Stock,Units,Cost,Descr)"
                       "values(:name, :yield, :stock, :units, :cost, :descr)");

    QSqlQuery updatePrime(conn);
    QString updateSQL = "UPDATE prime SET Descr=:descr, Stock=:stock,Units=:units,";
    updateSQL.append("Cost=:cost,Yield=:yield");
    updateSQL.append("WHERE Name=:name");

    selectPrime.bindValue(":name", p.getName());
    if(!selectPrime.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    selectPrime.next();
    if (selectPrime.value(0).toInt() == 0) {
        // Insert
        insertPrime.bindValue(":name", p.getName());
        insertPrime.bindValue(":yield", p.getYield());
        insertPrime.bindValue(":stock", p.getStock());
        insertPrime.bindValue(":units", p.getUnits());
        insertPrime.bindValue(":cost", p.getCostPerU());
        insertPrime.bindValue(":descr", p.getDescription());

        if(!insertPrime.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }
    } else {
        // Update
        updatePrime.bindValue(":name", p.getName());
        updatePrime.bindValue(":yield", p.getYield());
        updatePrime.bindValue(":stock", p.getStock());
        updatePrime.bindValue(":units", p.getUnits());
        updatePrime.bindValue(":cost", p.getCostPerU());
        updatePrime.bindValue(":descr", p.getDescription());

        if(!updatePrime.exec()) {
            qDebug() << conn.lastError().text();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(conn.lastError().text());
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            lastErrorString = conn.lastError().text();
            return false;
        }
    }

    // loop the results

    return true;
}

bool Database::readPrimeSugar() {
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectPrime(conn);
    selectPrime.prepare("SELECT * FROM prime;");

    if(!selectPrime.exec()) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    int nameCol = selectPrime.record().indexOf("Name");
    int yieldCol = selectPrime.record().indexOf("Yield");
    int unitsCol = selectPrime.record().indexOf("Units");
    int descrCol = selectPrime.record().indexOf("Descr");

    primeSugarDB.clear();
    // loop the results
    while(selectPrime.next()) {
        if (selectPrime.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        PrimeSugar *p = new PrimeSugar();

        p->setName(selectPrime.value(nameCol).toString());
        p->setYield(selectPrime.value(yieldCol).toDouble());
        p->setUnits(selectPrime.value(unitsCol).toString());
        p->setAmount(0);
        p->setDescription(selectPrime.value(descrCol).toString());
        primeSugarDB.push_back(p);
    }
    qDebug() << "Prime Found " << primeSugarDB.size();

    return true;
}

bool Database::readWater() {
    qDebug() << "Reading Water";
    // Now read the Database out
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectWater(conn);

    if (!selectWater.exec("SELECT * FROM water_profiles;")) {
        qDebug() << conn.lastError().text();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(conn.lastError().text());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        lastErrorString = conn.lastError().text();
        return false;
    }

    waterDB.clear();
    QSqlRecord waterRecord = selectWater.record();

    int nameCol = waterRecord.indexOf("Name");
    int descrCol = waterRecord.indexOf("Descr");
    int caCol = waterRecord.indexOf("Ca");
    int mgCol = waterRecord.indexOf("Mg");
    int naCol = waterRecord.indexOf("Na");
    int so4Col = waterRecord.indexOf("SO4");
    int hco3Col = waterRecord.indexOf("HCO3");
    int clCol = waterRecord.indexOf("Cl");
    int hardnessCol = waterRecord.indexOf("Hardness");
    int tdsCol = waterRecord.indexOf("TDS");
    int phCol = waterRecord.indexOf("PH");
    int alkCol = waterRecord.indexOf("Alk");

    while(selectWater.next() ) {
        if (selectWater.value(nameCol).toString().compare("") == 0) {
            continue;
        }

        //Name,Descr,Ca,Mg,Na,SO4,HCO3,Cl,Hardness,TDS,PH,Alk
        WaterProfile *w = new WaterProfile();
        w->setName(selectWater.value(nameCol).toString());
        w->setDescription(selectWater.value(descrCol).toString());
        w->setCa(selectWater.value(caCol).toDouble());
        w->setMg(selectWater.value(mgCol).toDouble());
        w->setNa(selectWater.value(naCol).toDouble());
        w->setSo4(selectWater.value(so4Col).toDouble());
        w->setHco3(selectWater.value(hco3Col).toDouble());
        w->setCl(selectWater.value(clCol).toDouble());
        w->setHardness(selectWater.value(hardnessCol).toDouble());
        w->setTds(selectWater.value(tdsCol).toDouble());
        w->setPh(selectWater.value(phCol).toDouble());
        w->setAlkalinity(selectWater.value(alkCol).toDouble());

        waterDB.push_back(w);
    }


    qDebug() << "Read all water";

    return true;
}

QStringList Database::getPrimeSugarNameList() {
    QStringList names;

    for (int i = 0; i < primeSugarDB.size(); i++) {
        names.append(primeSugarDB.at(i)->getName());
    }

    return names;
}

QStringList Database::getMashProfileNames() {
    qDebug() << "Reading Mash profiles";
    // Now read the Database out
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectMashProfiles(conn);
    QStringList retVal;

    if (!selectMashProfiles.exec("SELECT distinct Name FROM mash_profiles ORDER BY Name ASC")
            || selectMashProfiles.size() == 0) {
        qDebug() << "Couldn't get mash profile details: " << conn.lastError().text();
        qDebug() << selectMashProfiles.executedQuery();
        return retVal;
    }
    qDebug() << "Profile results: " << selectMashProfiles.size();

    while (selectMashProfiles.next()) {
        qDebug() << selectMashProfiles.value(0).toString();
        retVal << selectMashProfiles.value(0).toString();
    }

    return retVal;
}

bool Database::setMashProfile(Mash *mash, QString name) {
    qDebug() << "Reading Mash profiles";
    // Now read the Database out
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery selectMashProfiles(conn);
    QString sql = "SELECT * FROM mash_profiles WHERE Name = '" + name + "' ORDER BY Step ASC";
    selectMashProfiles.prepare(sql);
    if(!selectMashProfiles.exec()
            || selectMashProfiles.size() == 0) {
        qDebug() << "Couldn't get mash profile details: " << selectMashProfiles.lastError().text();
        qDebug() << selectMashProfiles.executedQuery();
        lastErrorString = conn.lastError().text();
        return false;

     }

    if (selectMashProfiles.size() == 0) {
        lastErrorString = "No mash steps found for this profile " + name;
        return false;
    }

    // Set the steps and add if needed
    mash->disableRecalcs();
    mash->setName(name);

    QSqlRecord mashRecord = selectMashProfiles.record();
    int startTempCol = mashRecord.indexOf("StartTempF");
    int endTempCol = mashRecord.indexOf("EndTempF");
    int timeCol = mashRecord.indexOf("Time");
    int methodCol = mashRecord.indexOf("Method");

    mash->clear();

    int i = 0;
    while(selectMashProfiles.next()) {

        if (i <= mash->getStepSize()) {
            mash->addStep();
        }
        mash->setStepStartTemp(i, selectMashProfiles.value(startTempCol).toInt());
        mash->setStepEndTemp(i, selectMashProfiles.value(endTempCol).toInt());
        mash->setStepMin(i, selectMashProfiles.value(timeCol).toInt());
        mash->setStepMethod(i, selectMashProfiles.value(methodCol).toString());
        i++;
    }
    mash->enableRecalcs();
    mash->calcMashSchedule();

    return true;
}

bool Database::addMashProfile(Mash *mash, QString name) {
    // First delete anything in the current database that matches the mash profile
    if (name == "" || name == "Default") {
        qDebug() << "No custom mash name specified";
        return false;
    }
    qDebug() << "Deleting Mash profile " + name;
    // Now read the Database out
    QSqlDatabase conn = QSqlDatabase::database(dbName);
    QSqlQuery mashQuery(conn);
    mashQuery.prepare("DELETE FROM mash_profiles WHERE Name = :name");
    mashQuery.bindValue(":name", name);
    if( !mashQuery.exec()) {
        qDebug() << "Couldn't delete mash profile details: " << mashQuery.lastError().text();
        qDebug() << mashQuery.executedQuery();
        lastErrorString = conn.lastError().text();
        return false;
    }


    QString insert = "INSERT INTO mash_profiles (Name, Step, StartTempF, EndTempF, Time, Method) "
            "VALUES(:name, :step, :startTempF, :endTempF, :time, :method);";
    mashQuery.prepare(insert);

    // Loop the current mash profile and save it
    for (int i = 0; i < mash->getStepSize(); i++) {
        mashQuery.bindValue(":name", mash->getName());
        mashQuery.bindValue(":step", i);
        mashQuery.bindValue(":startTempF", mash->getStepStartTempF(i));
        mashQuery.bindValue(":endTempF", mash->getStepEndTempF(i));
        mashQuery.bindValue(":time", mash->getStepMin(i));
        mashQuery.bindValue(":method", mash->getStepMethod(i));

        if (!mashQuery.exec()) {
            qDebug() << "Couldn't add mash profile step to DB: " + conn.lastError().text();
            qDebug() << mashQuery.executedQuery();

            lastErrorString = conn.lastError().text();
            return false;
        }
    }

    return true;
}

PrimeSugar *Database::findSugar(QString name) {
    if (primeSugarDB.size() == 0) {
        return NULL;
    }
    for (int i = 0; i < primeSugarDB.size(); i++) {
        if (primeSugarDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return primeSugarDB[i];
        }
    }
    return NULL;
}

Hop* Database::findHop(QString name) {
    if (hopsDB.size() == 0) {
        Database::readDB("");
        return NULL;
    }
    for (int i = 0; i < hopsDB.size(); i++) {
        if (hopsDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return hopsDB[i];
        }
    }
    return NULL;
}

Fermentable *Database::findFermentable(QString name) {
    if (fermDB.size() == 0) {
        return NULL;
    }
    for (int i = 0; i < fermDB.size(); i++) {
        if (fermDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return fermDB[i];
        }
    }

    return NULL;

}

Yeast* Database::findYeast(QString name) {
    if (yeastDB.size() == 0) {
        return NULL;
    }
    for (int i = 0; i < yeastDB.size(); i++) {
        if (yeastDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return yeastDB[i];
        }
    }
    return NULL;

}

Misc *Database::findMisc(QString name) {
    if (miscDB.size() == 0) {
        return NULL;
    }

    for (int i = 0; i < miscDB.size(); i++) {
        if (miscDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return miscDB[i];
        }
    }

    return NULL;
}

Style *Database::findStyle(QString name) {
    if (styleDB.size() == 0) {
        return NULL;
    }

    for (int i = 0; i < styleDB.size(); i++) {
        if (styleDB[i]->getName().compare(name, Qt::CaseInsensitive) == 0) {
            return styleDB[i];
        }
    }

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Couldn't find Style '" + name + "'"
                   "Please find a matching one in the Style List");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
    return NULL;
}

bool loadRRecipes() {
    qDebug() << "Loading Remote Recipes called NOT IMPLEMENTED";
    // Reads the list of recipes on the remote Database
    /*
    try
    {

        String baseURL = Options.getInstance().getProperty("cloudURL");
        URI rURI = new URI("http", null, baseURL, 80, "/recipes/", null, null);
        qDebug() << "Trying to access: " + rURI.toString());
        URL url = rURI.toURL();
        InputStream response = url.openStream();
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

        dbf.setValidating(false);
        dbf.setIgnoringComments(false);
        dbf.setIgnoringElementContentWhitespace(true);
        dbf.setNamespaceAware(true);
        // dbf.setCoalescing(true);
        // dbf.setExpandEntityReferences(true);

        DocumentBuilder db = null;
        db = dbf.newDocumentBuilder();
        //db.setEntityResolver(new NullResolver());

        // db.setErrorHandler( new MyErrorHandler());

        Document readXML = db.parse(response);


        NodeList childNodes = readXML.getChildNodes();

        qDebug() << "Found: " + childNodes.getLength() + "Recipes " + childNodes.item(0).getNodeName());
        // check that we have a valid first node recipe
        if(childNodes.item(0).getNodeName().equals("recipes")){
            return true;
        }

        qDebug() << "False");
        return false;

        for(int x = 0; x < childNodes.getLength(); x++ ) {


            Node child = childNodes.item(x);

            NamedNodeMap childAttr = child.getAttributes();

            childAttr.getNamedItem("id");



        }

    */
    return true;
}
