/* Copyright (c) 2013 BlackBerry Limited.
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
#include "appsettings.h"
#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include "appsettings.h"

// Setting default values.
const QString AppSettings::mDefaultToken("");
const QUrl AppSettings::mDefaultAddress("http://www.moinlela.com/api/v1/items.json");
const QString AppSettings::mDefaultUsername("");
const QString AppSettings::mDefaultEmail("");
const QString AppSettings::mDefaultPassword("");
const QString AppSettings::mDefaultUserid("");

// Settings keys.
const QString AppSettings::MOINLELA_TOKEN_KEY("token");
const QString AppSettings::MOINLELA_ADDRESS_KEY("address");
const QString AppSettings::MOINLELA_EMAIL_KEY("email");
const QString AppSettings::MOINLELA_USERNAME_KEY("user_name");
const QString AppSettings::MOINLELA_PASSWORD_KEY("password");
const QString AppSettings::MOINLELA_USERID_KEY("user_id");

AppSettings::AppSettings(QObject* parent) : QObject(parent)

{
    // Set up the QSettings object for the application with organization and application name.
    QCoreApplication::setOrganizationName("MoinLela");
    QCoreApplication::setApplicationName("MoinLela Settings");

    // Load the values from QSettings or set as the default values if not yet set.
    mToken = QSettings().value(MOINLELA_TOKEN_KEY, mDefaultToken).toString();
    mAddress =QSettings().value(MOINLELA_ADDRESS_KEY, mDefaultAddress).toUrl();
    mUsername =QSettings().value(MOINLELA_USERNAME_KEY, mDefaultUsername).toString();
    mEmail =QSettings().value(MOINLELA_EMAIL_KEY, mDefaultEmail).toString();
    mPassword =QSettings().value(MOINLELA_PASSWORD_KEY, mDefaultPassword).toString();
    mUserid =QSettings().value(MOINLELA_USERID_KEY, mDefaultUserid).toString();

}

QString AppSettings::email() const
{
    return mEmail;
}

QString AppSettings::password() const
{
    return mPassword;
}
QString AppSettings::username() const
{
    return mUsername;
}
QString AppSettings::userid() const
{
    return mUserid;
}

QString AppSettings::token() const
{
    return mToken;
}

QUrl AppSettings::address() const
{
    return mAddress;
}
void AppSettings::setUsername(QString username)
{
    qDebug() << "Username " << username;
    if (mUsername != username) {
        QSettings().setValue(MOINLELA_USERNAME_KEY, username);
        mUsername = username;
        emit usernameChanged(username);
    }
}
void AppSettings::setEmail(QString email)
{
    if (mEmail != email) {
        QSettings().setValue(MOINLELA_EMAIL_KEY, email);
        mEmail = email;
        emit emailChanged(email);
    }
}
void AppSettings::setPassword(QString password)
{
    if (mPassword != password) {
        QSettings().setValue(MOINLELA_PASSWORD_KEY, password);
        mPassword = password;
        emit passwordChanged(password);
    }
}
void AppSettings::setUserid(QString userid)
{
    if (mUserid != userid) {
        QSettings().setValue(MOINLELA_USERID_KEY, userid);
        mUserid = userid;
        emit useridChanged(userid);
    }
}

void AppSettings::setToken(QString token)
{
    qDebug() << "Token value :" << token;

    if (mToken != token) {
        QSettings().setValue(MOINLELA_TOKEN_KEY, token);
        mToken = token;
        emit tokenChanged(token);
    }
}

void AppSettings::setAddress(QUrl address)
{
    if(mAddress != address) {
        QSettings().setValue(MOINLELA_ADDRESS_KEY, address);
        mAddress = address;
        emit addressChanged(address);
    }
}
void AppSettings::clearUserInfo()
{
    mToken.clear();
    setToken(mToken);
    mUsername.clear();
    setUsername(mUsername);
    mEmail.clear();
    setEmail(mEmail);
    mPassword.clear();
    setPassword(mPassword);
    mUserid.clear();
    setUserid(mUserid);
}
