import bb.cascades 1.4
import bb.data 1.0
import "controls"

Page {
    titleBar: TitleBar {
        title: "Settings"
    }

    Container {
        layout: DockLayout {
            
        }
        ListView {
            id: listview
            dataModel: ArrayDataModel {
                id: arrayDataModel
            }
            listItemComponents: [
                ListItemComponent {
                    CustomListItem {
                        dividerVisible: true
                        highlightAppearance: HighlightAppearance.Frame
                        Container {
                            verticalAlignment: VerticalAlignment.Center
                            layout:StackLayout {
                                orientation: LayoutOrientation.LeftToRight;                
                            }
                            ImageView{
                                id: image
                                preferredHeight: 110; preferredWidth: 110
                                imageSource: ListItemData.picture;
                                verticalAlignment: VerticalAlignment.Center
                                filterColor: Color.create("#96BB00")
                            }
                            Container {             
                                layout:StackLayout {}
                                bottomPadding: 10
                                Label{
                                    text: ListItemData.name
                                    textStyle.base: SystemDefaults.TextStyles.TitleText
                                    textStyle.color: Color.create("#CC3F10")
                                }
                                Label{
                                    text: ListItemData.label;                            
                                    textStyle.base: SystemDefaults.TextStyles.SubtitleText
                                } 
                            }
                        }
                    }
                }
            ]
            onTriggered: {
                if (indexPath == 0) {
                    navigationPane.push(helpPage.createObject());
                }
                if (indexPath == 1) {
                    navigationPane.push(userSession.createObject());
                }
            }
        } // ListView
        onCreationCompleted: {
            dataSource.load();
        }
    }
    attachedObjects: [
        ComponentDefinition {
            id: userSession
            source: "userSession.qml"
        },
        ComponentDefinition {
            id: helpPage
            source: "helpPage.qml"
        },
        DataSource {
            id: dataSource
            source: "asset:///menu.json"
            onDataLoaded: {
                for (var i = 0; i < data.length; i ++) {
                    arrayDataModel.append(data[i]);
                } }
        }
    ]
}
