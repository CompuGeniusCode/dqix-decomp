#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov003_02155fc0  (semantic: CheckCombatantField130Bit0_02155fc0)
extern "C" ARM int func_ov003_02155fc0(void* unused, int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, combatantId);
    int result;
    if (c != NULL) {
        unsigned int* p = *(unsigned int**)((char*)c + 0x130);
        result = (*p & 1) != 0;
    } else {
        result = 0;
    }
    return result;
}
