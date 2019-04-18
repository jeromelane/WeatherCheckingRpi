<<<<<<< HEAD:zambretti/Zambretti.h
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
    
    private:
    int m_trend;
    int m_Znumber;
    float m_CurrentPressure;
    float m_PastPressure;
    
};

=======
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

>>>>>>> 8bcf0e42e76d1ed8caa6abe9ccf0d0389d45d6db:weathercheckingrpi/zambretti/Zambretti.h
#endif /* ZAMBRETTI_H_ */