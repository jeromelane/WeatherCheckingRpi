import QtQuick 2.0

Item {
    id: top

    property string metricIcon: "temperature"
    property string middileText: "Temperature:"
    property string rightText: "*"
    property int nbMetrics: 3

    MetricIcon {
        id: icon
        metricIcon: top.metricIcon

        property real side: {
            var h = 3 * top.height / nbMetrics
            if (top.width < h)
                top.width;
            else
                h;
        }

        width: icon.side
        height: icon.side

        anchors.centerIn: parent
    }

    Text {
        id: metricText
        horizontalAlignment: Text.AlignHCenter
        width: top.width
        text: top.middileText

        anchors.top: parent.top
        anchors.topMargin: top.height / nbMetrics - metricText.paintedHeight
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: valueText
        horizontalAlignment: Text.AlignHCenter
        width: top.width
        text: top.rightText

        anchors.bottom: parent.bottom
        anchors.bottomMargin: top.height / nbMetrics - valueText.paintedHeight
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
