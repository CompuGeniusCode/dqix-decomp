#include <globaldefs.h>

struct SearchStruct;
signed char FindSignedByteIndex(struct SearchStruct* obj, int value);

// USA: func_0202c1c0
ARM int TestBitBySignedByteIndex(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) return 0;
    return *(unsigned char*)((char*)obj + 0x1000 + 0xc) & (1 << idx);
}
