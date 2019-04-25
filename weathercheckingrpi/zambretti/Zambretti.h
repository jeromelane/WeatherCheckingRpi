#ifndef ZAMBRETTI_H_
#define ZAMBRETTI_H_
#include <string>
#include <time.h>
#include <float.h>
using namespace std;

class Zambretti{
    public:

    Zambretti();
    int getTrend();
    void setTrend(int currenttrend);
    float getCurrentPressure();
    int getZnumber();
    void findZnumber();
    ~Zambretti();
    
    void setCurrentPressure(float CurrentPressure);

    float getPastPressure() const;
    void setPastPressure(float PastPressure);

private:
    int m_trend;
    int m_Znumber;
    float m_CurrentPressure;
    float m_PastPressure;
    
};

#endif /* ZAMBRETTI_H_ */
