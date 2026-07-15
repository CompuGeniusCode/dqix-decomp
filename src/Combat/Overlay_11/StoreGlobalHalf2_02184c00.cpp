#include <globaldefs.h>

unsigned short GetGlobalHalf0x2(void);

// USA: func_ov011_02184c00
ARM void StoreGlobalHalf2_02184c00(void* obj) {
    *(unsigned int*)((char*)obj + 0x1d4) = GetGlobalHalf0x2();
}
