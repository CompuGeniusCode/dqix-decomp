#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void* FilterByTypeAndBytes020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5);

struct Evt021d18d8 {
    unsigned char pad0[4];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char pad1[2];
    int extra;
};

// USA: func_ov017_021d18d8  (semantic: Dispatch021d18d8)
extern "C" ARM void* func_ov017_021d18d8(int id, struct Evt021d18d8* evt, struct BattleStruct* battleStruct, int unused3) {
    struct CombatantStruct* self = GetCombatantUnchecked(battleStruct, id);
    int flag = 1;
    struct CombatantStruct* other = GetCombatantAtField0x397c(battleStruct);
    if (GetU16At0x6((struct U16Field0x6_020375f8*)self) != GetU16At0x6((struct U16Field0x6_020375f8*)other)) flag = 0;
    typedef void* (*Fn9)(int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int);
    return ((Fn9)FilterByTypeAndBytes020a86b8)(id, flag, evt->b0, evt->b1, evt->b2, evt->b3, evt->b4, evt->b5, evt->extra);
}
