#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021599c4
ARM int IsCombatantModStatsFlag0x20000Set(struct CombatantStruct* c) {
    return (*(int*)((char*)c->currentStats + 0x14) & 0x20000) != 0;
}
