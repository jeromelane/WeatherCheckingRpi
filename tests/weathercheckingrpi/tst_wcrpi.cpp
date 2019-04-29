#include <QtTest>
#include <QCoreApplication>

#include <iostream>

#include "../../weathercheckingrpi/appmodel.h"
#include "../../weathercheckingrpi/zambretti/Zambretti.h"


#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickItem>
#include <QLoggingCategory>

// add necessary includes here
QT_FORWARD_DECLARE_CLASS(AppModelPrivate);

class wcrpi : public QObject
{
    Q_OBJECT

public:
    wcrpi();
    ~wcrpi();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
    void test_case3();

};

wcrpi::wcrpi()
{

}

wcrpi::~wcrpi()
{

}

void wcrpi::initTestCase()
{

}

void wcrpi::cleanupTestCase()
{

}

void wcrpi::test_case1()
{
    //QString zpathtable = "/home/jerome/projects/WeatherCheckingRpi/tests/weathercheckingrpi/" ;
    QString zpathtable = "/home/pi/Bureau/Dev/WeatherCheckingRpi/tests/weathercheckingrpi/";
    AppModel *app;
    try{
        app = new AppModel();
    }catch (char const* e) {
        cerr << e << endl;
    }
    qDebug() << "Json doc: " << app->buildZambrettiQJsonDocument(zpathtable);
    app->setZtable(app->buildZambrettiQJsonDocument(zpathtable));
    QString strJson(app->ztable.toJson(QJsonDocument::Compact));
    qDebug() << "str Json: " << strJson;
    app->handleZambrettiNum(13);
    QVERIFY(app->weather()->weatherDescription() == "Fairly Fine , Showers likely");
}

void wcrpi::test_case2()
{
    QSKIP("skip measurement managment test");
    AppModel *app;
    try{
        app = new AppModel();
    }catch (char const* e) {
        cerr << e << endl;
    }

    struct bme280_dev dev;
    MetricsAverage measurement(&dev);// The initialization is done while creating the object measurement
    cout << "initialisation: "<< measurement.getSucessInitialization()<<endl;// this returns a boolean that tells you if the initialization went fine
    app->measurement = measurement;
    app->measurements = vector<struct data>();

    for(int i =0; i < 3; i++) {
        qDebug() << "measuring value " << i << endl;
        app->measurevalue();
    }

    Zambretti *Zamb = new Zambretti();
    app->manageMetricsAverage(Zamb);

    qDebug() << "-- measurements after removal: ";
    app->printMeasurements();

    QVERIFY(app->measurements.size() == 1);

}

void wcrpi::test_case3()
{
    AppModel *app;
    try{
        app = new AppModel();
    }catch (char const* e) {
        cerr << e << endl;
    }

    struct bme280_dev dev;
    MetricsAverage measurement(&dev);
    app->measurement = measurement;
    app->measurements = vector<struct data>();
    for(int i =0; i < 2; i++) {
        qDebug() << "measuring value " << i << endl;
        app->refreshWeather();
    }

    struct data test = refreshSensor(measurement.getDev());
    cout << "time:  " << test.currenttime << endl;
}

QTEST_MAIN(wcrpi)

#include "tst_wcrpi.moc"
