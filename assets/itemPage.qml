import bb.cascades 1.4
import "controls"
    
Page {
    titleBar: TitleBar {
        title: "Liste"
    }
    Container {
        layout: DockLayout {}
        background: color.create("#CC3F10")
        // The background image
/*        ImageView {
            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill
            imageSource: "asset:///images/SplashMoinLela_1440_1440.png"
        }*/
        //! [2]
        NetworkActivity {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            active: _requestService.active
        }
        //! [2]
        Container {
            layout: DockLayout {
            }
            visible: !_requestService.active
            //! [2]
        ListView {
            id: listItems
            dataModel: _requestService.model 
            function imageBase64(data) {
                return _requestService.imageFromBase64(data)
            }
            onTriggered: {
                listItems.clearSelection();
                toggleSelection(indexPath);
                var item = listItems.dataModel.data(indexPath);
                var itemDetails = itemPageDefinition.createObject();
                itemDetails.item = item;
                navigationPane.push(itemDetails);
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
                        status: "Note :"+ ListItemData.stars
                        image:itemRoot.ListItem.view.imageBase64(ListItemData.encoded)
                    }
                }  
            ]
        }
    }
    }

    attachedObjects: [
        ComponentDefinition {
            id: itemPageDefinition
            source: "itemDetails.qml"
        }
    ]
}
