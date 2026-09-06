#include <globaldefs.h>

struct ScaledElementList0204aa28 {
    char* base;         // 0x0
    short index;        // 0x4
    char pad[4];        // 0x6..0x9
    unsigned char flag; // 0xa
};

// USA: func_0204aa28
ARM void* GetScaledElementPtr(struct ScaledElementList0204aa28* list) {
    int shift = 5;
    if (list->flag) {
        shift = 6;
    }
    return list->base + (list->index << shift);
}
