#include <globaldefs.h>

struct BitfieldSrc_021edf6c { unsigned int pad0; unsigned int field : 12; };

extern "C" int func_ov000_02154a04(void* p0, int p1, unsigned short p2, int p3);

// USA: func_ov024_021edf6c
ARM int Forward4ArgsBitfield_021edf6c(void** a0, int a1, struct BitfieldSrc_021edf6c* a2, int* out, int a4) {
    *out = func_ov000_02154a04(*a0, a1, a2->field, a4);
    return 1;
}
