/****************************************************************************
** Meta object code from reading C++ file 'CircularSlider.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/RatingControl/CircularSlider.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CircularSlider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CircularSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   42,   15,   15, 0x08,
     108,  102,   15,   15, 0x08,
     137,  130,   15,   15, 0x08,
     174,  160,   15,   15, 0x08,
     215,   15,   15,   15, 0x08,

 // properties: name, type, flags
      16,  240, 0x87495903,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_CircularSlider[] = {
    "CircularSlider\0\0value\0valueChanged(float)\0"
    "touchEvent\0onSliderHandleTouched(bb::cascades::TouchEvent*)\0"
    "width\0onWidthChanged(float)\0height\0"
    "onHeightChanged(float)\0trackpadEvent\0"
    "onTrackpad(bb::cascades::TrackpadEvent*)\0"
    "onDevShortcutTriggered()\0float\0"
};

void CircularSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CircularSlider *_t = static_cast<CircularSlider *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->onSliderHandleTouched((*reinterpret_cast< bb::cascades::TouchEvent*(*)>(_a[1]))); break;
        case 2: _t->onWidthChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->onHeightChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->onTrackpad((*reinterpret_cast< bb::cascades::TrackpadEvent*(*)>(_a[1]))); break;
        case 5: _t->onDevShortcutTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CircularSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CircularSlider::staticMetaObject = {
    { &bb::cascades::CustomControl::staticMetaObject, qt_meta_stringdata_CircularSlider,
      qt_meta_data_CircularSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CircularSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CircularSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CircularSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CircularSlider))
        return static_cast<void*>(const_cast< CircularSlider*>(this));
    typedef bb::cascades::CustomControl QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int CircularSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef bb::cascades::CustomControl QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = value(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setValue(*reinterpret_cast< float*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CircularSlider::valueChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
