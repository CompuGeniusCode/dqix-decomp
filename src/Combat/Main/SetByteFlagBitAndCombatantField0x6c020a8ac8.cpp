#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_020a8ac8
ARM void SetByteFlagBitAndCombatantField0x6c(unsigned char* obj, int bit) {
    *(unsigned char*)(obj + 4) |= (1 << bit);
    OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x402);
    _ZN8Object3D10EnableFlagEi((unsigned char*)GetCombatantWithFlag0x800(GetBattleStruct(), bit), 0x8000100);
}
