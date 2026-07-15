#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
// USA: func_ov024_021e57c0
ARM void SetBytelag_021e57c0_021e57c0(int* param_1, int id) {
	struct CombatantStruct* combatant = GetCombatantByID(param_1[4], id);
	if (combatant != NULL) {
		*((char*)combatant->currentStats + 0x21) = 1;
	}
}
