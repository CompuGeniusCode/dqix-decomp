#include <globaldefs.h>

extern int data_ov033_022a2a2c;
extern "C" unsigned int func_0202f894(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_ov033_022a2180  (semantic: Trans_022a2180)
extern "C" ARM unsigned int func_ov033_022a2180(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r12 = 0;
    unsigned int r14 = 0;
    r14 = r0;
    r12 = r1;
    r3 = r2;
    r0 = (unsigned int)&data_ov033_022a2a2c;
    r1 = r14;
    r2 = r12;
    r0 = (unsigned int)func_0202f894(r0, r1, r2, r3);
    return r0;
}
