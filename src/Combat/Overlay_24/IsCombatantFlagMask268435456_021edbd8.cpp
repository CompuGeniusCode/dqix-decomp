#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021edbd8
ARM int IsCombatantFlagMask268435456_021edbd8(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x10000000) != 0;
}
