#include <globaldefs.h>

// USA: func_ov000_02160fbc
ARM void ClearCombatWorkFlags0x55f4(void* work, int mask) {
    *(int*)((char*)work + 0x55f4) &= ~mask;
}
