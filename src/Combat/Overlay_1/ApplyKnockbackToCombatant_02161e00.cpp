#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv(void);
extern "C" void* _Z18GetField0x3b0ValueP12BattleStruct(void* battle);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" float func_ov017_021d6110(void* obj);

struct S1f8 { char pad[0x1f8]; unsigned char active; char pad2[7]; float field200; unsigned int field204; };

// USA: func_ov001_02161e00  (semantic: ApplyKnockbackToCombatant_02161e00)
extern "C" ARM int func_ov001_02161e00(void* obj) {
    void* battle = _Z15GetBattleStructv();
    struct S1f8* combatant = (struct S1f8*)_Z18GetField0x3b0ValueP12BattleStruct(battle);
    int flag = func_ov017_021d60f4(obj);
    float a = func_ov017_021d6110((char*)obj + 8);
    float b = func_ov017_021d6110((char*)obj + 0x10);
    int fixedVal = (int)(4096.0f * b);
    if (combatant == NULL) {
        return 0;
    }
    if (flag == 0) {
        combatant->active = 0;
    } else {
        combatant->active = 1;
        combatant->field200 = 1.0f;
        combatant->field204 = 0x1000;
        combatant->field200 = a;
        combatant->field204 = fixedVal;
    }
    return 1;
}
