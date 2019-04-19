#include <QtTest>
#include <QCoreApplication>

#include <QString>
#include <QFileInfo>
#include "../dbmanager/dbmanager.h"

using namespace std;

class TestDbManager : public QObject
{
    Q_OBJECT

public:
    TestDbManager();
    ~TestDbManager();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_createTable();
    void test_connection();

};

TestDbManager::TestDbManager()
{

}

TestDbManager::~TestDbManager()
{

}

void TestDbManager::initTestCase()
{

}

void TestDbManager::cleanupTestCase()
{

}

void TestDbManager::test_connection()
{
    QString name = "test.db";
    QString path = "./";
    DbManager db;

    db.openConnection(path, name);

    QVERIFY(db.isOpen());

    db.closeConnection();
    db.removeDb(path,  name);
}

void TestDbManager::test_createTable()
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



QTEST_MAIN(TestDbManager)
#include "tst_testdbmanager.moc"
