#ifndef REMOTERECIPES_H
#define REMOTERECIPES_H

#include <QDialog>
#include <QDomDocument>
#include <QCompleter>

//#include <QXmlContentHandler>
//#include <QXmlSimpleReader>

#include "cloudcontrol.h"
#include "recipemodel.h"
#include "BasicRecipe.h"
#include "importxml.h"

namespace Ui {
class RemoteRecipes;
}

class RemoteRecipes : public QDialog
{
    Q_OBJECT
    RecipeModel *rModel;
    QList<basicRecipe> data_list;
    QStringList brewerList;
    QCompleter *brewerCompleter;
    QString recipeFileName;

public:
    explicit RemoteRecipes(QWidget *parent = 0);
    ~RemoteRecipes();

    QList<basicRecipe> recipeList;
    QNetworkAccessManager *networkManager;

    void listRecipesByStyle(QString style);
    void getRecipeStyles();
    QString getBaseURL();
    void getRecipeBrewers();
    void listRecipesByBrewer(QString brewer);
    QString getRecipeFileName();
protected slots:
    void recipeDownloaded();
    void stylesDownloaded();
private slots:
    void on_styleCombo_currentIndexChanged(const QString &style);

    void listRecipesDownloaded();
    void brewersDownloaded();
    void on_brewerCombo_currentIndexChanged(const QString &brewer);
    void on_downloadButton_clicked();

private:
    Ui::RemoteRecipes *ui;
};


#endif // REMOTERECIPES_H
