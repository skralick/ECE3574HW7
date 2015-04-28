/****************************************************************************
** Meta object code from reading C++ file 'clientwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_clientWindow_t {
    QByteArrayData data[10];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_clientWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_clientWindow_t qt_meta_stringdata_clientWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 11),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 21),
QT_MOC_LITERAL(4, 48, 19),
QT_MOC_LITERAL(5, 68, 2),
QT_MOC_LITERAL(6, 71, 9),
QT_MOC_LITERAL(7, 81, 12),
QT_MOC_LITERAL(8, 94, 25),
QT_MOC_LITERAL(9, 120, 10)
    },
    "clientWindow\0startClient\0\0"
    "on_sendButton_clicked\0appendToRecieveArea\0"
    "in\0addClient\0removeClient\0"
    "on_exitChatButton_clicked\0closeEarly\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clientWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08,
       4,    1,   51,    2, 0x08,
       6,    1,   54,    2, 0x08,
       7,    1,   57,    2, 0x08,
       8,    0,   60,    2, 0x08,
       9,    0,   61,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void clientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clientWindow *_t = static_cast<clientWindow *>(_o);
        switch (_id) {
        case 0: _t->startClient(); break;
        case 1: _t->on_sendButton_clicked(); break;
        case 2: _t->appendToRecieveArea((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->removeClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_exitChatButton_clicked(); break;
        case 6: _t->closeEarly(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clientWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientWindow::startClient)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject clientWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_clientWindow.data,
      qt_meta_data_clientWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *clientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clientWindow.stringdata))
        return static_cast<void*>(const_cast< clientWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int clientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void clientWindow::startClient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
