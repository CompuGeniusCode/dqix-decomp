#include <globaldefs.h>

// USA: func_ov004_0215eb20
ARM unsigned short GetFlagBitFromField150_0215eb20(void* obj, int bit) {
    void* p = *(void**)((char*)obj + 0x150);
    unsigned short v = *(unsigned short*)((char*)p + 0x954);
    return (unsigned short)(v & (1 << bit));
}
