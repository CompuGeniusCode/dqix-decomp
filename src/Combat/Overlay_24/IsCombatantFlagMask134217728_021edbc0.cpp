#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021edbc0
ARM int IsCombatantFlagMask134217728_021edbc0(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x8000000) != 0;
}
