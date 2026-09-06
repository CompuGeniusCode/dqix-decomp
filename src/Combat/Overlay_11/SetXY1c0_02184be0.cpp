#include <globaldefs.h>

// USA: func_ov011_02184be0
ARM void SetXY1c0_02184be0(void* obj, short x, short y) {
    *(short*)((char*)obj + 0x1c0) = x;
    *(short*)((char*)obj + 0x1c2) = y;
}
