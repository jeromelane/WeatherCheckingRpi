QT += testlib sql core network positioning qml quick
QT += gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += qt warn_on depend_includepath testcase c++11

TEMPLATE = app

SOURCES +=  \
            "../dbmanager/dbmanager.cpp" \
    main.cpp

HEADERS += "../dbmanager/dbmanager.h" \
    tst_testdbmanager.hpp
