#include <globaldefs.h>

// USA: func_ov000_02163404
ARM void SetByteField0x5901AndFlag0x8000(void* work, unsigned char val) {
    *(unsigned char*)((char*)work + 0x5901) = val;
    *(int*)((char*)work + 0x55f4) |= 0x8000;
}
