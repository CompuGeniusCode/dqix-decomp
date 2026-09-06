#include <globaldefs.h>
int MatchesAnyTableEntry020dd19c(unsigned int, int);
#include "Combat/Main/BattleList.h"

void* GetFieldAt0x150(unsigned char*);

// USA: func_020dd154
ARM int DispatchByField0x950Byte(int combatantId, int b) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == NULL) {
        return 0;
    }
    void* p = GetFieldAt0x150((unsigned char*)combatant);
    if (p == NULL) {
        return 0;
    }
    int val = *(int*)((char*)p + 0x950);
    return MatchesAnyTableEntry020dd19c((unsigned int)(val & 0xff), (int)(b));
}
