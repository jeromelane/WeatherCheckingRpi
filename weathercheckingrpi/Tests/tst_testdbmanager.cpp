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
    void test_create();

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

void TestDbManager::test_create()
{
    QString name = "test.db";
    QString path = "./";
    DbManager db(path, name);

    db.createTable();
    QFileInfo check_file(path);
    QVERIFY(check_file.exists() && check_file.isFile());
}



QTEST_MAIN(TestDbManager)
#include "tst_testdbmanager.moc"
