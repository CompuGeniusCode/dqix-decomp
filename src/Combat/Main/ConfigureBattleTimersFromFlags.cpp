#include <globaldefs.h>

extern "C" void func_020b6acc(int a, void* b, int c);

// USA: func_020b99b0
ARM void ConfigureBattleTimersFromFlags(void* p0) {
    int flags = *(int*)p0;
    if (flags & 4) {
        goto bit4;
    }
    if (flags & 2) {
        goto bit2;
    }
    func_020b6acc(0x19, (char*)p0 + 0x28, 0xc);
    goto after;
bit2:
    func_020b6acc(0x1c, (char*)p0 + 0x4c, 0x3);
    goto after;
bit4:
    if (flags & 2) {
        goto after;
    }
    func_020b6acc(0x1a, (char*)p0 + 0x28, 0x9);
after:
    if (!(*(int*)p0 & 1)) {
        func_020b6acc(0x1b, (char*)p0 + 4, 0x3);
    }
}
