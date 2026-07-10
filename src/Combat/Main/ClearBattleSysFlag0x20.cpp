#include <globaldefs.h>

extern char data_021118e0;
extern "C" void func_020c7950(int, int);

// USA: func_020d0f40
ARM void ClearBattleSysFlag0x20(int a, int b, int c) {
    unsigned int flags;
    int arg0;
    if (a != 0xb) return;
    if (c == 0) return;
    flags = *(unsigned int*)(&data_021118e0 + 0x114);
    arg0 = *(int*)(&data_021118e0 + 0x104);
    flags &= ~0x20;
    *(unsigned int*)(&data_021118e0 + 0x114) = flags;
    func_020c7950(arg0, flags);
}
