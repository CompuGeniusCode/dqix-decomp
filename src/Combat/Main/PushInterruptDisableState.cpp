#include <globaldefs.h>

unsigned int DisableInterruptBits(unsigned int mask);

struct IntState020d8654 {
    unsigned char field_0;
    unsigned char pad1[3];
    unsigned int field_4;
};
extern IntState020d8654 data_0214e4a0;

// USA: func_020d8654
ARM void PushInterruptDisableState(void) {
    data_0214e4a0.field_4 <<= 1;
    unsigned int old = DisableInterruptBits(4);
    data_0214e4a0.field_4 |= (old & 4) ? 1 : 0;
}
