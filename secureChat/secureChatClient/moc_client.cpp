/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[25];
    char stringdata[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 15),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 15),
QT_MOC_LITERAL(4, 40, 4),
QT_MOC_LITERAL(5, 45, 13),
QT_MOC_LITERAL(6, 59, 11),
QT_MOC_LITERAL(7, 71, 3),
QT_MOC_LITERAL(8, 75, 20),
QT_MOC_LITERAL(9, 96, 6),
QT_MOC_LITERAL(10, 103, 29),
QT_MOC_LITERAL(11, 133, 23),
QT_MOC_LITERAL(12, 157, 6),
QT_MOC_LITERAL(13, 164, 10),
QT_MOC_LITERAL(14, 175, 5),
QT_MOC_LITERAL(15, 181, 17),
QT_MOC_LITERAL(16, 199, 6),
QT_MOC_LITERAL(17, 206, 4),
QT_MOC_LITERAL(18, 211, 11),
QT_MOC_LITERAL(19, 223, 12),
QT_MOC_LITERAL(20, 236, 28),
QT_MOC_LITERAL(21, 265, 11),
QT_MOC_LITERAL(22, 277, 22),
QT_MOC_LITERAL(23, 300, 14),
QT_MOC_LITERAL(24, 315, 16)
    },
    "Client\0closeThisWindow\0\0addClientToList\0"
    "name\0startChatWith\0recievedMsg\0msg\0"
    "removePossibleClient\0client\0"
    "removePossibleConnectedClient\0"
    "writeStringToChatWindow\0string\0"
    "sendString\0input\0requestNewFortune\0"
    "hostIp\0port\0readFortune\0displayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "enableGetFortuneButton\0handleSSLError\0"
    "QList<QSslError>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06,
       3,    1,   80,    2, 0x06,
       5,    1,   83,    2, 0x06,
       6,    1,   86,    2, 0x06,
       8,    1,   89,    2, 0x06,
      10,    1,   92,    2, 0x06,
      11,    1,   95,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      13,    1,   98,    2, 0x0a,
      15,    3,  101,    2, 0x0a,
      18,    0,  108,    2, 0x08,
      19,    1,  109,    2, 0x08,
      22,    0,  112,    2, 0x08,
      23,    1,  113,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,    2,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->closeThisWindow(); break;
        case 1: _t->addClientToList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startChatWith((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->recievedMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->removePossibleClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->removePossibleConnectedClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->writeStringToChatWindow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->requestNewFortune((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->readFortune(); break;
        case 10: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 11: _t->enableGetFortuneButton(); break;
        case 12: _t->handleSSLError((*reinterpret_cast< QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::closeThisWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::addClientToList)) {
                *result = 1;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::startChatWith)) {
                *result = 2;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::recievedMsg)) {
                *result = 3;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::removePossibleClient)) {
                *result = 4;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::removePossibleConnectedClient)) {
                *result = 5;
            }
        }
        {
            typedef void (Client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::writeStringToChatWindow)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, 0, 0}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata))
        return static_cast<void*>(const_cast< Client*>(this));
    return QDialog::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Client::closeThisWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Client::addClientToList(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::startChatWith(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::recievedMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::removePossibleClient(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::removePossibleConnectedClient(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Client::writeStringToChatWindow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
