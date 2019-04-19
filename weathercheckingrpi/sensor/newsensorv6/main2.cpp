#include "sensor.h"

int main() {
    struct bme280_dev dev;
    struct data data_meteo;
    initSensor(&dev);
    data_meteo = refreshSensor(&dev);

return 0;
}
