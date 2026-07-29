#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Triple02159b94 { int c, d, e; };
int ForwardTriple_02159b94(int a, int b, struct Triple02159b94 t);

extern "C" int func_ov001_02164808(int a, int b, struct Vec3* out);
extern int data_ov001_02165884;

struct ObjA02159bbc {
    char pad0[0x4];
    struct Vec3 f4;
    int f10;
};

struct StateB02159bbc {
    char pad0[0x5c];
    int f5c;
    char pad1[0x70 - 0x5c - 4];
    int f70;
    char pad2[0x108 - 0x70 - 4];
    struct Vec3Fixed02030e2c f108;
};

// USA: func_ov001_02159bbc
ARM int AdvanceScaledOffsetTowardTarget_02159bbc(struct ObjA02159bbc* a, struct StateB02159bbc* b) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned int scaleCount = GetBattleScaleCount(battleStruct);
    int scaledCount = scaleCount << 12;
    if (b->f5c >= a->f10 * 2) {
        b->f5c = 0;
        return 0;
    }
    if (b->f5c <= 0) {
        struct Vec3 local28;
        struct Vec3 local1c;
        func_ov001_02164808(data_ov001_02165884, b->f70, &local1c);
        SubtractVec3(&a->f4, &local1c, &local28);
        int shifted10 = a->f10 << 12;
        b->f108.x = HwDivideRounded020c2bf4(local28.x, shifted10);
        b->f108.y = HwDivideRounded020c2bf4(local28.y, shifted10);
        b->f108.z = HwDivideRounded020c2bf4(local28.z, shifted10);
    } else {
        struct Vec3Fixed02030e2c tmp = b->f108;
        int scale = HwDivideRounded020c2bf4(scaledCount, 0x2000);
        ScaleVec3Fixed02030e2c(&tmp, scale, &tmp);
        struct Vec3 local4;
        func_ov001_02164808(data_ov001_02165884, b->f70, &local4);
        AddVec3(&local4, (struct Vec3*)&tmp, &local4);
        struct Triple02159b94 t = *(struct Triple02159b94*)&local4;
        ForwardTriple_02159b94(data_ov001_02165884, b->f70, t);
    }
    b->f5c += GetBattleScaleCount(battleStruct);
    return 1;
}
