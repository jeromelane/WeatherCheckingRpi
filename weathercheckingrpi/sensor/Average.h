#ifndef AVERAGE_H_
#define AVERAGE_H_
#include <string>
#include <time.h>
#include <iostream>
#include "sensor.h"
using namespace std;

int rounded(float x);

struct datatab // This structure is used to record a set of values
//The size of this table must be equal to (m_N-1), N is the variable used in:
//void Average::measurevalue()
{
    int currenttimetab[10];
    float temperaturetab[10];
    float pressuretab[10];
    float humiditytab[10]; 
};

class Average{

public:
    Average();
    Average(struct bme280_dev *dev);
    void measurevalue();
    bool getSucessInitialization();
    struct data getData();
    int rounded(float x);
    ~Average();

private:
    int m_N;
    struct data m_data_meteo_temp;
    struct datatab m_data_meteo_tab;
    struct data m_data_meteo_sum;
    struct data m_data_meteo;
    struct bme280_dev *m_dev;
    bool m_success;
};

#endif /* AVERAGE_H_ */
