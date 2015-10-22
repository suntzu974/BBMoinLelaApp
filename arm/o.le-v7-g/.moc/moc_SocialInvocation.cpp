/****************************************************************************
** Meta object code from reading C++ file 'SocialInvocation.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/SocialInvocation.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocialInvocation.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SocialInvocation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      45,   18,   17,   17, 0x0a,
      90,   85,   17,   17, 0x0a,
     116,  110,   17,   17, 0x0a,
     163,  151,   17,   17, 0x0a,
     206,   17,   17,   17, 0x0a,

 // methods: signature, parameters, type, tag, flags
     234,  225,  214,   17, 0x02,
     264,  257,   17,   17, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_SocialInvocation[] = {
    "SocialInvocation\0\0target,action,mimetype,uri\0"
    "invoke(QString,QString,QString,QString)\0"
    "waze\0invokeWaze(QString)\0venue\0"
    "invokeFoursquareVenueCard(QString)\0"
    "doneMessage\0childCardDone(bb::system::CardDoneMessage)\0"
    "onSSO()\0QByteArray\0toEncode\0"
    "encodeQString(QString)\0base64\0"
    "imageToData(QByteArray)\0"
};

void SocialInvocation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SocialInvocation *_t = static_cast<SocialInvocation *>(_o);
        switch (_id) {
        case 0: _t->invoke((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->invokeWaze((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->invokeFoursquareVenueCard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->childCardDone((*reinterpret_cast< const bb::system::CardDoneMessage(*)>(_a[1]))); break;
        case 4: _t->onSSO(); break;
        case 5: { QByteArray _r = _t->encodeQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 6: _t->imageToData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SocialInvocation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SocialInvocation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocialInvocation,
      qt_meta_data_SocialInvocation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SocialInvocation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SocialInvocation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SocialInvocation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SocialInvocation))
        return static_cast<void*>(const_cast< SocialInvocation*>(this));
    return QObject::qt_metacast(_clname);
}

int SocialInvocation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
