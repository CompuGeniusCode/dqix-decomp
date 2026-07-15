#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215516c
ARM int IsFlag0x14Bit0x8000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x8000000) != 0;
}
