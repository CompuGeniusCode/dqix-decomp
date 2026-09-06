#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern short data_ov000_02182d54;
extern short data_ov000_02182d56[];

// USA: func_ov000_02159cb4  (semantic: Lookup_02159cb4)
extern "C" ARM int func_ov000_02159cb4(void* unusedThis, int combatantId) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x100(battle, combatantId);
    if (!c) return 0;

    int i = 0;
    while (*(short*)((char*)&data_ov000_02182d54 + i * 4) != -1) {
        void* sub = *(void**)((char*)c + 0x150);
        short key = *(short*)((char*)&data_ov000_02182d54 + i * 4);
        if (key == *(int*)((char*)sub + 0x950)) {
            return data_ov000_02182d56[i * 2];
        }
        i++;
    }
    return 0;
}
