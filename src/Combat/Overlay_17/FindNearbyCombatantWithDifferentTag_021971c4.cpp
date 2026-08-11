#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" void* func_0200f374(void* dst, int count);

struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra);

struct Party021971c4 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

// USA: func_ov017_021971c4  (semantic: FindNearbyCombatantWithDifferentTag_021971c4)
extern "C" ARM unsigned short func_ov017_021971c4(unsigned char* ov) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (battleStruct == NULL) {
        return 0;
    }
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    if (combatant == NULL) {
        return 0;
    }
    struct Party021971c4* party = (struct Party021971c4*)GetPtrField0x2a04(battleStruct);
    int flags[4];
    unsigned short result = 0;
    func_0200f374(flags, 0x10);
    int i;
    for (i = 0; i < party->count; i++) {
        flags[party->ids[i]] = 1;
    }
    int j;
    for (j = 0; j < 4; j++) {
        if (flags[j] != 0) {
            continue;
        }
        struct CombatantStruct* other = GetCombatantWithFlag0x100(battleStruct, j);
        if (other == NULL) {
            continue;
        }
        if (GetU16At0x6((struct U16Field0x6_020375f8*)other) != GetU16At0x6((struct U16Field0x6_020375f8*)combatant)) {
            continue;
        }
        if (*((unsigned char*)other + 0xbe) != 2) {
            continue;
        }
        if (CheckProximity_02196fc8((unsigned char*)combatant, (unsigned char*)other, 0x1000)) {
            unsigned short v = *(unsigned short*)((unsigned char*)other + 0x1b2);
            if (*(unsigned short*)(ov + 0x4400 + 0xc2) != v) {
                result = v;
                break;
            }
        }
    }
    return result;
}
