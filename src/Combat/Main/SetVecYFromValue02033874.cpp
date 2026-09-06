#include <globaldefs.h>

struct Vec3_02033874 {
    int x;
    int y;
    int z;
};

struct Obj02033874 {
    char pad[0x50];
    struct Vec3_02033874 vec;
    char pad2[0x52];
    short fae;
};

extern "C" short func_02030f30(int);

// USA: func_02033874
ARM void SetVecYFromValue02033874(struct Obj02033874* obj, int arg) {
    struct Vec3_02033874* dst = (struct Vec3_02033874*)((char*)obj + 0x50);
    struct Vec3_02033874* src = (struct Vec3_02033874*)((char*)obj + 0x50);
    int x, y, z;
    obj->fae = func_02030f30(arg);
    z = src->z;
    y = obj->fae;
    x = src->x;
    dst->x = x;
    dst->y = y;
    dst->z = z;
    *(unsigned short*)((char*)obj + 0xc4) &= ~0x8000;
}
