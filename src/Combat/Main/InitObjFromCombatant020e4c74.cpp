#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Sub0x150_020e4c74 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" void func_020e4b34(void* obj, struct BaseCombatStats* stats1, struct BaseCombatStats* stats2,
    int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12);

// USA: func_020e4c74
ARM void InitObjFromCombatant020e4c74(void* obj, struct CombatantStruct* combatant) {
    memset(obj, 0, 0xc);
    if (combatant != NULL) {
        struct Sub0x150_020e4c74* sub = *(struct Sub0x150_020e4c74**)((char*)combatant + 0x150);
        func_020e4b34(obj, combatant->baseStats, combatant->baseStats, 0, 0, 0, 0, sub->bit0, 0, 1, 0, 1);
    }
}
