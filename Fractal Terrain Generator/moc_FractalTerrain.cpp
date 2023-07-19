/****************************************************************************
** Meta object code from reading C++ file 'FractalTerrain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FractalTerrain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FractalTerrain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FractalTerrain_t {
    QByteArrayData data[13];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FractalTerrain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FractalTerrain_t qt_meta_stringdata_FractalTerrain = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FractalTerrain"
QT_MOC_LITERAL(1, 15, 11), // "updateAngle"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "i"
QT_MOC_LITERAL(4, 30, 11), // "changeWater"
QT_MOC_LITERAL(5, 42, 15), // "changeRoughness"
QT_MOC_LITERAL(6, 58, 13), // "changeFeature"
QT_MOC_LITERAL(7, 72, 10), // "changeSize"
QT_MOC_LITERAL(8, 83, 12), // "changeModeDS"
QT_MOC_LITERAL(9, 96, 13), // "changeModeFFT"
QT_MOC_LITERAL(10, 110, 8), // "generate"
QT_MOC_LITERAL(11, 119, 9), // "exportMap"
QT_MOC_LITERAL(12, 129, 9) // "importMap"

    },
    "FractalTerrain\0updateAngle\0\0i\0changeWater\0"
    "changeRoughness\0changeFeature\0changeSize\0"
    "changeModeDS\0changeModeFFT\0generate\0"
    "exportMap\0importMap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FractalTerrain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    1,   67,    2, 0x0a /* Public */,
       5,    1,   70,    2, 0x0a /* Public */,
       6,    1,   73,    2, 0x0a /* Public */,
       7,    1,   76,    2, 0x0a /* Public */,
       8,    0,   79,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FractalTerrain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FractalTerrain *_t = static_cast<FractalTerrain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeWater((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeRoughness((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changeFeature((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->changeSize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changeModeDS(); break;
        case 6: _t->changeModeFFT(); break;
        case 7: _t->generate(); break;
        case 8: _t->exportMap(); break;
        case 9: _t->importMap(); break;
        default: ;
        }
    }
}

const QMetaObject FractalTerrain::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_FractalTerrain.data,
      qt_meta_data_FractalTerrain,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FractalTerrain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FractalTerrain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FractalTerrain.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int FractalTerrain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
