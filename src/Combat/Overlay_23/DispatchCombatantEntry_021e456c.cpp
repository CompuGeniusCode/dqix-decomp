#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov023_021e6194(int arg);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* self, int a, int b);

struct S1a0;
extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(struct S1a0* obj, unsigned int v);

int GetFieldAt0x150(unsigned char* obj);

extern "C" int func_ov023_021e5974(int a, int b, int c, int d, int e);

// USA: func_ov023_021e456c  (semantic: DispatchCombatantEntry_021e456c)
extern "C" ARM void func_ov023_021e456c(void* objRaw) {
    char* obj = (char*)objRaw;
    if (!(*(unsigned short*)(obj + 0x634) & 4)) return;
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, *(int*)(obj + 0x4fc));
    if (!combatant) return;
    int flag = 0;
    if (*(unsigned short*)(obj + 0x634) & 0x10) flag = 1;
    char* six4 = (char*)func_ov023_021e6194(*(int*)(obj + 0x128));
    char* five = (char*)func_ov023_021e6194(*(int*)(obj + 0x12c));
    _ZN8Object3D24MaybeSetRegularAnimationEPKci(five, *(int*)(six4 + 0x14), 0);
    _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)five, *(unsigned int*)(six4 + 0x1c));
    int fieldVal = GetFieldAt0x150((unsigned char*)combatant);
    func_ov023_021e5974(*(int*)(obj + 0x12c), fieldVal, *(int*)(obj + 0x4fc), flag, 1);
    *(unsigned short*)(obj + 0x634) &= ~4;
    *(unsigned short*)(obj + 0x634) &= ~0x10;
    *(int*)(obj + 0x134) = 0;
    *(unsigned short*)(obj + 0x634) |= 8;
}
