#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021599dc
ARM int IsCombatantModStatsFlag0x100Set(struct CombatantStruct* c) {
    return (*(int*)((char*)c->currentStats + 0x18) & 0x100) != 0;
}
