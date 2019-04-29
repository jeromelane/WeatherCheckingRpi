/*   
 =====================================================================================
 Name        : Sending Weather data to Data Base
 Author      : Katia
 Version     : 1
 Copyright   : NA
 Description : The resutling measurements for time, temperature, pressure and humidity
 are in the final structure meteo_data
 =====================================================================================         
*/
#include <time.h>
#include "MetricsAverage.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    struct bme280_dev dev;
    struct data AverageData;

    MetricsAverage measurement(&dev);// The initialization is done while creating the object measurement
    cout << "initialisation: "<<measurement.getSucessInitialization()<<endl;// this returns a boolean that tells you if the initialization went fine
    
    measurement.measurevalue();// This returns a structure data that contains the average values:
                                            /*struct data
                                        {
                                            int currenttime; (in seconds, origin of time: unix)
                                            float temperature; (in deg C)
                                            float pressure; (in Pa)
                                            float humidity;  (in %)
                                        };*/
    AverageData=measurement.getData();
    
    cout<<"L'horodatage de cette donnée est: "<<AverageData.currenttime<<endl;
    cout<<"La temperature moyennee sur 10 s est: "<<AverageData.temperature<<endl;
    cout<<"La pression moyenne sur 10 s est: "<<AverageData.pressure<<endl;
    cout<<"L'humidite moyenne sur 10 s est: "<<AverageData.humidity<<endl;

return 0;
}
