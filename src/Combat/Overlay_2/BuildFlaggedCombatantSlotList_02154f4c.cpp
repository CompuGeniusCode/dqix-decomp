#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
unsigned char CopyOutRegion0x571d(char* obj, void* dst);
extern "C" void func_ov002_02154c30(void* p);

// USA: func_ov002_02154f4c
ARM int BuildFlaggedCombatantSlotList_02154f4c(unsigned char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned char buf[8];
    unsigned char n = CopyOutRegion0x571d((char*)battle, buf);
    unsigned char count = 0;
    unsigned char i;

    buf[n] = 4;
    for (i = 0; i < n; i++) {
        if (GetCombatantWithFlag0x800(battle, buf[i]) != NULL) {
            unsigned char* q = obj + count;
            q += 0x1000;
            q[0xc68] = buf[i];
            count = count + 1;
        }
    }
    {
        unsigned char* q = obj + count;
        q += 0x1000;
        q[0xc68] = 4;
    }
    obj[0x1000 + 0xc6d] = count;

    int j;
    for (j = 0; j < 4; j++) {
        memset(obj + 0xa70 + 0x1000 + j * 16, 0, 4);
    }
    func_ov002_02154c30(obj + 0xa70 + 0x1000);
    return 0;
}
