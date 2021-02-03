/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Local/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[18];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 8), // "addPunto"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "addSegmento"
QT_MOC_LITERAL(4, 33, 8), // "addRetta"
QT_MOC_LITERAL(5, 42, 16), // "addCirconferenza"
QT_MOC_LITERAL(6, 59, 10), // "addEllisse"
QT_MOC_LITERAL(7, 70, 11), // "addRegolare"
QT_MOC_LITERAL(8, 82, 11), // "addPoligono"
QT_MOC_LITERAL(9, 94, 13), // "removeDisegno"
QT_MOC_LITERAL(10, 108, 13), // "cancellaTutto"
QT_MOC_LITERAL(11, 122, 12), // "getWorkspace"
QT_MOC_LITERAL(12, 135, 10), // "WorkSpace*"
QT_MOC_LITERAL(13, 146, 5), // "write"
QT_MOC_LITERAL(14, 152, 12), // "QJsonObject&"
QT_MOC_LITERAL(15, 165, 4), // "read"
QT_MOC_LITERAL(16, 170, 10), // "saveToFile"
QT_MOC_LITERAL(17, 181, 12) // "loadFromFile"

    },
    "Controller\0addPunto\0\0addSegmento\0"
    "addRetta\0addCirconferenza\0addEllisse\0"
    "addRegolare\0addPoligono\0removeDisegno\0"
    "cancellaTutto\0getWorkspace\0WorkSpace*\0"
    "write\0QJsonObject&\0read\0saveToFile\0"
    "loadFromFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      13,    1,   94,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addPunto(); break;
        case 1: _t->addSegmento(); break;
        case 2: _t->addRetta(); break;
        case 3: _t->addCirconferenza(); break;
        case 4: _t->addEllisse(); break;
        case 5: _t->addRegolare(); break;
        case 6: _t->addPoligono(); break;
        case 7: _t->removeDisegno(); break;
        case 8: _t->cancellaTutto(); break;
        case 9: { WorkSpace* _r = _t->getWorkspace();
            if (_a[0]) *reinterpret_cast< WorkSpace**>(_a[0]) = std::move(_r); }  break;
        case 10: _t->write((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 11: _t->read((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 12: { bool _r = _t->saveToFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->loadFromFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
