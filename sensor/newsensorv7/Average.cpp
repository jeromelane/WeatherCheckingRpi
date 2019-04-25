#include "Average.h"
#include <string>
#include <time.h>
#include <iostream>
#include "bme280.h"
#include "sensor.h"
using namespace std;

int rounded(float x){ // This function rounds a float to the nearest integer
            int Rinf=(int)x;
            float deci = x-Rinf;
            if (deci<0.5) return Rinf;
            else return Rinf+1;
            }
Average::Average(struct bme280_dev *dev) 
{
    m_N=9;
    //m_data_meteo_temp;
    //m_data_meteo_tab;
    m_data_meteo_sum.currenttime=0;
    //m_data_meteo;
    m_dev = dev;
    int8_t rslt_success;
    rslt_success=initSensor(dev);// We choose to initialize the sensor within the constructor
    if (rslt_success==0){m_success=0;}
}
bool Average::getSucessInitialization()
{
    return this->m_success;
}

struct data Average::getData()
{
    return this->m_data_meteo;
}

void Average::measurevalue(){
for (int i=0; i<=m_N; i++)
    { 
        int goal;
        goal=time(NULL)+1;
        this->m_data_meteo_temp = refreshSensor(this->m_dev);
        this->m_data_meteo_temp.currenttime-=1555900000;
        // we must substract a value in order to compute an average
        // without exceeding the maximum value of the integer type
        m_data_meteo_tab.currenttimetab[i]=m_data_meteo_temp.currenttime;
        m_data_meteo_tab.temperaturetab[i]=m_data_meteo_temp.temperature;
        m_data_meteo_tab.pressuretab[i]=m_data_meteo_temp.pressure;
        m_data_meteo_tab.humiditytab[i]=m_data_meteo_temp.humidity;
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
}
Average::~Average()
{
}