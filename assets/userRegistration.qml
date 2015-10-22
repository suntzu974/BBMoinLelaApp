import bb.cascades 1.4
import "controls"

Page {
    Container {
        layout: DockLayout {
        }
        ImageView {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
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
            visible: !_requestService.active && ! _requestService.logged
            topPadding: 100
            rightPadding: 50
            leftPadding: 50
            horizontalAlignment: HorizontalAlignment.Center
            
            TextField {
                id: userEmail
                hintText: "Email"
                inputMode: inputMode.EmailAddress
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
            TextField {
                id: userName
                hintText: "Username"
                inputMode: inputMode.Text
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
            TextField {
                id: userPassword
                hintText: "Password"
                inputMode: inputMode.Url
                textStyle.base: SystemDefaults.TextStyles.PrimaryText
            }
            Container {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Bottom
                bottomPadding: 100
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                Button {
                    id: registration
                    text: qsTr("Register")
                    onClicked: {
                        _requestService.requestRegister(userEmail.text.toLowerCase(), userName.text.toString(), userPassword.text.toString(), userPassword.text.toString())
                    }
                }
            }

        }
    }
}
