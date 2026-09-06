#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void* GetArrayEntryByIndex_02156034(void* obj);

// USA: func_ov003_02155f40
ARM int MatchesArrayEntry_02155f40(void* obj, int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(bs, combatantId);
    int result;
    if (combatant != NULL) {
        void* inner = *(void**)((char*)combatant + 0x150);
        int val = *(int*)((char*)inner + 0x950);
        result = (val == (int)GetArrayEntryByIndex_02156034(obj)) ? 1 : 0;
    } else {
        result = 0;
    }
    return result;
}
