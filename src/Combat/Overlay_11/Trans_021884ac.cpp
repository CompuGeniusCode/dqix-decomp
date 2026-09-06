#include <globaldefs.h>

extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();
extern "C" unsigned int func_020457e0();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_021884ac  (semantic: Trans_021884ac)
extern "C" ARM unsigned int func_ov011_021884ac(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    r0 = (unsigned int)func_020457e0();
    r1 = r0;
    r0 = r4;
    r0 = (unsigned int)func_ov011_02184c68(r0, r1);
    r0 = 0x1;
    return r0;
}
