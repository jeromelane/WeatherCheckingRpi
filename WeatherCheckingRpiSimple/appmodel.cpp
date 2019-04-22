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

#include "appmodel.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QTimer>
#include <QFile>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QLoggingCategory>
#include <QDir>

#include "dbmanager/dbmanager.h"

/*
 *This application uses http://openweathermap.org/api
 **/

#define ZERO_KELVIN 273.15

Q_LOGGING_CATEGORY(requestsLog,"wapp.requests")

WeatherData::WeatherData(QObject *parent) :
        QObject(parent)
{
}

WeatherData::WeatherData(const WeatherData &other) :
        QObject(nullptr),
        m_weather(other.m_weather),
        m_weatherDescription(other.m_weatherDescription),
        m_temperature(other.m_temperature)
{
}

QString WeatherData::weatherIcon() const
{
    return m_weather;
}

QString WeatherData::weatherDescription() const
{
    return m_weatherDescription;
}

QString WeatherData::weatherTrend() const
{
    return m_weatherTrend;
}

QString WeatherData::temperature() const
{
    return m_temperature;
}

QString WeatherData::pressure() const
{
    return m_pressure;
}

QString WeatherData::humidity() const
{
    return m_humidity;
}



void WeatherData::setWeatherIcon(const QString &value)
{
    m_weather = value;
    emit dataChanged();
}

void WeatherData::setWeatherDescription(const QString &value)
{
    m_weatherDescription = value;
    emit dataChanged();
}

void WeatherData::setWeatherTrend(const QString &value)
{
    m_weatherTrend = value;
    emit dataChanged();
}

void WeatherData::setTemperature(const QString &value)
{
    m_temperature = value;
    emit dataChanged();
}

void WeatherData::setPressure(const QString &pressure)
{
    m_pressure = pressure;
    emit dataChanged();
}

void WeatherData::setHumidity(const QString &humidity)
{
    m_humidity = humidity;
    emit dataChanged();
}

class AppModelPrivate
{
public:
    //static const int baseMsBeforeNewRequest = 5 * 1000; // 5 s, increased after each missing answer up to 10x
    WeatherData now;
    bool ready;
    QElapsedTimer throttle;
    //int nErrors;
    //int minMsBeforeNewRequest;
    QTimer requestNewWeatherTimer;
    DbManager db;

    AppModelPrivate() :
            ready(false)
            //nErrors(0)
            //minMsBeforeNewRequest(baseMsBeforeNewRequest)
    {
       // db = DbManager();
        //db.openConnection("mypath","test.db");

        requestNewWeatherTimer.setSingleShot(false);
        requestNewWeatherTimer.setInterval(1*10*1000); // 1 min
        //throttle.invalidate();
        //ready = true;
        //qDebug() << "ready: " + QString::number(ready);
    }
};

/*!
 * \brief niceTemperatureString
 * \param t
 * \return formatted Temperature QString
 */
static QString niceTemperatureString(double t)
{
    return QString::number(qRound(t)) + QChar(0xB0) ;
}

/*!
 * \brief nicePressureString
 * \param t
 * \return formatted pressure QString
 */
static QString nicePressureString(double t)
{
    return QString::number(qRound(t)) + "Pa";
}

/*!
 * \brief niceHumidityString
 * \param t
 * \return formatted humidity QString
 */
static QString niceHumidityString(double t)
{
    return QString::number(qRound(t)) + "%";
}


//! [0]
AppModel::AppModel(QObject *parent) :
        QObject(parent),
        d(new AppModelPrivate)
{
    //d->ready = true;

    double testtp = 20;
    double testpa = 959.5555;
    double testhumidity = 75;
    d->now.setTemperature(niceTemperatureString( testtp));
    d->now.setPressure(nicePressureString( testpa));
    d->now.setHumidity(niceHumidityString(testhumidity));

    int znum = 13;
    connect(&d->requestNewWeatherTimer, SIGNAL(timeout()), this, SLOT(handleZambrettiData(znum)));
    connect(&d->requestNewWeatherTimer, SIGNAL(timeout()), this, SLOT(refreshWeather()));


    d->requestNewWeatherTimer.start();



}

//! [1]

AppModel::~AppModel()
{
   // d->db.closeConnection();
    //TODO close db
    delete d;
}

void AppModel::handleZambrettiData(int zambretti_num)
{

    qDebug() << "got Zambretti data";

    QJsonParseError *error = new QJsonParseError();

    QString refpath="C:/Users/U/Documents/projets/WeatherCheckingRpi/WeatherCheckingRpiSimple";
    QFile zambjson(refpath+ "/data/zambretti_table.json");
    zambjson.open(QIODevice::ReadOnly | QIODevice::Text);
    QString inputData = zambjson.readAll();
    //qDebug() << inputData;
    QJsonDocument document = QJsonDocument::fromJson(inputData.toUtf8(),error);
    zambjson.close();

    QString strJson(document.toJson(QJsonDocument::Compact));
    //qDebug() <<   strJson;

    QJsonObject jo;
    QJsonValue jv;
    QJsonObject root = document.object();

    qDebug() << "# of json keys: " << QString::number(root.size());

    QString zqstring = QString::number(zambretti_num);
    jo = root.value(zqstring).toObject();

    d->now.setWeatherIcon(jo.value(QStringLiteral("Figure")).toString());
    d->now.setWeatherDescription(jo.value(QStringLiteral("Forecast Text")).toString());

    qDebug() << d->now.weatherIcon();
    qDebug() << d->now.weatherDescription();
    //emit weatherChanged();
}




/*!
 * \brief AppModel::refreshWeather
 * Access http://api.openweathermap.org/data/2.5/weather site to get a specific city data
 * Deals with connection errors
 */
void AppModel::refreshWeather()
{

    //qCDebug(requestsLog) << "refreshing weather";
    qDebug() << "refreshing weather";

    //d->db.getLastUpdatedMetrics();

    // connect up the signal right away
    //connect(rep, &QNetworkReply::finished, this, [this, rep]() { handleWeatherNetworkData(rep); });

    double testtp = 1;
    double testpa = 1;
    double testhumidity= 1;

    d->now.setTemperature(niceTemperatureString( testtp));
    d->now.setPressure(nicePressureString(testpa));
    d->now.setHumidity(niceHumidityString(testhumidity));
    d->now.setWeatherTrend("?");

   // d->ready = true;

    //emit readyChanged();
    //emit weatherChanged();
}


WeatherData *AppModel::weather() const
{
    return &(d->now);
}

bool AppModel::ready() const
{
    return d->ready;
}

