#include <globaldefs.h>

// USA: func_0208792c
ARM void ClearBattleFlags0x14And0x580208792c(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x800;
    *(int*)(base + 0x58) &= ~0x38;
    base[0x6f] = 0;
    base[0x92] = 0;
}
