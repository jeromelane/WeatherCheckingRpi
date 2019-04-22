#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>

class TestSuite : public QObject
{
public:
     TestSuite();

     static std::vector<QObject*> & suite();
};

#endif // TESTSUITE_H
