#include <globaldefs.h>

// USA: func_020c8dfc
ARM unsigned short GetTimer0Counter(void) {
    return *(volatile unsigned short*)0x4000100;
}
