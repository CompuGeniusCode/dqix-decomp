#include <globaldefs.h>

// USA: func_02087c08
ARM void ClearBattleFlags0x14And0x5802087c08(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x4000;
    *(int*)(base + 0x58) &= ~0x7000;
    base[0x72] = 0;
    base[0x95] = 0;
}
