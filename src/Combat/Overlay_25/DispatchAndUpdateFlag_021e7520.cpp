#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);
void SetBits0x40000AndFlag0x2(unsigned char* obj);
void ClearStateFlags0203400c(unsigned char* obj);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);

struct Param021e7520 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int field_c;
};

// USA: func_ov025_021e7520
ARM int DispatchAndUpdateFlag_021e7520(struct Param021e7520* p, int unused, int unusedR2, void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int ids[8];
    int count = DispatchByIndex021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x2(bs, ids[i]);
        if (c) {
            if (p->field_c != 0) {
                SetBits0x40000AndFlag0x2((unsigned char*)c);
            } else {
                ClearStateFlags0203400c((unsigned char*)c);
            }
        }
    }
    return 1;
}
