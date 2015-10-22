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

#ifndef MOINLELAREQUEST_HPP
#define MOINLELAREQUEST_HPP

#include <QtCore/QObject>
#include <QByteArray>
#include <bb/ImageData>
#include <bb/cascades/Image>
#include <bb/cascades/QListDataModel>
#include <bb/cascades/GroupDataModel>
#include <bb/system/SystemDialog>
#include <bb/system/SystemUiResult>
#include "appsettings.h"
/*
 * This class is responsible for making a REST call to the maven central api
 * to retrieve the search results for a given artifact name. It emits the complete()
 * signal when the request has completed.
 */
//! [0]
class MoinLelaRequest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool logged READ logged NOTIFY loggedChanged)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)
    Q_PROPERTY(bb::cascades::DataModel* model READ model CONSTANT)
    Q_PROPERTY(QString budget READ budget WRITE setBudget NOTIFY budgetChanged)
    Q_PROPERTY(QString service READ service WRITE setService NOTIFY serviceChanged)
    Q_PROPERTY(QString quality READ quality WRITE setQuality NOTIFY qualityChanged)
    Q_PROPERTY(QString privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)
    Q_PROPERTY(QString ambience READ ambience WRITE setAmbience NOTIFY ambienceChanged)

    Q_PROPERTY(QString itemName READ itemName WRITE setItemName NOTIFY itemNameChanged)
    Q_PROPERTY(QString itemLabel READ itemLabel WRITE setItemLabel NOTIFY itemLabelChanged)
    Q_PROPERTY(QString itemCountry READ itemCountry WRITE setItemCountry NOTIFY itemCountryChanged)
    Q_PROPERTY(QString itemRegion READ itemRegion WRITE setItemRegion NOTIFY itemRegionChanged)
    Q_PROPERTY(QString itemZipcode READ itemZipcode WRITE setItemZipcode NOTIFY itemZipcodeChanged)
    Q_PROPERTY(QString itemTown READ itemTown WRITE setItemTown NOTIFY itemTownChanged)
    Q_PROPERTY(QString itemAddress READ itemAddress WRITE setItemAddress NOTIFY itemAddressChanged)
    Q_PROPERTY(QString itemPhone READ itemPhone WRITE setItemPhone NOTIFY itemPhoneChanged)
    Q_PROPERTY(QString itemMobile READ itemMobile WRITE setItemMobile NOTIFY itemMobileChanged)

public:
    MoinLelaRequest(QObject *parent = 0);

    QByteArray  imagePathToBase64(const QString &imagePath);
    bb::ImageData fromQImage(const QImage &qImage);

    // Rating Budget
    void setBudget(const QString  &budget) {
        if (budget != mBudget) {
            mBudget = budget;
            emit budgetChanged();
        }
    }
    QString budget() const {
        return mBudget;
    }
    // Rating Service
    void setService(const QString  &service) {
        if (service != mService) {
            mService = service;
            emit serviceChanged();
        }
    }
    QString service() const {
        return mService;
    }
    // Rating Quality
    void setQuality(const QString  &quality) {
        if (quality != mQuality) {
            mQuality = quality;
            emit qualityChanged();
        }
    }
    QString quality() const {
        return mQuality;
    }
    // Rating Privacy
    void setPrivacy(const QString  &privacy) {
        if (privacy != mPrivacy) {
            mPrivacy = privacy;
            emit privacyChanged();
        }
    }
    QString privacy() const {
        return mPrivacy;
    }
    // Rating Ambience
    void setAmbience(const QString  &ambience) {
        if (ambience != mAmbience) {
            mAmbience = ambience;
            emit ambienceChanged();
        }
    }
    QString ambience() const {
        return mAmbience;
    }
    // itemName
    void setItemName(const QString  &itemName) {
        if (itemName != mItemName) {
            mItemName = itemName;
            emit itemNameChanged();
        }
    }
    QString itemName() const {
        return mItemName;
    }
    // itemLabel
    void setItemLabel(const QString  &itemLabel) {
        if (itemLabel != mItemLabel) {
            mItemLabel = itemLabel;
            emit itemLabelChanged();
        }
    }
    QString itemLabel() const {
        return mItemLabel;
    }
    // itemCountry
    void setItemCountry(const QString  &itemCountry) {
        if (itemCountry != mItemCountry) {
            mItemCountry = itemCountry;
            emit itemCountryChanged();
        }
    }
    QString itemCountry() const {
        return mItemCountry;
    }
    // itemRegion
    void setItemRegion(const QString  &itemRegion) {
        if (itemRegion != mItemRegion) {
            mItemRegion = itemRegion;
            emit itemRegionChanged();
        }
    }
    QString itemRegion() const {
        return mItemRegion;
    }
    // itemZipcode
    void setItemZipcode(const QString  &itemZipcode) {
        if (itemZipcode != mItemZipcode) {
            mItemZipcode = itemZipcode;
            emit itemZipcodeChanged();
        }
    }
    QString itemZipcode() const {
        return mItemZipcode;
    }
    // itemTown
    void setItemTown(const QString  &itemTown) {
        if (itemTown != mItemTown) {
            mItemTown = itemTown;
            emit itemTownChanged();
        }
    }
    QString itemTown() const {
        return mItemTown;
    }
    // itemAddress
    void setItemAddress(const QString  &itemAddress) {
        if (itemAddress != mItemAddress) {
            mItemAddress = itemAddress;
            emit itemAddressChanged();
        }
    }
    QString itemAddress() const {
        return mItemAddress;
    }

    // itemPhone
    void setItemPhone(const QString  &itemPhone) {
        if (itemPhone != mItemPhone) {
            mItemPhone = itemPhone;
            emit itemPhoneChanged();
        }
    }
    QString itemPhone() const {
        return mItemPhone;
    }
    // itemAddress
    void setItemMobile(const QString  &itemMobile) {
        if (itemMobile != mItemMobile) {
            mItemMobile = itemMobile;
            emit itemMobileChanged();
        }
    }
    QString itemMobile() const {
        return mItemMobile;
    }

Q_SIGNALS:
    /*
     * This signal is emitted when the search request is received
     * @param info - on success, this is the json reply from the request
     *               on failure, it is an error string
     * @param success - true if search request succeed, false if not
     */
    void loggedChanged();
    void activeChanged();
    void budgetChanged();
    void serviceChanged();
    void qualityChanged();
    void privacyChanged();
    void ambienceChanged();
    void itemNameChanged();
    void itemLabelChanged();
    void itemCountryChanged();
    void itemRegionChanged();
    void itemZipcodeChanged();
    void itemTownChanged();
    void itemAddressChanged();
    void itemPhoneChanged();
    void itemMobileChanged();

public Q_SLOTS:

        /*
         * Clears the internal state of the weather service object.
         */
        void reset();
        void requestRegister(const QString &email,const QString &name,const QString &password);
        void requestLogout(const QString &token);
        void requestPostRate(const QString id,const QString score,const QString dimension,QString klass);
        void requestAuthentication(const QString &login,const QString &password);
        bb::cascades::Image imageFromBase64(const QByteArray &base64);
        void requestItem(const QString &itemName);
        void rateItem(const QString item,const QString budget,const QString service,const QString quality,const QString privacy,const QString ambience);
        void stackRate(const QString budget,const QString service,const QString quality,const QString privacy,const QString ambience);
        void requestPostItem(const QString &name,const QString &label, const QString &regionID,const QString &country,const QString &region, const QString &town, const QString &zipcode, const QString &address, const QString phone, const QString mobile,const QString &latitude,const QString &longitude, const QString &imagePath );
private Q_SLOTS:
    /*
     * Callback handler for QNetworkReply finished() signal
     */
    void onMoinLelaReply();
public slots:
    void onDialogFinished(bb::system::SystemUiResult::Type type);
private:
    bool logged() const;
    bool active() const;
    bool isAuthenticated();
    bb::system::SystemDialog* m_dialog;
    bb::cascades::DataModel* model() const;
    AppSettings * m_settings;
    bool m_active, m_logged;
    void parseResponse(const QString&);
    bb::cascades::GroupDataModel* m_model;
    QString mBudget, mService, mQuality,mAmbience, mPrivacy;
    QString mItemID;
    QString mItemName,mItemLabel,mItemCountry,mItemRegion,mItemZipcode,mItemTown,mItemAddress,mItemPhone,mItemMobile;

};
//! [0]

#endif
