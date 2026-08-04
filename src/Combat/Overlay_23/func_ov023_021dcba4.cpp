#include <globaldefs.h>
#include "std_library_functions.h"

void ResetIfNonNeg_021db2e4(volatile int* p);
unsigned int GetSubBg0ScreenBaseAddr(void);
unsigned int GetBgCharBaseAddress020c4d1c(void);

struct SubStruct700_021dcba4 {
    char pad0[0x70];
    short f70;
    short f72;
    unsigned short f74;
    char pad76[0x7c - 0x76];
    signed char f7c;
};

// USA: func_ov023_021dcba4  (semantic: ApplyShortAndMaybeClearBg_021dcba4)
extern "C" ARM void func_ov023_021dcba4(void* obj, short arg1) {
    if (*((unsigned char*)obj + 0x776) == 0) {
        ((struct SubStruct700_021dcba4*)((char*)obj + 0x700))->f72 = arg1;
        return;
    }

    if ((((struct SubStruct700_021dcba4*)((char*)obj + 0x700))->f74 & 4) == 0) {
        return;
    }

    ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x734));
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x738 + i * 4));
    }

    *(short*)((char*)obj + 0x770) = arg1;
    *(short*)((char*)obj + 0x772) = *(short*)((char*)obj + 0x770);
    *(int*)((char*)obj + 0x754) = 0;
    *(unsigned short*)((char*)obj + 0x774) |= 9;

    if (*(signed char*)((char*)obj + 0x77c) == 1) {
        memset((void*)GetSubBg0ScreenBaseAddr(), 0, 0x800);
    } else {
        memset((void*)GetBgCharBaseAddress020c4d1c(), 0, 0x800);
    }
}
