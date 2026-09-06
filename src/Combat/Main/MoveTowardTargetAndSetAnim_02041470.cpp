#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" ARM void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, char* data, int mode);
extern "C" int fix32_Atan2(int x, int z);
extern "C" int func_02030f30(int angle);

extern char data_020efe6c;
extern char data_020efe71;

struct Obj02041470 {
    char pad0[0x44];
    struct Vec3 posTarget;   // 0x44
    char pad1[0xac - 0x50];
    unsigned short fac;      // 0xac
    int fb0;                 // 0xb0
    struct Vec3 posCurrent;  // 0xb4
    char pad2[0xd0 - 0xc0];
    int fd0;                 // 0xd0
    unsigned char bit0d4 : 1;
    unsigned char runFlag : 1;
    unsigned char restd4 : 6; // 0xd4
};

// USA: func_02041470  (semantic: MoveTowardTargetAndSetAnim_02041470)
extern "C" ARM void func_02041470(struct Obj02041470* obj, struct Vec3* target) {
    int dist = Vector3fix_Distance((struct Vec3s32_020c3030*)target, (struct Vec3s32_020c3030*)&obj->posTarget);
    if (dist == 0) {
        return;
    }
    _ZN8Vector3iaSERKS_((int*)&obj->posCurrent, (int*)target);
    obj->fac |= 1;
    int mode = obj->fd0;
    if (!obj->runFlag) {
        _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj, &data_020efe6c, mode);
    } else {
        _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj, &data_020efe71, mode);
    }
    if (!(obj->fac & 4)) {
        struct Vec3 diff;
        Vector3fix_Subtract(&obj->posCurrent, &obj->posTarget, &diff);
        int scale = fix32_Divide(0x1000, dist);
        func_02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
        int angle = fix32_Atan2(diff.x, diff.z);
        obj->fb0 = func_02030f30(angle);
    }
}
