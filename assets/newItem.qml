import bb.cascades 1.4
import bb.cascades.multimedia 1.2
import bb.system 1.2 
import com.moinlela.webmaps 1.0
import bb.cascades.pickers 1.0
import com.moinlela.MoinLelaRequest 1.0
import bb.cascades.places 1.0
import "controls"

Page {
        property string latitude
        property string longitude
        property variant currentCoord
        
        id: root
        titleBar: TitleBar {
        title: qsTr("Nouveau")
        kind: TitleBarKind.Default
        acceptAction: ActionItem {
        title: "Enregistrer"
            onTriggered: {
                // handle task creation here.
                _requestService.requestPostItem(itemName.text.toString(),itemLabel.text.toString(),itemRegionID.selectedIndex+1,itemCountry.text.toString(),itemRegion.text.toString(),itemTown.text.toString(),itemZipcode.text.toString(),itemAddress.text.toString(),itemPhone.text.toString(),itemMobile.text.toString(),_app.getLatitude(),_app.getLongitude(),itemPicture.imageSource);
                _requestService.stackRate(rateBudget.value, rateService.value,rateQuality.value,ratePrivacy.value,rateAmbience.value)
//                navigationPane.pop();
            }
        }
        dismissAction: ActionItem {
        title: "Annuler"
            onTriggered: {
                // handle task creation here
                navigationPane.pop();
            }
        }
    }
    actions: [
        ActionItem {
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Picture"
            imageSource: "asset:///icons/ic_camera.png"
            onTriggered: {
                // Add picture
                picker.open()
//                appInvoker.onInvokeButtonClicked();
            }
        },
        ActionItem {
            title: qsTr("Drop Pin")
            imageSource: "asset:///images/pin.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                map.removeAllPins()
                map.setZoom(19)
                map.setCenter(_app.getLatitude(), _app.getLongitude())
                map.createPushPin(map.center[0], map.center[1], qsTr("I am a Pin"))
                placePicker.selectPlace()
            }
        }
    ]
    ScrollView {
        scrollViewProperties {
            scrollMode: ScrollMode.Vertical
        }
    Container {
        background: color.create("#CC3F10")
        layout: StackLayout {
            orientation: LayoutOrientation.TopToBottom
        }
        leftPadding: 20
        topPadding: 20
        bottomPadding: 20
        rightPadding: 20
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            visible: !_requestService.active
            topPadding: 10.0
            bottomPadding: 10.0
            leftPadding: 10.0
            rightPadding: 10.0          
            ImageView {
                id: itemPicture
                preferredHeight: 200
                preferredWidth: 200
                leftPadding: 10.0
                rightPadding: 10.0
                topPadding: 10.0
                bottomPadding: 10.0
                scalingMethod: ScalingMethod.AspectFit
                verticalAlignment: VerticalAlignment.Top
                imageSource: "file://" + picker.selectedFile  
                }
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.TopToBottom
                }
                visible: !_requestService.active
                // identity
                TextField {
                    id: itemName
                    text: _requestService.itemName
                    inputMode: TextFieldInputMode.Text
                    input.submitKey: SubmitKey.Next
                    textStyle.textAlign: TextAlign.Left
                    textStyle.color: Color.DarkYellow
                    leftPadding: 20.0
                    rightPadding: 20.0
                    hintText: "Nom"
                    onTextChanging: {
                    }
                    textStyle.fontSize: FontSize.Large
                    preferredHeight: 50
                }
                TextField {
                    id: itemLabel
                    text: _requestService.itemLabel
                    inputMode: TextFieldInputMode.Text
                    input.submitKey: SubmitKey.Next
                    textStyle.textAlign: TextAlign.Left
                    textStyle.color: Color.DarkYellow
                    leftPadding: 10.0
                    rightPadding: 10.0
                    hintText: "Label"
                    textStyle.fontSize: FontSize.Large
                    preferredHeight: 50
                }

            }
        }
        //! [2]
        NetworkActivity {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            active: _requestService.active
        }
        //! [2]
        Container {

            FieldLabel {
                title: qsTr("street")
                field: "street"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("city")
                field: "city"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("region")
                field: "region"
                selectedPlace: placePicker.selectedPlace
            }

        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            visible: !_requestService.active

            TextField {
                id: itemCountry
                text: _requestService.itemCountry
                inputMode: TextFieldInputMode.Text
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                bottomPadding: 10.0
                hintText: "Country"
                textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }
            TextField {
                id: itemRegion
                text:_requestService.itemRegion
                inputMode: TextFieldInputMode.Text
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                bottomPadding: 10.0
                hintText: "Region"
                textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            visible: !_requestService.active

            topPadding: 10
            bottomPadding: 10
            TextField {
                id: itemZipcode
                text: _requestService.itemZipcode
                inputMode: TextFieldInputMode.Text
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                topPadding: 10.0
                hintText: "Zipcode"
                textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }
            TextField {
                id: itemTown
                text: _requestService.itemTown
                inputMode: TextFieldInputMode.Text
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                topPadding: 10.0
                hintText: "Town"
                textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }

        }
        TextField {
            id: itemAddress
            text: _requestService.itemAddress
            inputMode: TextFieldInputMode.Text
            input.submitKey: SubmitKey.Next
            textStyle.textAlign: TextAlign.Left
            textStyle.color: Color.DarkYellow
            leftPadding: 10.0
            rightPadding: 10.0
            hintText: "Adresse"
            textStyle.fontSize: FontSize.Large
            preferredHeight: 50
            visible: !_requestService.active

        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            visible: !_requestService.active

            TextField {
                id: itemPhone
                text: _requestService.itemPhone
                inputMode: TextFieldInputMode.PhoneNumber
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                hintText: qsTr("Phone")
                    textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }
            TextField {
                id: itemMobile
                text: _requestService.itemMobile
                inputMode: TextFieldInputMode.PhoneNumber
                input.submitKey: SubmitKey.Next
                textStyle.textAlign: TextAlign.Left
                textStyle.color: Color.DarkYellow
                leftPadding: 10.0
                rightPadding: 10.0
                hintText: "Mobile"
                textStyle.fontSize: FontSize.Large
                preferredHeight: 50
            }
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            visible: !_requestService.active

            topPadding: 20
            DropDown {
                id: itemRegionID
                title: "Region"
                enabled: true
                onSelectedIndexChanged: {
                    console.log("SelectedIndex was changed to " + selectedIndex);
                }
                Option {
                    text: "Nord"
                    description: "Région Nord"
                    value: "Nord"
                }
                Option {
                    text: "Est"
                    description: "Région Est"
                    value: "Est"
                }
                Option {
                    text: "Sud"
                    description: "Région Sud"
                    value: "Sud"
                    selected: true
                }
                Option {
                    text: "Ouest"
                    description: "Région Ouest"
                    value: "Ouest"
                }
            }
            Map {
                visible: !_requestService.active

                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Fill
                id: map
                preferredHeight: 300
                preferredWidth: 800
            }

        }
        // Rates
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            visible: !_requestService.active

            topPadding: 40.0
            leftPadding: 10.0
            // Budget
            Container {
                layout:GridLayout 
                {
                    columnCount: 3
                }
                Label {
                    text: "Budget :"
                    textStyle.color: Color.Blue
                    minWidth: 250.0
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Slider {
                    id: rateBudget
                    fromValue: 0
                    toValue: 5.0
                    leftPadding: 30
                    rightMargin: 30
                    value: _requestService.budget.toInt()
                    onImmediateValueChanged: {
                        budget.text = Math.round(immediateValue)
                    }
                }
                Label {
                    id: budget
                    minWidth: 100.0
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
            }
            Container {
                layout:GridLayout 
                {
                    columnCount: 3
                }
                Label {
                    text: "Service"
                    minWidth: 250.0
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Slider {
                    id: rateService
                    fromValue: 0
                    toValue: 5.0
                    value: _requestService.service.toInt()
                    onImmediateValueChanged: {
                        service.text = Math.round(immediateValue)
                    }
                }
                Label {
                    id: service
                    minWidth: 100.0
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
            }
            Container {
                layout:GridLayout 
                {
                    columnCount: 3
                }
                Label {
                    text: "Qualité"
                    textStyle.color: Color.Blue
                    minWidth: 250.0
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                
                Slider {
                    id: rateQuality
                    fromValue: 0
                    toValue: 5.0
                    value: _requestService.quality.toInt()
                    onImmediateValueChanged: {
                        quality.text = Math.round(immediateValue)
                    }
                }
                Label {
                    id: quality
                    textStyle.color: Color.Blue
                    minWidth: 100.0
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
            }
            Container {
                layout:GridLayout 
                {
                    columnCount: 3
                }
                Label {
                    minWidth: 250.0
                    text: "Intimité"
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Slider {
                    id: ratePrivacy
                    fromValue: 0
                    toValue: 5.0
                    value: _requestService.privacy.toInt()
                    onImmediateValueChanged: {
                        privacy.text = Math.round(immediateValue)
                    }
                }
                Label {
                    id: privacy
                    minWidth: 100
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
            }
            Container {
                layout:GridLayout 
                {
                    columnCount: 3
                }
                Label {
                    text: "Ambiance"
                    minWidth: 250.0
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
                Slider {
                    id: rateAmbience
                    fromValue: 0
                    toValue: 5.0
                    value: _requestService.ambience.toInt()
                    onImmediateValueChanged: {
                        ambience.text = Math.round(immediateValue)
                    }
                }
                Label {
                    id: ambience
                    minWidth: 100
                    textStyle.color: Color.Blue
                    textStyle {
                        base: SystemDefaults.TextStyles.TitleText
                    }
                }
            }
        // end Rates

    }

    attachedObjects: [
        FilePicker {
            id: picker
            property string selectedFile
            title: qsTr("File Picker")
            mode: FilePickerMode.Picker
            type: FileType.Picture
            viewMode: FilePickerViewMode.GridView
            onFileSelected: {
                selectedFile = selectedFiles[0]
                console.log("Selected filed :" + selectedFile)
            }
        },
        PlacePicker {
            id: placePicker
            
            property variant selectedPlace
            
            function selectPlace()
            {
                selectedPlace = show()
            }
        }

    ]

    onCreationCompleted: {
        _app.isLogged()
        _webMaps.currentProvider = WebMaps.GoogleMaps
        map.setCenter(_app.getLatitude(), _app.getLongitude());
    }
}
    
}
}