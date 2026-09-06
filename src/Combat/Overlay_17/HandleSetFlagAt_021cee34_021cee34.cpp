#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct EventArgs021cee34 {
    unsigned char pad[4];
    int id;
    unsigned int flag;
    int set;
};

// USA: func_ov017_021cee34
ARM void HandleSetFlagAt_021cee34_021cee34(void* unused, EventArgs021cee34* args, struct BattleStruct* battleStruct) {
    int set = args->set;
    unsigned int flag = args->flag;
    int id = args->id;
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, id);
    if (combatant == NULL) return;
    unsigned int* field = (unsigned int*)((char*)combatant + 0x18c);
    if (set) {
        *field |= flag;
    } else {
        *field &= ~flag;
    }
}
