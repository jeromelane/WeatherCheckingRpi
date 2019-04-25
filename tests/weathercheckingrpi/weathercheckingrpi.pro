QT += testlib core qml quick
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_wcrpi.cpp \
            ../../weathercheckingrpi/appmodel.cpp \
    ../../weathercheckingrpi/zambretti/Zambretti.cpp

HEADERS += ../../weathercheckingrpi/appmodel.h \
    ../../weathercheckingrpi/zambretti/Zambretti.h
