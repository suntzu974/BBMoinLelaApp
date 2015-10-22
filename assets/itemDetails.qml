import bb.cascades 1.4
import com.moinlela.MoinLelaRequest 1.0
import bb.system.phone 1.0
import bb.cascades.places 1.0
import "controls"

Page {
    property variant item;
    property string invokeTarget
    property string latLong
    id: root
    titleBar: TitleBar {
        title: qsTr("Mise à jour")
        kind: TitleBarKind.Default
        acceptAction: ActionItem {
            title: qsTr("Enregistrer")
            onTriggered: {
                // handle task creation here.
                _requestService.rateItem(item.id,rateBudget.value, rateService.value,rateQuality.value,ratePrivacy.value,rateAmbience.value)
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
        // General SHARE Framework call
        // Will display all the SHARE Targets available
        InvokeActionItem {
            ActionBar.placement: ActionBarPlacement.OnBar
            title: qsTr("Post Image")
            query {
                mimeType: ""
                invokeTargetId: "Facebook"
                invokeActionId: "bb.action.SHARE"
                // Share an image that is packaged with the app
                uri: _dirPaths.photo + "social.jpg"
            }
        },
        // PHONE
        ActionItem {
            title: qsTr("Phone")
            imageSource: "asset:///icons/ic_phone.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                // Invokes the phone app with dial pad
                phone.requestDialpad(item.phone.toString());
            }
        },
        // WAZE
        ActionItem {
            title: qsTr("Waze")
            imageSource: "asset:///icons/ic_nav_to.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                latLong = "waze://?ll=" + item.latitude + "," +item.longitude+"&z=10"
                _socialInvocation.invokeWaze(latLong.toString());
            }
        }

    ]
    Container {
        layout: DockLayout {}
        
        // The background image
        ImageView {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            
            imageSource: "asset:///images/background.png"
        }


ScrollView {
    scrollViewProperties {
        scrollMode: ScrollMode.Vertical
    }
    Container {
        id: rootDetail
        function imageBase64(data) {
            _socialInvocation.imageToData(data)
            return _requestService.imageFromBase64(data)
        }
        verticalAlignment: VerticalAlignment.Center
        horizontalAlignment: HorizontalAlignment.Center
        topPadding: 50
        layoutProperties: FlowListLayoutProperties {

        }
        ImageView {
            horizontalAlignment: HorizontalAlignment.Center
            image: rootDetail.imageBase64(item.encoded)
            preferredWidth: 200
            preferredHeight: 200
        }
        //! [2]
        NetworkActivity {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            active: _requestService.active
        }
        Label {
            textStyle.base: SystemDefaults.TextStyles.BigText
            horizontalAlignment: HorizontalAlignment.Center
            text: item.name
            textStyle.color: Color.DarkGreen
        }
        Button {
            horizontalAlignment: HorizontalAlignment.Center
            text: qsTr("Select Place")
            onClicked: placePicker.selectPlace()
        }
        Container {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            topMargin: ui.du(5.6)
            
            //! [1]
            FieldLabel {
                title: qsTr("name")
                field: "name"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("alternative name")
                field: "alternativeName"
                selectedPlace: placePicker.selectedPlace
            }
            //! [1]
            
            FieldLabel {
                title: qsTr("description")
                field: "description"
                selectedPlace: placePicker.selectedPlace
            }
            
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
            
            FieldLabel {
                title: qsTr("country")
                field: "country"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("postal code")
                field: "postal"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("address label")
                field: "addressLabel"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("phone")
                field: "phone"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("secondary phone")
                field: "secondaryPhone"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("fax")
                field: "fax"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("email")
                field: "email"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("web site")
                field: "url"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldNumber {
                title: qsTr("rating")
                field: "rating"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldLabel {
                title: qsTr("map URL")
                field: "mapURL"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldNumber {
                title: qsTr("latitude")
                field: "latitude"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldNumber {
                title: qsTr("longitude")
                field: "longitude"
                selectedPlace: placePicker.selectedPlace
            }
            
            FieldNumber {
                title: qsTr("altitude")
                field: "altitude"
                selectedPlace: placePicker.selectedPlace
            }
        }

        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            visible: !_requestService.active
            leftPadding: 10.0
        	Label {
                textStyle.base: SystemDefaults.TextStyles.TitleText
                horizontalAlignment: HorizontalAlignment.Left
                text: "Label       : " + item.label
            }
        	Label {
                textStyle.base: SystemDefaults.TextStyles.BodyText
                horizontalAlignment: HorizontalAlignment.Left
                text: "Createur    : " + item.created_by
            }
        	Label {
                textStyle.base: SystemDefaults.TextStyles.BodyText
                horizontalAlignment: HorizontalAlignment.Left
                text: "Region      : " + item.region
            }
        }
        
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            visible: !_requestService.active
            topPadding: 40.0
            leftPadding: 10.0
            Label {
                topMargin: ui.du(5) // 3 is the UI default for a large padding.
                text: "Adresse:"
                textStyle.fontSize: FontSize.Large
                textStyle.fontWeight: FontWeight.Bold
            }
            FieldLabel {
                title: qsTr("country")
                field: "country"
                selectedPlace: placePicker.selectedPlace
            }
            Label {
                text: item.country
            }
            Label {
                text: item.region
            }
            Label {
                text: item.zipcode+":"+item.town
            }
            Label {
                text: item.address
            }
            Label {
                text: "Téléphone      : " + item.phone
            }
            Label {
                text: "Mobile         : " + item.mobile
            }
        }

        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.TopToBottom
            }
            topPadding: 40.0
            leftPadding: 10.0
            visible: !_requestService.active
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
                    value: item.budget
                    leftPadding: 30
                    rightMargin: 30
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
                    value: item.service
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
                    value: item.quality
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
                    value: item.privacy
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
                    value: item.ambience
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
        }
    }
}
attachedObjects: [
    Phone {
        id: phone
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
}
}