#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Vec3 { int x, y, z; };
void CopyVec3(int* dst, int* src);
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_0200f374(void* ptr, int size);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct IntField0x68_020377bc { char unk[0x68]; int field; };
int GetIntAt0x68(struct IntField0x68_020377bc* obj);

struct Obj020a2be8 {
    char pad0[0x10];
    struct Vec3 vec10;       // +0x10
    char pad1[0x21c - 0x1c];
    short field21c;           // +0x21c
    char pad2[0x22c - 0x21e];
    struct Vec3 vec22c;         // +0x22c
    char pad3[0x245 - 0x238];
    unsigned char field245;      // +0x245
};

// USA: func_020a2be8  (semantic: UpdateCombatantOffsetVec020a2be8)
extern "C" ARM void func_020a2be8(struct Obj020a2be8* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    struct Vec3 v;
    func_0200f374(&v, 0xc);
    struct CombatantStruct* c = GetCombatantUnchecked(battle, obj->field21c);
    if (c != 0) {
        CopyVec3((int*)&v, (int*)((char*)c + 0x44));
        int val = GetIntAt0x68((struct IntField0x68_020377bc*)c);
        v.y = v.y + (val >> 1);
    }
    struct Vec3 diff;
    SubtractVec3(&obj->vec10, &v, &diff);
    CopyVec3((int*)&obj->vec22c, (int*)&diff);
    obj->field245 |= 0x11;
}
