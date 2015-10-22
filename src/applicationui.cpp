/*
 * Copyright (c) 2011-2015 BlackBerry Limited.
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

#include "applicationui.hpp"
#include "MoinLelaRequest.hpp"
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/data/JsonDataAccess>
#include <bb/system/SystemCredentialsPrompt>
#include <bb/platform/geo/Point>
#include <bb/platform/geo/GeoLocation>
#include <bb/ImageData>
#include <QImage>
#include <QByteArray>
#include "appsettings.h"
#include "SocialInvocation.hpp"

using namespace bb::cascades;
using namespace bb::system;



ApplicationUI::ApplicationUI(QObject *parent) :
        QObject(parent)
       , m_active(false)
       , m_error(false)
       ,m_settings(new AppSettings(this))
{
    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);

    bool res = QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()));
    // This is only available in Debug builds
    Q_ASSERT(res);
    // Since the variable is not used in the app, this is added to avoid a
    // compiler warning
    Q_UNUSED(res);

    statusEventHandler = new StatusEventHandler();

     // If any Q_ASSERT statement(s) indicate that the slot failed to
     // connect to the signal, make sure you know exactly why this has
     // happened. This is not normal, and will cause your app to
     // stop working!!

     // Since the variable is not used in the app, this is added to
     // avoid a compiler warning.

     res = connect(statusEventHandler,
                     SIGNAL(networkStatusUpdated(bool, QString)),
                     this,
                     SLOT(networkStatusUpdateHandler(bool, QString)));

     // This is only available in Debug builds.
     Q_ASSERT(res);

     res = connect(statusEventHandler,
                     SIGNAL(localeUpdated(QString, QString, QString)),
                     this,
                     SLOT(localeUpdateHandler(QString, QString, QString)));

     // This is only available in Debug builds.
     Q_ASSERT(res);

     res = connect(statusEventHandler,
                     SIGNAL(geolocationUpdated(double, double)),
                     this,
                     SLOT(geolocationUpdateHandler(double, double)));

     // This is only available in Debug builds.
     Q_ASSERT(res);

    // initial load
    onSystemLanguageChanged();

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///moinlela.qml").parent(this);
    qml->setContextProperty("_app", this);
    qml->setContextProperty("appSettings", new AppSettings(this));
    qml->setContextProperty("_webMaps", new WebMaps(this));
    qml->setContextProperty("_requestService", new MoinLelaRequest(this));
    qml->setContextProperty("_socialInvocation", new SocialInvocation(this));
    // Retrieve the path to the app's working directory
        const QString workDir = QDir::currentPath();

        // Build the path, add it as a context property,
        // and expose it to QML
        QVariantMap dirPaths;
        dirPaths["camera"] = QString::fromLatin1("file://%1/shared/camera/").arg(workDir);
        dirPaths["asset"] = QString::fromLatin1("file://%1/app/native/assets/").arg(workDir);
        dirPaths["photo"] = QString::fromLatin1("file://%1/shared/photos/").arg(workDir);
        qml->documentContext()->setContextProperty("_dirPaths", dirPaths);
    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();


    // Set created root object as the application scene
    Application::instance()->setScene(root);
}

void ApplicationUI::networkStatusUpdateHandler(bool status, QString type)
{
    if (status) {
        mNetworkStatusLabel.append("Network Status: true");
    } else {
        mNetworkStatusLabel.append("Network Status: false");
    }
    mNetworkStatusType = "Network Type: " + type;
}

QString ApplicationUI::getNetworkStatusLabel() {
    return mNetworkStatusLabel;
}
QString ApplicationUI::getNetworkStatusType() {
    return mNetworkStatusType;
}

void ApplicationUI::localeUpdateHandler(QString language, QString country, QString locale)
{
    mCountryLabel = "Country: " + country;
    mLanguageLabel = "Language: " + language;
    mLocaleLabel = "Locale: " + locale;
}
QString ApplicationUI::getCountryLabel() {
    return mCountryLabel;
}
QString ApplicationUI::getLanguageLabel() {
    return mLanguageLabel;
}
QString ApplicationUI::getLocaleLabel() {
    return mLocaleLabel;
}
void ApplicationUI::geolocationUpdateHandler(double latitude, double longitude)
{
    mLatitude = latitude;
    mLongitude = longitude;
}
QString ApplicationUI::getLatitude() {
    return QString::number(mLatitude);
}
QString ApplicationUI::getLongitude() {
    return QString::number(mLongitude);
}
void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("MoinLelaApp_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}

bool ApplicationUI::active() const
{
    return m_active;
}

bool ApplicationUI::error() const
{
    return m_error;
}

QString ApplicationUI::errorMessage() const
{
    return m_errorMessage;
}

QString ApplicationUI::dateFromTimestamp(const QString &timestamp) {
    QDateTime date;
    date.setMSecsSinceEpoch(timestamp.toLongLong());
    return date.toString();
}

