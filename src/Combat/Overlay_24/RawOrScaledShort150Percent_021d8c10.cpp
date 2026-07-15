#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021d8c10
ARM int RawOrScaledShort150Percent_021d8c10(char** arg0, int id, int a2, int a3, int a4, int val) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, id);
    if (!c) return val;
    int flags = *(int*)((char*)c->currentStats + 0x18);
    if (flags & 0x200) {
        return *(short*)(*arg0 + 0x8e00 + 0x54);
    }
    return (int)((float)(*(short*)(*arg0 + 0x8e00 + 0x54)) * 1.5f);
}
