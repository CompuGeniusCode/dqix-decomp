#include <globaldefs.h>

// USA: func_020c6d1c
ARM unsigned int SwapWordWithInterruptsDisabled(unsigned int value) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    volatile unsigned int* field = (volatile unsigned int*)0x4000214;
    unsigned short save = *ime;
    *ime = 0;
    unsigned int old = *field;
    *field = value;
    (void)*ime;
    *ime = save;
    return old;
}
