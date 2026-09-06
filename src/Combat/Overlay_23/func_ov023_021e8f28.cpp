#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3acValue(struct BattleStruct* battleStruct);
unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void* __clear(void* dst, int count);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov023_021e8f28
extern "C" ARM struct CombatantStruct* func_ov023_021e8f28(int index) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* result = 0;
    if (index >= 0) {
        int inRange = (index >= 0) && (index <= 3);
        if (inRange) {
            result = GetCombatantWithFlag0x100(battle, index);
        }
    } else {
        if (index == -1) {
            int key = GetField0x3acValue(battle);
            result = GetCombatantWithFlag0x100(battle, key);
        } else {
            unsigned char local[4];
            __clear(local, 4);
            unsigned char count = CopyOutRegion0x5718((char*)battle, local);
            int i = -1 - index;
            if (i < count) {
                result = GetCombatantWithFlag0x100(battle, local[i]);
            }
        }
    }
    return result;
}
