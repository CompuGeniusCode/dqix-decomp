#include <globaldefs.h>

extern "C" void func_ov031_02227804(void);
ARM void *CallWithZeroExtra_0223e218(void *a, void *b, void *c, int d);

// USA: func_ov031_022277e4
ARM void *RegisterCallback120_022277e4(void) {
    return CallWithZeroExtra_0223e218(0, (void*)func_ov031_02227804, 0, 0x78);
}
