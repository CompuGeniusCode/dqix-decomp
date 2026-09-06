#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" float _fflt(int v);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC);

// USA: func_ov003_02155740  (semantic: RescaleCombatantSizeTarget_02155740)
extern "C" ARM void func_ov003_02155740(char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    signed char idx = *(signed char*)(obj + 0x1f7);
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, idx);
    if (c == 0) {
        return;
    }

    if (*(int*)(obj + 0x1fc) & 1) {
        unsigned short* src = *(unsigned short**)((char*)c + 0x134);
        unsigned short w = src[0x30 / 2];
        int v1 = _ffix(_fmul(*(float*)(obj + 0x330), _fflt(w)));
        unsigned short h = src[0x32 / 2];
        int v2 = _ffix(_fmul(*(float*)(obj + 0x334), _fflt(h)));

        if (v1 <= 0) v1 = 1;
        if (v2 <= 0) v2 = 0;
        if (w < v1) v1 = w;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = (unsigned short)v1;
        if (h < v2) v2 = h;
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = (unsigned short)v2;
    } else {
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)c + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    }

    void* ptr = func_0202ae18();
    if (CheckField0NonZero((int*)ptr) == 0) {
        return;
    }
    signed char id2 = *(signed char*)(obj + 0x1f7);
    func_ov017_021c9e00(id2, 1, 0, 1);
}
