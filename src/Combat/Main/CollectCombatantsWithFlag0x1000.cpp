#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);

// USA: func_02010038
ARM int CollectCombatantsWithFlag0x1000(struct BattleStruct* battleStruct, unsigned char* out) {
    int i;
    int count;
    if (out == NULL) {
        return 0;
    }
    i = 0;
    out[0] = 0;
    count = 1;
    for (; i < 4; i++) {
        if (GetCombatantWithFlag0x1000(battleStruct, i) != NULL) {
            out[count] = i;
            count++;
        }
    }
    return count;
}
