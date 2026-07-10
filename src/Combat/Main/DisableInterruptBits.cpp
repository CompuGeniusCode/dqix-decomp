#include <globaldefs.h>

struct IntRegs020c6cec {
    volatile unsigned short ime;
    unsigned char pad[6];
    volatile unsigned int ie;
};

// USA: func_020c6cec
ARM unsigned int DisableInterruptBits(unsigned int mask) {
    struct IntRegs020c6cec* r = (struct IntRegs020c6cec*)0x4000208;
    unsigned short ime = r->ime;
    r->ime = 0;
    unsigned int old = r->ie;
    r->ie = old & ~mask;
    (void)r->ime;
    r->ime = ime;
    return old;
}
