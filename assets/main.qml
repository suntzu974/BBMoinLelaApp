import bb.cascades 1.4
NavigationPane {
    id: nav
    Menu.definition: MenuDefinition {
        settingsAction: SettingsActionItem {
            onTriggered: {
                settings.open()
            }
        }
        helpAction: HelpActionItem {
            onTriggered: {
                nav.push(helpPageDefinition.createObject());
                //help.open()
            } 
        }
    } // end of MenuDefinition
    
Page {
    titleBar: TitleBar {
        title: "Liste"
    }
    actions: [
        ActionItem {
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Nouveau"
            imageSource: "asset:///icons/ic_add.png"
            onTriggered: {
                // Add New Item
                var newItem = newItemDefinition.createObject();
                nav.push(newItem);
            }
        },
        ActionItem {
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Refresh"
            imageSource: "asset:///icons/ic_resume.png"
            onTriggered: {
                activityIndicator.setRunning(true)
                _app.requestItem();
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
        ActivityIndicator {
            id: activityIndicator
            objectName: "activityIndicator"
            running: false
            visible: false
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            preferredWidth: 300
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }
        ListView {
            id: listItems
            dataModel: _app.model 
            function imageBase64(data) {
                return _app.imageFromBase64(data)
            }
            onTriggered: {
                listItems.clearSelection();
                toggleSelection(indexPath);
                var item = listItems.dataModel.data(indexPath);
                var itemDetails = itemPageDefinition.createObject();
                itemDetails.item = item;
                nav.push(itemDetails);
            }
            listItemComponents: [
                ListItemComponent {
                    type: "item"
                    StandardListItem {
                        contextActions: [
                            ActionSet {
                                DeleteActionItem {
                                    onTriggered: {
                                        var myview = standardListItem.ListItem.view;
                                        var dataModel = myview.dataModel;
                                        var indexPath = myview.selected();
                                        // data model must support item deletion.
                                        dataModel.removeItem(indexPath);
                                    }
                                }// DeleteActionItem
                            }// ActionSet
                        ] // ContextActions
                        id: itemRoot
                        title: ListItemData.name
                        description: ListItemData.label
                        status: ListItemData.region
                        image:itemRoot.ListItem.view.imageBase64(ListItemData.encoded)
                    }
                }  
            ]
        
        }
    
    }
}
attachedObjects: [
    Sheet {
    id: settings
    Page {
        titleBar: TitleBar {
        title: "Settings"
        kind: TitleBarKind.Default
            acceptAction: ActionItem {
            title: "OK"
                onTriggered: {
                // handle task creation here.
                    settings.close();
                }
            }
        }
        Container {
            topPadding: 10
            leftPadding: 10
            rightPadding: 10
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.TopToBottom
                }
                    TextField {
                            id: token
                            text: appSettings.token
                            hintText: "Enter token"
                            objectName: "token"
                            onTextChanged: {
//                                appSettings.setToken(text.toString())
                            }
                        }
                    // Address
                    TextField {
                        id: address
                        objectName: "address"
                        text: appSettings.address
                        inputMode: TextFieldInputMode.Url
                        hintText: "Enter address"
                        onTextChanged: {
                            appSettings.setAddress(text.toString())
                        }
                    }
                    // email
                    TextField {
                        id: email
                        objectName: "email"
                        text: appSettings.email
                        hintText: "Enter email"
                        inputMode: TextFieldInputMode.EmailAddress
                        onTextChanged: {
                            //appSettings.setEmail(text.toString())
                        }
                    }
                    // password
                    TextField {
                        id: password
                        objectName: "password"
                        text: appSettings.password
                        inputMode: TextFieldInputMode.Password
                        hintText: "Enter password"
                        onTextChanged: {
                            //appSettings.setPassword(text.toString())
                        }
                    }
                    // username
                    TextField {
                        id: username
                        objectName: "username"
                        text: appSettings.username
                        hintText: "Enter username"
                        inputMode: TextFieldInputMode.Text
                        onTextChanged: {
                            appSettings.setUsername(text.toString())
                        }
                    }

                    // userid
                    TextField {
                        id: userId
                        objectName: "userid"
                        text: appSettings.userId
                        inputMode: TextFieldInputMode.NumericPassword
                        hintText: "Enter user id"
                        onTextChanged: {
                            //appSettings.setUserid(text.toString())
                        }
                    }

                    Label {
                        id: gravityLabel
                        horizontalAlignment: HorizontalAlignment.Center
                        text: qsTr("GRAVITY") + Retranslate.onLanguageChanged
                        
                        textStyle {
                            base: SystemDefaults.TextStyles.BodyText
                        }
                    }
                    
                    ToggleButton {
                        id: gravity
                        checked: appSettings.gravity
                        objectName: "gravity"
                        horizontalAlignment: HorizontalAlignment.Center
                        
                        onCheckedChanged: {
                            appSettings.gravity = checked;
                        }
                        
                        accessibility {
                             labelledBy: gravityLabel
                        }
                    }                    
            } 
    }
    }
    },
    // HELP
    Sheet {
        id: help
        Page {
            titleBar: TitleBar {
                title: "Information"
                kind: TitleBarKind.Default
                acceptAction: ActionItem {
                    title: "OK"
                    onTriggered: {
                        // handle task creation here.
                        help.close();
                    }
                }
            }
            Container {
                topPadding: 10
                leftPadding: 10
                rightPadding: 10
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.TopToBottom
                    }
                    Label {
                        id: helpToken
                        text: appSettings.token
                        textStyle {
                            base: SystemDefaults.TextStyles.TitleText
                        }

                    }
                    Label {
                        id: helpEmail
                        text: appSettings.email
                        textStyle {
                            base: SystemDefaults.TextStyles.TitleText
                        }
                    }
                    Label {
                        id: helpUsername
                        text: appSettings.username
                        textStyle {
                            base: SystemDefaults.TextStyles.TitleTextt
                        }
                    }
                } 
            }
        }
    },
    ComponentDefinition {
        id: itemPageDefinition
        source: "itemDetails.qml"
    },
    ComponentDefinition {
        id: helpPageDefinition
        source: "helpPage.qml"
    },
    ComponentDefinition {
        id: newItemDefinition
        source: "newItem.qml"
    }

]
onPopTransitionEnded: {
    page.destroy();
}
onCreationCompleted: {
    //
}

}