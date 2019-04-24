import QtQuick 2.0

Item {
    id: current

    //property string topText: "20*"
    property string bottomText: "No weather forecast data"
    property string weatherIcon: "unknown"
    property real smallSide: (current.width < current.height ? current.width : current.height)

   /* Text {
        text: current.topText
        font.pointSize: 28
        anchors {
            top: current.top
            left: current.left
            topMargin: 5
            leftMargin: 5
        }
    }*/

    WeatherIcon {
        weatherIcon: current.weatherIcon
        //useServerIcon: false
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -15
        width: current.smallSide
        height: current.smallSide
    }

    Text {
        text: current.bottomText
        font.pointSize: 23
        wrapMode: Text.WordWrap
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        anchors {
            bottom: current.bottom
            right: current.right
            rightMargin: 5
        }
    }
}
