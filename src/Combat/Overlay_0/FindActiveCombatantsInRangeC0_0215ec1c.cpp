#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_0215ec1c  (semantic: FindActiveCombatantsInRangeC0_0215ec1c)
extern "C" ARM int func_ov000_0215ec1c(void* unused, short* out, int max) {
    int found = 0;
    int i;
    for (i = 0; i < 8; i++) {
        short id = (short)(i + 0xc0);
        struct BattleStruct* bs = GetBattleStruct();
        struct CombatantStruct* c = GetCombatantWithFlag0x400(bs, id);
        if (c != NULL) {
            out[found++] = id;
            if (found == max) return found;
        }
    }
    return found;
}
