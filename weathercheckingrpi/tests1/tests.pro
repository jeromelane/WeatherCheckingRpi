QT += testlib sql
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testdbmanager.cpp \
            "../dbmanager/dbmanager.cpp"

HEADERS += "../dbmanager/dbmanager.h"
