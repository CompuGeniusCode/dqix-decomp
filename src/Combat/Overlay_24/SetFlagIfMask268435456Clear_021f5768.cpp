#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);
int IsCombatantFlagMask268435456_021edbd8(struct CombatantStruct* combatant);

// USA: func_ov024_021f5768
ARM int SetFlagIfMask268435456Clear_021f5768(int* p0, short id, int unused2, int* outFlag, short* out5) {
    struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(*p0, id);
    if (c == NULL) return 0;
    if (IsCombatantFlagMask268435456_021edbd8(c)) {
        return 0;
    }
    *outFlag = 1;
    *out5 = id;
    return 1;
}
