QT += testlib core qml quick
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_wcrpi.cpp \
            ../../weathercheckingrpi/appmodel.cpp \
            ../../weathercheckingrpi/zambretti/Zambretti.cpp \
            ../../weathercheckingrpi/sensor/MetricsAverage.cpp \
            ../../weathercheckingrpi/sensor/bme280.c \
            ../../weathercheckingrpi/sensor/sensor.c

HEADERS += ../../weathercheckingrpi/appmodel.h \
            ../../weathercheckingrpi/zambretti/Zambretti.h \
            ../../weathercheckingrpi/sensor/MetricsAverage.h \
            ../../weathercheckingrpi/sensor/bme280.h \
            ../../weathercheckingrpi/sensor/bme280_defs.h \
            ../../weathercheckingrpi/sensor/sensor.h
