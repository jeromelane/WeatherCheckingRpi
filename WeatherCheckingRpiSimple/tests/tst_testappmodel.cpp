#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestAppModel : public QObject
{
    Q_OBJECT

public:
    TestAppModel();
    ~TestAppModel();

private slots:
    void test_case1();

};

TestAppModel::TestAppModel()
{

}

TestAppModel::~TestAppModel()
{

}

void TestAppModel::test_case1()
{

}

QTEST_MAIN(TestAppModel)
#include "tst_testappmodel.moc"
