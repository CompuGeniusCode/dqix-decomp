#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02177300  (semantic: RecomputeElementTierAndDispatch_02177300)
#pragma opt_common_subs off
extern "C" ARM void func_ov003_02177300(char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int field = *(int*)(self + 0x1000 + 0x30);
    struct Obj2081* elemObj = *(struct Obj2081**)(self + 0x89c);
    int key1 = -1, key2 = -1;

    switch (field) {
    case 2:
        key1 = 0xb;
        key2 = 0x5d;
        break;
    case 3:
        key1 = 0xc;
        key2 = 0x60;
        break;
    case 4:
        key1 = 0xd;
        key2 = 0x64;
        break;
    }
    if (key1 < 0) {
        return;
    }

    ClearElementFlag0x20(elemObj, key1);
    SetEntryLowNibbleAndElement02080c68(elemObj, key1, 0);

    int hp;
    unsigned char i;
    for (i = 0; i < *(int*)(self + 0x1000 + 0x30); i++) {
        hp = 0;
        struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battle, *(int*)(self + 0x1000 + 0x1c + i * 4));
        if (combatant != 0) {
            hp = *(int*)((char*)combatant + 0x134);
        }
        SetEntryFirstField02080f8c((struct Container02080f8c*)elemObj, key2, hp);

        int tier = func_020dcc98((signed char)*(int*)(self + 0x1000 + 0x1c + i * 4));
        SetEntryHighNibble0x13((struct Container02080cc0*)elemObj, key2, tier);

        key2 = (short)(key2 + 1);
    }

    func_020813ec(elemObj, key1);
}
