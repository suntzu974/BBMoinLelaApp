import bb.cascades 1.4
import QtQuick 1.1

Item {
    id: starRating
    width:  140
    height:  24
    
    property int ratingLevel: 0
    
    Row {
        Repeater {
            model: 5
            Image {
                width: starRating.height
                height: starRating.height
                fillMode: Image.PreserveAspectFit
                smooth: true
                source:"asset:///images/star.png"
            }
        }
    }
    
    Row {
        Repeater {
            model: ratingLevel
            Image {
                width: starRating.height
                height: starRating.height
                fillMode: Image.PreserveAspectFit
                smooth: true
                source:"asset:///images/star.png"
            }
        }
    }
}