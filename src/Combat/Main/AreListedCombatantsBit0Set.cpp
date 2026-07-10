#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02086b98 {
    char pad[0xf78];
    unsigned char ids[4];   // 0xf78
    unsigned char count;    // 0xf7c
};

// USA: func_02086b98
ARM int AreListedCombatantsBit0Set(struct Obj02086b98* o) {
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    for (i = 0; i < o->count; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, o->ids[i]);
        if (c != NULL) {
            int* p = *(int**)((char*)c + 0x130);
            if ((*p & 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
