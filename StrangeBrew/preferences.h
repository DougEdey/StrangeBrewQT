#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>

#include "constants.h"
#include "brewcalcs.h"
#include "database.h"

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();

    void updateUI();
    void updateCalculations();
    void updateCostCarb();
    void updateBrewer();
    void updateStyle();
    void updateAppearance();
    void updateColourBoxes();
    void updateNewRecipe();

    void loadSettings();
    void saveSettings();
private slots:
    void on_tinsethRadio_clicked();

    void on_garetzRadio_clicked();

    void on_ragerRadio_clicked();

    void on_alcVolRadio_clicked();

    void on_alcWeightRadio_clicked();

    void on_ebcRadio_clicked();

    void on_srmRadio_clicked();

    void on_evapConsRadio_clicked();

    void on_evapPercRadio_clicked();

    void on_evapRateSpin_editingFinished();

    void on_pelletHopsSpin_editingFinished();

    void on_tinsethSpin_editingFinished();

    void on_drySpin_editingFinished();

    void on_FWHSpin_editingFinished();

    void on_mashSpin_editingFinished();

    void on_kettLossSpin_editingFinished();

    void on_miscLossSpin_editingFinished();

    void on_trubLossSpin_editingFinished();

    void on_otherCostSpin_editingFinished();

    void on_bottleSizeSpin_editingFinished();

    void on_bottleUnitCombo_currentIndexChanged(const QString &newSize);

    void on_primeSugarCombo_currentIndexChanged(const QString &sugar);

    void on_sugarUnitsCombo_currentIndexChanged(const QString &newUnits);

    void on_servTempSpin_editingFinished();

    void on_carbUnitF_clicked();

    void on_carbUnitC_clicked();

    void on_bottleTempSpin_editingFinished();

    void on_faucHeightSpin_editingFinished();

    void on_targetCO2Spin_editingFinished();

    void on_tubingIDCombo_currentIndexChanged(const QString &newID);

    void on_keggedCheck_clicked();

    void on_nameEdit_editingFinished();

    void on_phoneEdit_editingFinished();

    void on_clubEdit_editingFinished();

    void on_emailEdit_editingFinished();

    void on_pushButton_clicked();

    void on_efficiencySpin_editingFinished();

    void on_attenuationSpin_editingFinished();

    void on_bjcpYearCombo_currentIndexChanged(const QString &newYear);

    void on_method1Radio_clicked();

    void on_method2Radio_clicked();

    void on_redSpin_editingFinished();

    void on_greenSpin_editingFinished();

    void on_blueSpin_editingFinished();

    void on_alphaSpin_editingFinished();

    void on_maltUnitCombo_currentIndexChanged(const QString &newU);

    void on_hopUnitsCombo_currentIndexChanged(const QString &arg1);

    void on_volumeCombo_currentIndexChanged(const QString &arg1);

    void on_batchSizeSpin_editingFinished();

    void on_boilTimeSpin_editingFinished();

    void on_mashVolCombo_currentIndexChanged(const QString &arg1);

    void on_mashTempF_clicked();

    void on_mashTempC_clicked();

    void on_boilTempSpin_editingFinished();

    void on_mashRatioSpin_editingFinished();

    void on_deadSpaceSpin_editingFinished();

    void on_mashRatioCombo_currentIndexChanged(const QString &arg1);

    void on_hopTypeCombo_activated(const QString &arg1);

    void on_waterProfileCombo_currentIndexChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::Preferences *ui;

    QString cloudURL;
    QString ibuCalcMethod;
    QString alcCalcMethod;
    QString evapCalcMethod;
    QString colourMethod;
    int efficiency;
    int attenuation;
    double evaporation;
    double pelletPct;
    int dryHopTime;
    int fwhHopTime;
    int mashHopTime;
    double hopsUtil;
    QString hopForm;

    // losses from various areas
    double kettleLoss;
    double trubLoss;
    double miscLoss;

    // Recipe Stuff
    QString sizeU;
    QString maltU;
    QString hopsU;
    int boilTime;
    double postBoil;
    double preBoil;
    QString hopsType;
    QString waterProfile;

    // Colour
    int red, green, blue, alpha, rgbMethod;
    // cost
    double miscCost;

    // brewer preferences
    QString name, phone, street, city, state, code, club, country, email, recipeDIR;

    // Carbonation
    bool kegged;
    QString primeSugar, sugarU, bottleU, carbTempU, tubingID;
    double volsCO2, faucHeight;
    int bottleSize, bottleTempF, servTempF;

    // Mash Details
    QString mashTempU, mashVolU, mashRatioU;
    double mashRatio, thinDecoctRatio, thickDecoctRatio, deadSpace;
    int grainTempF, tunLossF, boilTempF, mashAcidF, mashBetaF, mashGlucanF,
        mashProteinF, mashAlphaF, mashoutTempF, spargeTempF, mashCerealF;
    QString style;
};

#endif // PREFERENCES_H
