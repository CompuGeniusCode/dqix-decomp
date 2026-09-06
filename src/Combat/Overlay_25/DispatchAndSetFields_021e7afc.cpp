#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);

struct ShortPair0xba0xbc;
extern "C" void _Z20SetFields0xbaAnd0xbcP17ShortPair0xba0xbcss(struct ShortPair0xba0xbc* obj, short a, unsigned short b);

struct S021e7afc { char pad[8]; unsigned short field8; short fieldA; unsigned short fieldC; };

// USA: func_ov025_021e7afc  (semantic: DispatchAndSetFields_021e7afc)
extern "C" ARM int func_ov025_021e7afc(struct S021e7afc* obj, int b, int unused, int c) {
    struct BattleStruct* battle = GetBattleStruct();
    int ids[12];
    int count = DispatchByIndex021820bc((void*)c, b, obj->field8, (int)ids);
    int i;
    for (i = 0; i < count; i++) {
        struct CombatantStruct* combatant = GetCombatantWithFlag0x2(battle, ids[i]);
        if (combatant) {
            _Z20SetFields0xbaAnd0xbcP17ShortPair0xba0xbcss((struct ShortPair0xba0xbc*)combatant, obj->fieldA, obj->fieldC);
        }
    }
    return 1;
}
