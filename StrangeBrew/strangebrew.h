#ifndef STRANGEBREW_H
#define STRANGEBREW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QSettings>
#include <QMenu>
#include <QRadioButton>
#include <QTextStream>
#include <QClipboard>

#include "ui_strangebrew.h"
#include "preferences.h"
#include "importxml.h"
#include "recipe.h"
#include "remoterecipes.h"

#include "newfermentable.h"
#include "newhop.h"
#include "newyeast.h"
#include "newmisc.h"
#include "newprimesugar.h"

#include "hopsmodel.h"
#include "maltmodel.h"
#include "stylemodel.h"
#include "miscmodel.h"
#include "notesmodel.h"
#include "mashmodel.h"
#include "fermmodel.h"

#include "maltitemdelegate.h"
#include "hopitemdelegate.h"
#include "miscitemdelegate.h"
#include "mashitemdelegate.h"
#include "fermitemdelegate.h"

#include "tool_dialogs/resizerecipe.h"
#include "tool_dialogs/refracttool.h"
#include "tool_dialogs/maltpercentdialog.h"
#include "tool_dialogs/conversiontool.h"
#include "tool_dialogs/extractdialog.h"
#include "tool_dialogs/hydrodialog.h"

namespace Ui {
class StrangeBrew;
}

class StrangeBrew : public QMainWindow
{
    Q_OBJECT
    HopsModel *hModel;
    MaltModel *mModel;
    StyleModel *sModel;
    MiscModel *miscModel;
    NotesModel *notesModel;
    MashModel *mashModel;
    FermModel *fermModel;
    QList<Style*> styleMatches;

    MaltItemDelegate *mcbid;
    MiscItemDelegate *miscid;
    MashItemDelegate *mashid;
    FermItemDelegate *fermid;
    HopItemDelegate *hcbid;

    ImportXML *recipeXML;

public:
    explicit StrangeBrew(QWidget *parent = 0);
    ~StrangeBrew();

    QString checkFileType(QString fileName);
    void updateUI();



    void updateTopUI();
    QList<Style*> getStyleMatches();
    void updateStylePanel();
    void focusLostOnComments(const QFocusEvent &event);
    bool eventFilter(QObject *object, QEvent *event);
    void updateMashDetails();
    void setupProfileMenu();
    void carbSettingsUpdated();
    void updateCarbPanel();
    void waterSettingsUpdated();
    void updateWaterPanel();
    void updateCostPanel();
    void updateSettingsPanel();
    void saveFile(bool force);
private slots:
    void openFile(QString fileName="");
    void hopsUpdated(const QModelIndex &from, const QModelIndex &to);
    void maltUpdated(const QModelIndex &from, const QModelIndex &to);
    void updateTopUI(const QModelIndex &from, const QModelIndex &to);
    void mashUpdated(const QModelIndex &from, const QModelIndex &to);
    void mashSettingsUpdated();
    void setMashProfile();
    void saveMashProfile();

    void boilUnitsUpdated(const QString &newUnits);

    void on_addMalt_clicked();
    void on_deleteMalt_clicked();

    void on_addHop_clicked();
    void on_deleteHop_clicked();

    void on_stylesList_activated(const QModelIndex &index);

    void on_miscIngredientsList_clicked(const QModelIndex &index);
    void on_addMisc_clicked();
    void on_delMisc_clicked();

    void on_notesList_clicked(const QModelIndex &index);
    void on_addNote_clicked();
    void on_delNote_clicked();

    void on_notesList_activated(const QModelIndex &index);

    void on_addMashStep_clicked();

    void on_delMashStep_clicked();

    void on_addFermStep_clicked();

    void on_delFermStep_clicked();

    void on_alcoholCombo_currentIndexChanged(const QString &arg1);

    void on_ibuCombo_currentIndexChanged(const QString &arg1);

    void on_colourCombo_currentIndexChanged(const QString &arg1);

    void on_evapType_currentIndexChanged(const QString &arg1);

    void on_costYeastSpin_editingFinished();

    void on_bottleSizeSpin_editingFinished();

    void on_bottleSizeUnit_currentIndexChanged(const QString &arg1);

    void on_costOtherSpin_editingFinished();

    void on_thinDecoctSpin_editingFinished();

    void on_thickDecoctSpin_editingFinished();

    void on_mashoutTempValue_editingFinished();

    void on_spargeTempValue_editingFinished();

    void on_addIBUValue_editingFinished();

    void on_actionPreferences_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_brewerEdit_editingFinished();

    void on_efficiencySpin_editingFinished();

    void on_efficiencySpin_valueChanged(int arg1);

    void on_attenuationSpin_valueChanged(int arg1);

    void on_dateTimeEdit_dateChanged(const QDate &date);

    void on_styleCombo_currentIndexChanged(const QString &arg1);

    void on_yeastCombo_currentIndexChanged(const QString &arg1);

    void on_preBoilSpin_editingFinished();

    void on_postBoilSpin_editingFinished();

    void on_boilVolumeUnitsCombo_currentIndexChanged(const QString &arg1);

    void on_boilTimeSpin_editingFinished();

    void on_evapSpin_valueChanged(double arg1);

    void on_ogSpin_editingFinished();

    void on_fgSpin_editingFinished();

    void on_actionCopy_to_Clipboard_triggered();

    void on_actionNew_Fermentable_triggered();

    void on_actionNew_Misc_triggered();

    void on_actionNew_Hop_triggered();

    void on_actionNew_Yeast_triggered();

    void on_actionNew_Prime_Sugar_triggered();

    void on_actionResize_Convert_triggered();

    void on_actionRefractometer_triggered();

    void on_actionMalt_Percent_triggered();

    void on_actionExtract_Tool_triggered();

    void on_actionHydrometer_triggered();

    void on_actionConversion_triggered();

    void recipeDownloaded();
    void on_actionBrowse_triggered();

    void on_actionUpload_triggered();

private:
    QSettings *preferences;
    Recipe *currentRecipe;
    Ui::StrangeBrew *ui;
    void setupConnections();

};

#endif // STRANGEBREW_H
