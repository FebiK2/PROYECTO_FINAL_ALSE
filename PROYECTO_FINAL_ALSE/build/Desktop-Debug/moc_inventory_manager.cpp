/****************************************************************************
** Meta object code from reading C++ file 'inventory_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../inventory_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inventory_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_inventory_manager_t {
    QByteArrayData data[11];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_inventory_manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_inventory_manager_t qt_meta_stringdata_inventory_manager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "inventory_manager"
QT_MOC_LITERAL(1, 18, 30), // "on_lineEdit_buscar_textChanged"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 4), // "arg1"
QT_MOC_LITERAL(4, 55, 22), // "on_btn_agregar_clicked"
QT_MOC_LITERAL(5, 78, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(6, 110, 5), // "index"
QT_MOC_LITERAL(7, 116, 30), // "on_pushButton_crearCSV_clicked"
QT_MOC_LITERAL(8, 147, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(9, 181, 24), // "on_btn_agregar_2_clicked"
QT_MOC_LITERAL(10, 206, 32) // "on_lineEdit_buscar_2_textChanged"

    },
    "inventory_manager\0on_lineEdit_buscar_textChanged\0"
    "\0arg1\0on_btn_agregar_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_pushButton_crearCSV_clicked\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_btn_agregar_2_clicked\0"
    "on_lineEdit_buscar_2_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_inventory_manager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void inventory_manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<inventory_manager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_lineEdit_buscar_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_btn_agregar_clicked(); break;
        case 2: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_crearCSV_clicked(); break;
        case 4: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_btn_agregar_2_clicked(); break;
        case 6: _t->on_lineEdit_buscar_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject inventory_manager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_inventory_manager.data,
    qt_meta_data_inventory_manager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *inventory_manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *inventory_manager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_inventory_manager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int inventory_manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
