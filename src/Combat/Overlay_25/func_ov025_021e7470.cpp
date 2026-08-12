#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct ListNode020378dc;
void UnlinkOrClearListNode020378dc(struct ListNode020378dc* node);
void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
void ClearFlag0x1InField0x6c(unsigned char* obj);

struct Param2_021e7470 { char pad[0x10]; unsigned char* node; };

// USA: func_ov025_021e7470
extern "C" ARM int func_ov025_021e7470(void* unused, struct Param2_021e7470* p2) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantUnchecked(bs, 0xc8);
    if (c) {
        UnlinkOrClearListNode020378dc((struct ListNode020378dc*)c);
        ClearCombatantSlot(bs, 0xc8);
    }
    unsigned short idx = *(unsigned short*)(p2->node + 0x20);
    struct CombatantStruct* c2 = GetCombatantUnchecked(bs, idx * 0xc + 0x1c);
    if (c2) {
        ClearFlag0x1InField0x6c((unsigned char*)c2);
    }
    return 1;
}
