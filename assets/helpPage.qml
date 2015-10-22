import bb.cascades 1.4

Page {
    titleBar: TitleBar {
        title: "Titre"
    }
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        leftPadding: 50
        rightPadding: 50
        topPadding: 50
        bottomPadding: 50
        Label {
            text: "Aide en ligne"
        }
        Label {
            text: "ID utilisateur :" + appSettings.token
            textStyle.base: SystemDefaults.TextStyles.SubtitleText
            textStyle.color: Color.DarkMagenta
        }
        // Address
        Label {
            id: address
            objectName: "address"
            text: "URL :"+ appSettings.address
        }
        // email
        Label {
            id: email
            objectName: "email"
            text: "Email :"+appSettings.email
        }
        // username
        Label {
            id: username
            objectName: "username"
            text: "Username :" + appSettings.username
        }
        
        // userid
        Label {
            id: userId
            objectName: "userid"
            text: "UserID :" + appSettings.userid
        }

        Label {
            id: countryLabel
            objectName: "countryLabel"
            text: _app.getCountryLabel();
        }
        Label {
            id: languageLabel
            objectName: "languageLabel"
            text: _app.getLanguageLabel();
        }
        Label {
            id: localeLabel
            objectName: "localeLabel"
            text: _app.getLocaleLabel();
        }
        Label {
            id: networkStatusLabel
            objectName: "networkStatusLabel"
            text: _app.getNetworkStatusLabel();
        }
        Label {
            id: networkStatusType
            objectName: "networkStatusType"
            text: _app.getNetworkStatusType();
        }
        Label {
            id: geolocationLatitude
            objectName: "geolocationLatitude"
            text: "Latitude :" + _app.getLatitude();
        }
        Label {
            id: geolocationLongitude
            objectName: "geolocationLongitude"
            text: "Longitude :" + _app.getLongitude();
        }
    }
}
