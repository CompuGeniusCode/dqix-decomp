#include <globaldefs.h>

// USA: func_ov000_02163440
ARM void SetShortTriple0x6e44(void* obj, unsigned short a, unsigned short b, unsigned short c) {
    *(unsigned short*)((char*)obj + 0x6e44) = a;
    *(unsigned short*)((char*)obj + 0x6e46) = b;
    *(unsigned short*)((char*)obj + 0x6e48) = c;
}
