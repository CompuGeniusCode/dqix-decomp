#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c);

struct Obj020a8c4c {
    char pad0[4];
    unsigned char f4;
    char pad5[7];
    int fc;
};

// USA: func_020a8c4c  (semantic: SetOrClearAxisFlagAndNotify_020a8c4c)
extern "C" ARM void func_020a8c4c(struct Obj020a8c4c* obj, unsigned char axis) {
    if ((obj->f4 & (1 << axis)) != 0) {
        return;
    }
    struct BattleStruct* battle = GetBattleStruct();
    void* ov = func_ov017_0218b5b0();
    struct CombatantStruct* c397c = GetCombatantAtField0x397c(battle);
    struct CombatantStruct* c800 = GetCombatantWithFlag0x800(battle, axis);
    GetPtrField0x2a04(battle);
    if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)ov, 0) == 0) {
        CancelPendingAction020397cc((struct Obj020397cc*)c800, 1);
        *(short*)((char*)c800 + 0xac) = 0;
        if (axis == *(short*)((char*)c397c + 4)) {
            return;
        }
        EnqueueEventTag36_021d2c34(axis, 0, 0);
        return;
    }
    obj->f4 |= (1 << axis);
    *(short*)((char*)c800 + 0xac) = -obj->fc;
    *(unsigned char*)((char*)c800 + 0xc1) |= 8;
}
