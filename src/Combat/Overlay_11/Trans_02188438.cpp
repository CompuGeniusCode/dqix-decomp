#include <globaldefs.h>

extern int data_02109bf4;
extern "C" unsigned int _Z25IsAnimationActive0209ca2cPv(unsigned int);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02188438  (semantic: Trans_02188438)
extern "C" ARM unsigned int func_ov011_02188438(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)&data_02109bf4;
    r0 = (unsigned int)_Z25IsAnimationActive0209ca2cPv(r0);
    r1 = r0;
    r0 = r4;
    r0 = (unsigned int)func_ov011_02184c68(r0, r1);
    r0 = 0x1;
    return r0;
}
