#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02157cc4
ARM int IsFlag0x14Bit0x800000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x800000) != 0;
}
