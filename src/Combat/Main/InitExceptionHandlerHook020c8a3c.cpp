#include <globaldefs.h>

extern "C" void func_020c8aac(void);

struct HookState020c8a3c { unsigned int value; unsigned int unused4; unsigned int flag8; };
extern HookState020c8a3c data_02111588;

struct HwBlock020c8a3c { char pad[0xfdc]; void (*handler)(void); };

// USA: func_020c8a3c  (semantic: InitExceptionHandlerHook020c8a3c)
#pragma optimize_for_size off
extern "C" ARM void func_020c8a3c(void) {
    unsigned int v = *(unsigned int*)0x027ffd9c;
    if (v >= 0x02600000 && v < 0x02800000) {
        data_02111588.value = v;
    } else {
        data_02111588.value = 0;
    }
    if (data_02111588.value == 0) {
        *(void(**)(void))0x027ffd9c = func_020c8aac;
        HwBlock020c8a3c* hw = (HwBlock020c8a3c*)0x027e3000;
        hw->handler = func_020c8aac;
    }
    data_02111588.flag8 = 0;
}
