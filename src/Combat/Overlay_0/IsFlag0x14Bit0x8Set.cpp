#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156038
ARM int IsFlag0x14Bit0x8Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x8) != 0;
}
