#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
void CopyVec3(int* dst, int* src);
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

extern "C" int func_02036e34(void* obj, char* data, int mode);
extern "C" int func_020c338c(int x, int z);
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
    int dist = Distance3D020c3030((struct Vec3s32_020c3030*)target, (struct Vec3s32_020c3030*)&obj->posTarget);
    if (dist == 0) {
        return;
    }
    CopyVec3((int*)&obj->posCurrent, (int*)target);
    obj->fac |= 1;
    int mode = obj->fd0;
    if (!obj->runFlag) {
        func_02036e34(obj, &data_020efe6c, mode);
    } else {
        func_02036e34(obj, &data_020efe71, mode);
    }
    if (!(obj->fac & 4)) {
        struct Vec3 diff;
        SubtractVec3(&obj->posCurrent, &obj->posTarget, &diff);
        int scale = HwDivideRounded020c2bf4(0x1000, dist);
        ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
        int angle = func_020c338c(diff.x, diff.z);
        obj->fb0 = func_02030f30(angle);
    }
}
