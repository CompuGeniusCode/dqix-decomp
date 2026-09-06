#include <globaldefs.h>

unsigned int EnableSpecificInterrupts(unsigned int mask);
unsigned int DisableSpecificInterrupts(unsigned int mask);

struct IntState020d8654 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d8654 data_0214e4a0;

// USA: func_020d8694  (semantic: PopInterruptDisableState)
extern "C" ARM void func_020d8694(void) {
    if (data_0214e4a0.field_4 & 1) {
        EnableSpecificInterrupts(4);
    } else {
        DisableSpecificInterrupts(4);
    }
    data_0214e4a0.field_4 >>= 1;
}
