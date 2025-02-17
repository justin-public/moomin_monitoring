/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "startMessageSending"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "token"
QT_MOC_LITERAL(4, 38, 7), // "channel"
QT_MOC_LITERAL(5, 46, 4), // "text"
QT_MOC_LITERAL(6, 51, 16), // "handlePingResult"
QT_MOC_LITERAL(7, 68, 7), // "address"
QT_MOC_LITERAL(8, 76, 9), // "isSuccess"
QT_MOC_LITERAL(9, 86, 24), // "onProjectorStatusUpdated"
QT_MOC_LITERAL(10, 111, 15), // "projectorstatus"
QT_MOC_LITERAL(11, 127, 26), // "lampProjectorStatusUpdated"
QT_MOC_LITERAL(12, 154, 15), // "currentLampTime"
QT_MOC_LITERAL(13, 170, 17), // "updateTemperature"
QT_MOC_LITERAL(14, 188, 4), // "temp"
QT_MOC_LITERAL(15, 193, 14), // "updateHumidity"
QT_MOC_LITERAL(16, 208, 5), // "humid"
QT_MOC_LITERAL(17, 214, 22), // "handleGPIOStateChanged"
QT_MOC_LITERAL(18, 237, 4), // "isOn"
QT_MOC_LITERAL(19, 242, 15), // "handleGPIOError"
QT_MOC_LITERAL(20, 258, 7), // "message"
QT_MOC_LITERAL(21, 266, 16), // "sendDailyMessage"
QT_MOC_LITERAL(22, 283, 19), // "sendDailyendMessage"
QT_MOC_LITERAL(23, 303, 13), // "onMessageSent"
QT_MOC_LITERAL(24, 317, 7), // "success"
QT_MOC_LITERAL(25, 325, 11) // "errorString"

    },
    "MainWindow\0startMessageSending\0\0token\0"
    "channel\0text\0handlePingResult\0address\0"
    "isSuccess\0onProjectorStatusUpdated\0"
    "projectorstatus\0lampProjectorStatusUpdated\0"
    "currentLampTime\0updateTemperature\0"
    "temp\0updateHumidity\0humid\0"
    "handleGPIOStateChanged\0isOn\0handleGPIOError\0"
    "message\0sendDailyMessage\0sendDailyendMessage\0"
    "onMessageSent\0success\0errorString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   76,    2, 0x08 /* Private */,
       9,    2,   81,    2, 0x08 /* Private */,
      11,    2,   86,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,
      15,    1,   94,    2, 0x08 /* Private */,
      17,    1,   97,    2, 0x08 /* Private */,
      19,    1,  100,    2, 0x08 /* Private */,
      21,    0,  103,    2, 0x08 /* Private */,
      22,    0,  104,    2, 0x08 /* Private */,
      23,    2,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    7,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,   12,
    QMetaType::Void, QMetaType::Float,   14,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startMessageSending((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->handlePingResult((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->onProjectorStatusUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->lampProjectorStatusUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->updateTemperature((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->updateHumidity((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->handleGPIOStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->handleGPIOError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->sendDailyMessage(); break;
        case 9: _t->sendDailyendMessage(); break;
        case 10: _t->onMessageSent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startMessageSending)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startMessageSending(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
