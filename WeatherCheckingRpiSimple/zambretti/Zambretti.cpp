#include "Zambretti.h"
#include <string>
#include <iostream>
#include <time.h>
#include <float.h>
using namespace std;

int rounded(float x){ // This function rounds a float to the nearest integer
            int Rinf=(int)x;
            float deci = x-Rinf;
            if (deci<0.5) return Rinf;
            else return Rinf+1;
            }

Zambretti::Zambretti()
{
    m_trend = -1; // For falling barometer: m_trend=0
                  // For steady barometer: m_trend=1
                  // For rising barometer: m_trend=2
                  // If not available, available: m_trend=-1
    m_Znumber = -1; //Zambretti number (=-1 of not available, =Zambretti number if available)
    m_CurrentPressure = 10000; // pressure (Pa)
    m_PastPressure= 9998;
}
int Zambretti::getTrend()
{
   return this->m_trend; 
}
void Zambretti::setTrend(int currenttrend)
{
    this->m_trend = currenttrend;
}

float Zambretti::getCurrentPressure()
{
    return this->m_CurrentPressure;
}
int Zambretti::getZnumber()
{
    return this->m_Znumber;
}

void Zambretti::findZnumber()
{   float cP;
    float pP;
    float CorrectionFactor=1;// Correction factor corresponding to a 140 m altitude
    cP=this->m_CurrentPressure;
    pP=this->m_PastPressure;
    float cPsealevel;
    float pPsealevel;
    cPsealevel= cP*CorrectionFactor;
    pPsealevel=pP*CorrectionFactor;
    float trend = (pPsealevel-cPsealevel)*6; //trend /h over 10min
    cout<<"la tendance est: "<< trend <<"Pa/hour"<<endl;
    if (trend>0){if (trend<30) {this->m_trend=1;}else{this->m_trend=2;}}
    else{if (trend>-30){this->m_trend=1;}else{this->m_trend=0;}};
    int i=this->m_trend;
    switch (i)
    {
        case -1:this->m_Znumber=-1;break;
        case 0:this->m_Znumber=rounded(130-cP/81);break;
        case 1:this->m_Znumber=rounded(147-(5*cP)/376);break;
        case 2:this->m_Znumber=rounded(179-(2*cP)/129);
            break;

        default:m_Znumber=-1;
            break;
    }
}

Zambretti::~Zambretti()
{
}
