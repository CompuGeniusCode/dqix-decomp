#include <globaldefs.h>

struct IntRegs020c6c90 {
    volatile unsigned short ime;
    unsigned char pad[6];
    volatile unsigned int ie;
};

// USA: func_020c6c90
ARM unsigned int SetInterruptEnable(unsigned int val) {
    struct IntRegs020c6c90* r = (struct IntRegs020c6c90*)0x4000208;
    unsigned short ime = r->ime;
    r->ime = 0;
    unsigned int old = r->ie;
    r->ie = val;
    (void)r->ime;
    r->ime = ime;
    return old;
}
