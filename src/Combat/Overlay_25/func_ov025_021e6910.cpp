#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void ClearFlag0x1InField0x6c(unsigned char* obj);
void SetFlag0x6cBit0(unsigned char* obj);
extern "C" void func_02036e34(void* a, void* b, int c);
extern int data_ov025_021ef82b;

struct Param2_021e6910 { char pad[0x10]; unsigned char* node; };

// USA: func_ov025_021e6910  (semantic: ClearAndSetCombatantFlags_021e6910)
extern "C" ARM int func_ov025_021e6910(void* unused, struct Param2_021e6910* p2) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantUnchecked(bs, 0xc8);
    if (!c) return 1;
    ClearFlag0x1InField0x6c((unsigned char*)c);
    func_02036e34(c, &data_ov025_021ef82b, 1);
    unsigned short idx = *(unsigned short*)(p2->node + 0x20);
    struct CombatantStruct* c2 = GetCombatantUnchecked(bs, idx * 0xc + 0x1c);
    if (c2) {
        SetFlag0x6cBit0((unsigned char*)c2);
    }
    return 1;
}
