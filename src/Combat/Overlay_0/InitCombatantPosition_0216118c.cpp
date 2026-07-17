#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov000_021626a0(void* self, int a, int b);
extern "C" void func_ov000_0216d600(void* obj, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void ApplyVec3Tail(void* obj, int* vec);
void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b);

struct Vec3_0216118c { int v[3]; };

// USA: func_ov000_0216118c
ARM void InitCombatantPosition_0216118c(void* self, int flag) {
    GetBattleStruct();
    func_ov017_0218b5b0();
    func_ov000_021626a0(self, 0x26, 0);
    func_ov000_0216d600((char*)self + 0x18 + 0xc00, 1, 1, 0, 0, 0, 0, 1);
    if (flag == 0) {
        return;
    }
    int* mirrorPtr = *(int**)((char*)self + 0x29c);
    if (*(int*)((char*)mirrorPtr + 0x8000 + 0xe20) != 0) {
        return;
    }
    struct Vec3_0216118c temp1 = *(struct Vec3_0216118c*)((char*)self + 0x88 + 0xc00);
    struct Vec3_0216118c temp2 = temp1;
    temp2.v[1] += 0x800;
    temp2.v[2] += 0x3000;
    ApplyVec3Tail((char*)self + 0x18 + 0xc00, temp2.v);
    SetPosAndFields0216f1e4((char*)self + 0x18 + 0xc00, temp1.v, 0xf33, 0);
}
