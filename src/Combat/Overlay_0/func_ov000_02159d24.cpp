#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct TableEntry02182d88 { short key; short pad; };
extern struct TableEntry02182d88 data_ov000_02182d88[];

struct TableEntry02182d8a { short value; short pad; };
extern struct TableEntry02182d8a data_ov000_02182d8a[];

// USA: func_ov000_02159d24
extern "C" ARM int func_ov000_02159d24(int unused, int combatantId) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == 0) {
        return 0;
    }
    int i = 0;
    goto test;
    do {
        short key = data_ov000_02182d88[i].key;
        int base = *(int*)((char*)combatant + 0x150);
        int field950 = *(int*)((char*)base + 0x950);
        if (key == field950) {
            return data_ov000_02182d8a[i].value;
        }
        i++;
test:
        ;
    } while (data_ov000_02182d88[i].key != -1);
    return 0;
}
