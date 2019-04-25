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
    QString zpathtable = "/home/jerome/projects/WeatherCheckingRpi/tests/weathercheckingrpi/" ;

    AppModel *app;
    try{
        app = new AppModel();
    }catch (char const* e) {
        cerr << e << endl;
    }
    qDebug() << app->buildZambrettiQJsonDocument(zpathtable);
    app->setZtable(app->buildZambrettiQJsonDocument(zpathtable));
    QString strJson(app->ztable.toJson(QJsonDocument::Compact));
    app->handleZambrettiNum(13);
    QVERIFY(app->weather()->weatherDescription() == "Fairly Fine , Showers likely");
}

QTEST_MAIN(wcrpi)

#include "tst_wcrpi.moc"
