#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);

// USA: func_020ae4c8
ARM bool IsFieldAEqual4020ae4c8() {
    int base = func_ov017_0218b5b0();
    int p = *(int*)(base + 0x3734);
    return *(unsigned short*)(p + 0xa) == 4;
}
