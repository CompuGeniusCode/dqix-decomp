#include <globaldefs.h>

// USA: func_020c82d4
ARM void CleanDataCacheRange(int addr, int size) {
    int end = size + addr;
    addr &= ~0x1f;
    do {
        asm { mcr p15, 0, addr, c7, c10, 1 }
        addr += 0x20;
    } while (addr < end);
}
