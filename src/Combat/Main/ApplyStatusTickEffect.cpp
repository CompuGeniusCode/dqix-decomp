#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);

struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

struct Struct020372b8;
void ScaleColorChannel020372b8(struct Struct020372b8* obj, int a, int b);

struct S02037418;
void SetFieldAAndSync02037418(struct S02037418* obj, int val);

struct Obj02039df4 {
    char pad0[4];
    short combatantId;
    char pad6[0xc2 - 6];
    unsigned char lo0xc2 : 5;
    unsigned char flagBit0xc2 : 1;
    unsigned char hi0xc2 : 2;
    char padc3[0x1ce - 0xc3];
    unsigned char flags1ce;
};

// USA: func_02039df4
ARM void ApplyStatusTickEffect(struct Obj02039df4* obj) {
    int q;
    struct CombatantStruct* combatant;

    if (obj->flagBit0xc2) return;
    combatant = GetCombatantWithFlag0x1000(GetBattleStruct(), obj->combatantId);
    if (combatant == NULL) return;
    q = GetU16At0x6((struct U16Field0x6_020375f8*)obj) / 100;
    if (q != 0x2b && q != 0x2d && q != 0x40 && q != 0x29) return;
    obj->flags1ce |= 4;
    ScaleColorChannel020372b8((struct Struct020372b8*)obj, 0, 0);
    SetFieldAAndSync02037418((struct S02037418*)obj, 0);
}
