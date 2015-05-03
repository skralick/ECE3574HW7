/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[16];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 13),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 19),
QT_MOC_LITERAL(4, 42, 15),
QT_MOC_LITERAL(5, 58, 10),
QT_MOC_LITERAL(6, 69, 5),
QT_MOC_LITERAL(7, 75, 22),
QT_MOC_LITERAL(8, 98, 18),
QT_MOC_LITERAL(9, 117, 6),
QT_MOC_LITERAL(10, 124, 14),
QT_MOC_LITERAL(11, 139, 17),
QT_MOC_LITERAL(12, 157, 16),
QT_MOC_LITERAL(13, 174, 10),
QT_MOC_LITERAL(14, 185, 17),
QT_MOC_LITERAL(15, 203, 13)
    },
    "Server\0displayString\0\0handleNewConnection\0"
    "readIncomingMsg\0sendString\0input\0"
    "sendStringToAllClients\0sendStringToClient\0"
    "client\0sendClientList\0destinationClient\0"
    "disconnectClient\0clientName\0"
    "displayServerInfo\0getServerInfo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x08,
       4,    0,   68,    2, 0x08,
       5,    1,   69,    2, 0x0a,
       7,    1,   72,    2, 0x0a,
       8,    2,   75,    2, 0x0a,
      10,    1,   80,    2, 0x0a,
      12,    1,   83,    2, 0x0a,
      14,    0,   86,    2, 0x0a,
      15,    0,   87,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,    6,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->displayString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->handleNewConnection(); break;
        case 2: _t->readIncomingMsg(); break;
        case 3: _t->sendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendStringToAllClients((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sendStringToClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendClientList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->disconnectClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->displayServerInfo(); break;
        case 9: { QString _r = _t->getServerInfo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Server::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::displayString)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, 0, 0}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata))
        return static_cast<void*>(const_cast< Server*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Server::displayString(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
