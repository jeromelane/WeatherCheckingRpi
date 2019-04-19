#include <QtTest/QtTest>
#include "../weatherdata.h"

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void TestQString::toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

class TestWeatherData: public QObject
{
    Q_OBJECT
private slots:
    void setWeatherDescription();
};

void TestWeatherData::setWeatherDescription()
{
    QString str = "MyDescription";
    WeatherData wd;
    wd.setWeatherDescription(str);
    QVERIFY(wd.weatherDescription() == str);
}

QTEST_MAIN(TestWeatherData)
#include "tests.moc"
