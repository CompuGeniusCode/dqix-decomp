#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov000_02161318(void* obj, int id);

// USA: func_ov000_02175754
ARM void UpdateSlotStatField_02175754(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    for (i = 0; i < 4; i++) {
        void* slot = func_ov000_02161318(obj, i);
        if (slot) {
            int combatantId = *(int*)((char*)slot + 0x4c);
            struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
            if (c) {
                *(int*)((char*)slot + 0x28) = *(int*)((char*)c->currentStats + 0x14);
            }
        }
    }
}
