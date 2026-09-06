#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int TestBitInArray0x8ec(unsigned char* obj, int index);

struct Pair16_dd200 { unsigned short a; unsigned short b; };
extern Pair16_dd200 data_020ee712[];
extern Pair16_dd200 data_020ee710[];

// USA: func_020dd200
ARM int TestCombatantCategoryBit020dd200(int combatantId, int category) {
    int result = 0;
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, combatantId);
    if (combatant == 0) {
        return result;
    }
    unsigned char idx = 0;
    while (data_020ee710[idx].a != 0xffff) {
        unsigned int cat2 = data_020ee712[idx].a & 0xff;
        if (cat2 == category) {
            if (TestBitInArray0x8ec(*(unsigned char**)((char*)combatant + 0x150), data_020ee710[idx].a) != 0) {
                result = 1;
            }
            break;
        }
        idx++;
    }
    return result;
}
