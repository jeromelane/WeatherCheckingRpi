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
#include <QCoreApplication>

//#include "dbmanager/dbmanager.h"
#include "zambretti/Zambretti.h"
#include "sensor/MetricsAverage.h"
#include "sensor/sensor.h"
#include <iostream>

using namespace std;


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


class AppModelPrivate
{
public:
    //static const int baseMsBeforeNewRequest = 5 * 1000; // 5 s, increased after each missing answer up to 10x
    WeatherData now;
   // vector <Average> averages;
    bool ready;
    //QElapsedTimer throttle;
    //int nErrors;
    //int minMsBeforeNewRequest;
        //DbManager db;
    QTimer requestNewWeatherTimer;


    AppModelPrivate():
            ready(false)
            //nErrors(0)
            //minMsBeforeNewRequest(baseMsBeforeNewRequest)
    {
       // db = DbManager();
        //db.openConnection("mypath","test.db");


        requestNewWeatherTimer.setSingleShot(false);
        requestNewWeatherTimer.setInterval(1*1*1000); // 1 s

        //throttle.invalidate();
        //ready = true;
        //qDebug() << "ready: " + QString::number(ready);
    }


};




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

static QString niceZamberttiTrendString(signed int t)
{
    QString symb ;
    switch(t) {
    case 1:
        symb = "=";
        break;
    case 0:
        symb = "-";
        break;
    case 2:
        symb = "+";
         break;
    default:
        symb = "?";
    }
    return symb;

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

   /* double testtp = 20;
    double testpa = 959.5555;
    double testhumidity = 75;*/

    struct bme280_dev dev;
   // struct data avg;

    MetricsAverage measurement(&dev);// The initialization is done while creating the object measurement
    cout << "initialisation: "<< measurement.getSucessInitialization()<<endl;// this returns a boolean that tells you if the initialization went fine
    this->measurement=measurement;
    this->measurements = vector<struct data>();

    try{

        setZambrettiQJsonDocument();

        /*measurement.measurevalue();
        avg = measurement.getData();
        this->measurements.push_back( avg );
        printMeasurements();*/

        qDebug() << "measurments round finished";

        /*d->now.setTemperature(niceTemperatureString(avg.temperature));
        d->now.setPressure(nicePressureString(avg.pressure));
        d->now.setHumidity(niceHumidityString(avg.humidity));*/

        //connect(&d->requestNewWeatherTimer, SIGNAL(timeout()), this, SLOT(refreshWeather()));
        //d->requestNewWeatherTimer.start();

        connect(this, SIGNAL(measurementsUpdated()), this, SLOT(refreshWeather()));
        this->measurevalue();

    } catch (char const* chain) {
        cerr << chain << endl;
    }

}

void AppModel::measurevalue(){
    this->measurement.measurevalue();
    this->measurements.push_back(this->measurement.getData());
    emit measurementsUpdated();
}

AppModel::~AppModel()
{

    delete d;
}

QJsonDocument AppModel::buildZambrettiQJsonDocument(QString zpathtable)
{
    QJsonParseError *error = new QJsonParseError();

    //QString refpath="C:/Users/U/Documents/projets/WeatherCheckingRpi/WeatherCheckingRpiSimple";
    QFile zambjson(zpathtable + "/data/zambretti_table.json");
    zambjson.open(QIODevice::ReadOnly | QIODevice::Text);
    QString inputData = zambjson.readAll();
    //qDebug() << inputData;
    QJsonDocument document = QJsonDocument::fromJson(inputData.toUtf8(),error);
    zambjson.close();
    return document;
}
void AppModel::setZambrettiQJsonDocument()
{
    const QStringList args = QCoreApplication::arguments();

    if(args.count() > 1)
    {
        QString zpathtable = args[1];
        qDebug() << "got Zambretti data";
        this->ztable = buildZambrettiQJsonDocument(zpathtable);
        //return document;
    } else {
        throw "No args provided, please provide the Zambretti table path.";
    }
}

bool AppModel::ready() const
{
    return d->ready;
}

void AppModel::handleZambrettiData()
{
    qDebug() << "handleZambrettiData";
    Zambretti *Zamb = new Zambretti();
    if(this->getMeasurements().size() >= 2){
        Zamb->setCurrentPressure( this->getMeasurements().back().pressure);
        Zamb->setPastPressure(this->getMeasurements().front().pressure ) ;
        this->getMeasurements().erase (this->getMeasurements().begin());

    }
    // Calcul Zambretti:
    Zamb->findZnumber();// this is the current Z number
    qDebug() << "la tendance de pression actuelle est :" <<Zamb->getTrend()<<endl;
    qDebug() << "le nb de Zambretti est: "<<Zamb->getZnumber()<<endl;

    //execute zambretti algo here.
    if(Zamb->getTrend() != -1){
        d->now.setWeatherTrend(niceZamberttiTrendString(Zamb->getTrend()));
    } else {
        qDebug() << "No trend available";
    }

    signed int zambretti_num = Zamb->getZnumber();
    if( zambretti_num  != -1) {
        handleZambrettiNum(zambretti_num);
    }
    delete Zamb;
}

void AppModel::handleZambrettiNum(signed int zambretti_num)
{
    qDebug() << "got Zambretti number";

    //QString strJson(d->ztable.toJson(QJsonDocument::Compact));
    //qDebug() <<   strJson;

    QJsonObject jo;
    //QJsonValue jv;
    QJsonObject root = this->ztable.object();

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

    qDebug() << "refreshing weather";

    /*measurement.measurevalue();
    struct data avg = measurement.getData();
    this->measurements.push_back( avg );
    printMeasurements();*/
    niceTemperatureString( this->getMeasurements().back().temperature);
    // qDebug() << "tests";

     qDebug() << niceTemperatureString( this->getMeasurements().back().temperature);

    d->now.setTemperature(niceTemperatureString( this->getMeasurements().back().temperature));
    d->now.setPressure(nicePressureString(this->getMeasurements().back().pressure));
    d->now.setHumidity(niceHumidityString(this->getMeasurements().back().humidity));
    d->now.setWeatherTrend("?");

    handleZambrettiData();

    emit weatherChanged();
}


WeatherData *AppModel::weather() const
{
    return &(d->now);
}

void AppModel::printMeasurements() const
{
    for(auto const& m: measurements) {
        printMeasurement(m);
    }
}



void AppModel::printMeasurement( struct data data ) const
{

    cout << to_string(data.humidity) << endl;
    cout << to_string(data.pressure)  << endl;
    cout << to_string(data.temperature) << endl;
    cout << to_string(data.currenttime) << endl;

}


vector<struct data> AppModel::getMeasurements() const
{
    return measurements;
}

void AppModel::setMeasurements(const vector<struct data> &value)
{
    measurements = value;
}

MetricsAverage AppModel::getMeasurement() const
{
    return measurement;
}

void AppModel::setMeasurement(const MetricsAverage &value)
{
    measurement = value;
}


QJsonDocument AppModel::getZtable() const
{
    return ztable;
}

void AppModel::setZtable(const QJsonDocument &value)
{
    ztable = value;
}

bool AppModel::hasValidWeather() const
{
    return !((d->now.weatherIcon().isEmpty()) && (d->now.weatherIcon().size() > 1) && d->now.weatherIcon() != "");
}

