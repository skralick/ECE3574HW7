/****************************************************************************
** Meta object code from reading C++ file 'selectionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../secureChatClient/selectionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectionWindow_t {
    QByteArrayData data[8];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SelectionWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SelectionWindow_t qt_meta_stringdata_SelectionWindow = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 21),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 19),
QT_MOC_LITERAL(4, 59, 5),
QT_MOC_LITERAL(5, 65, 13),
QT_MOC_LITERAL(6, 79, 4),
QT_MOC_LITERAL(7, 84, 24)
    },
    "SelectionWindow\0on_sendButton_clicked\0"
    "\0addClientToComboBox\0input\0startChatWith\0"
    "name\0on_connectButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectionWindow[] = {

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
       1,    0,   34,    2, 0x08,
       3,    1,   35,    2, 0x08,
       5,    1,   38,    2, 0x08,
       7,    0,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void SelectionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectionWindow *_t = static_cast<SelectionWindow *>(_o);
        switch (_id) {
        case 0: _t->on_sendButton_clicked(); break;
        case 1: _t->addClientToComboBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startChatWith((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_connectButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SelectionWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SelectionWindow.data,
      qt_meta_data_SelectionWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *SelectionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectionWindow.stringdata))
        return static_cast<void*>(const_cast< SelectionWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SelectionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
