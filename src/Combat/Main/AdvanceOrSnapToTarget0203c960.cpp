#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void CopyVec3(int* dst, int* src);

ARM int Vec3LengthRounded(int* v);
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Struct_0203fc5c {
    char pad[0x40];
    float field40;
};
ARM int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

extern "C" double func_0200b074(int);

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
    SubtractVec3((struct Vec3*)obj->target, (struct Vec3*)obj->position, &diff);
    int dist = Vec3LengthRounded((int*)&diff);
    if (obj->speed < dist) {
        int scale = HwDivideRounded020c2bf4(obj->speed, dist);
        ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
        struct Vec3 sum;
        AddVec3((struct Vec3*)obj->position, &diff, &sum);
        CopyVec3(obj->position, (int*)&sum);
        double speedD = func_0200b074(obj->speed);
        float f = (float)(speedD / 0.03 / 4096.0);
        SetField40IfPositive((struct Struct_0203fc5c*)obj, f);
        return;
    }
    CopyVec3(obj->position, obj->target);
    obj->flags &= ~1;
}
