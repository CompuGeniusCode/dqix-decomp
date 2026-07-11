#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetFieldAt0x150(unsigned char*);
extern "C" int func_020dd19c(int, int);

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
    return func_020dd19c(val & 0xff, b);
}
