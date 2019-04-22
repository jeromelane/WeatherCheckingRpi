#include <QtTest>
#include <QCoreApplication>

#include <QString>
#include <QFileInfo>
#include "../dbmanager/dbmanager.h"
#include "../../WeatherCheckingRpiSimple/appmodel.h"
//#include "../appmodel.h"

using namespace std;

class TestAppModel : public QObject
{
    Q_OBJECT

public:
    TestAppModel();
    ~TestAppModel();

private slots:
    void test_createTable();
    void test_connection();
    void test_zambretti();

};

TestAppModel::TestAppModel()
{

}

TestAppModel::~TestAppModel()
{

}

void TestAppModel::test_connection()
{
    QString name = "test.db";
    QString path = "./";
    DbManager db;

    db.openConnection(path, name);

    QVERIFY(db.isOpen());

    db.closeConnection();
    db.removeDb(path,  name);
}

void TestAppModel::test_createTable()
{
    QString name = "test.db";
    QString path = "./";
    DbManager db;
    db.openConnection(path, name);
    db.createTable();
    QFileInfo check_file(path + "/" + name);
    QVERIFY(check_file.exists() && check_file.isFile());
    db.closeConnection();
    db.removeDb(path,  name);
}

void TestAppModel::test_zambretti()
{
    int znum = 13;
    AppModel app(nullptr);
    /*app.handleZambrettiData(znum);
    //AppModelPrivate* d = app.getD();
    //QVERIFY(d->now.weatherDescription == "Fairly Fine , Showers likely");
    QVERIFY(true);*/
}


QTEST_MAIN(TestAppModel)
#include "tst_testappmodel.moc"
