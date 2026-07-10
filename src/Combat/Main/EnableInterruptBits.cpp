#include <globaldefs.h>

struct IntRegs020c6cbc {
    volatile unsigned short ime;
    unsigned char pad[6];
    volatile unsigned int ie;
};

// USA: func_020c6cbc
ARM unsigned int EnableInterruptBits(unsigned int mask) {
    struct IntRegs020c6cbc* r = (struct IntRegs020c6cbc*)0x4000208;
    unsigned short ime = r->ime;
    r->ime = 0;
    unsigned int old = r->ie;
    r->ie = old | mask;
    (void)r->ime;
    r->ime = ime;
    return old;
}
