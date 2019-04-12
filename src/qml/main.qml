import QtQuick 2.0
import QtQuick.Window 2.0

Window
{
    id: root
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    title: "Weather Station"
    
    Image {
            width: Screen.desktopAvailableWidth
            height: Screen.desktopAvailableHeight
            fillMode: Image.Stretch 
            source: "data/img/sky_bg.jpg"
        }

    Rectangle {
        Text {
            id: msg1
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            text: "<h1>Weather Metrics</h1>"
        }
        
        color: "transparent"
        
        x: 0
        y: 0
        
        border.width : 2
        width: parent.width / 2
        height: parent.height
 
    }
    
    Rectangle {
        Text {
            id: msg2
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            text: "<h1>Weather Trend</h1>"
        }
        
        text: obj.temp #TODO MonObjet instancier dans main.cpp et passer a qml
        color: "transparent"
        
        x: parent.width / 2
        y: 0
        
        border.width : 2
        
        width: parent.width / 2
        height: parent.height
        
        Rectangle {
            x: (parent.width / 4)
            y: 0
            
            border.width : 2

            Image {
                width: 100
                height: 50
//                 fillMode: Image.Stretch 
                source: "data/img/sun_bg.jpg"
            }
            MouseArea {
                onCLicked:
                
            }

    
        }
 
    }
    
}
