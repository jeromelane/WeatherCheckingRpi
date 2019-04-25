#pragma once
#if defined (__cplusplus)
extern "C" {
#endif
#include "bme280.h"

struct data
{
    int currenttime;
    float temperature;
    float pressure;
    float humidity; 
};
    // Initialize
    int8_t initSensor(struct bme280_dev *dev);

    // Get data
    struct data refreshSensor( struct bme280_dev *dev);
    
#if defined ( __cplusplus)
}
#endif