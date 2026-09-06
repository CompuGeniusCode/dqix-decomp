#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern "C" ARM int Vector3fix_Length(int* v);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" ARM void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Struct_0203fc5c {
    char pad[0x40];
    float field40;
};
ARM int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

extern "C" double _dflt(int);

struct MoverObj0203c960 {
    char pad0[4];
    int position[3];  /* 0x4 */
    char pad1[0x4c];
    int flags;        /* 0x5c */
    char pad2[0x18];
    int target[3];    /* 0x78 */
    char pad3[8];
    int speed;         /* 0x8c */
};

// USA: func_0203c960
ARM void AdvanceOrSnapToTarget0203c960(struct MoverObj0203c960* obj) {
    struct Vec3 diff;
    Vector3fix_Subtract((struct Vec3*)obj->target, (struct Vec3*)obj->position, &diff);
    int dist = Vector3fix_Length((int*)&diff);
    if (obj->speed < dist) {
        int scale = fix32_Divide(obj->speed, dist);
        func_02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
        struct Vec3 sum;
        Vector3fix_Add((struct Vec3*)obj->position, &diff, &sum);
        _ZN8Vector3iaSERKS_(obj->position, (int*)&sum);
        double speedD = _dflt(obj->speed);
        float f = (float)(speedD / 0.03 / 4096.0);
        SetField40IfPositive((struct Struct_0203fc5c*)obj, f);
        return;
    }
    _ZN8Vector3iaSERKS_(obj->position, obj->target);
    obj->flags &= ~1;
}
