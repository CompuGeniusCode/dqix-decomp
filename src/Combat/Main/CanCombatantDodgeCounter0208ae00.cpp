#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" unsigned int* func_ov017_0218b5b0(void);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
unsigned char GetByte0x26c(char* obj);

// USA: func_0208ae00
ARM int CanCombatantDodgeCounter0208ae00(char* obj, int combatantId) {
    unsigned int* v5 = func_ov017_0218b5b0();
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c1 = GetCombatantWithFlag0x100(battle, combatantId);
    struct CombatantStruct* c2 = GetCombatantWithFlag0x100(battle, combatantId);
    if (c1 == NULL || (**(int**)((char*)c1 + 0x130) & 1)) {
        return 0;
    }
    int* p2 = *(int**)((char*)c2 + 0x130);
    if (!(*p2 & 2)) {
        return 0;
    }
    if (GetBitsInField4(v5, 0x10) != 0) {
        return 0;
    }
    if (*(int*)(obj + 0x1c) != 0) {
        return 0;
    }
    struct CombatantStruct* c3 = GetCombatantAtField0x397c(battle);
    if (*(short*)((char*)c3 + 0xb2) == 0) {
        return 0;
    }
    return GetByte0x26c((char*)c3) == 0 ? 1 : 0;
}
