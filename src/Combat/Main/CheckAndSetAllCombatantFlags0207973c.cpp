#include <globaldefs.h>

#include "Combat/Main/BattleList.h"

struct SearchStruct;
struct CombatantStruct;

extern "C" void* func_0202ae18(void);

int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
void SetField0x17eBitAndHigh(unsigned char* obj, int bit, int cond);

// USA: func_0207973c
ARM int CheckAndSetAllCombatantFlags0207973c(unsigned char* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    int i;
    for (i = 0; i < 4; i++) {
        if (!TestBitBySignedByteIndex(search, i) || GetCombatantWithFlag0x1000(battleStruct, i) != 0) {
            SetField0x17eBitAndHigh(obj, i, 1);
        }
    }
    return (obj[0x17e] & 0xf) == 0xf ? 1 : 0;
}
