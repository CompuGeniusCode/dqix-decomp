#include <globaldefs.h>

extern "C" unsigned int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();
extern "C" unsigned int _Z39CallFunc021f6788ForIndexUnder3_021f6eb8Pvi(unsigned int, unsigned int);
extern "C" unsigned int func_ov011_021849c8();
extern "C" unsigned int func_ov017_021b2164();

// USA: func_ov011_02188384  (semantic: Trans_02188384)
extern "C" ARM unsigned int func_ov011_02188384(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();
    r4 = r0;
    r0 = (unsigned int)func_ov017_021b2164();
    r0 = (unsigned int)func_ov011_021849c8();
    r1 = r4;
    r0 = (unsigned int)_Z39CallFunc021f6788ForIndexUnder3_021f6eb8Pvi(r0, r1);
    r0 = 0x1;
    return r0;
}
