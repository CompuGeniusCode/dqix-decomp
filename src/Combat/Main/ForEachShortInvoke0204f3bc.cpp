#include <globaldefs.h>

extern "C" void func_0204f3bc(void* ctx, int value);

struct ShortList02081530 {
    char pad[4];
    short* entries;
    char pad2[0x14 - 8];
    unsigned char count;
};

// USA: func_02081530
ARM void ForEachShortInvoke0204f3bc(void* unused, void* ctx, struct ShortList02081530* list) {
    unsigned char i;
    if (list == NULL) {
        return;
    }
    for (i = 0; i < list->count; i++) {
        func_0204f3bc(ctx, list->entries[i]);
    }
}
