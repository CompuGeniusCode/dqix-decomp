#include <globaldefs.h>

void ProcessBattlerEffects02019568(void* a, int b);

struct Flags5951_021636ac {
    unsigned char lowBits : 3;
    unsigned char isActive : 1;
    unsigned char parityFlag : 1;
    unsigned char highBits : 3;
};

// USA: func_ov000_021636ac
ARM void UpdateFlag8AndBit4_021636ac(void* objRaw) {
    if (((struct Flags5951_021636ac*)((char*)objRaw + 0x5951))->isActive) {
        return;
    }
    ProcessBattlerEffects02019568((char*)objRaw + 0xec8, 1);
    ((struct Flags5951_021636ac*)((char*)objRaw + 0x5951))->isActive = 1;
    int v = *(int*)((char*)objRaw + 0x55d8);
    ((struct Flags5951_021636ac*)((char*)objRaw + 0x5951))->parityFlag = (unsigned char)(v % 2);
}
