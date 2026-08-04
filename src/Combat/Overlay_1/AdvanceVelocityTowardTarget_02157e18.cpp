#include <globaldefs.h>
#include "std_library_functions.h"

struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Blk3_02157e18 { int v[3]; };

struct BattleStruct;
ARM struct BattleStruct* GetBattleStruct(void);
ARM unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

// USA: func_ov001_02157e18  (semantic: AdvanceVelocityTowardTarget_02157e18)
extern "C" ARM int func_ov001_02157e18(void* a, void* b) {
    char* pA = (char*)a;
    char* pB = (char*)b;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int scale = GetBattleScaleCount(battleStruct) << 0xc;
    int period = *(int*)(pA + 0x1c);
    if (period == 0) {
        memcpy(pB + 0x58, pA + 0x10, 0xc);
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    if (*(int*)(pB + 0x38) <= 0) {
        struct Vec3 diff;
        int denom = period << 0xd;
        SubtractVec3((struct Vec3*)(pA + 0x10), (struct Vec3*)(pB + 0x58), &diff);
        *(int*)(pB + 0xc0) = HwDivideRounded020c2bf4(diff.x, denom);
        *(int*)(pB + 0xc4) = HwDivideRounded020c2bf4(diff.y, denom);
        *(int*)(pB + 0xc8) = HwDivideRounded020c2bf4(diff.z, denom);
    }
    struct Blk3_02157e18 vel = *(struct Blk3_02157e18*)(pB + 0xc0);
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&vel, scale, (struct Vec3Fixed02030e2c*)&vel);
    AddVec3((struct Vec3*)(pB + 0x58), (struct Vec3*)&vel, (struct Vec3*)(pB + 0x58));
    int counter = *(int*)(pB + 0x38) + GetBattleScaleCount(battleStruct);
    *(int*)(pB + 0x38) = counter;
    int limit = *(int*)(pA + 0x1c) << 1;
    if (counter >= limit) {
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    return 1;
}
