#include <globaldefs.h>

#define EXMEMCNT (*(volatile unsigned short*)0x4000204)

// USA: func_020d14b0
ARM void RestoreExmemcnt(int* in) {
    EXMEMCNT = (in[0] << 2) | (EXMEMCNT & ~0xc);
    EXMEMCNT = (in[1] << 4) | (EXMEMCNT & ~0x10);
}
