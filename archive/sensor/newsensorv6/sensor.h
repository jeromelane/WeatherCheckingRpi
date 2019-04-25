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
//rangeoutside()?? ... nope

    // Initialisation
    int8_t initSensor(struct bme280_dev *dev);

    //recuperation des donnees:
    struct data refreshSensor( struct bme280_dev *dev);
    
    #if defined ( __cplusplus)
}
#endif