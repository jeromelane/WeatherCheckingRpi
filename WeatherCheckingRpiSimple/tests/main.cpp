#include "tst_testdbmanager.hpp"
#include <QtTest/QtTest>


int main(int argc, char *argv[])
{
    int status = 0;
    status |= QTest::qExec(new TestDbManager, argc, argv);
    // status |= QTest::qExec(new TestObject, argc, argv);
    // status |= QTest::qExec(new ..., argc, argv);

    return status;

    /*// setup lambda
    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    auto &suite = TestSuite::suite();
    for (auto it = suite.begin(); it != suite.end(); ++it) {
        runTest(*it);
    }*/
}
