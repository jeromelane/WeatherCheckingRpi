/****************************************************************************
** Meta object code from reading C++ file 'appmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weathercheckingrpi/appmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeatherData_t {
    QByteArrayData data[9];
    char stringdata0[96];
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
QT_MOC_LITERAL(3, 25, 9), // "dayOfWeek"
QT_MOC_LITERAL(4, 35, 11), // "weatherIcon"
QT_MOC_LITERAL(5, 47, 18), // "weatherDescription"
QT_MOC_LITERAL(6, 66, 11), // "temperature"
QT_MOC_LITERAL(7, 78, 8), // "pressure"
QT_MOC_LITERAL(8, 87, 8) // "humidity"

    },
    "WeatherData\0dataChanged\0\0dayOfWeek\0"
    "weatherIcon\0weatherDescription\0"
    "temperature\0pressure\0humidity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherData[] = {

 // content:
       8,       // revision
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
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->dayOfWeek(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->weatherIcon(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->weatherDescription(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->temperature(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->pressure(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->humidity(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDayOfWeek(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWeatherIcon(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setWeatherDescription(*reinterpret_cast< QString*>(_v)); break;
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

QT_INIT_METAOBJECT const QMetaObject WeatherData::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WeatherData.data,
    qt_meta_data_WeatherData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WeatherData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherData.stringdata0))
        return static_cast<void*>(this);
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
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_AppModel_t {
    QByteArrayData data[30];
    char stringdata0[413];
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
QT_MOC_LITERAL(3, 23, 13), // "useGpsChanged"
QT_MOC_LITERAL(4, 37, 11), // "cityChanged"
QT_MOC_LITERAL(5, 49, 14), // "weatherChanged"
QT_MOC_LITERAL(6, 64, 14), // "refreshWeather"
QT_MOC_LITERAL(7, 79, 9), // "queryCity"
QT_MOC_LITERAL(8, 89, 20), // "networkSessionOpened"
QT_MOC_LITERAL(9, 110, 15), // "positionUpdated"
QT_MOC_LITERAL(10, 126, 16), // "QGeoPositionInfo"
QT_MOC_LITERAL(11, 143, 6), // "gpsPos"
QT_MOC_LITERAL(12, 150, 13), // "positionError"
QT_MOC_LITERAL(13, 164, 29), // "QGeoPositionInfoSource::Error"
QT_MOC_LITERAL(14, 194, 1), // "e"
QT_MOC_LITERAL(15, 196, 20), // "handleGeoNetworkData"
QT_MOC_LITERAL(16, 217, 14), // "QNetworkReply*"
QT_MOC_LITERAL(17, 232, 12), // "networkReply"
QT_MOC_LITERAL(18, 245, 24), // "handleWeatherNetworkData"
QT_MOC_LITERAL(19, 270, 25), // "handleForecastNetworkData"
QT_MOC_LITERAL(20, 296, 5), // "ready"
QT_MOC_LITERAL(21, 302, 9), // "hasSource"
QT_MOC_LITERAL(22, 312, 12), // "hasValidCity"
QT_MOC_LITERAL(23, 325, 15), // "hasValidWeather"
QT_MOC_LITERAL(24, 341, 6), // "useGps"
QT_MOC_LITERAL(25, 348, 4), // "city"
QT_MOC_LITERAL(26, 353, 7), // "weather"
QT_MOC_LITERAL(27, 361, 12), // "WeatherData*"
QT_MOC_LITERAL(28, 374, 8), // "forecast"
QT_MOC_LITERAL(29, 383, 29) // "QQmlListProperty<WeatherData>"

    },
    "AppModel\0readyChanged\0\0useGpsChanged\0"
    "cityChanged\0weatherChanged\0refreshWeather\0"
    "queryCity\0networkSessionOpened\0"
    "positionUpdated\0QGeoPositionInfo\0"
    "gpsPos\0positionError\0QGeoPositionInfoSource::Error\0"
    "e\0handleGeoNetworkData\0QNetworkReply*\0"
    "networkReply\0handleWeatherNetworkData\0"
    "handleForecastNetworkData\0ready\0"
    "hasSource\0hasValidCity\0hasValidWeather\0"
    "useGps\0city\0weather\0WeatherData*\0"
    "forecast\0QQmlListProperty<WeatherData>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       8,   96, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    1,   81,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      15,    1,   87,    2, 0x08 /* Private */,
      18,    1,   90,    2, 0x08 /* Private */,
      19,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,

 // properties: name, type, flags
      20, QMetaType::Bool, 0x00495001,
      21, QMetaType::Bool, 0x00495001,
      22, QMetaType::Bool, 0x00495001,
      23, QMetaType::Bool, 0x00495001,
      24, QMetaType::Bool, 0x00495103,
      25, QMetaType::QString, 0x00495103,
      26, 0x80000000 | 27, 0x00495009,
      28, 0x80000000 | 29, 0x00495009,

 // properties: notify_signal_id
       0,
       0,
       2,
       3,
       1,
       2,
       3,
       3,

       0        // eod
};

void AppModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyChanged(); break;
        case 1: _t->useGpsChanged(); break;
        case 2: _t->cityChanged(); break;
        case 3: _t->weatherChanged(); break;
        case 4: _t->refreshWeather(); break;
        case 5: _t->queryCity(); break;
        case 6: _t->networkSessionOpened(); break;
        case 7: _t->positionUpdated((*reinterpret_cast< QGeoPositionInfo(*)>(_a[1]))); break;
        case 8: _t->positionError((*reinterpret_cast< QGeoPositionInfoSource::Error(*)>(_a[1]))); break;
        case 9: _t->handleGeoNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->handleWeatherNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->handleForecastNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGeoPositionInfo >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::readyChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::useGpsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::cityChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::weatherChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeatherData* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->ready(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->hasSource(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->hasValidCity(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->hasValidWeather(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->useGps(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->city(); break;
        case 6: *reinterpret_cast< WeatherData**>(_v) = _t->weather(); break;
        case 7: *reinterpret_cast< QQmlListProperty<WeatherData>*>(_v) = _t->forecast(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setUseGps(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setCity(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AppModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AppModel.data,
    qt_meta_data_AppModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppModel::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppModel::useGpsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppModel::cityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppModel::weatherChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
