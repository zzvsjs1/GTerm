/****************************************************************************
** Meta object code from reading C++ file 'gtSubWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../gtSubWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gtSubWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GtSubWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GtSubWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GtSubWindow_t qt_meta_stringdata_GtSubWindow = {
    {
QT_MOC_LITERAL(0, 11), // "GtSubWindow"
QT_MOC_LITERAL(12, 5), // "print"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 7), // "println"
QT_MOC_LITERAL(27, 14), // "getInputString"
QT_MOC_LITERAL(42, 8), // "showHelp"
QT_MOC_LITERAL(51, 17), // "showMessageDialog"
QT_MOC_LITERAL(69, 15), // "showErrorDialog"
QT_MOC_LITERAL(85, 17), // "showWarningDialog"
QT_MOC_LITERAL(103, 5) // "setXY"

    },
    "GtSubWindow\0print\0\0println\0getInputString\0"
    "showHelp\0showMessageDialog\0showErrorDialog\0"
    "showWarningDialog\0setXY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GtSubWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    0 /* Public */,
       3,    0,   63,    2, 0x0a,    1 /* Public */,
       4,    0,   64,    2, 0x0a,    2 /* Public */,
       5,    0,   65,    2, 0x0a,    3 /* Public */,
       6,    0,   66,    2, 0x0a,    4 /* Public */,
       7,    0,   67,    2, 0x0a,    5 /* Public */,
       8,    0,   68,    2, 0x0a,    6 /* Public */,
       9,    0,   69,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GtSubWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GtSubWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->print(); break;
        case 1: _t->println(); break;
        case 2: _t->getInputString(); break;
        case 3: _t->showHelp(); break;
        case 4: _t->showMessageDialog(); break;
        case 5: _t->showErrorDialog(); break;
        case 6: _t->showWarningDialog(); break;
        case 7: _t->setXY(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject GtSubWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GtSubWindow.offsetsAndSize,
    qt_meta_data_GtSubWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GtSubWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GtSubWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GtSubWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GtSubWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GtSubWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
