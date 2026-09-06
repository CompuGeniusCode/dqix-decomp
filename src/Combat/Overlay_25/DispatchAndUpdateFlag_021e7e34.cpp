#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);

struct Flags02033fdc;
struct Flags02033fcc;
void ClearFlag0x4At0xe0(struct Flags02033fdc* p);
void SetFlag0x4At0xe0(struct Flags02033fcc* p);

struct Param021e7e34 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int field_c;
};

// USA: func_ov025_021e7e34  (semantic: DispatchAndUpdateFlag_021e7e34)
extern "C" ARM int func_ov025_021e7e34(struct Param021e7e34* p, int unused, int unusedR2, void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int ids[12];
    int count = DispatchByIndex021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x2(bs, ids[i]);
        if (c) {
            if (p->field_c != 0) {
                ClearFlag0x4At0xe0((struct Flags02033fdc*)c);
            } else {
                SetFlag0x4At0xe0((struct Flags02033fcc*)c);
            }
        }
    }
    return 1;
}
