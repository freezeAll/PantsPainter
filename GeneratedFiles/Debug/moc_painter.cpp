/****************************************************************************
** Meta object code from reading C++ file 'painter.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../painter.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'painter.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Painter_t {
    QByteArrayData data[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Painter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Painter_t qt_meta_stringdata_Painter = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Painter"
QT_MOC_LITERAL(1, 8, 11), // "points2path"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 19), // "zoom_status_changed"
QT_MOC_LITERAL(4, 41, 10), // "refresh_gl"
QT_MOC_LITERAL(5, 52, 16), // "set_axis_display"
QT_MOC_LITERAL(6, 69, 10), // "reset_date"
QT_MOC_LITERAL(7, 80, 8), // "top_view"
QT_MOC_LITERAL(8, 89, 11), // "upward_view"
QT_MOC_LITERAL(9, 101, 10), // "fornt_view"
QT_MOC_LITERAL(10, 112, 11), // "behind_view"
QT_MOC_LITERAL(11, 124, 9), // "left_view"
QT_MOC_LITERAL(12, 134, 10), // "right_view"
QT_MOC_LITERAL(13, 145, 11) // "path2points"

    },
    "Painter\0points2path\0\0zoom_status_changed\0"
    "refresh_gl\0set_axis_display\0reset_date\0"
    "top_view\0upward_view\0fornt_view\0"
    "behind_view\0left_view\0right_view\0"
    "path2points"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Painter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   85,    2, 0x0a /* Public */,
       5,    0,   86,    2, 0x0a /* Public */,
       6,    0,   87,    2, 0x0a /* Public */,
       7,    0,   88,    2, 0x0a /* Public */,
       8,    0,   89,    2, 0x0a /* Public */,
       9,    0,   90,    2, 0x0a /* Public */,
      10,    0,   91,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,
      12,    0,   93,    2, 0x0a /* Public */,
      13,    0,   94,    2, 0x0a /* Public */,
       1,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Double,    2,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Painter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Painter *_t = static_cast<Painter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->points2path((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->zoom_status_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->refresh_gl(); break;
        case 3: _t->set_axis_display(); break;
        case 4: _t->reset_date(); break;
        case 5: _t->top_view(); break;
        case 6: _t->upward_view(); break;
        case 7: _t->fornt_view(); break;
        case 8: _t->behind_view(); break;
        case 9: _t->left_view(); break;
        case 10: _t->right_view(); break;
        case 11: _t->path2points(); break;
        case 12: _t->points2path(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Painter::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Painter::points2path)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Painter::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Painter::zoom_status_changed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Painter::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_Painter.data,
      qt_meta_data_Painter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Painter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Painter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Painter.stringdata0))
        return static_cast<void*>(const_cast< Painter*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int Painter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Painter::points2path(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Painter::zoom_status_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
