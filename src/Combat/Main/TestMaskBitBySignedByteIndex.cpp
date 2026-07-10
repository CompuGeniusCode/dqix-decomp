#include <globaldefs.h>

struct SearchStruct;
signed char FindSignedByteIndex(struct SearchStruct* obj, int value);
extern "C" int func_0202bc8c(void* obj);

// USA: func_0202bd34
ARM int TestMaskBitBySignedByteIndex(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) return 0;
    return (func_0202bc8c(obj) & (1 << idx)) != 0;
}
