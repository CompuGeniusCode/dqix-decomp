#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215991c
ARM int IsCombatantFlag0x400Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x400) != 0;
}
