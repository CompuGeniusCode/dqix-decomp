#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetData02104304Field4();
struct Obj150_021b354c;
unsigned char GetSubByteField56e_021b354c(Obj150_021b354c* obj);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_02072afc(int id, int* arr, short* arr2);

extern int data_020f2a38;
extern int data_020f2a30;

struct Obj_021b3444 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1;
    unsigned char flagByte;
    unsigned char pad2[4];
    int result;
};

// USA: func_ov017_021b3444  (semantic: CallFunc0202fa38IfMismatch_021b3444)
extern "C" ARM int func_ov017_021b3444(struct Obj_021b3444* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int field4 = GetData02104304Field4();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, obj->id);
    if (combatant != 0) {
        if (GetSubByteField56e_021b354c((Obj150_021b354c*)combatant) != 0) {
            obj->result = CallFunc0202fa38Mode2(field4, data_020f2a38, data_020f2a30, 0);
            return 1;
        }
    }

    int arr1[11];
    short arr2[11];
    func_02072afc(obj->id, arr1, arr2);
    int flag = obj->flagByte & 1;

    int i;
    for (i = 0; i < 0xb; i++) {
        struct CombatantStruct* c = GetCombatantUnchecked(bs, arr1[i]);
        if (c == 0) {
            continue;
        }
        short* p2 = (short*)((char*)c + 0x2);
        if (flag) {
            *p2 = -1;
        }
        short bVal = arr2[i];
        short aVal = *p2;
        if (bVal == aVal) {
            continue;
        }
        obj->result = CallFunc0202fa38Mode2(field4, data_020f2a38, data_020f2a30, 0);
        return 1;
    }
    return 0;
}
