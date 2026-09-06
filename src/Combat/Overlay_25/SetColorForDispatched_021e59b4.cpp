#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct Struct020372b8;
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);

struct P021e59b4 {
    char pad[8];
    unsigned char f8;
    unsigned char f9;
    unsigned short fa;
};

// USA: func_ov025_021e59b4
ARM int SetColorForDispatched_021e59b4(struct P021e59b4* obj, int unused, int unused2, void* ctx) {
    struct BattleStruct* bs = GetBattleStruct();
    int buf[8];
    int count = DispatchByIndex021820bc(ctx, unused, obj->f8, (int)buf);
    for (int j = 0; j < count; j++) {
        struct CombatantStruct* combatant = GetCombatantUnchecked(bs, buf[j]);
        if (combatant) {
            _ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)combatant, obj->f9, obj->fa);
        }
    }
    return 1;
}
