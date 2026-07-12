#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
unsigned char CopyOutRegion0x571d(char* obj, void* dst);

// USA: func_020dc4d0
ARM void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount) {
    struct BattleStruct* battle = GetBattleStruct();
    signed char buf[8];
    signed char n = CopyOutRegion0x571d((char*)battle, buf);
    signed char count = 0;
    for (signed char i = 0; i < n; i++) {
        if (GetCombatantWithFlag0x800(battle, buf[i]) != NULL) {
            out[count] = buf[i];
            count = count + 1;
        }
    }
    *outCount = count;
}
