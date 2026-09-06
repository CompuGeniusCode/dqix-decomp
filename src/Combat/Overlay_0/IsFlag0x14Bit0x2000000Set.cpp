#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021563ec
ARM int IsFlag0x14Bit0x2000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x2000000) != 0;
}
