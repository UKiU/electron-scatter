/****************************************************************************
** Meta object code from reading C++ file 'Initial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Initial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Initial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Initial_t {
    QByteArrayData data[14];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Initial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Initial_t qt_meta_stringdata_Initial = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Initial"
QT_MOC_LITERAL(1, 8, 6), // "onlrwb"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "onsjlr"
QT_MOC_LITERAL(4, 23, 9), // "ondzsrsnl"
QT_MOC_LITERAL(5, 33, 7), // "ondzsbj"
QT_MOC_LITERAL(6, 41, 6), // "ondzgs"
QT_MOC_LITERAL(7, 48, 6), // "onclcs"
QT_MOC_LITERAL(8, 55, 8), // "onsstype"
QT_MOC_LITERAL(9, 64, 7), // "onstart"
QT_MOC_LITERAL(10, 72, 6), // "onszsj"
QT_MOC_LITERAL(11, 79, 4), // "on3d"
QT_MOC_LITERAL(12, 84, 3), // "onz"
QT_MOC_LITERAL(13, 88, 3) // "onr"

    },
    "Initial\0onlrwb\0\0onsjlr\0ondzsrsnl\0"
    "ondzsbj\0ondzgs\0onclcs\0onsstype\0onstart\0"
    "onszsj\0on3d\0onz\0onr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Initial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Initial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Initial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onlrwb(); break;
        case 1: _t->onsjlr(); break;
        case 2: { double _r = _t->ondzsrsnl();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->ondzsbj();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->ondzgs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->onclcs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->onsstype();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->onstart(); break;
        case 8: _t->onszsj(); break;
        case 9: _t->on3d(); break;
        case 10: _t->onz(); break;
        case 11: _t->onr(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Initial::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Initial.data,
    qt_meta_data_Initial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Initial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Initial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Initial.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Initial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
