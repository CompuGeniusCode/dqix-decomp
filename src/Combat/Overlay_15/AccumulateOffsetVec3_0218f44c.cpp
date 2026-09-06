#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern "C" void __clear(void* ptr, int size);

struct Elem0x400_0218f44c { unsigned char pad[0x400]; };
struct Base0218f44c { unsigned char pad0[8]; struct Elem0x400_0218f44c arr[2]; };

struct Obj0218f44c {
    unsigned char pad1[0x1c];
    unsigned char mode;
    unsigned char pad2[3];
    unsigned char pad3[4];
    struct Base0218f44c* base;
};

// USA: func_ov015_0218f44c
ARM void AccumulateOffsetVec3_0218f44c(struct Obj0218f44c* obj, struct Vec3 accum) {
    struct Vec3 local;
    __clear(&local, 0xc);
    switch (obj->mode) {
        case 0:
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0xf0));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0xf0), (int*)&local);
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0x44));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
        case 1:
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)&obj->base->arr[1] + 0x44));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)&obj->base->arr[1] + 0x44), (int*)&local);
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0xf0));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0xf0), (int*)&local);
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0x3a0));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0x3a0), (int*)&local);
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0x44));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
        default:
            _ZN8Vector3iaSERKS_((int*)&local, (int*)((char*)obj->base + 0x44));
            Vector3fix_Add(&local, &accum, &local);
            _ZN8Vector3iaSERKS_((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
    }
}
