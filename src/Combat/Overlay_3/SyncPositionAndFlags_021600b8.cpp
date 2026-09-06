#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3acValue(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_02032fdc(void* a, int b, int c);

struct Struct31c_021600b8 { char pad[0x31c]; int field31c; void* field320; };

// USA: func_ov003_021600b8  (semantic: SyncPositionAndFlags_021600b8)
extern "C" ARM void func_ov003_021600b8(Struct31c_021600b8* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (obj->field31c == 0 || obj->field320 == 0) return;
    int val = GetField0x3acValue(battleStruct);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, val);
    if (combatant == 0) return;
    _ZN8Vector3iaSERKS_((int*)((char*)obj->field320 + 0x44), (int*)((char*)combatant + 0x44));
    *(int*)0x4000444 = 0;
    func_02032fdc(obj->field320, 0, 0);
    *(int*)0x4000448 = 1;
}
