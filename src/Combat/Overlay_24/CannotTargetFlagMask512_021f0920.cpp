#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"

int IsCombatantFlagMask512_021eda60(struct CombatantStruct* combatant);

struct RngHolder_021f0920 { void* field0; };

// USA: func_ov024_021f0920  (semantic: CannotTargetFlagMask512_021f0920)
extern "C" ARM int func_ov024_021f0920(struct RngHolder_021f0920* holder, int id) {
	struct CombatantStruct* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	int flag = IsCombatantFlagMask512_021eda60(combatant);
	int result = !flag;
	return result;
}
