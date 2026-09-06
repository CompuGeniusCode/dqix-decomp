#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021599ac
ARM int IsCombatantModStatsFlag0x10000Set(struct CombatantStruct* c) {
    return (*(int*)((char*)c->currentStats + 0x14) & 0x10000) != 0;
}
