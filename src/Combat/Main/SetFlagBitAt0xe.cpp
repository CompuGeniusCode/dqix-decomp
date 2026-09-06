#include <globaldefs.h>

struct SearchStruct;
struct ByteSearchStruct;
signed char FindSignedByteIndex(struct SearchStruct* obj, int value);
signed char FindSignedByteSlot(struct ByteSearchStruct* obj, int value);

// USA: func_0202c5bc
ARM void SetFlagBitAt0xe(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) {
        idx = FindSignedByteSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) |= (1 << idx);
}
