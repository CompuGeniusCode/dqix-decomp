#include <globaldefs.h>

// USA: func_ov000_02160fd4
ARM int GetCombatWorkFlags0x55f4(void* work, int mask) {
    return *(int*)((char*)work + 0x55f4) & mask;
}
