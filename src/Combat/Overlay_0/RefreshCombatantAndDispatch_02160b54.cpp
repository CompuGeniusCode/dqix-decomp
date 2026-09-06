#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b0Value(struct BattleStruct* battleStruct);
extern "C" unsigned int* func_ov017_0218b5b0(void);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void func_02016874(void* big);
extern "C" void func_ov000_02161020(void* obj);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct*, int);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vec3i_020374f0 { int x; int y; int z; };
extern "C" struct Vec3i_020374f0 _ZNK8Object3D8GetScaleEv(unsigned char* src);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);
extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);
int PeekInputLogB(void);
extern "C" void func_ov025_021df864(void* arg);

// USA: func_ov000_02160b54  (semantic: RefreshCombatantAndDispatch_02160b54)
extern "C" ARM void func_ov000_02160b54(unsigned char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned int* v = func_ov017_0218b5b0();
    GetField0x3b0Value(battle);
    if (!(*(int*)(obj + 0x55f4) & 0x200)) {
        return;
    }
    if (GetBitsInField4(v, 0x100000) == 0) {
        func_02016874(obj + 0xec8);
    }
    func_ov000_02161020(obj);
    if (GetBitsInField4(v, 4) == 0) {
        struct CombatantStruct* c1 = GetCombatantUnchecked(battle, *(short*)(obj + 0x6fd6));
        struct CombatantStruct* c2 = GetCombatantUnchecked(battle, 0xc8);
        if (c2 != 0) {
            if (c1 != 0) {
                _ZN8Vector3iaSERKS_((int*)((char*)c2 + 0x44), (int*)((char*)c1 + 0x44));
                _ZN8Vector3iaSERKS_((int*)((char*)c2 + 0x50), (int*)((char*)c1 + 0x50));
                const struct Vec3i_020374f0& tmp = _ZNK8Object3D8GetScaleEv((unsigned char*)c1);
                _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)c2, (int*)&tmp);
            }
            _ZN8Object3D4DrawEb(c2, 0);
        }
    }
    _ZN12RenderConfig12SubmitToFifoEv();
    if (*(int*)(obj + 0xea8) != 8) {
        return;
    }
    if (PeekInputLogB() != 4) {
        return;
    }
    func_ov025_021df864(obj + 0x5ab0);
}
