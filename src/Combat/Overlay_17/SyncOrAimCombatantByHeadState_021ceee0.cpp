#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct HeadNode02046b24 { signed char id; };
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void CopyVec3(int* dst, int* src);

struct Obj02033834;
struct Obj02033874;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

extern "C" void func_0200f374(void* buf, int n);

struct Info021ceee0 {
    char pad4[4];
    int vec[3];
    short field10;
    unsigned char field12;
    unsigned char field13;
};

// USA: func_ov017_021ceee0  (semantic: SyncOrAimCombatantByHeadState_021ceee0)
extern "C" ARM void func_ov017_021ceee0(void* unused0, struct Info021ceee0* info, struct BattleStruct* battle, char* obj) {
    struct CombatantStruct* held;
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(obj + 0x3000 + 0x6fc);
    held = GetCombatantWithFlag0x2(battle, info->field12);
    if (ArrayContainsByte((struct ArrayContainsByteStruct*)GetPtrField0x2a04(battle), info->field12)) {
        return;
    }
    if (!held) {
        return;
    }
    if (GetHeadNodeIdOrMinusOne(list) == 0xa) {
        int withinRange = info->field12 <= 3;
        if (!withinRange) {
            return;
        }
        if (!(*(unsigned short*)held & 0x80)) {
            return;
        }
        struct CombatantStruct* target = GetCombatantWithFlag0x100(battle, info->field12);
        if (!target) {
            return;
        }
        int buf[3];
        func_0200f374(buf, 0xc);
        buf[1] = info->field10;
        CopyVec3((int*)((char*)target + 0x160), info->vec);
        CopyVec3((int*)((char*)target + 0x16c), buf);
        return;
    }
    if (GetHeadNodeIdOrMinusOne(list) == 4) {
        return;
    }
    CopyVec3((int*)((char*)held + 0x44), info->vec);
    if (info->field13 == 0) {
        SetVecYByMode02033834((struct Obj02033834*)held, info->field10);
    } else {
        SetVecYFromValue02033874((struct Obj02033874*)held, info->field10);
    }
}
