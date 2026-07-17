#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
int GetField0x580207ecc4(void* obj);
extern "C" void func_020dc124(int a, int b);
extern "C" void func_020dc184(int a, int b);

// USA: func_ov017_021a2840
ARM void ProcessSlotField58_021a2840(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();

    int i;
    for (i = 0; i < 0xc; i++) {
        struct CombatantStruct* combatant = GetCombatantUnchecked(battleStruct, i + 7);
        if (combatant == NULL) {
            continue;
        }

        void* ptr = *(void**)((char*)combatant + 0x8);
        if (ptr == NULL) {
            continue;
        }

        int field58 = GetField0x580207ecc4(ptr);
        if (field58 != 0) {
            func_020dc124(field58, 0);
            func_020dc184(field58, 0);
        }
    }
}
