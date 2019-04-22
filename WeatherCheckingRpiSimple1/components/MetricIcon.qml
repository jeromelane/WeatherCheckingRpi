import QtQuick 2.0

Item {
    id: container

    property string metricIcon: "temperature"

    Image {
        id: img
        source: {
            switch (metricIcon) {
            case "temperature":
                 "../img/metrics/T.png"
                break;
            case "pression":
                "../img/metrics/P.png"
                break;
            case "humidity":
                "../img/metrics/RH.png"
                break;
            }
        }
        smooth: true
        anchors.fill: parent
    }
}
