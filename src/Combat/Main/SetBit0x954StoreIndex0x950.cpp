#include <globaldefs.h>

// USA: func_02083ca0
ARM void SetBit0x954StoreIndex0x950(unsigned char* obj, int bit) {
    *(unsigned short*)(obj + 0x954) |= 1 << bit;
    *(int*)(obj + 0x950) = bit;
}
