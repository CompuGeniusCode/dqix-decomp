#include <globaldefs.h>

struct Entry_021e2c38 {
    char pad0[0xc];
    short f0xc;
    char pad1[0x10 - 0xe];
    short f0x10;
    char pad2[0x16 - 0x12];
    unsigned char f0x16;
};

extern "C" struct Entry_021e2c38* func_ov023_021db4e4(void*);

// USA: func_ov023_021e2c38  (semantic: SomeFunc_021e2c38)
extern "C" ARM int func_ov023_021e2c38(void* obj) {
    int result = 1;
    struct Entry_021e2c38* entry = func_ov023_021db4e4(obj);
    int falseVal = 0;
    int trueVal = result;
    while (entry != 0) {
        result = (entry->f0x16 & 1) ? trueVal : falseVal;
        if (result == 0) break;
        while (entry->f0x10 > 0) {
            entry = func_ov023_021db4e4(obj);
        }
        if (entry->f0xc >= 0) {
            entry = func_ov023_021db4e4(obj);
        }
    }
    return result;
}
