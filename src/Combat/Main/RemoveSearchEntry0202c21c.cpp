#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};
struct ByteSearchStruct;

signed char FindSignedByteIndex(struct SearchStruct* obj, int value);
signed char FindSignedByteSlot(struct ByteSearchStruct* obj, int value);
void ClearSearchFlagBit0202c69c(struct SearchStruct* obj, int value);
extern "C" void func_0202c288(struct SearchStruct* obj);

// USA: func_0202c21c
ARM void RemoveSearchEntry0202c21c(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex(obj, value);
    if (idx < 0) {
        idx = FindSignedByteSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100c) &= ~(1 << idx);
    ClearSearchFlagBit0202c69c(obj, value);
    func_0202c288(obj);
    obj->arr[idx] = 0;
}
