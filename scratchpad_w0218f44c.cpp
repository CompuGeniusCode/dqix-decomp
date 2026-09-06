#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void CopyVec3(int* dst, int* src);

extern "C" void func_0200f374(void* ptr, int size);

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
    func_0200f374(&local, 0xc);
    switch (obj->mode) {
        case 0:
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0xf0));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0xf0), (int*)&local);
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0x44));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
        case 1:
            CopyVec3((int*)&local, (int*)((char*)&obj->base->arr[1] + 0x44));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)&obj->base->arr[1] + 0x44), (int*)&local);
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0xf0));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0xf0), (int*)&local);
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0x3a0));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0x3a0), (int*)&local);
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0x44));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
        default:
            CopyVec3((int*)&local, (int*)((char*)obj->base + 0x44));
            AddVec3(&local, &accum, &local);
            CopyVec3((int*)((char*)obj->base + 0x44), (int*)&local);
            break;
    }
}
