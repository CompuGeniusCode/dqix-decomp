#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_020dc548(int a, signed char* arr, signed char* count);

struct Obj_021bd3a4;
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void ClearFlag0x1InField0x6c(unsigned char* obj);
void SetFlag0x6cBit0(unsigned char* obj);

struct TagObj_021bd4d0 {
    unsigned char pad0[0x16];
    unsigned short field16;
    unsigned char pad1[0x101 - 0x18];
    unsigned char field101;
};

// USA: func_ov017_021bd4d0  (semantic: DispatchAndPropagateFlag_021bd4d0)
extern "C" ARM void func_ov017_021bd4d0(struct TagObj_021bd4d0* obj, int id, int clearFlag, int checkFlag2) {
    struct BattleStruct* battleStruct;
    struct CombatantStruct* combatant;
    struct CombatantStruct* combatant2;
    signed char arr[7];
    signed char count;
    int i;
    int keep;
    unsigned short g;
    unsigned short u;

    battleStruct = GetBattleStruct();
    combatant = GetCombatantWithFlag0x800(battleStruct, id);
    if (combatant != 0) {
        keep = 1;
        g = *(unsigned short*)func_02012fe4();
        u = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
        if (u != g) {
            if (clearFlag == 0) {
                keep = 0;
            }
        }
        if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
            if (obj->field16 == 0x2972 || obj->field101 == 0) {
                checkFlag2 = 0;
            }
        }
        if (keep != 0) {
            if (checkFlag2 == 0 || !HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
                func_020dc548((signed char)id, arr, &count);
                for (i = 0; i < count; i++) {
                    combatant2 = GetCombatantWithFlag0x800(battleStruct, arr[i]);
                    if (combatant2 != 0) {
                        if (clearFlag) {
                            ClearFlag0x1InField0x6c((unsigned char*)combatant2);
                        } else {
                            SetFlag0x6cBit0((unsigned char*)combatant2);
                        }
                    }
                }
            }
        }
    }
}
