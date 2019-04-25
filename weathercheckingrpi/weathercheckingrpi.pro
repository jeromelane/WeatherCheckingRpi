TEMPLATE= app
QT += core qml quick
#requires(qtConfig(bearermanagement))

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    appmodel.cpp \
    zambretti/Zambretti.cpp
    #sensor/bme280.c \
    #sensor/Average.cpp \
    #sensor/sensor.c


HEADERS += appmodel.h \
        zambretti/Zambretti.h \
    #sensor/Average.h \
    #sensor/bme280.h \
    #sensor/bme280_defs.h \
    #sensor/sensor.h


RESOURCES += \
    weathercheckingrpi.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    components/WeatherIcon.qml \
    components/ForecastIcon.qml \
    components/BigForecastIcon.qml \
    components/SensorIcon.qml \
    class_diag.qmodel \
    diag_seq.qmodel \
    diad_class_dbmanager.qmodel \
    diag_activity.qmodel

#SUBDIRS += \
 #   tests/tests.pro
