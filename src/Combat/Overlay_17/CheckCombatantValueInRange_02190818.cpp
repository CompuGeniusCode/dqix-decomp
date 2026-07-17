#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_02190818
ARM int CheckCombatantValueInRange_02190818(int id) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, id);
    if (c != NULL) {
        struct CombatantStruct* c2 = GetCombatantUnchecked(bs, id * 0xc + 0x14);
        if (c2 != NULL) {
            int v = *(short*)((char*)c2 + 2);
            const int K = 0x2347;
            if (v == K || v == K + 1 || v == K + 2) return 1;
        }
    }
    return 0;
}
