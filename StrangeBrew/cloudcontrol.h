#ifndef CLOUDCONTROL_H
#define CLOUDCONTROL_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QSettings>
#include <QProgressDialog>
#include <QMessageBox>
#include <QObject>

#include "recipe.h"

class CloudControl: public QObject
{
    Q_OBJECT
public:
    explicit CloudControl(QObject *parent = 0);
    void UploadRecipe(Recipe *recipe, QWidget *parent=0);

    QString getBaseURL();
private:
    QProgressDialog *uploadProgress;
    QNetworkAccessManager *networkManager;

private slots:
    void slotError(QNetworkReply::NetworkError e);
    void uploadComplete(QNetworkReply *reply);
    void uploadingData(qint64 bytesSent, qint64 bytesTotal);
    void uploadCancelled();
};

#endif // CLOUDCONTROL_H
