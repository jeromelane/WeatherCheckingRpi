/*   
 =====================================================================================
 Name        : Zambretti algorithm
 Author      : Katia
 Version     : 1
 Copyright   : Your copyright notice
 Description : The algorithm is implemented for an altitude of 140 meters
 (correponding to the 3th floor of the test location). The altitude must be adjusted
 for different locations. The approximation used is a linear regression of the initial
 algorithm, retrieved from
 https://web.archive.org/web/20110610213848/http://www.meteormetrics.com/zambretti.htm
 =====================================================================================         
*/
#include "Zambretti.h"
#include <string>
#include <iostream>
#include <float.h>
using namespace std;

int main (void)

{
Zambretti Zamb;
//optionnal: initial values:
//cout << "la tendance de pression actuelle est :" <<Zamb.getTrend()<<endl;
//cout << "la valeur actuelle de la pression est: " <<Zamb.getCurrentPressure()<<endl;
//cout << "le nb de Zambretti est: " <<Zamb.getZnumber()<<endl;
// Calcul Zambretti:
Zamb.findZnumber();// this is the current Z number
cout << "la tendance de pression actuelle est :" <<Zamb.getTrend()<<endl;
cout << "le nb de Zambretti est: "<<Zamb.getZnumber()<<endl;

    return 0;
}
