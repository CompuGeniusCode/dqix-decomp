#include <globaldefs.h>

// USA: func_ov000_02160fa8
ARM void SetCombatWorkFlags0x55f4(void* work, int mask) {
    *(int*)((char*)work + 0x55f4) |= mask;
}
