#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct S_10088;
int IsFlag10088Set(struct S_10088* obj);

// USA: func_ov023_021ed92c
ARM int AreAllListedCombatantsFlagged_021ed92c(void) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char* base = (unsigned char*)GetPtrField0x2a04(bs);
    for (int i = 0; i < base[0xf7c]; i++) {
        unsigned char* p = base + i;
        struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, p[0xf78]);
        if (combatant) {
            if (!IsFlag10088Set((struct S_10088*)combatant)) return 0;
        }
    }
    return 1;
}
