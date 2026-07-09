#include <globaldefs.h>

// USA: func_020c832c
ARM void InvalidateInstructionCacheRange(int addr, int size) {
    int end = size + addr;
    addr &= ~0x1f;
    do {
        asm { mcr p15, 0, addr, c7, c5, 1 }
        addr += 0x20;
    } while (addr < end);
}
