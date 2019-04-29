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

/*!
 * \author Jerome Lane
 */

#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QJsonDocument>
#include "sensor/MetricsAverage.h"
#include "sensor/sensor.h"
#include "zambretti/Zambretti.h"

class WeatherData : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString weatherIcon
               READ weatherIcon WRITE setWeatherIcon
               NOTIFY dataChanged)
    Q_PROPERTY(QString weatherDescription
               READ weatherDescription WRITE setWeatherDescription
               NOTIFY dataChanged)
    Q_PROPERTY(QString weatherTrend
               READ weatherTrend WRITE setWeatherTrend
               NOTIFY dataChanged)
    Q_PROPERTY(QString temperature
               READ temperature WRITE setTemperature
               NOTIFY dataChanged)
    Q_PROPERTY(QString pressure
               READ pressure WRITE setPressure
               NOTIFY dataChanged)
    Q_PROPERTY(QString humidity
               READ humidity WRITE setHumidity
               NOTIFY dataChanged)

public:
    explicit WeatherData(QObject *parent = nullptr);
    WeatherData(const WeatherData &other);

    QString weatherIcon() const;
    QString weatherDescription() const;
    QString weatherTrend() const;
    QString temperature() const;
    QString pressure() const;
    QString humidity() const;

    void setWeatherIcon(const QString &value);
    void setWeatherDescription(const QString &value);
    void setWeatherTrend(const QString &value);
    void setTemperature(const QString &value);
    void setPressure(const QString &pressure);
    void setHumidity(const QString &humidity);

signals:
    void dataChanged();

private:
    QString m_weather;
    QString m_weatherDescription;
    QString m_weatherTrend;
    QString m_temperature;
    QString m_pressure;
    QString m_humidity;

};

Q_DECLARE_METATYPE(WeatherData)

class AppModelPrivate;

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool ready
               READ ready
               NOTIFY readyChanged)
    Q_PROPERTY(WeatherData *weather
               READ weather
               NOTIFY weatherChanged)
    Q_PROPERTY(bool hasValidWeather
               READ hasValidWeather
               NOTIFY weatherChanged)

public:
    explicit AppModel(QObject *parent = nullptr);
    ~AppModel();

    bool hasValidWeather() const;
    bool ready() const;
    WeatherData *weather() const;
    QJsonDocument ztable;
    MetricsAverage measurement;
    vector <struct data> measurements;

public slots:
    Q_INVOKABLE void refreshWeather();


public:
    void handleZambrettiData();
    void handleZambrettiNum(int);
    void manageMetricsAverage(Zambretti *Zamb );
    QJsonDocument buildZambrettiQJsonDocument(QString zpathtable);
    void printMeasurement( struct data data ) const;
    void printMeasurements( ) const;
    void measurevalue();

    void setZambrettiQJsonDocument();
    QJsonDocument getZtable() const;
    void setZtable(const QJsonDocument &value);
    MetricsAverage getMeasurement() const;
    void setMeasurement(const MetricsAverage &value);
    vector<struct data> getMeasurements() const;
    void setMeasurements(const vector<struct data> &value);


signals:
    void readyChanged();
    void weatherChanged();
    void measurementsUpdated();


private:
    AppModelPrivate *d;

};
//! [4]

