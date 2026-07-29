#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
unsigned int CountLeadingZeros(unsigned int x);

extern unsigned int data_0211166c;
extern unsigned short data_02111670[];

// USA: func_020c9a88
ARM void ClearMatchingBitmapEntries_020c9a88(unsigned int mask, unsigned short target) {
    unsigned int irq = DisableIRQInterrupts();
    unsigned int bits = mask & data_0211166c & 0x1ff;
    for (;;) {
        int i = 31 - CountLeadingZeros(bits);
        if (i < 0) break;
        unsigned int bit = 1u << i;
        if (data_02111670[i] == target) {
            bits &= ~bit;
            data_0211166c &= ~bit;
            data_02111670[i] = 0;
        } else {
            bits &= ~bit;
        }
    }
    SetIRQInterruptState(irq);
}
