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
loop:
    {
        int i = 31 - CountLeadingZeros(bits);
        if (i < 0) goto done;
        unsigned int bit = 1u << i;
        unsigned int notBit = ~bit;
        bits &= notBit;
        if (data_02111670[i] != target) goto loop;
        data_02111670[i] = 0;
        data_0211166c &= notBit;
        goto loop;
    }
done:
    SetIRQInterruptState(irq);
}
