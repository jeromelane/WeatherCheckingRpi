#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestDbManager : public QObject
{
    Q_OBJECT

public:
    TestDbManager();
    ~TestDbManager();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

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

void TestDbManager::test_case1()
{

}

QTEST_MAIN(TestDbManager)

#include "tst_testdbmanager.moc"
