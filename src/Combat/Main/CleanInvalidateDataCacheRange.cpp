#include <globaldefs.h>

// USA: func_020c82f0
ARM void CleanInvalidateDataCacheRange(int addr, int size) {
    asm { mov ip, 0 }
    int end = size + addr;
    addr &= ~0x1f;
    do {
        asm {
            mcr p15, 0, ip, c7, c10, 4
            mcr p15, 0, addr, c7, c14, 1
        }
        addr += 0x20;
    } while (addr < end);
}
