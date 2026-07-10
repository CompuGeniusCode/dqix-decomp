#include <globaldefs.h>

extern "C" void func_020c9be0(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_020ca054
ARM void ValidateAndFlushRange(unsigned int mode, unsigned int addr, unsigned int size, unsigned int dir) {
    unsigned int region, adjusted;
    if (mode != 0) return;
    region = addr & 0xff000000;
    if (dir != 0) {
        if (dir == 0x800000) addr = addr - size;
    } else {
        addr = addr + size;
    }
    adjusted = addr & 0xff000000;
    if (region == 0x4000000 || region >= 0x8000000 ||
        adjusted == 0x4000000 || adjusted >= 0x8000000) {
        func_020c9be0(adjusted, addr, size, dir);
    }
}
