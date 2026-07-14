#include <globaldefs.h>

extern "C" void func_020b6acc(int a, void* b, int c);

// USA: func_020b9a6c
ARM void ConfigureBattleTimersFromFlags020b9a6c(void* p0) {
    int flags = *(int*)p0;
    int notBit4 = 0;
    if (!(flags & 4)) notBit4 = 1;
    if (flags & 0x20) {
        if (!(flags & 8)) {
            if (notBit4) {
                func_020b6acc(0x1c, (char*)p0 + 0x4c, 3);
                notBit4 = 0;
            }
            func_020b6acc(0x1b, (char*)p0 + 0x10, 3);
        }
    }
    flags = *(int*)p0;
    if (!(flags & 2)) {
        if (notBit4) {
            func_020b6acc(0x19, (char*)p0 + 0x28, 0xc);
        } else {
            func_020b6acc(0x1a, (char*)p0 + 0x28, 9);
        }
    } else {
        if (notBit4) {
            func_020b6acc(0x1c, (char*)p0 + 0x4c, 3);
        }
    }
    flags = *(int*)p0;
    if (!(flags & 1)) {
        func_020b6acc(0x1b, (char*)p0 + 4, 3);
    }
}
