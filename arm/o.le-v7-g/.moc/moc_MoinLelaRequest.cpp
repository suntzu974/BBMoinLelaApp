/****************************************************************************
** Meta object code from reading C++ file 'MoinLelaRequest.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/MoinLelaRequest.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MoinLelaRequest.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MoinLelaRequest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
      17,  154, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      33,   16,   16,   16, 0x05,
      49,   16,   16,   16, 0x05,
      65,   16,   16,   16, 0x05,
      82,   16,   16,   16, 0x05,
      99,   16,   16,   16, 0x05,
     116,   16,   16,   16, 0x05,
     134,   16,   16,   16, 0x05,
     152,   16,   16,   16, 0x05,
     171,   16,   16,   16, 0x05,
     192,   16,   16,   16, 0x05,
     212,   16,   16,   16, 0x05,
     233,   16,   16,   16, 0x05,
     251,   16,   16,   16, 0x05,
     272,   16,   16,   16, 0x05,
     291,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     311,   16,   16,   16, 0x0a,
     339,  319,   16,   16, 0x0a,
     386,  380,   16,   16, 0x0a,
     434,  409,   16,   16, 0x0a,
     498,  483,   16,   16, 0x0a,
     564,  557,  537,   16, 0x0a,
     601,  592,   16,   16, 0x0a,
     667,  622,   16,   16, 0x0a,
     765,  725,   16,   16, 0x0a,
     914,  816,   16,   16, 0x0a,
    1035,   16,   16,   16, 0x08,
    1058, 1053,   16,   16, 0x0a,

 // properties: name, type, flags
    1114, 1109, 0x01495001,
    1121, 1109, 0x01495001,
    1153, 1128, 0x00095409,
    1167, 1159, 0x0a495103,
    1174, 1159, 0x0a495103,
    1182, 1159, 0x0a495103,
    1190, 1159, 0x0a495103,
    1198, 1159, 0x0a495103,
     592, 1159, 0x0a495103,
    1207, 1159, 0x0a495103,
    1217, 1159, 0x0a495103,
    1229, 1159, 0x0a495103,
    1240, 1159, 0x0a495103,
    1252, 1159, 0x0a495103,
    1261, 1159, 0x0a495103,
    1273, 1159, 0x0a495103,
    1283, 1159, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,
       0,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,

       0        // eod
};

static const char qt_meta_stringdata_MoinLelaRequest[] = {
    "MoinLelaRequest\0\0loggedChanged()\0"
    "activeChanged()\0budgetChanged()\0"
    "serviceChanged()\0qualityChanged()\0"
    "privacyChanged()\0ambienceChanged()\0"
    "itemNameChanged()\0itemLabelChanged()\0"
    "itemCountryChanged()\0itemRegionChanged()\0"
    "itemZipcodeChanged()\0itemTownChanged()\0"
    "itemAddressChanged()\0itemPhoneChanged()\0"
    "itemMobileChanged()\0reset()\0"
    "email,name,password\0"
    "requestRegister(QString,QString,QString)\0"
    "token\0requestLogout(QString)\0"
    "id,score,dimension,klass\0"
    "requestPostRate(QString,QString,QString,QString)\0"
    "login,password\0requestAuthentication(QString,QString)\0"
    "bb::cascades::Image\0base64\0"
    "imageFromBase64(QByteArray)\0itemName\0"
    "requestItem(QString)\0"
    "item,budget,service,quality,privacy,ambience\0"
    "rateItem(QString,QString,QString,QString,QString,QString)\0"
    "budget,service,quality,privacy,ambience\0"
    "stackRate(QString,QString,QString,QString,QString)\0"
    "name,label,regionID,country,region,town,zipcode,address,phone,mobile,l"
    "atitude,longitude,imagePath\0"
    "requestPostItem(QString,QString,QString,QString,QString,QString,QStrin"
    "g,QString,QString,QString,QString,QString,QString)\0"
    "onMoinLelaReply()\0type\0"
    "onDialogFinished(bb::system::SystemUiResult::Type)\0"
    "bool\0logged\0active\0bb::cascades::DataModel*\0"
    "model\0QString\0budget\0service\0quality\0"
    "privacy\0ambience\0itemLabel\0itemCountry\0"
    "itemRegion\0itemZipcode\0itemTown\0"
    "itemAddress\0itemPhone\0itemMobile\0"
};

void MoinLelaRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MoinLelaRequest *_t = static_cast<MoinLelaRequest *>(_o);
        switch (_id) {
        case 0: _t->loggedChanged(); break;
        case 1: _t->activeChanged(); break;
        case 2: _t->budgetChanged(); break;
        case 3: _t->serviceChanged(); break;
        case 4: _t->qualityChanged(); break;
        case 5: _t->privacyChanged(); break;
        case 6: _t->ambienceChanged(); break;
        case 7: _t->itemNameChanged(); break;
        case 8: _t->itemLabelChanged(); break;
        case 9: _t->itemCountryChanged(); break;
        case 10: _t->itemRegionChanged(); break;
        case 11: _t->itemZipcodeChanged(); break;
        case 12: _t->itemTownChanged(); break;
        case 13: _t->itemAddressChanged(); break;
        case 14: _t->itemPhoneChanged(); break;
        case 15: _t->itemMobileChanged(); break;
        case 16: _t->reset(); break;
        case 17: _t->requestRegister((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 18: _t->requestLogout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->requestPostRate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 20: _t->requestAuthentication((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 21: { bb::cascades::Image _r = _t->imageFromBase64((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bb::cascades::Image*>(_a[0]) = _r; }  break;
        case 22: _t->requestItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->rateItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 24: _t->stackRate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 25: _t->requestPostItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13]))); break;
        case 26: _t->onMoinLelaReply(); break;
        case 27: _t->onDialogFinished((*reinterpret_cast< bb::system::SystemUiResult::Type(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MoinLelaRequest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MoinLelaRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MoinLelaRequest,
      qt_meta_data_MoinLelaRequest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MoinLelaRequest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MoinLelaRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MoinLelaRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MoinLelaRequest))
        return static_cast<void*>(const_cast< MoinLelaRequest*>(this));
    return QObject::qt_metacast(_clname);
}

int MoinLelaRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = logged(); break;
        case 1: *reinterpret_cast< bool*>(_v) = active(); break;
        case 2: *reinterpret_cast< bb::cascades::DataModel**>(_v) = model(); break;
        case 3: *reinterpret_cast< QString*>(_v) = budget(); break;
        case 4: *reinterpret_cast< QString*>(_v) = service(); break;
        case 5: *reinterpret_cast< QString*>(_v) = quality(); break;
        case 6: *reinterpret_cast< QString*>(_v) = privacy(); break;
        case 7: *reinterpret_cast< QString*>(_v) = ambience(); break;
        case 8: *reinterpret_cast< QString*>(_v) = itemName(); break;
        case 9: *reinterpret_cast< QString*>(_v) = itemLabel(); break;
        case 10: *reinterpret_cast< QString*>(_v) = itemCountry(); break;
        case 11: *reinterpret_cast< QString*>(_v) = itemRegion(); break;
        case 12: *reinterpret_cast< QString*>(_v) = itemZipcode(); break;
        case 13: *reinterpret_cast< QString*>(_v) = itemTown(); break;
        case 14: *reinterpret_cast< QString*>(_v) = itemAddress(); break;
        case 15: *reinterpret_cast< QString*>(_v) = itemPhone(); break;
        case 16: *reinterpret_cast< QString*>(_v) = itemMobile(); break;
        }
        _id -= 17;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: setBudget(*reinterpret_cast< QString*>(_v)); break;
        case 4: setService(*reinterpret_cast< QString*>(_v)); break;
        case 5: setQuality(*reinterpret_cast< QString*>(_v)); break;
        case 6: setPrivacy(*reinterpret_cast< QString*>(_v)); break;
        case 7: setAmbience(*reinterpret_cast< QString*>(_v)); break;
        case 8: setItemName(*reinterpret_cast< QString*>(_v)); break;
        case 9: setItemLabel(*reinterpret_cast< QString*>(_v)); break;
        case 10: setItemCountry(*reinterpret_cast< QString*>(_v)); break;
        case 11: setItemRegion(*reinterpret_cast< QString*>(_v)); break;
        case 12: setItemZipcode(*reinterpret_cast< QString*>(_v)); break;
        case 13: setItemTown(*reinterpret_cast< QString*>(_v)); break;
        case 14: setItemAddress(*reinterpret_cast< QString*>(_v)); break;
        case 15: setItemPhone(*reinterpret_cast< QString*>(_v)); break;
        case 16: setItemMobile(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 17;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MoinLelaRequest::loggedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MoinLelaRequest::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MoinLelaRequest::budgetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MoinLelaRequest::serviceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MoinLelaRequest::qualityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MoinLelaRequest::privacyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MoinLelaRequest::ambienceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MoinLelaRequest::itemNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MoinLelaRequest::itemLabelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void MoinLelaRequest::itemCountryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void MoinLelaRequest::itemRegionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void MoinLelaRequest::itemZipcodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void MoinLelaRequest::itemTownChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void MoinLelaRequest::itemAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void MoinLelaRequest::itemPhoneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void MoinLelaRequest::itemMobileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}
QT_END_MOC_NAMESPACE
