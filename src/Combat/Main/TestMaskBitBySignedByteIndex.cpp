#include <globaldefs.h>

struct SearchStruct;
signed char FindSignedByteIndex(struct SearchStruct* obj, int value);
struct SearchStruct;
int GetEntryField0x4OrFieldA0202bc8c(struct SearchStruct*);

// USA: func_0202bd34
ARM int TestMaskBitBySignedByteIndex(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) return 0;
    return (GetEntryField0x4OrFieldA0202bc8c((struct SearchStruct*)obj) & (1 << idx)) != 0;
}
