#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b0Value(struct BattleStruct* battleStruct);

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

extern "C" ARM void func_020c2f18(struct Vec3* v, struct Vec3* out);

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Vec3copy0202ec84;
ARM int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Obj02052350 {
    unsigned char pad0[0x86];
    short f86;
    int f88;
};

// USA: func_02052350  (semantic: SetSteeringFromTarget_02052350)
extern "C" ARM void func_02052350(struct Obj02052350* obj) {
    void* target = (void*)GetField0x3b0Value(GetBattleStruct());
    struct Vec3 diff;
    SubtractVec3((struct Vec3*)((char*)target + 0x12c), (struct Vec3*)((char*)target + 0x120), &diff);
    int savedY = diff.y;
    diff.y = 0;
    func_020c2f18(&diff, &diff);
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, 0x800000, (struct Vec3Fixed02030e2c*)&diff);
    int out1, out2;
    ComputeTwoFromVec3_0202ec84(target, (struct Vec3copy0202ec84*)&diff, &out1, &out2);
    if (out2 < 0xc0 && out2 > 0) {
        int val = HwDivideRounded020c2bf4(out2 << 12, 0xbf000);
        obj->f86 = (short)val;
        if (obj->f86 < 0) obj->f86 = -obj->f86;
        obj->f88 = out2;
    } else {
        if (savedY >= 0) obj->f86 = 0x1000;
        else obj->f86 = 0;
    }
}
