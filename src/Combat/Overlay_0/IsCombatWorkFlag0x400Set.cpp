#include <globaldefs.h>

// USA: func_ov000_02161264
ARM int IsCombatWorkFlag0x400Set(void* work) {
    return *(int*)((char*)work + 0x55f4) & 0x400;
}
