/****************************************************************************
** Meta object code from reading C++ file 'weatherdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weathercheckingrpi/weatherdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherdata.h' doesn't include <QObject>."
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
