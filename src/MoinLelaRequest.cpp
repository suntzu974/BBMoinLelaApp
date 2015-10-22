/*
 * Copyright (c) 2011-2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "MoinLelaRequest.hpp"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <bb/system/SystemToast>
#include <bb/data/JsonDataAccess>
#include <QMap>
#include <QHash>
#include <bb/cascades/Image>
#include <QFile>
#include <bb/utility/ImageConverter>


using namespace bb::system;
using namespace bb::data;
using namespace bb::cascades;

MoinLelaRequest::MoinLelaRequest(QObject *parent)
    : QObject(parent),
      m_active(false),
      m_logged(false),
      m_model(new GroupDataModel(QStringList() << "id", this)),
      m_settings(new AppSettings())
{
    m_model->setGrouping(ItemGrouping::None);
    if(!m_settings->token().isEmpty()) {
       m_logged = true;
       emit loggedChanged();
       qDebug() << "Logged :" << logged();
    }
    else
        qDebug() << "MARCHE PAS";
}
void MoinLelaRequest::requestLogout(const QString &token) {
    m_settings = new AppSettings();
    m_settings->clearUserInfo();

    if (m_settings->token().isEmpty()) {
        m_logged = false;
        emit loggedChanged();
    }
    else {
        m_logged = true;
        emit loggedChanged();
    }
    qDebug() << "Logout new :" << m_settings->token() << "Old token :" << token;

}
bool MoinLelaRequest::isAuthenticated() {
    m_settings = new AppSettings();

    if (m_settings->token().isEmpty()) {
        m_dialog = new SystemDialog("OK");
        m_dialog->setTitle("Authentification");
        m_dialog->setBody("Veuillez vous authentifier");
        m_dialog->setEmoticonsEnabled(true);
        bool success = connect(m_dialog,
        SIGNAL(finished(bb::system::SystemUiResult::Type)),
                 this,
                 SLOT(onDialogFinished(bb::system::SystemUiResult::Type)));
        if (success) {
                // Signal was successfully connected
                // Now show the dialog box in your UI

                m_dialog->show();
        } else {
                // Failed to connect to signal
                m_dialog->deleteLater();
        }
        return false;
    }
    else
        return true;
}
void MoinLelaRequest::onDialogFinished(bb::system::SystemUiResult::Type type)
{
    if (type == SystemUiResult::ConfirmButtonSelection)
    {
        qDebug() << "Dialog Accepted:";
        // The user accepted the dialog
    }
    else {
        qDebug() << "Dialog Rejected";
        // The user rejected the dialog
        m_dialog->deleteLater();
    }
}
void MoinLelaRequest::reset()
{
    mBudget.clear();
    mService.clear();
    mQuality.clear();
    mPrivacy.clear();
    mAmbience.clear();
    mItemName.clear();
    mItemLabel.clear();
    mItemCountry.clear();
    mItemRegion.clear();
    mItemZipcode.clear();
    mItemTown.clear();
    mItemAddress.clear();
    mItemPhone.clear();
    mItemMobile.clear();

    emit budgetChanged();
    emit serviceChanged();
    emit qualityChanged();
    emit privacyChanged();
    emit ambienceChanged();
    emit itemNameChanged();
    emit itemLabelChanged();
    emit itemCountryChanged();
    emit itemRegionChanged();
    emit itemZipcodeChanged();
    emit itemTownChanged();
    emit itemAddressChanged();
    emit itemPhoneChanged();
    emit itemMobileChanged();

}

// ![0.10]
void MoinLelaRequest::requestRegister(const QString &email, const QString &name,const QString &password)
{
    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
    const QString queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/registrations.json");
    QNetworkRequest request(queryUri);
    request.setRawHeader("User-Agent", "MoinLela v1.0");
    request.setRawHeader("X-Custom-User-Agent", "MoinLela v1.0");
    request.setRawHeader("Content-Type", "application/json");
    // Assemble Request
    QByteArray mRequestJson;
    QString mUserEmail = email;
    QString mUserName = name;
    QString mUserPassword= password;
    QVariantMap userSession,userRoot;

    userSession["email"] = email.toUtf8();
    userSession["name"] = name.toUtf8();
    userSession["password"] = password.toUtf8();
    userSession["confirm_password"] = password.toUtf8();
    userRoot["user"] = userSession;
    // Add each employee to a QVariantList, and then wrap it in a QVariant
    QVariant myData = QVariant(QVariant(userRoot));
    bb::data::JsonDataAccess jda;
    jda.saveToBuffer(myData, &mRequestJson);

    //
    m_active = true;
        emit activeChanged();

    qDebug() << "request Json :" << mRequestJson;
    QNetworkReply* reply = networkAccessManager->post(request,mRequestJson);
    bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onMoinLelaReply()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);

}
void MoinLelaRequest::requestAuthentication(const QString &email, const QString &password)
{

    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
    const QString queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/sessions.json");
    QNetworkRequest request(queryUri);
    request.setRawHeader("User-Agent", "MoinLela v1.0");
    request.setRawHeader("X-Custom-User-Agent", "MoinLela v1.0");
    request.setRawHeader("Content-Type", "application/json");

    // Assemble Request
    QByteArray mRequestJson;
    QString mUserEmail = email;
    QString mUserPassword= password;
    QVariantMap userSession,userRoot;

    userSession["email"] = email.toUtf8();
    userSession["password"] = password.toUtf8();
    userRoot["user"] = userSession;
    // Add each employee to a QVariantList, and then wrap it in a QVariant
    QVariant myData = QVariant(QVariant(userRoot));
    bb::data::JsonDataAccess jda;
    jda.saveToBuffer(myData, &mRequestJson);

    //
    qDebug() << "request Json :" << mRequestJson;
    QNetworkReply* reply = networkAccessManager->post(request,mRequestJson);
    bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onMoinLelaReply()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);
}

// ![0.10]
/*
 *
 * Makes a network call to retrieve items
 */
//! [0]
void MoinLelaRequest::requestItem(const QString &search)
{
    qDebug() << "Search values :" << search;
    if (m_active)
           return;

    QString queryUri;
    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);

    if (search=="All") {
        m_model->clear();
        queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/items.json");
    }
    else {
        const QStringList list = search.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        const QString itemId = list.first();
        m_model->clear();
        queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/items.json?search=%1").arg(search);
    }

    m_active = true;
    emit activeChanged();

    QNetworkRequest request(queryUri);
    QNetworkReply* reply = networkAccessManager->get(request);
    bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onMoinLelaReply()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);

}

//! [0]
//! [rates]
void MoinLelaRequest::requestPostRate(const QString id,const QString score,const QString dimension,QString klass)
{

    m_settings = new AppSettings();
    QString mUserToken= m_settings->token();
    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
    const QString queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/rate.json?auth_token=%1").arg(mUserToken);

    QNetworkRequest request(queryUri);
    request.setRawHeader("User-Agent", "My app name v0.1");
    request.setRawHeader("X-Custom-User-Agent", "MoinLela v1.0");
    request.setRawHeader("Content-Type", "application/json");

    // Assemble Request
    QByteArray mRequestJson;

    QVariantMap itemRate,itemRoot;
    // itemRoot
    // Populate each object with data
    itemRate["score"] = score.toUtf8();
    itemRate["id"] = id.toUtf8();
    itemRate["dimension"] = dimension.toUtf8();
    itemRate["klass"] = "Item";
    // Add each employee to a QVariantList, and then wrap it in a QVariant
    QVariant myData = QVariant(QVariant(itemRate));
    bb::data::JsonDataAccess jda;
    jda.saveToBuffer(myData, &mRequestJson);

    QNetworkReply* reply = networkAccessManager->post(request,mRequestJson);
    bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onMoinLelaReply()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);
}

//! [rates]
//! [1.0]
void MoinLelaRequest::requestPostItem(const QString &name,const QString &label, const QString &regionID,const QString &country,const QString &region, const QString &town, const QString &zipcode, const QString &address, const QString phone, const QString mobile,const QString &latitude,const QString &longitude , const QString &imagePath)
{
    m_settings = new AppSettings();
    if (m_active)
           return;

    if (isAuthenticated()) {
        QString mUserToken= m_settings->token();
        QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
        const QString queryUri = QString::fromLatin1("http://www.moinlela.com/api/v1/items.json?auth_token=%1").arg(mUserToken);
        QNetworkRequest request(queryUri);
        request.setRawHeader("User-Agent", "MoinLela v1.0");
        request.setRawHeader("X-Custom-User-Agent", "MoinLela v1.0");
        request.setRawHeader("Content-Type", "application/json");


        QByteArray mRequestJson;
        // Create QVariantMap objects to contain the data for each employee
        QVariantMap itemData,itemAddress,itemRoot;
        // itemRoot
        // Populate each object with data
        itemData["name"] = name;
        itemData["label"] = label;
        itemData["region_id"] = regionID;
        itemAddress["country"] = country;
        itemAddress["region"] = region;
        itemAddress["town"] = town;
        itemAddress["zipcode"] = zipcode;
        itemAddress["address"] = address;
        itemAddress["phone"] = phone;
        itemAddress["mobile"] = mobile;
        itemAddress["latitude"] = latitude;
        itemAddress["longitude"] = longitude;
        itemData["file"] = imagePathToBase64(imagePath);
        itemData["filename"] = "item.jpg";
        itemData["picture"] = "item.jpg";
        itemData["geoaddress_attributes"] = itemAddress;
        itemRoot["item"] = itemData;

        // Add each employee to a QVariantList, and then wrap it in a QVariant
        QVariant myData = QVariant(QVariant(itemRoot));
        bb::data::JsonDataAccess jda;
        jda.saveToBuffer(myData, &mRequestJson);

        m_active = true;
        emit activeChanged();
        qDebug() << "Request JSON : Status (actif):" << m_active;

        QNetworkReply* reply = networkAccessManager->post(request,mRequestJson);
        bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onMoinLelaReply()));
        Q_ASSERT(ok);
        Q_UNUSED(ok);
    }
}

QByteArray MoinLelaRequest::imagePathToBase64(const QString &imagePath) {

    bb::ImageData image = bb::utility::ImageConverter::decode(imagePath);
    QByteArray encodedImage = bb::utility::ImageConverter::encode("image/jpg",image,75);
    QImage mImage;
    mImage.loadFromData(encodedImage);
    QImage resized = mImage.scaledToWidth(400,Qt::FastTransformation);
    QByteArray encodedmImage = bb::utility::ImageConverter::encode("image/jpg",fromQImage(resized),75);
    QByteArray encodedFile = encodedmImage.toBase64();
    return encodedFile;
}
bb::ImageData MoinLelaRequest::fromQImage(const QImage &qImage)
{
    bb::ImageData imageData(bb::PixelFormat::RGBA_Premultiplied, qImage.width(), qImage.height());

    unsigned char *dstLine = imageData.pixels();
    for (int y = 0; y < imageData.height(); y++) {
        unsigned char * dst = dstLine;
        for (int x = 0; x < imageData.width(); x++) {
            QRgb srcPixel = qImage.pixel(x, y);
            *dst++ = qRed(srcPixel);
            *dst++ = qGreen(srcPixel);
            *dst++ = qBlue(srcPixel);
            *dst++ = qAlpha(srcPixel);
        }
        dstLine += imageData.bytesPerLine();
    }

    return imageData;
}
void MoinLelaRequest::parseResponse(const QString &response)
{
     if (response.trimmed().isEmpty())
        return;
    // Parse the json response with JsonDataAccess
    bb::data::JsonDataAccess jda;
    const QVariantMap map = jda.loadFromBuffer(response).toMap();
    int statusValue = map["status"].toInt();
    qDebug() << "Status :" << statusValue;
    if (statusValue == 100) {
       QVariantList items = map["items"].toList(); // get items array.
       foreach(const QVariant &var,items) {
           QVariantMap itemMap = var.toMap();
           QVariantMap rates = itemMap["ratings"].toMap(); // get items array.
           QVariantMap geoaddress = itemMap["geoaddress"].toMap(); // get items array.
           // Setup the image processing thread
           itemMap["budget"] = rates["budget"];
           itemMap["quality"] = rates["quality"];
           itemMap["privacy"] = rates["privacy"];
           itemMap["ambience"] = rates["ambience"];
           itemMap["service"] = rates["service"];
           itemMap["country"] = geoaddress["country"];
//           itemMap["region"] = geoaddress["region"];
           itemMap["town"] = geoaddress["town"];
           itemMap["zipcode"] = geoaddress["zipcode"];
           itemMap["address"] = geoaddress["address"];
           itemMap["latitude"] = geoaddress["latitude"];
           itemMap["longitude"] = geoaddress["longitude"];
           itemMap["phone"] = geoaddress["phone"];
           itemMap["mobile"] = geoaddress["mobile"];
           qDebug() << "Inside items " << itemMap["name"].toString();
           m_model->insert(itemMap);
      }
    }
    if (statusValue == 200) {
            qDebug() << "Status" << "created";
            QVariantMap item = map["items"].toMap();
            QString id = item["id"].toString();
            qDebug() << "Item ID :" << item["id"].toString();
            // Post rating
            QString dimension,klass;
            requestPostRate(id,budget(), dimension="budget",klass="Item");
            requestPostRate(id,service(),dimension="service",klass="Item");
            requestPostRate(id,quality(),dimension="quality",klass="Item");
            requestPostRate(id,privacy(),dimension="privacy",klass="Item");
            requestPostRate(id,ambience(),dimension="ambience",klass="Item");

          //  requestPostRate(item_id,budget(),service(),quality(),privacy(),ambience());
    }
    if (statusValue == 300) {
        //
        m_settings = new AppSettings();
        QVariantMap user = map["data"].toMap();
        m_settings->setToken(user["auth_token"].toString());
        m_settings->setUsername(user["name"].toString());
        m_settings->setEmail(user["email"].toString());
        m_settings->setUserid(user["user_id"].toString());

        if (m_settings->token().isEmpty()) {
            m_logged = false;
            emit loggedChanged();
        }
        else {
            m_logged = true;
            emit loggedChanged();
        }

    }
    if (statusValue == 350) {
        //
        m_settings = new AppSettings();
        QVariantMap user = map["data"].toMap();
        m_settings->setToken(user["auth_token"].toString());
        m_settings->setUsername(user["name"].toString());
        m_settings->setEmail(user["email"].toString());
        m_settings->setUserid(user["user_id"].toString());

        if (m_settings->token().isEmpty()) {
            m_logged = false;
            emit loggedChanged();
        }
        else {
            m_logged = true;
            emit loggedChanged();
        }

    }

    if (statusValue == 400) {
        qDebug() << "Good";
    }
}

void MoinLelaRequest::onMoinLelaReply()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    QString response;
    bool success = false;
    SystemToast* recordMessage = new SystemToast();

    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            const int available = reply->bytesAvailable();
            if (available > 0) {
                recordMessage->setBody("Enregistrement Ok");
                recordMessage->setPosition(SystemUiPosition::MiddleCenter);
                recordMessage->show();

                const QByteArray buffer = reply->readAll();
                response = QString::fromUtf8(buffer);
                success = true;
                parseResponse(response);
                m_active = false;
                emit activeChanged();
                reset();
            }
        } else {
            response =  tr("Error: %1 status: %2").arg(reply->errorString(), reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
            m_active = false;
            emit activeChanged();

        }

        reply->deleteLater();
    }

    if (response.trimmed().isEmpty()) {
        response = tr("Moinlal request failed. Check internet connection");
    }

//    emit complete(response, success);
}
//! [4]
bool MoinLelaRequest::logged() const
{
    return m_logged;
}
bool MoinLelaRequest::active() const
{
    return m_active;
}
bb::cascades::DataModel* MoinLelaRequest::model() const
{
    return m_model;
}
bb::cascades::Image MoinLelaRequest::imageFromBase64(const QByteArray &base64) {
    QByteArray decoded = QByteArray::fromBase64(base64);
    QImage qImage;
    qImage.loadFromData(decoded);

    bb::ImageData imageData(bb::PixelFormat::RGBA_Premultiplied,
            qImage.width(), qImage.height());

    unsigned char *dstLine = imageData.pixels();
    for (int y = 0; y < imageData.height(); y++) {
         unsigned char * dst = dstLine;
         for (int x = 0; x < imageData.width(); x++) {
              QRgb srcPixel = qImage.pixel(x, y);
              *dst++ = qRed(srcPixel);
              *dst++ = qGreen(srcPixel);
              *dst++ = qBlue(srcPixel);
              *dst++ = qAlpha(srcPixel);
          }
          dstLine += imageData.bytesPerLine();
    }

    Image m_image = bb::cascades::Image(imageData);
    return m_image;
}
void MoinLelaRequest::stackRate(const QString budget,const QString service,const QString quality,const QString  privacy,const QString ambience) {

    setBudget(budget);
    setQuality(quality);
    setService(service);
    setPrivacy(privacy);
    setAmbience(ambience);

}
void MoinLelaRequest::rateItem(const QString id,const QString mBudget,const QString mService,const QString mQuality,const QString  mPrivacy,const QString mAmbience) {
    if (isAuthenticated()) {
        stackRate(mBudget,mService,mQuality,mPrivacy,mAmbience);
        QString dimension,klass;
        requestPostRate(id,budget(), dimension="budget",klass="Item");
        requestPostRate(id,service(),dimension="service",klass="Item");
        requestPostRate(id,quality(),dimension="quality",klass="Item");
        requestPostRate(id,privacy(),dimension="privacy",klass="Item");
        requestPostRate(id,ambience(),dimension="ambience",klass="Item");
    }
}
