#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);

// USA: func_02057db8
ARM void ClearCombatantSlotIfValidId02057db8(int unused, int id) {
    if (id < 0xd0) return;
    if (id > 0xdf) return;
    ClearCombatantSlot(GetBattleStruct(), id);
}
