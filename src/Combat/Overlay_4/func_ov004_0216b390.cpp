#include <globaldefs.h>

struct Vec3_0216b390 {
    int x, y, z;
};

class VObj0216b390 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void Method1c(Vec3_0216b390* arg);
    virtual Vec3_0216b390 Method20();
};

extern "C" int func_ov004_0216af24(void* a, int key);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" VObj0216b390* func_ov023_021f6880(void* obj, int key);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov004_0216b390  (semantic: OffsetPositionAndNotify_0216b390)
extern "C" ARM void func_ov004_0216b390(void* a, int rawKey, int axis) {
    Vec3_0216b390 v2;
    Vec3_0216b390 v4;

    int delta = func_ov004_0216af24(a, (short)rawKey);
    VObj0216b390* node1 = func_ov023_021f6880(func_ov011_021849c8(a), rawKey);
    if (!node1) return;

    const Vec3_0216b390& v1 = node1->Method20();
    _ZN8Vector3iaSERKS_((int*)&v2, (int*)&v1);
    v2.x = v2.x + ((delta + 0xa) << 12);

    VObj0216b390* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
    if (!node2) return;

    const Vec3_0216b390& v3 = node2->Method20();
    _ZN8Vector3iaSERKS_((int*)&v4, (int*)&v3);
    v4.x = v2.x;

    if (axis == 0) v4.y = 0x24000;
    else if (axis == 1) v4.y = 0x34000;
    else if (axis == 2) v4.y = 0x42000;
    else if (axis == 3) v4.y = 0x1b000;

    node2->Method1c(&v4);
    *((unsigned char*)node2 + 0x3a) = 0;
}
