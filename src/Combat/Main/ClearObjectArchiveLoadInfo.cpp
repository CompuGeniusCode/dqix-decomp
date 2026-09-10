#include <globaldefs.h>

struct Struct_203dafc {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
};

// Zeroes an ObjectArchiveLoadInfo before it is filled in and handed to
// Object3D::LoadFromCHRArchive or Object3D::LoadFromCCHROrCMOTArchive. The struct is the eight-int
// one declared in include/World/Object3D.h, whose last member is the package id.
extern "C" ARM void ClearObjectArchiveLoadInfo(struct Struct_203dafc* obj) {
    obj->field0 = 0;
    obj->field4 = 0;
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field10 = 0;
    obj->field14 = 0;
    obj->field18 = 0;
    obj->field1c = 0;
}
