#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
void SetCombatByteAt0x2c8d0203970c(void* unused, int index, int value);

struct Sub0215aa14 { char pad[0x7c]; signed char val; };

// USA: func_ov002_0215aa14
ARM void CopyByteField0215aa14(char* base) {
    struct CombatantStruct* combatant = GetCombatantAtField0x3ac(GetBattleStruct());
    if (!combatant) return;
    for (int i = 0; i < 7; i++) {
        struct Sub0215aa14* sub = (struct Sub0215aa14*)(base + i + 0x1c00);
        SetCombatByteAt0x2c8d0203970c(combatant, i, sub->val);
    }
}
