/****************************************************************************
** Meta object code from reading C++ file 'appmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weathercheckingrpi/appmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherData_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherData_t qt_meta_stringdata_WeatherData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WeatherData"
QT_MOC_LITERAL(1, 12, 11), // "dataChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "weatherIcon"
QT_MOC_LITERAL(4, 37, 18), // "weatherDescription"
QT_MOC_LITERAL(5, 56, 12), // "weatherTrend"
QT_MOC_LITERAL(6, 69, 11), // "temperature"
QT_MOC_LITERAL(7, 81, 8), // "pressure"
QT_MOC_LITERAL(8, 90, 8) // "humidity"

    },
    "WeatherData\0dataChanged\0\0weatherIcon\0"
    "weatherDescription\0weatherTrend\0"
    "temperature\0pressure\0humidity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       6,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       4, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void WeatherData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherData *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherData::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WeatherData *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->weatherIcon(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->weatherDescription(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->weatherTrend(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->temperature(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->pressure(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->humidity(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WeatherData *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWeatherIcon(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWeatherDescription(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setWeatherTrend(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setTemperature(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setPressure(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setHumidity(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject WeatherData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherData.data,
      qt_meta_data_WeatherData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherData.stringdata0))
        return static_cast<void*>(const_cast< WeatherData*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WeatherData::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_AppModel_t {
    QByteArrayData data[11];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppModel_t qt_meta_stringdata_AppModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppModel"
QT_MOC_LITERAL(1, 9, 12), // "readyChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "weatherChanged"
QT_MOC_LITERAL(4, 38, 19), // "measurementsUpdated"
QT_MOC_LITERAL(5, 58, 14), // "refreshWeather"
QT_MOC_LITERAL(6, 73, 12), // "measurevalue"
QT_MOC_LITERAL(7, 86, 5), // "ready"
QT_MOC_LITERAL(8, 92, 7), // "weather"
QT_MOC_LITERAL(9, 100, 12), // "WeatherData*"
QT_MOC_LITERAL(10, 113, 15) // "hasValidWeather"

    },
    "AppModel\0readyChanged\0\0weatherChanged\0"
    "measurementsUpdated\0refreshWeather\0"
    "measurevalue\0ready\0weather\0WeatherData*\0"
    "hasValidWeather"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::Bool, 0x00495001,
       8, 0x80000000 | 9, 0x00495009,
      10, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       1,

       0        // eod
};

void AppModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppModel *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyChanged(); break;
        case 1: _t->weatherChanged(); break;
        case 2: _t->measurementsUpdated(); break;
        case 3: _t->refreshWeather(); break;
        case 4: _t->measurevalue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppModel::readyChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppModel::weatherChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AppModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppModel::measurementsUpdated)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeatherData* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        AppModel *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->ready(); break;
        case 1: *reinterpret_cast< WeatherData**>(_v) = _t->weather(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->hasValidWeather(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject AppModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppModel.data,
      qt_meta_data_AppModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppModel.stringdata0))
        return static_cast<void*>(const_cast< AppModel*>(this));
    return QObject::qt_metacast(_clname);
}

int AppModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppModel::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AppModel::weatherChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AppModel::measurementsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
