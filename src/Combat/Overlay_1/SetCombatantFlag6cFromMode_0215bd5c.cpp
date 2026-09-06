#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* _Z21GetCombatantUncheckedP12BattleStructi(void*, int);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);

// USA: func_ov001_0215bd5c
ARM int SetCombatantFlag6cFromMode_0215bd5c(void* self, int mode) {
    void* battle = _Z15GetBattleStructv();
    if (battle == NULL) return 0;
    int flag = 1;
    int id = func_ov017_021d60f4(self);
    if (mode >= 2) {
        flag = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* combatant = _Z21GetCombatantUncheckedP12BattleStructi(battle, id);
    if (combatant == NULL) return 0;
    if (flag != 0) {
        _ZN8Object3D11MakeVisibleEv(combatant);
    } else {
        _ZN8Object3D10MakeHiddenEv(combatant);
    }
    return 1;
}
