#include <globaldefs.h>
#include "std_library_functions.h"

struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Blk3_02157f10 { int v[3]; };

struct BattleStruct;
ARM struct BattleStruct* GetBattleStruct(void);
ARM unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
extern "C" ARM void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

// USA: func_ov001_02157f10  (semantic: AdvanceVelocityTowardTarget_02157f10)
extern "C" ARM int func_ov001_02157f10(void* a, void* b) {
    char* pA = (char*)a;
    char* pB = (char*)b;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int scale = GetBattleScaleCount(battleStruct) << 0xc;
    int period = *(int*)(pA + 0x1c);
    if (period == 0) {
        memcpy(pB + 0x4c, pA + 0x4, 0xc);
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    if (*(int*)(pB + 0x38) <= 0) {
        struct Vec3 diff;
        int denom = period << 0xd;
        Vector3fix_Subtract((struct Vec3*)(pA + 0x4), (struct Vec3*)(pB + 0x4c), &diff);
        *(int*)(pB + 0xb4) = fix32_Divide(diff.x, denom);
        *(int*)(pB + 0xb8) = fix32_Divide(diff.y, denom);
        *(int*)(pB + 0xbc) = fix32_Divide(diff.z, denom);
    }
    struct Blk3_02157f10 vel = *(struct Blk3_02157f10*)(pB + 0xb4);
    func_02030e2c((struct Vec3Fixed02030e2c*)&vel, scale, (struct Vec3Fixed02030e2c*)&vel);
    Vector3fix_Add((struct Vec3*)(pB + 0x4c), (struct Vec3*)&vel, (struct Vec3*)(pB + 0x4c));
    int counter = *(int*)(pB + 0x38) + GetBattleScaleCount(battleStruct);
    *(int*)(pB + 0x38) = counter;
    int limit = *(int*)(pA + 0x1c) << 1;
    if (counter >= limit) {
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    return 1;
}
