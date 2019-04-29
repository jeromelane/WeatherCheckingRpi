#include "MetricsAverage.h"
#include <string>
#include <time.h>
#include <iostream>
#include "bme280.h"
#include "sensor.h"
using namespace std;

struct bme280_dev g_dev;

MetricsAverage::MetricsAverage()
{

}

MetricsAverage::MetricsAverage(struct bme280_dev *dev)
{
    m_N=9;
    //m_data_meteo_temp;
    //m_data_meteo_tab;
    m_data_meteo_sum.currenttime=0;
    //m_data_meteo;
    m_dev = &g_dev;
    int8_t rslt_success;
    rslt_success=initSensor(this->m_dev);// We choose to initialize the sensor within the constructor
    if (rslt_success==0){m_success=0;}
        //qDebug() << "Init : " << m_dev;

}
bool MetricsAverage::getSucessInitialization()
{
    return this->m_success;
}

struct data MetricsAverage::getData()
{
    return this->m_data_meteo;
}


int MetricsAverage::rounded(float x){ // This function rounds a float to the nearest integer
    int Rinf=(int)x;
    float deci = x-Rinf;
    if (deci<0.5) return Rinf;
    else return Rinf+1;
    }


MetricsAverage::~MetricsAverage()
{
}

bme280_dev *MetricsAverage::getDev() const
{
    return m_dev;
}

void MetricsAverage::setDev(bme280_dev *dev)
{
    m_dev = dev;
}

void MetricsAverage::measurevalue(){
    qDebug() << "measure value";
    //qDebug() << "measure value : " << m_dev;

    for (int i=0; i<=m_N; i++)
    {
        int goal;
        goal=time(NULL)+1;

        //qDebug() <<  this->m_dev;
        //qDebug() << "refresh sensor boucle 1";
        //This line makes the programme crash when refreshing with Qt connect method
        this->m_data_meteo_temp = refreshSensor(this->m_dev);
        //qDebug() << "fin refresh sensor 1.1";
        this->m_data_meteo_temp.currenttime-=1555900000;
        // we must substract a value in order to compute an average
        // without exceeding the maximum value of the integer type
        m_data_meteo_tab.currenttimetab[i]=m_data_meteo_temp.currenttime;
        m_data_meteo_tab.temperaturetab[i]=m_data_meteo_temp.temperature;
        m_data_meteo_tab.pressuretab[i]=m_data_meteo_temp.pressure;
        m_data_meteo_tab.humiditytab[i]=m_data_meteo_temp.humidity;
        //qDebug() << "fin boucle 1.2";
        while(goal>time(NULL)){};//wait until the next second
    }

    this->m_data_meteo_sum.currenttime=0;
    this->m_data_meteo_sum.temperature=0;
    this->m_data_meteo_sum.pressure=0;
    this->m_data_meteo_sum.humidity=0;

    for (int i=0; i<=m_N; i++){
        this->m_data_meteo_sum.currenttime+=m_data_meteo_tab.currenttimetab[i];
        this->m_data_meteo_sum.temperature+=m_data_meteo_tab.temperaturetab[i];
        this->m_data_meteo_sum.pressure+=m_data_meteo_tab.pressuretab[i];
        this->m_data_meteo_sum.humidity+=m_data_meteo_tab.humiditytab[i];
    }

    m_data_meteo.currenttime=(rounded(m_data_meteo_sum.currenttime/(m_N+1)))+1555900000;
    m_data_meteo.temperature=(m_data_meteo_sum.temperature/(m_N+1));
    m_data_meteo.pressure=(m_data_meteo_sum.pressure/(m_N+1))/10;
    m_data_meteo.humidity=(m_data_meteo_sum.humidity/(m_N+1));
    //qDebug() << "fin boucle 2";
}
