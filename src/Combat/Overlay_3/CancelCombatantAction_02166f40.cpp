#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void AddPositiveField150EntriesToMap_021b6bb8(int combatantId);
int GetSignedField6Bit_021b6c2c(int a, int d);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

// USA: func_ov003_02166f40  (semantic: CancelCombatantAction_02166f40)
extern "C" ARM void func_ov003_02166f40(char* obj) {
    AddPositiveField150EntriesToMap_021b6bb8(*(short*)(obj + 0x400 + 0x82));
    GetSignedField6Bit_021b6c2c(*(short*)(obj + 0x400 + 0x82), 0);
    struct CombatantStruct* c = GetCombatantAtField0x3ac(GetBattleStruct());
    if (c == NULL) return;
    CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
}
