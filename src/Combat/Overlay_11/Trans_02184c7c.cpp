#include <globaldefs.h>

extern "C" unsigned int _Z15SetBothCountersPvii(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(unsigned int);
extern "C" unsigned int _s32_div_f(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_0218b5b0();

// USA: func_ov011_02184c7c  (semantic: Trans_02184c7c)
extern "C" ARM unsigned int func_ov011_02184c7c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r6 = r0;
    r0 = (unsigned int)func_ov017_0218b5b0();
    r5 = r0;
    r0 = r6;
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(r0);
    r4 = r0;
    r0 = r6 + 0x8;
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(r0);
    r1 = 0x22;
    r0 = (unsigned int)_s32_div_f(r0, r1);
    r1 = r4;
    r2 = r0;
    r0 = r5;
    r0 = (unsigned int)_Z15SetBothCountersPvii(r0, r1, r2);
    r0 = 0x1;
    return r0;
}
