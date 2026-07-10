#include <globaldefs.h>

extern void* data_020fe9a4;
extern "C" void func_020c5e98(void* p, int a, int b);
extern "C" void func_020c5e38(void* p, int a, int b);

// USA: func_020290ac
ARM void FlushOrClearBuffer020290ac(int flag) {
    if (data_020fe9a4 == NULL) return;
    if (flag == 0) {
        func_020c5e98(data_020fe9a4, 0, 0x6000);
    } else {
        func_020c5e38(data_020fe9a4, 0, 0x6000);
    }
}
