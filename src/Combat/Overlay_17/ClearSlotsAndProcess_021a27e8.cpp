#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int index);

// USA: func_ov017_021a27e8
ARM void ClearSlotsAndProcess_021a27e8(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* obj = func_02057924();

    int i;
    for (i = 7; i <= 0x12; i++) {
        ClearCombatantSlot(battleStruct, i);
    }

    int j;
    for (j = 0x78; j <= 0x8b; j++) {
        func_02057f00(obj, j);
    }
}
