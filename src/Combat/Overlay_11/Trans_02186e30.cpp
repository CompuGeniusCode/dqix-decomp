#include <globaldefs.h>

extern "C" unsigned int _Z28CheckField0x14Or0x20PositivePi();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_0218b5b0();

// USA: func_ov011_02186e30  (semantic: Trans_02186e30)
extern "C" ARM unsigned int func_ov011_02186e30(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov017_0218b5b0();
    r0 = (unsigned int)_Z28CheckField0x14Or0x20PositivePi();
    r1 = r0;
    r0 = r4;
    r0 = (unsigned int)func_ov011_02184c68(r0, r1);
    r0 = 0x1;
    return r0;
}
