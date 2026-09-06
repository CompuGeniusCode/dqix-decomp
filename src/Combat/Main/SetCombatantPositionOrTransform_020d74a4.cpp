#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void Mat4x3_WriteIdentity(void* mtx);
extern "C" void Mat4x3_ApplyTranslation(void* a, void* b, int x, int y, int z);

struct Vec3_020d74a4 { int x, y, z; };
struct Mtx43_020d74a4 { unsigned int v[12]; };

struct Target020d74a4 {
    char pad[0xe8];
    struct Mtx43_020d74a4 mtx;
};

struct Combatant020d74a4 {
    char pad0[0x4];
    struct Target020d74a4* target;
    char pad1[0x3c];
    struct Vec3_020d74a4 pos;
    char pad2[0x5c];
    int flag0xac;
    char pad3[0x28];
};

// USA: func_020d74a4  (semantic: SetCombatantPositionOrTransform_020d74a4)
extern "C" ARM void func_020d74a4(struct Combatant020d74a4* base, int index, struct Vec3_020d74a4 v) {
    struct Mtx43_020d74a4 mtx;
    if (base[index].flag0xac == 0) {
        _ZN8Vector3iaSERKS_((int*)&base[index].pos, (int*)&v);
    } else {
        struct Target020d74a4* target;
        Mat4x3_WriteIdentity(&mtx);
        Mat4x3_ApplyTranslation(&mtx, &mtx, v.x, v.y, v.z);
        target = base[index].target;
        target->mtx = mtx;
    }
}
