#include <globaldefs.h>

// USA: func_ov000_02163454
ARM void ZeroShortTriple0x6e44(void* obj) {
    *(unsigned short*)((char*)obj + 0x6e44) = 0;
    *(unsigned short*)((char*)obj + 0x6e46) = 0;
    *(unsigned short*)((char*)obj + 0x6e48) = 0;
}
