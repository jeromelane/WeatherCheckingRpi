/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import "components"
//! [0]
import WeatherChecking 1.0

Item {
    id: window

    width: 360
    height: 640

    state: "ready"

    states: [
        State {
            name: "loading"
            PropertyChanges { target: main; opacity: 0 }
            PropertyChanges { target: wait; opacity: 1 }
            /*when: (state == "ready")
            PropertyChanges { target: main; opacity: 1 }
            PropertyChanges { target: wait; opacity: 0 }
            PropertyChanges { target: iconRow; opacity: 0 }*/

        },
        State {
            name: "ready"
            PropertyChanges { target: main; opacity: 1 }
            PropertyChanges { target: wait; opacity: 0 }
            /*PropertyChanges { target: sensor; opacity: 0 }
            PropertyChanges { target: iconRow; opacity: 1 }*/
        }/*
        State {
            name: "useSensor"
            PropertyChanges { target: iconRow; opacity: 0 }
            PropertyChanges { target: sensor; opacity: 1 }
        }*/
    ]
//! [1]
    AppModel {
        id: model
        onReadyChanged: {
            if (model.ready)
                window.state = "ready"
            else
                window.state = "loading"
        }
    }
//! [1]
    Item {
        id: wait
        anchors.fill: parent

        Text {
            text: "Loading weather data..."
            anchors.centerIn: parent
            font.pointSize: 18
        }
    }

    Item {
        id: main
        anchors.fill: parent

        Column {
            //id: mycol
            spacing: 6

            anchors {
                fill: parent
                topMargin: 6; bottomMargin: 6; leftMargin: 6; rightMargin: 6
            }

            Rectangle {
                width: parent.width
                height: 25
                color: "lightgrey"

                Text {
                    //text: (model.hasValidCity ? model.city : "Unknown location") + (model.useGps ? " (GPS)" : "" ) + (model.useSensor ? " (Sensor)" : "" )
                    text: "BME280 Sensor"
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }


            }

            BigForecastIcon {
                id: current

                width: main.width - 12
                height: 2 * (main.height - 25 - 12) / 3

                weatherIcon: (model.hasValidWeather  ? model.weather.weatherIcon : "01d")

                //topText: (model.hasValidWeather ? model.weather.temperature : "??")

                bottomText: (model.hasValidWeather ? model.weather.weatherDescription  : "No weather data") + (model.hasValidWeather ? model.weather.weatherTrend : " NA ")

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        model.refreshWeather()
                    }
                }
            }


            Row{
                id: sensor
                width: main.width - 12
                height: (main.height - 25 - 24) / 3

                property real iconWidth: sensor.width / 4 - 10
                property real iconHeight: sensor.height

                spacing: sensor.width - (4 * sensor.iconWidth)

                SensorIcon {
                    id: metric1
                    width: sensor.iconWidth
                    height: sensor.iconHeight

                    metricIcon: "temperature"
                    middileText: "Temperature"
                    rightText: model.weather.temperature

                }
                SensorIcon {
                    id: metric2
                    width: sensor.iconWidth
                    height: sensor.iconHeight

                    metricIcon: "pression"
                    middileText: "Pression"
                    rightText: model.weather.pressure

                }
                SensorIcon {
                    id: metric3
                    width: sensor.iconWidth
                    height: sensor.iconHeight

                    metricIcon: "humidity"
                    middileText: "Humidiy"
                    rightText: model.weather.humidity
                }
            }//row
        } //column
    }//Item
}

