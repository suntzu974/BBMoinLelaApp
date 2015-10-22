/****************************************************************************
** Meta object code from reading C++ file 'appsettings.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/appsettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppSettings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       6,   79, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x05,
      48,   42,   12,   12, 0x05,
      76,   70,   12,   12, 0x05,
     107,   98,   12,   12, 0x05,
     141,  132,   12,   12, 0x05,
     173,  166,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     196,   98,   12,   12, 0x0a,
     217,  166,   12,   12, 0x0a,
     236,  132,   12,   12, 0x0a,
     257,   70,   12,   12, 0x0a,
     275,   42,   12,   12, 0x0a,
     293,   13,   12,   12, 0x0a,
     310,   12,   12,   12, 0x0a,

 // properties: name, type, flags
      42,  326, 0x0a495903,
      13,  334, 0x11495903,
      70,  326, 0x0a495903,
      98,  326, 0x0a495903,
     132,  326, 0x0a495903,
     166,  326, 0x0a495903,

 // properties: notify_signal_id
       1,
       0,
       2,
       3,
       4,
       5,

       0        // eod
};

static const char qt_meta_stringdata_AppSettings[] = {
    "AppSettings\0\0address\0addressChanged(QUrl)\0"
    "token\0tokenChanged(QString)\0email\0"
    "emailChanged(QString)\0username\0"
    "usernameChanged(QString)\0password\0"
    "passwordChanged(QString)\0userid\0"
    "useridChanged(QString)\0setUsername(QString)\0"
    "setUserid(QString)\0setPassword(QString)\0"
    "setEmail(QString)\0setToken(QString)\0"
    "setAddress(QUrl)\0clearUserInfo()\0"
    "QString\0QUrl\0"
};

void AppSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppSettings *_t = static_cast<AppSettings *>(_o);
        switch (_id) {
        case 0: _t->addressChanged((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 1: _t->tokenChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emailChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->usernameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->passwordChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->useridChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setUsername((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setUserid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setEmail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setToken((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setAddress((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 12: _t->clearUserInfo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppSettings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppSettings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppSettings,
      qt_meta_data_AppSettings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppSettings))
        return static_cast<void*>(const_cast< AppSettings*>(this));
    return QObject::qt_metacast(_clname);
}

int AppSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = token(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = address(); break;
        case 2: *reinterpret_cast< QString*>(_v) = email(); break;
        case 3: *reinterpret_cast< QString*>(_v) = username(); break;
        case 4: *reinterpret_cast< QString*>(_v) = password(); break;
        case 5: *reinterpret_cast< QString*>(_v) = userid(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setToken(*reinterpret_cast< QString*>(_v)); break;
        case 1: setAddress(*reinterpret_cast< QUrl*>(_v)); break;
        case 2: setEmail(*reinterpret_cast< QString*>(_v)); break;
        case 3: setUsername(*reinterpret_cast< QString*>(_v)); break;
        case 4: setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 5: setUserid(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
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
void AppSettings::addressChanged(QUrl _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppSettings::tokenChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppSettings::emailChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AppSettings::usernameChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AppSettings::passwordChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AppSettings::useridChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
