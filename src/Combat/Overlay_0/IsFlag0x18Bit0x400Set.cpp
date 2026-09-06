#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156404
ARM int IsFlag0x18Bit0x400Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x400) != 0;
}
