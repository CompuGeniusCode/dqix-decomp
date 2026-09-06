#include <globaldefs.h>

// USA: func_0204a67c
ARM void SetMainBg3Priority(int priority) {
    unsigned short *reg = (unsigned short *)0x400000e;
    *reg = (*reg & ~3) | priority;
}
