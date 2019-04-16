#ifndef ZAMBRETTI_H_
#define ZAMBRETTI_H_
#include <string>
#include <time.h>
#include <float.h>
using namespace std;

class Zambretti{
    public:

    Zambretti();
    float getPressureVal();
    int getZnumber();
    void findZnumber();
    ~Zambretti();
    
    private:
    int m_trend;
    int m_Znumber;
    float m_CurrentPressure;
    float m_PastPressure;
    
};

#endif /* ZAMBRETTI_H_ */