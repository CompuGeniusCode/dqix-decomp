#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void* FilterByTypeAndBytes020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5);

struct StackArgs021d18d8 {
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    volatile int extra;
};

struct Struct021d18d8 {
    unsigned char pad0[4];
    unsigned char byte4;
    unsigned char byte5;
    unsigned char byte6;
    unsigned char byte7;
    unsigned char byte8;
    unsigned char byte9;
    int wordC;
};

// USA: func_ov017_021d18d8
ARM void FilterCombatantByType_021d18d8(int combatantId, struct Struct021d18d8* s, struct BattleStruct* battleStruct) {
    struct CombatantStruct* c1 = GetCombatantUnchecked(battleStruct, combatantId);
    int flag = 1;
    struct CombatantStruct* c2 = GetCombatantAtField0x397c(battleStruct);
    unsigned short u1 = GetU16At0x6((struct U16Field0x6_020375f8*)c1);
    unsigned short u2 = GetU16At0x6((struct U16Field0x6_020375f8*)c2);
    if (u1 != u2) flag = 0;
    struct StackArgs021d18d8 args;
    args.b2 = s->byte6;
    args.b3 = s->byte7;
    args.b4 = s->byte8;
    args.b5 = s->byte9;
    args.extra = s->wordC;
    FilterByTypeAndBytes020a86b8(combatantId, flag, s->byte4, s->byte5, args.b2, args.b3, args.b4, args.b5);
}
