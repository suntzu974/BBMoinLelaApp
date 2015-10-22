  import bb.cascades 1.4
  import com.moinlela.MoinLelaRequest 1.0

NavigationPane {
    id: navigationPane
    Menu.definition: MenuDefinition {
        settingsAction: SettingsActionItem {
            onTriggered: {
                navigationPane.push(settingsPageDefinition.createObject())
            }
        }
    } // end of MenuDefinition

    Page {
        titleBar: TitleBar {
            title: "MoinLela"
        }
        actions: [
            ActionItem {
                ActionBar.placement: ActionBarPlacement.OnBar
                title: "Nouveau"
                imageSource: "asset:///icons/ic_add.png"
                onTriggered: {
                    // Add New Item
                    var newItem = newItemPageDefinition.createObject();
                    navigationPane.push(newItem);
                }
            },
            ActionItem {
                ActionBar.placement: ActionBarPlacement.OnBar
                title: "Search"
                imageSource: "asset:///icons/ic_search.png"
                onTriggered: {
                    // Search Item
                    var search = itemPageDefinition.createObject()
                    _requestService.requestItem(itemSearch.text)
                    navigationPane.push(search);
                }
            }

        ]
        Container {
            background: Color.create("#0098F0")
            layout: DockLayout {
            }
            // The background image
/*            ImageView {
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                imageSource: "asset:///images/SplashMoinLela_1440_1440.png"
            }*/
            Container {
                topPadding: 20
                bottomPadding: 20
                leftPadding: 20
                rightPadding: 20

                DropDown {
                    id: itemRegion
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
                TextField {
                    id: itemSearch
                    hintText: qsTr("Search")
                    text: "All"
                    inputMode: inputMode.Text
                    input {
                        submitKey: SubmitKey.Search
                        onSubmitted: {
                            var search = itemPageDefinition.createObject()
                            _requestService.requestItem(itemSearch.text)
                            navigationPane.push(search);

                        }
                    }
                }
            }
        }
    }
    
    attachedObjects: [
        ComponentDefinition {
            id: itemPageDefinition
            source: "itemPage.qml"
        },
        ComponentDefinition {
            id: settingsPageDefinition
            source: "settings.qml"
        },
        ComponentDefinition {
            id: newItemPageDefinition
            source: "newItem.qml"
        }

    ]
    
    onPopTransitionEnded: {
        search.deleteLater();
        newItem.deleteLater();
    }
}
