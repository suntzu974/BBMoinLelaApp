import bb.cascades 1.4
import bb.data 1.0
import "controls"

Page {
    titleBar: TitleBar {
        title: qsTr("User")
        kind: TitleBarKind.Default
        dismissAction: ActionItem {
            title: "Annuler"
            onTriggered: {
                // handle task creation here
                navigationPane.pop()
            }
        }
    }
    Container {
        layout: DockLayout { }
        // The background image
        ImageView {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            imageSource: "asset:///images/background.png"
        }
        //! [2]
        NetworkActivity {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            active: _requestService.active
        }
        //! [2]
        Container {
            topPadding: 100
            rightPadding: 50
            leftPadding: 50
            horizontalAlignment: HorizontalAlignment.Center
            id: userShow
            visible: _requestService.logged
            
            Label {
                id: userShowToken
                text: appSettings.token
                textStyle.base: SystemDefaults.TextStyles.TitleText
            }
            Label {
                id: userShowEmail
                text: appSettings.email
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
            Label {
                id: userShowUsername
                text: appSettings.username
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
        }

        Container {
            horizontalAlignment: HorizontalAlignment.Center
            id: userBuild
            visible: !_requestService.logged
            TextField {
                id: userEmail
                hintText: "Email"
                inputMode: inputMode.EmailAddress
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
            TextField {
                id: userPassword
                hintText: "Password"
                inputMode: inputMode.Password
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
        }
        Container {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Bottom
                bottomPadding: 100
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                Button {
                    id: userConnect
                    visible: ! _requestService.logged
                    text: qsTr("Connecter")
                    onClicked: {
                        _requestService.requestAuthentication(userEmail.text.toLowerCase(), userPassword.text.toString())
                        }
                }
                Button {
                    id: userLogout
                    visible: _requestService.logged
                    color: Color.DarkRed
                    text: qsTr("Deconnection")
                    onClicked: {
                        _requestService.requestLogout(appSettings.token)
                    }
                }
                Button {
                    visible: ! _requestService.logged
                    id: userRegister
                    text: qsTr("Register")
                    color: Color.create("#00B800")
                    onClicked: {
                        var registration = userRegistrationDefinition.createObject();
                        navigationPane.push(registration);
                    }
                }
          }
    }
    attachedObjects: [
        ComponentDefinition {
            id: userRegistrationDefinition
            source: "userRegistration.qml"
        }
    ]

}
