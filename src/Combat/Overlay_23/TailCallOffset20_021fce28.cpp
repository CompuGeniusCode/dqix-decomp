#include <globaldefs.h>

extern "C" int func_02034bc4(void *obj, int a1, int a2, int a3);

// USA: func_ov023_021fce28
ARM int TailCallOffset20_021fce28(void *obj, int a1, int a2, int a3) {
    return func_02034bc4((char*)obj + 0x20, a1, a2, a3);
}
