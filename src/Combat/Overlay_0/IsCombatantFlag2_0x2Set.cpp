#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021598ec
ARM int IsCombatantFlag2_0x2Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x2) != 0;
}
