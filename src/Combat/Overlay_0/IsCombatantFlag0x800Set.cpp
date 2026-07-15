#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02159934
ARM int IsCombatantFlag0x800Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x800) != 0;
}
