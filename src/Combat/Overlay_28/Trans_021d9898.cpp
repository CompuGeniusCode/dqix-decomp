#include <globaldefs.h>

extern int data_ov028_021d9bc4;
extern "C" unsigned int _Z21GetTaggedValueAsFloatP19TaggedValue02030b44();

// USA: func_ov028_021d9898  (semantic: Trans_021d9898)
extern "C" ARM unsigned int func_ov028_021d9898(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)_Z21GetTaggedValueAsFloatP19TaggedValue02030b44();
    r1 = (unsigned int)&data_ov028_021d9bc4;
    r1 = *(unsigned int*)((char*)r1 + 0x0);
    *(unsigned int*)((char*)r1 + 0x0) = (unsigned int)r0;
    r0 = 0x1;
    return r0;
}
