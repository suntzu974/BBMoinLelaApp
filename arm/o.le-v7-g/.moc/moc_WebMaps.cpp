/****************************************************************************
** Meta object code from reading C++ file 'WebMaps.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/WebMaps.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebMaps.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebMaps[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       4,   29, // properties
       1,   45, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      34,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,    8,    8,    8, 0x0a,

 // properties: name, type, flags
      76,   67, 0x0049510b,
     100,   92, 0x0a495001,
     112,   92, 0x0a495001,
     126,   92, 0x0a495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       1,

 // enums: name, flags, count, data
      67, 0x0,    3,   49,

 // enum data: key, value
     135, uint(WebMaps::GoogleMaps),
     146, uint(WebMaps::BingMaps),
     155, uint(WebMaps::OpenLayers),

       0        // eod
};

static const char qt_meta_stringdata_WebMaps[] = {
    "WebMaps\0\0currentProviderChanged()\0"
    "viewModeChanged()\0nextViewMode()\0"
    "Provider\0currentProvider\0QString\0"
    "pageContent\0viewModeTitle\0viewMode\0"
    "GoogleMaps\0BingMaps\0OpenLayers\0"
};

void WebMaps::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WebMaps *_t = static_cast<WebMaps *>(_o);
        switch (_id) {
        case 0: _t->currentProviderChanged(); break;
        case 1: _t->viewModeChanged(); break;
        case 2: _t->nextViewMode(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WebMaps::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WebMaps::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebMaps,
      qt_meta_data_WebMaps, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebMaps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebMaps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebMaps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebMaps))
        return static_cast<void*>(const_cast< WebMaps*>(this));
    return QObject::qt_metacast(_clname);
}

int WebMaps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Provider*>(_v) = currentProvider(); break;
        case 1: *reinterpret_cast< QString*>(_v) = pageContent(); break;
        case 2: *reinterpret_cast< QString*>(_v) = viewModeTitle(); break;
        case 3: *reinterpret_cast< QString*>(_v) = viewMode(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentProvider(*reinterpret_cast< Provider*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WebMaps::currentProviderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WebMaps::viewModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
