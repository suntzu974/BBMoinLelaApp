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
#ifndef APPSETTINGS_H_
#define APPSETTINGS_H_

#include <QObject>
#include <QVariantMap>
#include <QUrl>

/**
 * AppSettings Description
 *
 * This class handles application wide settings that persist between runs.
 */
class AppSettings: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString token READ token WRITE setToken NOTIFY tokenChanged FINAL)
    Q_PROPERTY(QUrl address READ address WRITE setAddress NOTIFY addressChanged FINAL   )
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged FINAL   )
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged FINAL   )
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL   )
    Q_PROPERTY(QString userid READ userid WRITE setUserid NOTIFY useridChanged FINAL   )

public:
    AppSettings(QObject *parent = 0);

    bool gravity() const;
    /**
     * @return True if gravity is on otherwise False
     */
    QString token() const;
    QString username() const;
    QString email() const;
    QString password() const;
    QString userid() const;
    QUrl address() const;



public slots:

    void setUsername(QString username);
    void setUserid(QString userid);
    void setPassword(QString password);
    void setEmail(QString email);
    void setToken(QString token);
    void setAddress(QUrl address);
    void clearUserInfo();


signals:

    void addressChanged(QUrl address);
    void tokenChanged(QString token);
    void emailChanged(QString email);
    void usernameChanged(QString username);
    void passwordChanged(QString password);
    void useridChanged(QString userid);


private:
    /**
     * Default values for properties
     */
    static const QString mDefaultToken;
    static const QUrl mDefaultAddress;
    static const QString mDefaultUsername;
    static const QString mDefaultEmail;
    static const QString mDefaultPassword;
    static const QString mDefaultUserid;

    static const QString MOINLELA_TOKEN_KEY;
    static const QString MOINLELA_ADDRESS_KEY;
    static const QString MOINLELA_EMAIL_KEY;
    static const QString MOINLELA_USERID_KEY;
    static const QString MOINLELA_PASSWORD_KEY;
    static const QString MOINLELA_USERNAME_KEY;

    /**
     * The property variables.
     */
    QString mToken;
    QUrl mAddress;
    QString mUserid;
    QString mUsername;
    QString mEmail;
    QString mPassword;

};

#endif /* APPSETTINGS_H_ */
