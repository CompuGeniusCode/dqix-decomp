#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02153a8c
ARM int IsFlag0x18Bit0x200Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x200) != 0;
}
