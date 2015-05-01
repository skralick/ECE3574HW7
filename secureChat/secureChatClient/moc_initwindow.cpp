/****************************************************************************
** Meta object code from reading C++ file 'initwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "initwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InitWindow_t {
    QByteArrayData data[9];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_InitWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_InitWindow_t qt_meta_stringdata_InitWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 2),
QT_MOC_LITERAL(4, 25, 11),
QT_MOC_LITERAL(5, 37, 4),
QT_MOC_LITERAL(6, 42, 11),
QT_MOC_LITERAL(7, 54, 4),
QT_MOC_LITERAL(8, 59, 15)
    },
    "InitWindow\0ipChanged\0\0ip\0portChanged\0"
    "port\0nameChanged\0name\0connectToServer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InitWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08,
       4,    1,   37,    2, 0x08,
       6,    1,   40,    2, 0x08,
       8,    0,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void InitWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InitWindow *_t = static_cast<InitWindow *>(_o);
        switch (_id) {
        case 0: _t->ipChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->portChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->connectToServer(); break;
        default: ;
        }
    }
}

const QMetaObject InitWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_InitWindow.data,
      qt_meta_data_InitWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *InitWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InitWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InitWindow.stringdata))
        return static_cast<void*>(const_cast< InitWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int InitWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
