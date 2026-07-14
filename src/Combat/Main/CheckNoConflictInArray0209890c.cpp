#include <globaldefs.h>

extern "C" int func_02001aec(void* a, void* b, int n);

// USA: func_0209890c
ARM int CheckNoConflictInArray0209890c(void* arr, void* obj) {
    int i;
    unsigned int field = *(unsigned int*)((char*)obj + 0x6c);
    if (((field << 5) >> 31) == 0) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        if (func_02001aec((char*)arr + i * 0xe8 + 0x14, (char*)obj + 0x14, 6) == 0) {
            return 0;
        }
    }
    return 1;
}
