#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021543f4
ARM int IsFlag0x14Bit0x20Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x20) != 0;
}
