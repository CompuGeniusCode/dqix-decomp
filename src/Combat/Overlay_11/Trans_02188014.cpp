#include <globaldefs.h>

extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();
extern "C" unsigned int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();

// USA: func_ov011_02188014  (semantic: Trans_02188014)
extern "C" ARM unsigned int func_ov011_02188014(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();
    r4 = r0;
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    *(unsigned int*)((char*)r0 + 0x99c) = (unsigned int)r4;
    r0 = 0x1;
    return r0;
}
