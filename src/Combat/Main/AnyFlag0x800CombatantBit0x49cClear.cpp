#include <globaldefs.h>
void* GetPtrField0x2a04(struct BattleStruct*);
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Sub0x150_020685f0 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

struct PartyRow_020685f0 {
    char pad[0xf78];
    unsigned char id;
};

// USA: func_020685f0
ARM int AnyFlag0x800CombatantBit0x49cClear(struct BattleStruct* battleStruct) {
    unsigned char* p = (unsigned char*)GetPtrField0x2a04((struct BattleStruct*)(battleStruct));
    int i;
    for (i = 0; i < p[0xf7c]; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, ((struct PartyRow_020685f0*)(p + i))->id);
        if (c != 0) {
            struct Sub0x150_020685f0* sub = *(struct Sub0x150_020685f0**)((char*)c + 0x150);
            if (sub->bit0 == 0) {
                return 1;
            }
        }
    }
    return 0;
}
