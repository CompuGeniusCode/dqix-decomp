#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3 { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Target02059f38;
struct Vec3_02059f38;

int GetField0x3b4Value(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
extern "C" int fix32_Divide(unsigned int numerHi, unsigned int denomLo);

struct MoveRequest_021eeb8c {
    char pad0[8];
    unsigned short combatantId;
    unsigned short remaining;
    struct Vec3 target;
};

struct PosHolder_021eeb8c { char pad[0x44]; struct Vec3 pos; };

// USA: func_ov025_021eeb8c  (semantic: MoveTowardTargetOverTime_021eeb8c)
extern "C" ARM int func_ov025_021eeb8c(struct MoveRequest_021eeb8c* req) {
    struct BattleStruct* battle = GetBattleStruct();
    int elapsed = GetField0x3b4Value(battle);
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, req->combatantId);
    if (!combatant) return 1;
    if (req->remaining <= (unsigned int)elapsed) {
        CopyVec3ToField0x44((struct Target02059f38*)combatant, (struct Vec3_02059f38*)&req->target);
        return 1;
    }
    struct Vec3 curPos = ((struct PosHolder_021eeb8c*)combatant)->pos;
    int dist = Vector3fix_Distance((struct Vec3s32_020c3030*)&curPos, (struct Vec3s32_020c3030*)&req->target);
    float ratio = (float)(unsigned int)elapsed / (float)req->remaining;
    int step = (int)(((long long)dist * (int)(ratio * 4096.0f) + 0x800) >> 12);
    struct Vec3 diff;
    Vector3fix_Subtract(&req->target, &curPos, &diff);
    int scale2 = fix32_Divide(step, dist);
    func_02030e2c((struct Vec3Fixed02030e2c*)&diff, scale2, (struct Vec3Fixed02030e2c*)&diff);
    Vector3fix_Add(&curPos, &diff, &curPos);
    CopyVec3ToField0x44((struct Target02059f38*)combatant, (struct Vec3_02059f38*)&curPos);
    req->remaining -= elapsed;
    return 0;
}
