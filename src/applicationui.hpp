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

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <bb/cascades/QListDataModel>
#include <bb/cascades/GroupDataModel>
#include <bb/cascades/ActivityIndicator>
#include <bb/cascades/Image>
#include "WebMaps.hpp"
#include "appsettings.h"
#include <bb/ImageData>
#include <bb/cascades/Label>

#include "StatusEventHandler.h"

namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)
    Q_PROPERTY(bool error READ error NOTIFY statusChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY statusChanged)
public:
    ApplicationUI(QObject *parent = 0);
    virtual ~ApplicationUI() {}



public Q_SLOTS:
        /*
         * Called by the QML to get a artifact feed for the artifact search name
         */
        QString getLatitude();
        QString getLongitude();
        QString getNetworkStatusLabel() ;
        QString getNetworkStatusType() ;
        QString getCountryLabel() ;
        QString getLanguageLabel() ;
        QString getLocaleLabel() ;

        /**
         * Called to get date string from a timestamp.
         */
        Q_INVOKABLE QString dateFromTimestamp(const QString &timestamp);

Q_SIGNALS:
        /*
         * The change notification signals of the properties
         */
        void activeChanged();
        void statusChanged();

private Q_SLOTS:
        /*
         * Handles the complete signal from ArtifactRequest when
         * the request is complete
         */
public slots:
    void localeUpdateHandler(QString language, QString country, QString locale);
    void networkStatusUpdateHandler(bool status, QString type);
    void geolocationUpdateHandler(double latitude, double longiture);
private slots:
    void onSystemLanguageChanged();

private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;
    AppSettings* m_settings;

    /*
       * The accessor methods of the properties
    */
    bool active() const;
    bool error() const;
    QString errorMessage() const;
    bool m_active;
    bool m_error;
    QString m_errorMessage;

    StatusEventHandler  *statusEventHandler;
    double mLatitude;
    double mLongitude;
    QString mNetworkStatusLabel;
    QString mNetworkStatusType;
    QString mCountryLabel ;
    QString mLanguageLabel;
    QString mLocaleLabel;

};

#endif /* ApplicationUI_HPP_ */
