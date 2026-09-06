#include <globaldefs.h>

// USA: func_0204a60c
ARM void SetSubBg3Priority(int priority) {
    unsigned short *reg = (unsigned short *)0x400100e;
    *reg = (*reg & ~3) | priority;
}
